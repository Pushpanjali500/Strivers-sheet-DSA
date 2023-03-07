/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/


//approach 1  time comp---O(N*LOGN)  space comp---O(1)
#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
    int main()
    {
        vector<int> arr{100,200,1,2,3,4};
        int lon=longestConsecutive(arr);
        cout<<"The longest consecutive sequence is "<<lon<<endl;
        
    }


//approach 2   time comp---O(N) space comp--O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set < int > hashSet;
        for (int num: nums) {
            hashSet.insert(num);
        }

        int longestStreak = 0;

       for (int num: nums) {
         if (!hashSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while (hashSet.count(currentNum + 1)) {
              currentNum += 1;
              currentStreak += 1;
            }

           longestStreak = max(longestStreak, currentStreak);
          }
       }

      return longestStreak;
    }
};