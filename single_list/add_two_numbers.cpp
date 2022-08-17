// - 两数相加
// - 加法的逻辑和链表的一些操作考察
#include "single_list.h"

ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2)
{
    // - 定义一个虚拟头节点，记录结果
    auto dummy = new ListNode(-1);
    auto head = dummy;
    int carry = 0;
    while (l1 || l2)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->value;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->value;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        auto node = new ListNode(sum);
        head->next = node;
        head = head->next;
    }

    // - 最后判断一下进位
    if (carry != 0)
    {
        auto node = new ListNode(carry);
        head->next = head;
    }
    return dummy->next;
}