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

int isSorted(struct Array Arr)
{
	int i;
	for(i=0;i<Arr.length-1;i++)
	{
		if(Arr.A[i] > Arr.A[i+1])
		return -1;
	}
	return 1;
}
int main()
{
	int x;
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	x = isSorted(Arr);
	if(x == -1)
	 printf("Array not Sorted ");
	else if(x == 1)
	 printf("Array Sorted ");
	
}
