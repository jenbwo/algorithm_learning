# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: Optional[ListNode]
        :type val: int
        :rtype: Optional[ListNode]
        """
        virtual_nodes = ListNode(0)
        virtual_nodes.next = head
        cur_nodes = virtual_nodes
        while cur_nodes.next != None :
            if cur_nodes.next.val == val :
                cur_nodes.next = cur_nodes.next.next
            else:
                cur_nodes = cur_nodes.next
        head = virtual_nodes.next
        return head