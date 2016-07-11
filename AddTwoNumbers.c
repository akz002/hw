/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
/*
 * Question from https://leetcode.com/problems/add-two-numbers/ 
 * You are given two linked lists representing two non-negative
 * numbers. The digits are stored in reverse order and each of 
 * their nodes contain a single digit. Add the two numbers and 
 * return it as a linked list. 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int temp, carry = 0;
    struct ListNode *NodeCurrent, *NodeHead = (struct ListNode *)NULL, *NodeTail;
    struct ListNode *p = l1, *q = l2;
    
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    do {
        temp = carry;
        if (p != NULL) {
            temp += p->val;
            p = p->next;
        }
        if (q != NULL) {
            temp += q->val;    
            q = q->next;
        }
//      printf("temp is: %d\n", temp);
        NodeCurrent = (struct ListNode *) calloc (1, sizeof(struct ListNode));
        NodeCurrent->val = temp >= 10 ? (temp - 10): temp;
        carry = (temp >= 10) ? 1:0;

        if (NodeHead == NULL) { //first node
            NodeHead = NodeCurrent;
            NodeTail = NodeCurrent;
        } else {
            NodeTail->next = NodeCurrent;
            NodeTail = NodeCurrent;
        }
    } while (p != NULL || q != NULL || carry != 0);

    return NodeHead;
}
