import logging
import threading

import pytest

import singleton


logger = logging.getLogger("test_singleton")


@pytest.fixture(autouse=True)
def del_singleton():
    yield


def test_is_singleton():
    instance1 = singleton.Singleton(instance_name="instance1")
    instance2 = singleton.Singleton(instance_name="instance2")
    assert instance1 is instance2


def test_child_is_singleton():
    child1 = singleton.ChildSingleton(instance_name="child1")
    child2 = singleton.ChildSingleton(instance_name="child2")
    assert child1 is child2



def get_singleton(set_, instance_name):
    set_.add(singleton.ChildSingleton(instance_name=instance_name))


def test_multithreading():
    set_ = set()
    thread1 = threading.Thread(target=get_singleton, args=(set_, "child1",))
    thread2 = threading.Thread(target=get_singleton, args=(set_, "child2",))
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()
    assert len(list(set_)) == 1
