/*  ERGASIA 3 - shop.c  */
/*  Vekris Alexandros - AM 1115202000021  */
/*  This is the main file   */
#include "shop_init.h"
int shop(int m, int n, int *k, int **c);
int main(int argc, char *argv[]){
    int m, n, i, j, *k, **c, *t, num_of_models, optim_cost;
    // 'm' is the starting money, 'n' is the number of products to be bought
    // 'k' stores the memory address of the matrix containing the number K of different models of each product
    m = atoi(argv[1]);              
    scanf("%d", &n);                    //reading number 'n' of products we want to buy
    k = malloc(n * sizeof(int));        //allocating memory to store the number of models of each product in a K matrix
    if (k==NULL){return -1;}
    c = malloc(n * sizeof(int *));
    if (c==NULL){return -2;}                              
    for (i=0 ; i<=n-1 ; i++){           //allocating matrix lines in memory for the costs of the models of each product 
        scanf("%d", k+i);               // reading number of models for each product
        num_of_models = *(k+i);
        *(c+i) = malloc(num_of_models * sizeof(int));
        if (*(c+i)==NULL){return -3;}                   //allocated memory to store the costs of all the models of each product in a dynamically created matrix
        t = NULL;                                       //initializing pointer 't'
        for (j=0 ; j<=num_of_models-1 ; j++){
            t = *(c+i)+j;                       // 't' points to every cell of the costs table serially
            scanf("%d", t);                     // reading the costs for each one of the models of a product (we are initialising the costs table)
        }
    }
    optim_cost = shop(m, n, k, c);
    if (optim_cost == -1)
        printf("No solution found");
    else
        printf("Maximum amount spent: %d", optim_cost);
    printf("\n");
    return 0;
}