/*
Given an m x n matrix, return all elements of the matrix in spiral order

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int s_r=0;
        int s_c=0;
        int e_r=row-1;
        int e_c=col-1;
        int c=0;
        int t=row*col;
        while(c<t){
            //printing first row
            for(int i=s_c; c<t && i<=e_c;i++){
                ans.push_back(matrix[s_r][i]);
                c++;
            }
            s_r++;
            //printing last col
            for(int i=s_r;c<t && i<=e_r;i++){
                ans.push_back(matrix[i][e_c]);
                c++;
            }
            e_c--;
            //print last row
            for(int i=e_c;c<t && i>=s_c;i--){
                ans.push_back(matrix[e_r][i]);
                c++;
            }
            e_r--;
            //print first col
            for(int i=e_r; c<t && i>=s_r;i--){
                ans.push_back(matrix[i][s_c]);
                c++;
            }
            s_c++;
        }
        return ans;
    }
};