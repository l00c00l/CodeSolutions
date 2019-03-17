/*
 @Date    : 2019-01-08 11:01:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/merge-two-sorted-lists/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *l = new ListNode(0), *p = nullptr;
        l->next = nullptr;
        p = l;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            p = p->next;
        }
        while (l1)
        {
            p->next = new ListNode(l1->val);
            p = p->next;
            l1 = l1->next;
        }
        while (l2)
        {
            p->next = new ListNode(l2->val);
            p = p->next;
            l2 = l2->next;
        }
        ListNode* ret = l->next;
        delete l;
        return ret;
    }
};
