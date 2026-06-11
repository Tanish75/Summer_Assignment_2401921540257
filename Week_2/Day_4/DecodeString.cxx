/*
  Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

  */




class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string curr = "";
        int num = 0;
        for (int i = 0; i < s.size(); i++) 
        {
            char ch = s[i];

            if (ch >= '0' && ch <= '9') 
                num = num * 10 + (ch - '0');
            

            else if (ch == '[') 
            {
                numStack.push(num);
                strStack.push(curr);

                curr = "";
                num = 0;
            }

            else if (ch == ']') 
            {
                int k = numStack.top();
                numStack.pop();

                string temp = curr;

                curr = strStack.top();
                strStack.pop();

                while (k--) {
                    curr += temp;
                }
            }

            else 
                curr += ch;
            
        }

        return curr;
    }
};
