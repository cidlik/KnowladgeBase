#!/usr/bin/env python3

import asyncio
import time
from aiohttp import ClientSession

OPERATE_INSIDE = False


async def get_weather(city):
    async with ClientSession() as session:
        url = 'http://api.openweathermap.org/data/2.5/weather'
        params = {'q': city, 'APPID': '2a4ff86f9aaa70041ec8e82db64abf56'}
        proxy = "http://proxy.elvees.com:3128"

        async with session.get(url=url, params=params, timeout=10, proxy=proxy) as response:
            weather_json = await response.json()
            if OPERATE_INSIDE:
                print(f'{city}: {weather_json["weather"][0]["main"]}')
            else:
                return f'{city}: {weather_json["weather"][0]["main"]}'


async def main(cities_):
    tasks = []
    for city in cities_:
        tasks.append(asyncio.create_task(get_weather(city)))

    if OPERATE_INSIDE:
        for task in tasks:
            await task
    else:
        results = await asyncio.gather(*tasks)
        for result in results:
            print(result)


cities = ['Moscow', 'St. Petersburg', 'Rostov-on-Don', 'Kaliningrad', 'Vladivostok',
          'Minsk', 'Beijing', 'Delhi', 'Istanbul', 'Tokyo', 'London', 'New York']

print(time.strftime('%X'))

asyncio.run(main(cities))

print(time.strftime('%X'))
