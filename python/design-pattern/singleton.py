#!/usr/bin/env python

import logging

logger = logging.getLogger("singleton")

class Singleton:
    _instances = {}

    def __new__(cls, *args, **kwargs):
        logger.debug(f"{kwargs['instance_name']}: __new__()")
        logger.debug(cls._instances)
        if cls not in cls._instances:
            logger.debug("cls not in cls._instances")
            instance = super().__new__(cls)
            cls._instances[cls] = instance
        return cls._instances[cls]

    def __init__(self, instance_name):
        self.instance_name = instance_name
        logger.debug(f"{self.instance_name}: __init__()")

    def __del__(self):
        logger.debug(f"{self.instance_name}: __del__()")


class ChildSingleton(Singleton):
    pass
