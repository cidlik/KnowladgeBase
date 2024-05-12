import random

from collections import deque
from treelib import Tree, Node


# https://readthedocs.org/projects/treelib/downloads/pdf/stable/
def get_random_tree(max_lvl: int = 3, max_neighbors: int = 3) -> Tree:
    tree = Tree()
    tree.create_node("Root", "root")
    parents_ = ["root"]

    count = 0
    en_blacksheep = True
    for lvl in range(max_lvl):
        tmp = []
        while parents_:
            # n = random.randint(1, max_neighbors)
            n = 2
            p = parents_.pop(0)
            for i in range(n):
                node = f"whitesheep_{count}"
                if en_blacksheep and random.randint(1, 6) == 6:
                    node = "blacksheep"
                    en_blacksheep = False
                tree.create_node(node.upper(), node, parent=p)
                tmp.append(node)
                count += 1
        parents_ = tmp

    if en_blacksheep:
        print("tree has NOT blacksheep")
    else:
        print("tree blacksheeped")

    return tree


class RanList(list):
    def __init__(
        self,
        len_: int = 10,
        left: int = 1,
        right: int = 1000,
    ):
        self.l = self._gen_list(len_, left, right)

    def _gen_list(self, len_, left, right):
        return list([random.randint(left, right) for i in range(len_)])

    def update(
        self,
        len_: int = 10,
        left: int = 1,
        right: int = 1000,
    ):
        self.l = self._gen_list(len_, left, right)
