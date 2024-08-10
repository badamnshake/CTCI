
#include <algorithm>
using namespace std;

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
    int pairSum(ListNode *head)
    {
        ListNode *prev = head;
        ListNode *curr = head;
        int maxs = 1;

        while (curr != nullptr)
        {
            curr = curr->next->next;
            prev = prev->next;
        }

        prev = reverseList(prev);
        curr = head;

        while (prev != nullptr)
        {
            maxs = max(prev->val + curr->val, maxs);
            prev = prev->next;
            curr = curr->next;
        }
        return maxs;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *temp;

        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};