/*
  Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/






class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <bool> count (256,0);// SC O(1)
        int first =0,second=0,len=0;
        while(second<s.size())// TC O(N)
        {
            while(count[s[second]])
            {
                count[s[first]]=0;// removal of repeating element in previous pointer
                first++;
            }
            count[s[second]]=1;
            len=max(len,(second-first+1));
            second++;   
        }
        return len;
        
    }
};
