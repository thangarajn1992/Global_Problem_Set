#include<vector>
#include<iostream>
#include<string>
using namespace std;

void Rotate_Array_Clockwise(vector<int> &vec, int shift)
{
    int size = vec.size();
    shift = shift % size;
    int start = 0, count = 0;
    /* Handling Cyclic Dependencies */
    while(count < size)
    {
        int curr = start;
        int prev = vec[curr];
        do
        {
            curr = (shift + curr) % size;
            int temp = prev;
            prev = vec[curr];
            vec[curr] = temp;
            count++;
        }while(curr != start);
        start++;
    }
}

string print_vector_int(vector<int> vec)
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
    int n = 0, k = 0;
    cout << "Enter the Number of Elements:" ;
    cin >> n;
    vector<int> vec(n,0);
    for(int i = 0; i < n; i++)
        cin >> vec[i];
    cout << "Enter the shifting size:" ;
    cin >> k;
    Rotate_Array_Clockwise(vec, k);
    cout << "Array after shifting by " << k << " is " << print_vector_int(vec) << endl;
    return 1;
}