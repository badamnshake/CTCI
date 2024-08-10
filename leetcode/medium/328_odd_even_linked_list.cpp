// https://leetcode.com/problems/odd-even-linked-list
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *temp = head->next;
        ListNode *prev;

        while (odd != nullptr && even != nullptr)
        {
            prev = odd;
            odd->next = even->next;
            odd = odd->next;
            if (odd == nullptr)
                break;
            even->next = odd->next;
            even = even->next;
        }
        if (prev->next != nullptr)
            prev = prev->next;
        prev->next = temp;
        return head;
    }
};
