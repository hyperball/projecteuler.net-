/*----------------------------------------------------------------------------*
*		
*If we list all the natural numbers below 10 that are multiples of 3 or 5, we 
*get 3, 5, 6 and 9. The sum of these multiples is 23.
*
*Find the sum of all the multiples of 3 or 5 below 1000.
*-----------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>

struct mono_node{
	int val;
	struct mono_node *ptr_next;
}mono_node;

struct mono_node *GetTargetValues(int n);
int Sum(struct mono_node *p);

int main(int argv, char **argc)
{
	int limit = 0;
	int sum_value = 0;
	struct mono_node *ptr_list;
	ptr_list = (struct mono_node *)malloc(sizeof(struct mono_node));
	printf("Enter a Upper Limit Value\n");
	scanf("%d", &limit);
	
	ptr_list = GetTargetValues(limit);
	sum_value = Sum(ptr_list);	
	printf("TARGET SUM = %d\n", sum_value);
	return 0;
}



struct mono_node *GetTargetValues(int n)
{
	int i;
	struct mono_node *p1, *p2;

	struct mono_node *ptr_head;
	p1 = p2 = (struct mono_node *)malloc(sizeof(mono_node));
	ptr_head = NULL;

	for(i=3; i<n+1; i++){
		if((0==i%3)||(0==i%5)){
			if(i==3){
				p1->val = i;
				ptr_head = p1;
			}
			else{ 
				p2->ptr_next = p1;
				p2 = p1;
				p1 = (struct mono_node *)malloc(sizeof(mono_node));
				p1->val = i;
			}

		}
	}
	p2->ptr_next = NULL;
	return ptr_head;
}

int Sum(struct mono_node *p_head)
{
	int sum_value = 0;
	while(NULL != p_head){
		sum_value = sum_value + p_head->val;
		p_head = p_head->ptr_next;
	}
	return sum_value;
}
