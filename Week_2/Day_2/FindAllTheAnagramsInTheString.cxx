/*
  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/







class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
{
        int n = s.size(), m = p.size();
        vector<int> ans;

        if (m > n) 
          return ans;

        vector<int> need(26, 0), window(26, 0);

        for (char c : p)
            need[c - 'a']++;

        for (int i = 0; i < n; i++) 
        {
            window[s[i] - 'a']++;

            if (i >= m) 
                window[s[i - m] - 'a']--;
            
            if (window == need) 
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
