import logging

import pytest
import pytest_asyncio
from aiohttp import ClientSession, web

import weather_server


# https://github.com/pytest-dev/pytest-asyncio/issues/842
@pytest_asyncio.fixture
async def server():
    logging.debug("Try to start server")
    app = web.Application()
    app.add_routes([web.get('/weather', weather_server.handle)])
    runner = web.AppRunner(app)
    await runner.setup()
    host = "localhost"
    port = 8080
    site = web.TCPSite(runner, host, port)
    await site.start()
    logging.debug(f"Server started at '{host}:{port}'")
    yield host, port
    logging.debug(f"Try to stop server")


@pytest.mark.asyncio
async def test_server(server):
    logging.debug("Try to get weather")
    async with ClientSession() as session:
        city = "Moscow"

        url=f"http://{server[0]}:{server[1]}/weather"
        async with session.get(url=url, params={"city": city}, timeout=10) as response:
            text = await response.text()
            logging.debug(text)
            assert text
