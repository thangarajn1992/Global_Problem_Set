#include "Math.h"

/* Catalan number using Recursive Formula */
unsigned long int catalanNumberRecursive(unsigned int n)
{
    if(n <= 1)
        return 1;
    
    unsigned long int result = 0;

    for(unsigned int i = 0; i < n; i++)
        result += catalanNumberRecursive(i) * catalanNumberRecursive(n-i-1);

    return result;
}

/* Catalan Number using Dynamic Programming */
unsigned long int catalanNumberDP(unsigned int n)
{
    unsigned long int catalan[n+1];

    catalan[0] = catalan[1] = 1;

    for(unsigned int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for(unsigned int j = 0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i-j-1]);
        }
    }
    return catalan[n];
}

/* Catalan Number using Binomial Coefficient */
unsigned long int catalanBinomial(unsigned int n)
{
    /* Catalan Number = (2nCn)/(n+1) */
    //std::cout << binomialCoefficient(2*n, n) << std::endl;
    return binomialCoefficient(2*n, n)/(n+1);
}
