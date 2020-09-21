#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int *A;
	int size;
	int length;
};

void createArray(struct Array *Arr)
{
	printf("Enter the size of Array : ");
	int x;
	scanf("%d",&x);
	Arr->size = x;
    Arr->A = (int *)malloc(x*sizeof(int));
    printf("Array is Created\n");
    Arr->length = 0;
}

void insertElements(struct Array *Arr)
{
	int num;
	printf("Enter the number of elements to insert : ");
	scanf("%d",&num);
	int i,value;
	printf("Enter the elements : ");
	for(i=0;i<num;i++)
	{
		scanf("%d",&value);
		Arr->A[i] = value;
		Arr->length++;
	}
}

void displayArray(struct Array Arr)
{
	printf("The elements present in Array are : ");
	int i;
	for(i=0;i<Arr.length;i++)
	printf("%d ",Arr.A[i]);
}

void rearrangeArray(struct Array *Arr)
{
	int i,j,temp;
	i = 0;
	j = Arr->length-1;
	
	while(i<j)
	{
	while(Arr->A[i] <0)
	 i++;
	while(Arr->A[j] >= 0)
	 j--;
	 
	if(i<j)
	{
		temp = Arr->A[j];
		Arr->A[j] = Arr->A[i];
		Arr->A[i] = temp;
	}
	}
}
int main()
{
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	rearrangeArray(&Arr);
	displayArray(Arr);
}
