#include <unordered_set>
#include <iostream>
//题目：相交链表
//https://leetcode.cn/problems/intersection-of-two-linked-lists/?envType=problem-list-v2&envId=hash-table
using namespace std;

struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    class Solution
    {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            if (headA == nullptr || headB == nullptr)
            {
                return nullptr;
            }
            unordered_set<ListNode *> hash_table;
            while (headA != nullptr)
            {
                hash_table.insert(headA);
                headA = headA->next;
            }
            while (headB != nullptr)
            {
                if (hash_table.find(headB) != hash_table.end())
                {
                    return headB;
                }
                headB = headB->next;
            }
            return nullptr;
        }
    };
int main()
{
    //a [4,1,8,4,5] b [5,6,1,8,4,5]
    Solution solution;
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    ListNode *result = solution.getIntersectionNode(headA, headB);
    std::cout << result->val << std::endl;
    return 0;
}