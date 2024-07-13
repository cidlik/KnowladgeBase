#include <gst/gst.h>
#include <glib.h>

// #define SET_CTX_MANUAL 1

gboolean
callback(gpointer data)
{
  static guint16 i=0;
  g_print("Iter=%"G_GUINT16_FORMAT"\n",i++);
  return TRUE;
}


static gboolean
bus_call (GstBus     *bus,
          GstMessage *msg,
          gpointer    data)
{
  GMainLoop *loop = (GMainLoop *) data;

  switch (GST_MESSAGE_TYPE (msg)) {

    case GST_MESSAGE_EOS:
      g_print ("End of stream\n");
      g_main_loop_quit (loop);
      break;

    case GST_MESSAGE_ERROR: {
      gchar  *debug;
      GError *error;

      gst_message_parse_error (msg, &error, &debug);
      g_free (debug);

      g_printerr ("Error: %s\n", error->message);
      g_error_free (error);

      g_main_loop_quit (loop);
      break;
    }
    default:
      break;
  }

  return TRUE;
}

/**
 * make gst-felix-dirclean && make gst-felix \
 *    && scp $ssh_no_key buildroot/output/build/gst-felix-custom/src/foo/test-app root@$ASSET_1764:/root
 *
 * gst-launch-1.0 \
      felixmultisrc name=multi sensor=IMX415 sensor-mode=4 setup-file=/etc/felix/imx415/imx415.cfg \
      setup-file-ctx0=/etc/felix/imx415/overlay/imx415-crop-3840x2160.cfg \
      setup-file-ctx1=/etc/felix/imx415/overlay/imx415-crop-2304x1296.cfg \
      ! video/x-raw,width=1920,height=1080,format=NV12 \
      ! queue \
      ! fakesink \
      multi. \
      ! video/x-raw,width=3840,height=2160,format=NV12 \
      ! queue \
      ! fakesink

      // ifdef SET_CTX_MANUAL
      src_0::context=0 src_1::context=0 \
*/
int
main (int   argc,
      char *argv[])
{
  GMainLoop *loop = NULL;
  GMainContext* context = NULL;
  GSource* gsrc = NULL;

  GstElement *pipeline, *source, *capsfilter1, *capsfilter2, *queue1, *queue2, *sink1, *sink2;
  GstBus *bus;
  guint bus_watch_id;
  GstPad *src_pad1, *src_pad2;
  GstPad *caps_pad1, *caps_pad2;
  GstCaps *caps1, *caps2;

  const gchar *caps_str1 = "video/x-raw,width=1920,height=1080,format=NV12";
  const gchar *caps_str2 = "video/x-raw,width=3840,height=2160,format=NV12";

  gst_init (&argc, &argv);

  /* Initialisation */
  /* https://stackoverflow.com/questions/26410585/add-callback-for-separate-g-main-loop */
  context = g_main_context_new ();
  loop = g_main_loop_new (context, FALSE);
  gsrc = g_timeout_source_new_seconds (1);
  g_source_set_callback (gsrc, callback, loop, NULL);
  g_source_attach (gsrc, context);

  g_main_context_unref (context);
  context = NULL;
  g_source_unref (gsrc);
  gsrc = NULL;

  /* Create gstreamer elements */
  pipeline  = gst_pipeline_new ("test");
  source    = gst_element_factory_make ("felixmultisrc",  "src");
  capsfilter1 = gst_element_factory_make("capsfilter",    "caps1");
  capsfilter2 = gst_element_factory_make("capsfilter",    "caps2");
  queue1    = gst_element_factory_make ("queue",          "queue1");
  queue2    = gst_element_factory_make ("queue",          "queue2");
  sink1     = gst_element_factory_make ("fakesink",       "sink1");
  sink2     = gst_element_factory_make ("fakesink",       "sink2");

  if (!pipeline || !source || !capsfilter1 || !capsfilter2 || !queue1 || !queue2 || !sink1 || !sink2) {
    g_printerr ("One element could not be created. Exiting.\n");
    return -1;
  }

  /* Set up the pipeline */
  g_object_set (source,
                "sensor", "IMX415",
                "sensor-mode", 4,
                "setup-file", "/etc/felix/imx415/imx415.cfg",
                "setup-file-ctx0", "/etc/felix/imx415/overlay/imx415-crop-3840x2160.cfg",
                "setup-file-ctx1", "/etc/felix/imx415/overlay/imx415-crop-2304x1296.cfg",
                "exposure-auto", false,
                "exposure-gain", 1.4,
                NULL);
  caps1 = gst_caps_from_string(caps_str1);
  g_object_set(capsfilter1, "caps", caps1, NULL);
  caps2 = gst_caps_from_string(caps_str2);
  g_object_set(capsfilter2, "caps", caps2, NULL);

  /* we add a message handler */
  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  bus_watch_id = gst_bus_add_watch (bus, bus_call, loop);
  gst_object_unref (bus);

  /* we add all elements into the pipeline */
  gst_bin_add_many (GST_BIN (pipeline),
                    source, capsfilter1, capsfilter2, queue1, sink1, queue2, sink2, NULL);
  if (gst_element_link_many (capsfilter1, queue1, sink1, NULL) != TRUE ||
      gst_element_link_many (capsfilter2, queue2, sink2, NULL) != TRUE) {
    g_printerr ("Elements could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }

  /* Manually link the Tee, which has "Request" pads */
  /* https://gstreamer.freedesktop.org/documentation/tutorials/basic/multithreading-and-pad-availability.html?gi-language=c */
  src_pad1 = gst_element_request_pad_simple (source, "src_%u");
#ifdef SET_CTX_MANUAL
  g_object_set(src_pad1, "context", 1, NULL);
#endif
  g_print ("Obtained request pad %s\n", gst_pad_get_name (src_pad1));
  caps_pad1 = gst_element_get_static_pad (capsfilter1, "sink");
  if (gst_pad_link (src_pad1, caps_pad1) != GST_PAD_LINK_OK) {
    g_printerr ("Source pad 1 could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }
  src_pad2 = gst_element_request_pad_simple (source, "src_%u");
#ifdef SET_CTX_MANUAL
  g_object_set(src_pad2, "context", 0, NULL);
#endif
  g_print ("Obtained request pad %s\n", gst_pad_get_name (src_pad2));
  caps_pad2 = gst_element_get_static_pad (capsfilter2, "sink");
  if (gst_pad_link (src_pad2, caps_pad2) != GST_PAD_LINK_OK) {
    g_printerr ("Source pad 2 could not be linked.\n");
    gst_object_unref (pipeline);
    return -1;
  }
  gst_object_unref (caps_pad1);
  gst_object_unref (caps_pad2);

  /* Set the pipeline to "playing" state*/
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Iterate */
  g_print ("Running...\n");
  // g_main_loop_run (loop);

  g_usleep(1000000);
  // gst_element_set_state (pipeline, GST_STATE_PAUSED);
  int x, y;
  unsigned int width, height;
  int context_num;
  unsigned int current_context;
  g_object_get (src_pad1,
                "context", &context_num,
                "current-context", &current_context,
                "bounds-x", &x,
                "bounds-y", &y,
                "bounds-width", &width,
                "bounds-height", &height,
                NULL);
  g_print ("FOOBAR: %s: bounds x = %d; y = %d; width = %u; height = %u\n",
           gst_pad_get_name (src_pad1), x, y, width, height);
  g_print ("FOOBAR: %s: context = %d; current-context = %u\n",
           gst_pad_get_name (src_pad1), context_num, current_context);

  g_object_get (src_pad2,
                "context", &context_num,
                "current-context", &current_context,
                "bounds-x", &x,
                "bounds-y", &y,
                "bounds-width", &width,
                "bounds-height", &height,
                NULL);
  g_print ("FOOBAR: %s: bounds x = %d; y = %d; width = %u; height = %u\n",
           gst_pad_get_name (src_pad2), x, y, width, height);
  g_print ("FOOBAR: %s: context = %d; current-context = %u\n",
           gst_pad_get_name (src_pad2), context_num, current_context);

  /* Out of the main loop, clean up nicely */
  g_print ("Returned, stopping playback\n");
  gst_element_set_state (pipeline, GST_STATE_NULL);

  g_print ("Deleting pipeline\n");
  gst_object_unref (GST_OBJECT (pipeline));
  g_source_remove (bus_watch_id);
  g_main_loop_unref (loop);

  return 0;
}
