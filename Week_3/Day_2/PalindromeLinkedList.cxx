/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:
Input: head = [1,2]
Output: false
*/





class Solution {
public:
    bool isPalindrome(ListNode* head) 
      {
        if (head == nullptr || head->next == nullptr) 
         {
            return true;
        }
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while (curr != nullptr) 
       {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Compare first half with reversed second half
        ListNode* left = head;
        ListNode* right = prev;
        
        while (right != nullptr) 
         {
            if (left->val != right->val) 
            {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};
