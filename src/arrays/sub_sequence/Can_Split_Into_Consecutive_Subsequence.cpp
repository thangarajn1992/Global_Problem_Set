/*
Problem Statement:
You are given an integer array nums that is sorted in non-decreasing order.
Determine if it is possible to split nums into one or more subsequences 
such that both of the following conditions are true:
    * Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
    * All subsequences have a length of 3 or more.
Return true if you can split nums according to the above conditions, or false otherwise.
*/

/*
Algorithm:
    Greedy Approach:
    1. We maintain two maps 
        "remaining" indicating how many entries remaining for this num
        "subseqEndingCount" indcating how many subsequence ending with this num
    2. We iterate through each element and store the occurances in "remaining" map.
    3. While iterating next time we either
       try to include this entry with previous subsequence ending with (i-1)
       or 
       try to create a new subsequence with i, i+1, i+2. 
       If both are not possible, then we return false.
*/

/* Problem/Solution Links:
    * https://leetcode.com/problems/split-array-into-consecutive-subsequences/
*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> remaining, subseqEndingCount;
        for(int num : nums)
        {
            remaining[num]++;
        }
        
        for(int num : nums)
        {
            if(remaining[num] > 0)
            {
                remaining[num]--;
                if(subseqEndingCount[num-1] > 0)
                {
                    subseqEndingCount[num-1]--;
                    subseqEndingCount[num]++;
                }
                else if(remaining[num+1] > 0 && remaining[num+2] > 0)
                {
                    remaining[num+1]--;
                    remaining[num+2]--;
                    subseqEndingCount[num+2]++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

