/*
Problem Statement:
Given an array containing N integers and an integer target.
Find the length of the longest Sub-Array with the sum of the elements equal to the given value target.
*/

/*
Algorithm:
Without -ve numbers:
    Without -ve numbers, we can use sliding window method.
    1. Use start, end pointers both initialized to 0. Sum = 0
    2. For end < N, 
       if Sum == target, result = max (result, end - start + 1)
       if sum > target, remove the first element and decrement the sum.

With -ve Numbers:
 Since we can negative numbers, we can't use sliding window method.
 1. Use unordered_map to store the running_sum with the index. 
 2. If running_sum is not present in MAP already, then we insert it. 
    We don't override the entry, because we need longest sub-array.
 3. If running_sum = target, result = max(result, index+1)
 4. If (running_sum - target is already present in the map, 
        result = max(result, index - map[running_sum - target])
*/

/*
Problem/Solution Links:
    * https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
*/
using namespace std;
#include <unordered_map>

class Solution{
    public:
    int lenOfLongSubarrNonNegative(int A[], int N, int target)
    {
        int start = 0, end = 0, sum = 0;
        int result = 0;
        while(end < N)
        {
            sum += A[end];
            if(sum == target)
            {
                result = max(result, end - start + 1);
            }
            else if(sum > target)
            {
                while(sum > target)
                {
                    sum -= A[start];
                    start++;
                }
            }
            end++;
        }
        return result;
    }


    /* With Negative Numbers */
    int lenOfLongSubarr(int A[],  int N, int target) 
    { 
        int result = 0;
        unordered_map<int,int> sum;
        sum[0] = -1;
        int currentSum = 0;
        for(int index = 0; index < N; index++)
        {
            currentSum += A[index];
            
            if(currentSum == target)
                result = max(result, index+1);
            
            if(sum.find(currentSum) == sum.end())
                sum[currentSum] = index;
            
            if(sum.find(currentSum - target) != sum.end())
                result = max(result, index - sum[currentSum - target]);
        }
        return result;
    } 
};


