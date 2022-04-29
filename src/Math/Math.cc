#include "Math.h"

int main()
{
    std::cout << "Catalan Numbers: " << std::endl;
    unsigned int number = 10;
    std::cout << "10th Catalan Number (recursive): " << catalanNumberRecursive(number) << std::endl;
    std::cout << "10th Catalan Number (DP): " << catalanNumberDP(number) << std::endl;
    std::cout << "10th Catalan Number (Binomial Coefficient): " << catalanBinomial(number) << std::endl;
    return 0;
}
