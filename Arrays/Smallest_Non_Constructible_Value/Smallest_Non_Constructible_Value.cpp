#include<vector>
#include<iostream>

using namespace std;

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
    cout << "Smallest Non-Constructible Value is " << SmallestNonConstructibleValue(vec) << endl;
    return 1;
}

/* Unit-Testing
   Test-Case 1:
   Enter the Number of Elements:6
   4 5 2 1 9 12
   Smallest Non-Constructible Value is 34  
*/ 