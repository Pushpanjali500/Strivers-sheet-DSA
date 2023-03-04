/*
Given a matrix of size N x M. You have to find the Kth element which will obtain while traversing the matrix spirally starting from the top-left corner of the matrix.
Example 1:

Input: 
N = 3, M = 3, K = 4
A[] = {{1, 2, 3}, 
       {4, 5, 6}, 
       {7, 8, 9}}
Output: 
6
Explanation: Spiral traversal of matrix: 
{1, 2, 3, 6, 9, 8, 7, 4, 5}. Fourth element
is 6.
Example 2:

Input: 
N = 2, M = 2, K = 2 
A[] = {{1, 2},
       {3, 4}} 
Output: 
2
Explanation: Spiral traversal of matrix: 
{1, 2, 4, 3}. Second element is 2.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
	 int findK(vector<vector<int>> &a, int n, int m, int k)

    {

        int count =0;

        int sr=0;

        int sc=0;

        int er=n-1;

        int ec=m-1;

        int total=m*n;

       while(total--){

        
        // checking in starting row
        for(int i=sc;total>0&&i<=ec;i++){

            count++;

            if(count==k){

                return a[sr][i];

            }

        }

        sr++;
        // checking in ending column
        for(int i=sr;total>0&&i<=er;i++){

            count++;

            if(count==k){

                return a[i][ec];

            }

        }

        ec--;
        // checking in ending row
        for(int i=ec;total>0&&i>=sc;i--){

            count++;

            if(count==k){

                return a[er][i];

            }

        }
        er--;
        // checking in starting column
        for(int i=er;total>0&&i>=sr;i--){

            count++;

            if(count==k){

                return a[i][sc];

            }

        }

        sc++;
       }  

       return -1;

    }

};
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}