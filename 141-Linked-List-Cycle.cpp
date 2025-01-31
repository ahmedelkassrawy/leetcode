/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        ListNode* slow = head; //this will point to the head , move 1 step
        ListNode* fast = head; //this pointing to head, move 2 steps

        while(fast != NULL && fast-> next != NULL) //check that fast is not null or the next not null
        {
            slow = slow -> next; //moving one step
            fast = fast->next->next; //moving two steps

            if(slow == fast) return true; //if they both point to the same thing then it becomes a cycle 
        }

        return false;
    }
};