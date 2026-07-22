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

/*  太多if判断，导致速度较慢。
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = new ListNode();
        if(fast -> next == nullptr){
            head = nullptr;
            delete(temp);
            return head;
        }
        while(n --) fast = fast -> next;
        if(fast == nullptr){
            head = head -> next;
            delete temp;
            return head;
        }
        while(fast -> next != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }
        temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete(temp);
        return head;
    }
};
*/

//  使用一个虚拟头结点，让结果统一，从而减少判断！
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dull_nodes = new ListNode(0);
        dull_nodes->next = head;
        ListNode *fast = dull_nodes;
        ListNode *slow = dull_nodes;
        ListNode *temp = new ListNode();
        while (n--)
            fast = fast->next;
        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        temp = slow->next;
        slow->next = slow->next->next;
        delete (temp);
        head = dull_nodes->next;
        return head;
    }
};