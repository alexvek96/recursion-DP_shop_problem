/* This is the dynamic programming method of function shop() */
#include "shop_init.h"
#define COSTS 2
int shop(int m, int n, int *k, int **c){
    int i,j, a[n][m+1], w, rem, t, s, flag, x, b[n];
    for (i=0; i<n; i++){
        for (j=0; j<m+1; j++){
            a[i][j] = 0;                            // initializing the boolean matrix
        }
    }
    for (i=0; i<n; i++){                            // for every product
        for (w=0; w<*(k+i); w++){                   // for every model of each product
            if (i>0){                               // for all lines under the first line
                for (t=0; t<m+1; t++){         
                    if (a[i-1][t] == 1){            // searching previous row for the ones '1'
                        for (s=0; s<*(k+i); s++){   // for every '1' that we find, we calculate the next possible amounts of remaining money
                            rem = t - *(*(c+i)+s);
                            if (rem>=0){
                                a[i][rem] = 1;      // implementing the description of the problem
                            }
                        }   
                    }
                }
            }
            else{
                rem = m - *(*(c+i)+w);              // calculating remaining money for the first line
            }
            if (rem>=0){
                a[i][rem] = 1;                      // implementing the description of the problem
            }
        }
    }
    flag = 0;
    for (w=0; w<m+1; w++){
        if (a[n-1][w] == 1){                        // searching for the first '1' in last line of the matrix
            rem = w;
            flag = 1;
            break;
        }
    }
    if (flag == 1){                         // it means we found an optimal path of costs
        x = rem;                            // 'rem' is the least possible amount of remaining money after buying n-products, so store it in 'x'
        for (i=n-1; i>0; i--){              // for each product from the last to the first...
            for (j=0; j<*(k+i); j++){
                t = x + *(*(c+i)+j);        // check the cost of all its models and calculate every possible previous remaining amount of money
                                            // because:     (current remaining money = previus remaining money + cost of last product bought)
                for (s=0; s<m+1; s++){
                    if (a[i-1][s]==1 && t==s){      // searching the row of the previous (above) product for ones '1'
                        x = s;                      // if we find an '1' and the index 's' (=possible remining money) equals the remaining money 't' we created
                                                    // it means we found a "step" from the n-remaining amount to the (n-1)-remaining amount
                        b[i] = *(*(c+i)+j);         // the step is *(*(c+i)+j) so store it in a matrix
                        break;                      // no need to search further for this product
                    }
                }
                if (s<m+1){break;}                  // it means we don't need to search further for this product, else continue searching, returning to the s-loop
            }
        }
        b[0] = m - x;               // first cost = starting money - first remaining money
        #ifdef COSTS
            printf("Item costs: ");
            for (i=0; i<n; i++){                //  !!!!!!!!! BONUS part !!!!!!!!
                printf("%d ", b[i]);
            }
        #endif
        printf("\n");
        return m - rem;}                   // returning maximum amount we can spend for the n-products
    else{return -1;}                       // returning -1 if no solution was found, hence if no '1' exists in the last row                                 
}                                              