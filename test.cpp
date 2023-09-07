#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *reverse(ListNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->next == NULL)
    {
        head = node;
        return node;
    }
    ListNode *node1 = reverse(node->next);
    node1->next = node;
    node->next = NULL;
    return node;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{

    // if (head == NULL)
    // {
    //     return NULL;
    // }

    // int i = 0;
    // ListNode *Currleft = NULL;
    // ListNode *Prevleft = NULL;

    // while (i != left)
    // {
    //     if (i == 0)
    //     {
    //         Currleft = head;
    //     }
    //     else
    //     {
    //         Prevleft = Currleft;
    //         Currleft = Currleft->next;
    //     }
    //     i++;
    // }

    // int j = 0;
    // ListNode *currRight = NULL;
    // ListNode *nextRight = NULL;

    // while (j != right)
    // {
    //     if (j == 0)
    //     {
    //         currRight = head;
    //     }
    //     else
    //     {
    //         currRight = currRight->next;
    //     }
    //     j++;
    // }

    // currRight->next = nextRight;
    // currRight->next = NULL;

    // ListNode *NewHead = reverse(Currleft);
    // Prevleft->next = NewHead;

    // ListNode *temp = NewHead;

    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = nextRight;

    // return head;
}