"""
    Author: Tanseer Saji <github.com/tanseersaji>
    Desc: An Implementation of Linked List Data Structure
"""


class Node:
    def __init__(self, val=0, next=None) -> None:
        self.val = val
        self.next = next


def search(root, val) -> bool:
    ptr = root
    while ptr:
        if ptr.val == val:
            return True
        ptr = ptr.next
    return False


def traverse(root) -> None:
    ptr = root
    while ptr:
        print(ptr.val)
        ptr = ptr.next


def insert(root, val) -> None:
    ptr = root
    while ptr.next:
        ptr = ptr.next
    ptr.next = Node(val)


def delete(root, val) -> None:
    ptr = root
    if ptr.val == val:
        root = ptr.next
        ptr = None
        return

    prev = None
    while ptr:
        if ptr.val == val:
            break
        prev = ptr
        ptr = ptr.next
    if not ptr:
        return

    prev.next = ptr.next
    ptr = None


if __name__ == "__main__":
    llist = Node(0)
    for i in range(1, 10):
        insert(llist, i)
    delete(llist, 1)
    traverse(llist)
