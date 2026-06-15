/*
  Given the head of a singly linked list, reverse the list, and return the reversed list.
  
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
  
Example 2:
Input: head = [1,2]
Output: [2,1]
  
Example 3:
Input: head = []
Output: []
 
*/



class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next; 
            /// Save the rest of the list
            curr->next = prev;              // Flip the pointer backward
            
            // Move both pointers one step forward
            prev = curr;
            curr = nextNode;
        }
        
        return prev; // New head of the reversed list
    }
};
