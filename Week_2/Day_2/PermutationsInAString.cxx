/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 */



class Solution {
public:
    bool checkInclusion(string s1, string s2) 
{
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        vector<int> need(26, 0), window(26, 0);

        for (char c : s1) need[c - 'a']++;

        for (int i = 0; i < m; i++) 
        {
            window[s2[i] - 'a']++;

            if (i >= n) 
            {
                window[s2[i - n] - 'a']--;
            }

            if (window == need) return true;
        }

        return false;
    }
};
