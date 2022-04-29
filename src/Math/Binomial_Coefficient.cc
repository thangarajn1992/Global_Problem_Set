#include "Math.h"

/* 
    nCk = (n!) / ((n-k)! * k!)
    which will get converted to 
    nCk = (n * n-1 * n-2 ... n-k-1)/(1 * 2 * 3 ... * k)
*/
unsigned long int binomialCoefficient(unsigned int n, unsigned int k)
{
   unsigned long int binomialCoeff = 1;

    /* Because nCk = nCn-k */
   if(k > n-k)
   {
       k = n - k;
   }

   for(int i = 1; i <= k; i++)
   {
       binomialCoeff *= (n - i + 1);
       binomialCoeff /= (i);
   }

   return binomialCoeff;
}