/* GeeksForGeeks Repo Link
   https://app.gitbook.com/@thangarajn1992/s/geeksforgeeks/gfg-easy/bitonic-point
 */
#include "all_lib.h"

class BitonicPoint {
public:
    int getBitonicPoint(vector<int> arr)
    {
        int size = arr.size();
        for(int num = 1; num < size; num++)
        if(arr[num] < arr[num-1])
        {
            return arr[num-1];
        }
        return arr[size-1];
    }
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
