//
// Created by 燕文豪 on 2022/7/26.
//

#ifndef _LIST_NODE_H
#define _LIST_NODE_H
class ListNode
{
public:
    int value;
    ListNode *next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int value) : value(value), next(nullptr) {}
    ListNode(int value, ListNode *next) : value(value), next(next) {}
};
#endif
