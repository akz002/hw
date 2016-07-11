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
    struct ListNode *l1Current = l1, *l2Current = l2;
    struct ListNode NullNode;
    NullNode.val = 0;
    NullNode.next = &NullNode;
    
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    do {
        NodeCurrent = (struct ListNode *) malloc (sizeof(struct ListNode));
        temp = l1Current->val + l2Current->val + carry;
        NodeCurrent->val = temp >= 10 ? (temp - 10): temp;
        carry = temp >= 10 ? 1:0;

        NodeCurrent->next = NULL;
        if (NodeHead == NULL) { //first node
            NodeHead = NodeCurrent;
            NodeTail = NodeCurrent;
        } else {
            NodeTail->next = NodeCurrent;
            NodeTail = NodeCurrent;
        }
//        printf("current val=%d\n", NodeCurrent->val);

        l1Current = l1Current->next;
        l2Current = l2Current->next;
        if (l1Current == NULL)
            l1Current = &NullNode;
        if (l2Current == NULL)
            l2Current = &NullNode;
    } while (l1Current != &NullNode || l2Current != &NullNode || carry != 0);

    return NodeHead;
}
