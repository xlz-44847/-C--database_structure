/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* cur = head, * prev = NULL;
    while (cur)
    {
        if (prev == NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev->val == cur->val)
            {
                struct ListNode* tmp = cur;
                prev->next = NULL;
                cur = cur->next;
                free(tmp);
                tmp = NULL;
            }
            else
            {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}