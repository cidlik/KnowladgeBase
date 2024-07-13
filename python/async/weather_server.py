#!/usr/bin/env python3

import asyncio
import json
from aiohttp import ClientSession, web


PROXY_URL = "http://proxy.elvees.com:3128"


async def get_weather(city):
    async with ClientSession() as session:
        url = f'http://api.openweathermap.org/data/2.5/weather'
        params = {'q': city, 'APPID': '2a4ff86f9aaa70041ec8e82db64abf56'}

        async with session.get(url=url, params=params, timeout=10, proxy=PROXY_URL) as response:
            weather_json = await response.json()
            try:
                return weather_json["weather"][0]["main"]
            except KeyError:
                return 'Нет данных'


async def get_translation(text, source, target):
    async with ClientSession() as session:
        url = 'https://libretranslate.de/translate'

        data = {'q': text, 'source': source, 'target': target, 'format': 'text'}

        async with session.post(url, json=data, timeout=10, proxy=PROXY_URL) as response:
            translate_json = await response.json()

            try:
                return translate_json['translatedText']
            except KeyError:
                return text


async def handle(request):
    city_en = request.rel_url.query['city']

    weather_en = await get_weather(city_en)

    result = {'city': city_en, 'weather': weather_en}

    return web.Response(text=json.dumps(result, ensure_ascii=False))


async def main():
    # curl 'localhost:8080/weather?city=Moscow'
    app = web.Application()
    app.add_routes([web.get('/weather', handle)])
    runner = web.AppRunner(app)
    await runner.setup()
    host = "localhost"
    port = 8080
    site = web.TCPSite(runner, host, port)
    await site.start()
    print(f"Server started at '{host}:{port}'")

    while True:
        await asyncio.sleep(3600)


if __name__ == '__main__':
    asyncio.run(main())
