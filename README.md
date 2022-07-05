This is a project of 1st/8 semester in NKUA IT Department (Sep 2020 - Feb 2021).
Some introductive info:

1)	We have a certain amount of money available, say M, and we want to buy with
	it N products. For each product i (1 ≤ i ≤ N), there are K[i] available model choices, which
	each costs C[i,j] (1 ≤ j ≤ Ki, Cij > 0). For example, let's say we have 500 euros available
	and we want to buy a computer, a printer and an external drive, spending
	as much money as we can. Suppose that for the computer we have three options, an HP,
	a Dell and an Asus. For the printer we have two options, an Epson and a Lexmark,
	while for the external disk we have four options, a Seagate, a Samsung, a Maxtor
	and a Toshiba. For every possible model of the products we may buy, we know
	its cost. What is the maximum amount we can spend, naturally at most M, to
	buy ONE model for EACH of the N products? For example:
	
	M=20 N=3
	K[1]=3 C[1,1]=8 C[1,2]=5 C[1,3]=9
	K[2]=2 C[2,1]=11 C[2,2]=4
	K[3]=4 C[3,1]=9 C[3,2]=5 C[3,3]=10 C[3,4]=3
	
	For the example above, one solution is to buy the models that cost C[1,2] = 5,
	C[2,1] = 11 and C[3,4] = 3, where the total cost is 19. Notice that there is no combination
	of models giving a total cost of 20, so that we spend all the amount we have available.
	A solution with the same total cost as the previous one is the 5-4-10 combination.

	
Objectives:

1) Implement a separate .c file (shop.c) which initializes the "shop" environment.
2) Implement 2 methods to solve the problem: (a) recursively, (b) iteratively with dynamic programming (DP).
3) In the DP case, find the model costs that we have to buy in order to maximize our money M value
   (i.e. find the solution structure).
   
4) In code, main() is to be called with command line argument M and read from standard input the value N,
   the number K[1] of models for the first product, then the costs C[1,1], C[1,2],.., C[1,K1] of these models.
   After that, the number K[2] of the models for the second product, the costs C[2,1], C[2,2],.., C[2,K2] of
   these models, and so on, up to the last product K[N]. Example:
   
    $ ./shoprec 20
	3
	3 8 5 9
	2 11 4
	4 9 5 10 3
	Maximum amount spent is: 19
	$

5) We can even set a .txt file as input to the code. Ths .txt file is, somehow, the price catalog of all products.
   For example:
   
    $ cat shop.txt
	10
	3 511 839 646
	8 284 552 694 690 883 474 724 46
	6 295 599 434 570 28 682
	5 757 408 106 22 529
	5 964 877 41 620 431
	7 458 428 286 93 979 331 782
	5 804 858 906 378 152
	8 163 722 883 845 750 639 252 207
	4 132 51 975 360
	3 946 790 345
	$
	
	$ ./shoprec 3000 < shop.txt
	Maximum amount spent is: 3000
	$
   
   
   
   
   
   
   
   