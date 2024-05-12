from collections import deque


def first_var(graph: dict) -> None:
    print("\nfirst var")
    peach_seller = "tom"
    l = deque(graph["you"])
    searched = {"you": None}
    while l:
        friend = l.popleft()
        if friend not in searched:
            searched[friend] = None
            if friend != peach_seller:
                l += graph[friend]
            else:
                print(f"peach seller: {friend}")
                return True
        else:
            print(f"{friend} was skipped")
    print("peach seller was not found")
    return False


def second_var(graph: dict) -> None:
    print("\nsecond var")
    queue = deque(["you"])
    peach_seller = "bob"
    visited = {"you": None}

    while queue:
        cur_node = queue.popleft()
        if cur_node == peach_seller:
            break

        next_nodes = graph[cur_node]
        for next_node in next_nodes:
            if next_node not in visited:
                visited[next_node] = cur_node
                queue.append(next_node)

    cur_node = peach_seller
    short_path = []
    while cur_node != "you":
        short_path.append(cur_node)
        cur_node = visited[cur_node]
    short_path.append("you")
    short_path = list(reversed(short_path))
    print(f"short path: {short_path}")
    print(f"length: {len(short_path) - 1}")


def main():
    # see the book on page 139
    graph = {}
    graph["you"] = ["bob", "alice", "claire"]

    graph["bob"] = ["anuj", "peggy"]
    graph["alice"] = ["peggy"]
    graph["claire"] = ["tom", "jonny"]

    graph["anuj"] = []
    graph["peggy"] = []
    graph["tom"] = []
    graph["jonny"] = []

    first_var(graph)
    second_var(graph)


if __name__ == "__main__":
    main()
