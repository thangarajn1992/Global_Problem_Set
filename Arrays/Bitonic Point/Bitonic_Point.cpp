/* GeeksForGeeks Repo Link
   https://app.gitbook.com/@thangarajn1992/s/geeksforgeeks/gfg-easy/bitonic-point
 */
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++)
        if(arr[i] < arr[i-1])
        {
            cout << "Max element is " << arr[i-1] << endl;
            return 0;
        }
    cout << "Max element is " << arr[n-1] << endl;
    return 0;
}

/* 
Testcase 1
Input: 
9
1 15 25 45 42 21 17 12 11
Output: 
45

Testcase 2
Input: 
5
1 45 47 50 5
Output: 
50
*/
