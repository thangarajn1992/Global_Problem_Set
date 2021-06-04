/*
Leetcode Repo Link: 
https://app.gitbook.com/@thangarajn1992/s/leetcode/v/main/leetcode-medium/leetcode-1465-maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts
*/

#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007;

int max_area(int height, int width, vector<int>& horizontalCuts, vector<int>& verticalCuts)
{
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());

    int row_max = max(horizontalCuts[0], height - horizontalCuts.back());
    int col_max = max(verticalCuts[0], width - verticalCuts.back());
        
    for(int row = 1; row < horizontalCuts.size(); row++)
        row_max = max(row_max, horizontalCuts[row] - horizontalCuts[row-1]);
        
    for(int col = 1; col < verticalCuts.size(); col++)
        col_max = max(col_max, verticalCuts[col] - verticalCuts[col-1]);
        
    return long(row_max) * long(col_max) % MOD;
}

int main()
{
    /* Input Format 
        eg:
        5 4              Height   Width 
        3                Horizontal Cut Count
        1 2 4            Horizontal Cut Indices
        2                Vertical Cut Count
        1 3              Vertical Cut Indices
    */    
    int height, width, n;
    cin >> height;
    cin >> width;
    cin >> n;
    vector<int> horizontalCuts(n);
    for(int i = 0; i < n; i++)
        cin >> horizontalCuts[i];
    cin >> n;
    vector<int> verticalCuts(n);
    for(int i = 0; i < n; i++)
        cin >> verticalCuts[i];
    cout << "Maximum area after cuts is " << max_area(height, width, horizontalCuts, verticalCuts) << endl;
    return 0;
}

