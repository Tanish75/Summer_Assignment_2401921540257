/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false
Example 4:
Input: s = "([])"
Output: true
Example 5:
Input: s = "([)]"
Output: false

*/




#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> openBrackets;
        
        for (char c : s)
         {
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[') {
                openBrackets.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, it means we have a closing bracket 
                // without a matching opening bracket (e.g., s = "]")
                if (openBrackets.empty()) 
                {
                    return false;
                }
                
                char topElement = openBrackets.top();
                
                //  if current closing bracket matches the top of the stack
                if ((c == ')' && topElement == '(') ||
                    (c == '}' && topElement == '{') ||
                    (c == ']' && topElement == '[')) 
                    openBrackets.pop(); // Matched successfully! Remove it.
                else 
                    return false; // Mismatch found (e.g., "(]")
                
            }
        }
        
        // If stack is empty, all brackets were matched correctly.
        // If not empty, some opening brackets were left unclosed (e.g., s = "(").
        return openBrackets.empty();
    }
};

