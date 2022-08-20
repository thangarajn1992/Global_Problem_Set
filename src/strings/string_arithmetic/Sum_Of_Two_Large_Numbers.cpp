/*
Problem Statement:
Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y. 
Takes two strings as inputs and returns the string without leading zeros
*/

/*
Algorithm: (Basic Mathematics)
    1. Traverse from end of both strings, add them and calc carry to be used next iteration.
    2. Once common length is done, do the same for extra length in longer string.
    3. Calculate total trailing zeroes.
    4. If result string is full zeroes, return "0". otherwise return sub_str without trailing zeroes.
       eg: "0000000" + "0000"
*/

/* Problem/Solution Link:
    * https://www.geeksforgeeks.org/sum-two-large-numbers/
*/

class Solution {
  public:
    string findSum(string X, string Y) {
        int XLen = X.size() - 1, YLen = Y.size() - 1;
        int carry = 0;
        string result = "";
        
        while(XLen >= 0 && YLen >= 0)
        {
            int val = (X[XLen] - '0') + (Y[YLen] - '0') + carry;
            carry = val / 10;
            val %= 10;
            char c = '0' + val;
            result = c + result;
            XLen--; YLen--;
        }
        while(XLen >= 0)
        {
            int val = X[XLen] - '0' + carry;
            carry = val/10;
            val %= 10;
            char c = '0' + val;
            result = c + result;
            XLen--;
        }
        while(YLen >= 0)
        {
            int val = Y[YLen] - '0' + carry;
            carry = val/10;
            val %= 10;
            char c = '0' + val;
            result = c + result;
            YLen--;
        }
        if(carry > 0)
        {
            char c = '0' + carry;
            result = c + result;
        }
        
        int i = 0;
        while(result[i] == '0')
            i++;
        
        if(i == result.size())
            return "0";
        else
            return result.substr(i, (int)result.size() - i + 1);
    }
};