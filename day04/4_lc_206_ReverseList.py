class Solution(object):
    def reverseList(self, head):
        pre = None          # 前驱指针，初始为空
        cur = head          # 当前指针，从头开始
        while cur:
            temp = cur.next   # 保存下一个节点，防止丢失
            cur.next = pre    # 反转：当前节点指向前驱
            pre = cur         # 前驱后移
            cur = temp        # 当前后移
        return pre            # 循环结束，pre 就是新头节点