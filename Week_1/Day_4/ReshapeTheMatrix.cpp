/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Example 1:


Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]
Example 2:


Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]
*/
#include <vector>

class Solution {
public:
    std::vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) {
            return mat;
        }
        
       
        vector<vector<int>> reshaped(r, vector<int>(c));
        
    
        for (int i = 0; i < m * n; ++i) {
            // Map the 1D index 'i' to the original mat coordinates
            int orig_row = i / n;
            int orig_col = i % n;
            
            // Map the 1D index 'i' to the new reshaped coordinates
            int new_row = i / c;
            int new_col = i % c;
            
            reshaped[new_row][new_col] = mat[orig_row][orig_col];
        }
        
        return reshaped;
    }
};
