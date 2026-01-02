#include <cstdio>
#include <cstdlib>

// 题目： 两数相加
// https://leetcode.cn/problems/add-two-numbers/

class Solution
{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr)
        {
            ;
        }
        ListNode(int x) : val(x), next(nullptr)
        {
            ;
        }
        ListNode(int x, ListNode *next) : val(x), next(next)
        {
            ;
        }
    };

public: // 实现
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = nullptr;
        // 创建头节点一定要初始化为空
        size_t len_sum = 0;
        size_t sum = 0;
        // 加上sum判断保证在最后一个节点在还有值的情况下完成拷贝
        while (l1 || l2 || sum)
        {
            int L1_val = l1 ? l1->val : 0;
            int l2_val = l2 ? l2->val : 0;

            len_sum = L1_val + l2_val + sum;
            sum = len_sum / 10;
            // 计算进位数
            int temp_val = len_sum % 10;
            // 计算个位
            if (head != nullptr)
            {
                ListNode *temp = head;
                while (temp->next)
                {
                    temp = temp->next;
                }
                ListNode *_val = new ListNode(temp_val);
                temp->next = _val;
            }
            else
            {
                ListNode *temp = new ListNode(temp_val);
                head = temp;
            }

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        return head;
    }
};