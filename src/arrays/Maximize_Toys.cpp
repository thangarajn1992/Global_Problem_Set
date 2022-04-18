#include "all_lib.h"

/* Problem Link: https://practice.geeksforgeeks.org/problems/maximize-toys0331/1#
 * Input Format:
   no_of_toys
   money_in_hand
   vector of price for each toys
 */
int main()
{
    int no_of_toys, money_in_hand;
    std::cin >> no_of_toys;
    std::cin >> money_in_hand;
    std::vector<int> brochure(no_of_toys);
    for(int toy_no = 0; toy_no < no_of_toys; toy_no++)
        std::cin >> brochure[toy_no];

    std::sort(brochure.begin(), brochure.end());
    int toy_cnt = 0, sum_so_far = 0;
    for(toy_cnt = 0; toy_cnt < no_of_toys; toy_cnt++)
    {
        if((sum_so_far += brochure[toy_cnt]) > money_in_hand)
            break;
    }
    std::cout << " We can buy maximum of " << toy_cnt << " toys" << std::endl;
    return 0;
}

/* Testcase 1
 7 
 50
 1 12 5 111 200 1000 10
 Output:
 4

 Testcase 2
 3 
 100
 20 30 50
 Output:
 3
*/ 