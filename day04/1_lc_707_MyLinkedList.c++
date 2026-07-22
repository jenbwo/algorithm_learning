//  这个在之前学过，还是不难的，就是一些边界条件需要注意。本次实现选用的是双链表。

class MyLinkedList
{
private:
    // 节点结构
    struct Node
    {
        int val;
        Node *prev;
        Node *next;
        Node(int v) : val(v), prev(nullptr), next(nullptr) {}
    };

    Node *dummy_nodes_head; // 虚拟头节点，不存储有效值
    Node *dummy_nodes_tail; // 虚拟尾节点，不存储有效值
    int size;               // 当前链表实际节点个数
public:
    MyLinkedList()
    {
        dummy_nodes_head = new Node(0);
        dummy_nodes_tail = new Node(0);
        dummy_nodes_head->next = dummy_nodes_tail;
        dummy_nodes_tail->prev = dummy_nodes_head;
        size = 0;
    }

    int get(int index)
    {
        if (index >= size || index < 0)
            return -1;
        else
        {
            Node *cur_nodes = dummy_nodes_head;
            int i = index;
            while (i--)
            {
                cur_nodes = cur_nodes->next;
            }
            return cur_nodes->next->val;
        }
    }

    void addAtHead(int val)
    {
        Node *temp_node = new Node(val);
        temp_node->next = dummy_nodes_head->next;
        temp_node->prev = dummy_nodes_head;
        dummy_nodes_head->next->prev = temp_node;
        dummy_nodes_head->next = temp_node;
        size += 1;
    }

    void addAtTail(int val)
    {
        Node *temp_node = new Node(val);
        temp_node->prev = dummy_nodes_tail->prev;
        temp_node->next = dummy_nodes_tail;
        dummy_nodes_tail->prev->next = temp_node;
        dummy_nodes_tail->prev = temp_node;
        size += 1;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
            return;
        else if (index == size)
        {
            addAtTail(val);
        }
        else if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            Node *cur_nodes = dummy_nodes_head;
            int i = index;
            while (i--)
                cur_nodes = cur_nodes->next;
            Node *temp_node = new Node(val);
            temp_node->next = cur_nodes->next;
            temp_node->prev = cur_nodes;
            cur_nodes->next->prev = temp_node;
            cur_nodes->next = temp_node;
            ++size;
            return;
        }
        return;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
            return;
        else
        {
            Node *cur_nodes = dummy_nodes_head;
            int i = index;
            while (i--)
                cur_nodes = cur_nodes->next;
            Node *temp_node = cur_nodes->next;
            cur_nodes->next = temp_node->next;
            temp_node->next->prev = cur_nodes;
            delete (temp_node);
            --size;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */