class MyLinkedList(object):
    def __init__(self):
        self.dummy = ListNode(0)   # 虚拟头节点，不存储有效值
        self.size = 0

    def get(self, index):
        if index < 0 or index >= self.size:
            return -1
        current = self.dummy.next
        for _ in range(index):
            current = current.next
        return current.val

    def addAtHead(self, val):
        new_node = ListNode(val)
        new_node.next = self.dummy.next
        self.dummy.next = new_node
        self.size += 1

    def addAtTail(self, val):
        # 找到真正的尾节点（dummy 之后的最后一个）
        current = self.dummy
        while current.next:
            current = current.next
        current.next = ListNode(val)
        self.size += 1

    def addAtIndex(self, index, val):
        if index < 0 or index > self.size:
            return
        # 找到前驱节点（插入位置的前一个）
        current = self.dummy
        for _ in range(index):
            current = current.next
        new_node = ListNode(val)
        new_node.next = current.next
        current.next = new_node
        self.size += 1

    def deleteAtIndex(self, index):
        if index < 0 or index >= self.size:
            return
        current = self.dummy
        for _ in range(index):
            current = current.next
        current.next = current.next.next
        self.size -= 1