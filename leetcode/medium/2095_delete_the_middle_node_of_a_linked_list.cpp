// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
// solved on 10-08-2024
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;

        ListNode *fast = head;
        ListNode *slow = new ListNode();
        slow->next = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return head;
    }
};