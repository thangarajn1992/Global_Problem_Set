using namespace std;
#include<vector>
#include<iostream>
int SmallestNonConstructibleValue(vector<int> A) {
    sort(A.begin(), A.end());
    int max_constructible_value = 0;
    for(int a: A)
    {
        if( a > max_constructible_value + 1)
            break;
        max_constructible_value += a;
    }
    return max_constructible_value + 1;
}
int main()
{
    int n = 0;
    cout << "Enter the Number of Elements:" ;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    cout << "Smallest Non-Constructible Value is " << SmallestNonConstructibleValue(vec);
    return 1;
}