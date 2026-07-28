class ListNode:
    # 如果你本地测试需要这个定义，LeetCode 环境已自带，可以省略
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class MyLinkedList(object):

    def __init__(self):
        self.head = None
        self.size = 0

    def get(self, index):
        if index < 0 or index >= self.size:
            return -1
        current = self.head
        for _ in range(index):
            current = current.next
        return current.val

    def addAtHead(self, val):
        new_node = ListNode(val)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def addAtTail(self, val):
        new_node = ListNode(val)
        if self.head is None:          # 空链表
            self.head = new_node
        else:
            current = self.head
            while current.next:        # 遍历到最后一个节点
                current = current.next
            current.next = new_node
        self.size += 1

    def addAtIndex(self, index, val):
        # 1. 无效索引判断
        if index < 0 or index > self.size:
            return
        
        # 2. 如果 index == 0，直接复用 addAtHead
        if index == 0:
            self.addAtHead(val)
            return
        
        # 3. 如果 index == size，直接复用 addAtTail（可选，也可以统一处理）
        if index == self.size:
            self.addAtTail(val)
            return
        
        # 4. 中间插入：找到前驱节点（第 index-1 个节点）
        current = self.head
        for _ in range(index - 1):
            current = current.next
        
        new_node = ListNode(val)
        new_node.next = current.next
        current.next = new_node
        self.size += 1

    def deleteAtIndex(self, index):
        # 1. 无效索引
        if index < 0 or index >= self.size:
            return
        
        # 2. 删除头节点
        if index == 0:
            self.head = self.head.next
        else:
            # 3. 找到前驱节点（第 index-1 个节点）
            current = self.head
            for _ in range(index - 1):
                current = current.next
            # 跳过待删除节点
            current.next = current.next.next
        self.size -= 1