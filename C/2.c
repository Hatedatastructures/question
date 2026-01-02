#include <stdio.h>
#include <stdlib.h>


// 题目： 两数相加
// https://leetcode.cn/problems/add-two-numbers/
struct ListNode
{
    int val;
    struct ListNode *next;
};
void push_back(struct ListNode **cur, int val)
{
    struct ListNode *list = (struct ListNode *)malloc(sizeof(struct ListNode));
    list->next = NULL;
    // 如果list->next不置为空，则会出现野指针，出现内存错误等
    if (list == NULL)
    {
        return;
    }
    if (*cur == NULL)
    {
        list->val = val;
        *cur = list;
    }
    else
    {
        struct ListNode *temp = *cur;
        while (temp->next)
        {
            temp = temp->next;
        }
        // 找末尾
        list->val = val;
        temp->next = list;
    }
}
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = NULL;
    int carry = 0; // 进位变量
    // 如果while循环内没有carry判断，可以在循环判断过后检查carry，拷贝在链表的最后一个节点
    while (l1 || l2 || carry)
    {
        // 当 l1、l2 有节点或还有进位时循环
        int head_val = l1 ? l1->val : 0;
        int tail_val = l2 ? l2->val : 0;
        int sum = head_val + tail_val + carry;

        carry = sum / 10;

        int list_val = sum % 10;
        // 取个位
        push_back(&head, list_val);
        if (l1)
        {
            l1 = l1->next; // 移动 l1
        }

        if (l2)
        {
            l2 = l2->next; // 移动 l2
        }
    }
    // 没有需要释放的内存
    return head;
}