#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
    }
};

int main()
{
    Solution sol;

    // TODO create a linked list using a vector
    // https://www.youtube.com/watch?v=vcQIFT79_50&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=5

    std::vector<int> inVect = {3, 2, 0, -4};

    ListNode input(inVect[0]);
    ListNode *ptr = &input;
    for (int i = 1; i < inVect.size(); ++i)
    {
        ListNode tmp = ListNode(inVect[i]);
    }

    sol.hasCycle(ptr);
    return 0;
}

Input : head = [ 3, 2, 0, -4 ], pos = 1 Output : true