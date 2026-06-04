/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size(), col=matrix[0].size();
        int top=0,left=0,right=col-1,bottom=row-1;

        while(top<=bottom && left <= right)
        {
            //top
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;

            //right
            for(int j=top;j<=bottom;j++)
                ans.push_back(matrix[j][right]); 
            right--;
           
           //bottom
           if(top<=bottom)
           {
            for(int i=right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
              bottom--;
           }
          
           
           //left
           if(left<=right)
           {
            for(int j=bottom;j>=top;j--)
               ans.push_back(matrix[j][left]);
             left++;
           }
           
            
        }

       return ans; 
    }
};
