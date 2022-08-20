/*
Problem Statement:
Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order.

Algorithm:
    1. We maintain unordered_map<int,int> to have elements we have seen already and their index.
    2. As we iterate, we check whether (target - nums[i]) is already seen, if so
        return i, map[target - nums[i]]

Problem/Solution Link:
    * https://leetcode.com/problems/two-sum/
    * https://app.gitbook.com/s/-MZXXYVMjEVeUTwQExBj-2910905616/difficulty-based-problem-index/leetcode-easy/leetcode-1-two-sum

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        seen[nums[0]] = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(seen.find(target - nums[i]) != seen.end())
                return {i, seen[target - nums[i]]};
            seen[nums[i]] = i;
        }
        return {}; // Control won't reach here
    }
};
