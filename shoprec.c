/* This is the recursive method of function shop() */
#include "shop_init.h"
int cost(int n, int *k, int **c, int rem, int *central){
    int s, i;
    if (n==0){                              // we have got out of the costs table
        if (rem>=0 && rem<*central){        // so we have found the remaining amount of money for this path of buying strategy
            *central = rem;                 // store this amount in '*central' if it is less than the existing
        }
    }
    else{
        for (i=0; i<(*(k+n-1)); i++){       // accessing every cell of each row of the costs table
            s = *(*(c+n-1)+i);              // 's' is the cost stored in the current cell
            if (rem<0){continue;}
            // if, sometime during our crossing of a path, we reach rem<0, then it's not the right path, we stop there and go for another path
            // to find the remaining money after buying the 'n' product, go and find the remaining money of 'n-1' product
            cost(n-1, k, c, rem-s, central);    
        }
    }
}
int shop(int m, int n, int *k, int **c){
    int rem, *central, optim_cost;          // 'central' points to a memory place where the minimum amount of remaining money ('rem') is stored
    central = malloc(sizeof(int));
    if (central == NULL){return -4;}
    rem = m;                                // starting value of 'rem' is the starting value of money 'm' we have to spend
    *central = m+1;                         // starting value of '*central' is such, so that the first comparison in line 6 above enters the 'if' statement
    cost(n, k, c, rem, central);
    optim_cost = m - *central;              // 'optim_cost' is the largest amount of money we can spend in order to buy all 'n' products
    return optim_cost;
}