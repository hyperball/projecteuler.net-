/*
Each new term in the Fibonacci sequence is generated by adding the 
previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not
exceed four million, find the sum of the even-valued terms.
*/

#include<stdio.h>
#include<malloc.h>
#define LIM 4000000
struct fi_node{
	int val;
	struct fi_node *pnext;
}fi_node;

struct fi_node *GetFibonacciNumber();
int Sum(struct fi_node *ptr_head);

int main(int argc, char **argv)
{
	Sum(GetFibonacciNumber());
	return 0;
}

int IsEven(int figure)
{
	if(0==(figure%2))
		return 1;
	else
		return 0;
}

struct fi_node *GetFibonacciNumber()
{
	int an_2 = 1;
	int an_1 = 2;
	int an = 0;
	struct fi_node *ptr_head;
	struct fi_node *p1, *p2;
	p1 = p2 = (struct fi_node *)malloc(sizeof(fi_node));

	while(an < LIM){
		an = an_1 + an_2;
		an_2 = an_1;
		an_1 = an;
		if(3==an){
				p1->val = 2;
				ptr_head = p1;
				}
		else{
				p2->pnext = p1;
				p2 = p1;
				if(1==IsEven(an)){
					p1 = (struct fi_node *)malloc(sizeof(fi_node));
					p1->val = an;
				}
			}
		}
	p2->pnext = NULL;
	return ptr_head;
}

int Sum(struct fi_node *ptr_head)
{
	int sum = 0;
	while(NULL != ptr_head){
		sum = sum + ptr_head->val;
		ptr_head = ptr_head->pnext;
	}
	printf("Sum = %d\n", sum);
	return sum;
}
