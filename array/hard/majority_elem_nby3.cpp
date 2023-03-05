/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
*/



/***************************************** Approach 1 *****************************************/
/*

    Time Complexity : O(N^2), The brute force algorithm contains two nested for loops that each run for N
    iterations, adding up to quadratic time complexity. Where N is the size of the Array(nums). Where N is the
    size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because unordered_set(set) and Array(output) will maximum store 2
    element not more than that.

    Solved using Array + Hash Table(Unordered set). Brute Force.

    Note : This Approach is giving TLE.

*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countMajority = nums.size()/3;
        unordered_set<int> set;
        vector<int> output;
        for(auto num : nums){
            int count = 0;
            for(auto element : nums){
                if(element == num){
                    count++;
                }
            }
            if(count > countMajority){
                set.insert(num);
            }
        }
        for(auto it = set.begin(); it != set.end(); it++){
            output.push_back(*it);
        }
        return output;
    }
};

/***************************************** Approach 2 *****************************************/
/*

    Time Complexity : O(N), We iterate over Array(nums) once and make a constant time HashMap(Unordered map)
    insertion on each iteration. Therefore, the algorithm runs in O(N) time. Where N is the size of the Array
    (nums).

    Space Complexity : O(N), Unordered map space. 

    Solved using Array + Hash Table(Unordered map).

*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countMajority = nums.size()/3;
        unordered_map<int, int> map;
        vector<int> output;
        for(auto num : nums){
            map[num]++;
        }
        for(auto num : map){
            if(num.second > countMajority){
                output.push_back(num.first);
            }
        }
        return output;
    }
};

/***************************************** Approach 3 *****************************************/
/*

    Time Complexity : O(NlogN), Sorting the array(nums) costs O(NlogN). Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because unordered_set(set) and Array(output) will maximum store 2
    element not more than that.

    Solved using Array + Sorting + Hash Table(Unordered set).

*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 1){
            return {nums[0]};
        }
        if(nums.size() == 2 && nums[0] != nums[1]){
            return {nums[0], nums[1]};
        }
        sort(nums.begin(), nums.end());
        int countMajority = nums.size()/3;
        unordered_set<int> set;
        vector<int> output;
        int count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] == nums[i]){
                count++;
                if(count > countMajority){
                    set.insert(nums[i]);
                }
            }
            else{
                count = 1;
            }
        }
        for(int it : set){
            output.push_back(it);
        }
        return output;
    }
};

/***************************************** Approach 4 *****************************************/
/*

    Time Complexity : O(N), Boyer-Moore performs constant work exactly N times, so the algorithm runs in
    linear time. Where N is the size of the Array(nums).

    Space Complexity : O(1), Constant Space. Because we are creating Array(output) as per the demand of
    program so it doesnot count as auxilary space also Array(output) will maximum store 2 element not more than
    that which is a constant. 

    Solved using Boyer-Moore Voting Algorithm.

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = INT_MIN, num2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            else if(num2 == element){
                count2++;
            }
            else if(count1 == 0){
                num1 = element;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = element;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> output;
        int countMajority = nums.size()/3;
        count1 = 0, count2 = 0;
        for(auto element : nums){
            if(num1 == element){
                count1++;
            }
            if(num2 == element){
                count2++;
            }
        }
        if(count1 > countMajority){
            output.push_back(num1);
        }
        if(count2 > countMajority){
            output.push_back(num2);
        }
        return output;
    }
};
