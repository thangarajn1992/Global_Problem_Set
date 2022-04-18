/*
https://app.gitbook.com/@thangarajn1992/s/geeksforgeeks/gfg-medium/untitled
*/

#include "all_lib.h"

using namespace std;

int findNumberOfTriangles(vector<int> &arr);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findNumberOfTriangles(arr) << " Triangles are possible." << endl;
}

int findNumberOfTriangles(vector<int> &arr){
    int count = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = n-1; i >= 1; i--)
    {
        int l = 0, r = i - 1; 
        while(l < r)
        {
            if(arr[l] + arr[r] > arr[i])
            {
                count += r-l;
                r--;
            }
            else 
            {
                l++;
            }
        }
    }
    return count;
}

/* 
Testcase 1
6
26 9 27 22 16 27
17 Triangles are possible.
*/
