#include <iostream>
#include <unordered_set>
using namespace std;
// 题目：环形链表
// https://leetcode.cn/problems/linked-list-cycle/?envType=problem-list-v2&envId=hash-table
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
        unordered_set<ListNode *> hash_table;
        while (head)
        {
            if (hash_table.find(head) != hash_table.end())
            {
                return true;
            }
            hash_table.insert(head);
            head = head->next;
        }
        return false;
    }
};
class Solution_second
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *next = head;
        while (head)
        {
            if (next == NULL)
            {
                return false;
            }
            next = next->next ? next->next->next : NULL;
            head = head->next;
            if (next == head && next != NULL)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution solution; //[3,2,0,-4]
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    cout << solution.hasCycle(head) << endl;
    return 0;
}