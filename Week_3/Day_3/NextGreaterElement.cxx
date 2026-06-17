/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

  */




#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) 
{
        std::unordered_map<int, int> nextGreater;
        std::stack<int> st;
        
        // Find next greater element for all items in nums2
        for (int num : nums2) 
        {
            while (!st.empty() && st.top() < num) 
            {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // Map remaining elements in stack to -1
        while (!st.empty())
          {
            nextGreater[st.top()] = -1;
            st.pop();
        }
        
        // Build the answer for nums1
        std::vector<int> ans;
        for (int num : nums1) 
        {
            ans.push_back(nextGreater[num]);
        }
        
        return ans;
    }
};
