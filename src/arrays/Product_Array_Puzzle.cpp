#include "all_lib.h"
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& nums) {
    vector<long long int> result(nums.size());
    long long int temp = 1;
    for(int i = 0; i < nums.size(); i++)
    {
        result[i] = temp;
        temp *= nums[i];
    }
    temp = 1;
    for(int i = nums.size()-1; i >= 0 ; i--)
    {
        result[i] *= temp;
        temp *= nums[i];
    }
    return result;
}

string print_vector_long_long_int(vector<long long int> vec)
{
    string result = "";
    result += "[ ";
    for(int i = 0; i < vec.size(); i++)
        result += to_string(vec[i])+ " ";
    result += ']';
    return result;
}

int main()
{
    int n;
    cout << "Enter the number of elements:\t" ;
    cin >> n;
    vector<long long int> nums(n);
    cout << "Enter " << n << " elements:" ;
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << print_vector_long_long_int(productExceptSelf(nums));
}

/* Testcase 1 
n = 5, [ 10, 3, 5, 6, 2]
Ans: [180, 600, 360, 300, 900]
*/