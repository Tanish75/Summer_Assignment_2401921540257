/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 */





class Solution {
public:
    void LPS(vector<int>&lps ,string &s) 
    {  
        int pre=0,suf=1;
        while(suf<s.size())
        {
            if(s[pre]==s[suf])
            {
                lps[suf]=pre+1;
                pre++,suf++;
            }
            else
            {
                if(pre==0)
                {
                    lps[suf]=0;
                    suf++;
                }
                else
                {
                    pre=lps[pre-1];
                }
            }
        }
       
    }

    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        LPS(lps,needle);
        int first=0,second=0;
        while(first<haystack.size() && second< needle.size())
        {
            if(haystack[first]==needle[second])
            first++,second++;

            else
            {
                if(second==0)
                first++;
                else
                {
                    second=lps[second-1];
                }

            }
        }
        if(second==needle.size())
        return first-second;
        else
        return -1;
        
    }
};
