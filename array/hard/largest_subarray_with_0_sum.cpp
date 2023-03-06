/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        //time comp 0(N)
        unordered_map<int, int> map;
        int ans = 0, sum = 0;
        
        for(int i=0; i<n; i++){
            
            sum += arr[i];
            // Array element starting from 0 to i adds up to 0
            if(sum == 0){
                ans = max(ans, i+1);
            }
            
            else {
                
                if(map.find(sum) != map.end()){
                    ans = max(ans, i - map[sum]);
                }
            }
            
            if(map.find(sum) == map.end())
                map[sum] = i;
            
        }
        
        return ans;
        
    }
};
