/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 移除链表中指定元素其实就两步，查找到，然后移除
// 为了将删除头结点也统一起来，定义一个新的虚拟头结点，这样删除第一个结点也统一了

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *virtual_nodes = new ListNode(0);
        virtual_nodes->next = head;
        ListNode *cur = virtual_nodes;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                //  node作为临时节点
                ListNode *node = cur->next;
                cur->next = node->next;
                delete (node);
            }
            else
                cur = cur->next;
        }
        head = virtual_nodes->next;
        delete (virtual_nodes);
        return head;
    }
};