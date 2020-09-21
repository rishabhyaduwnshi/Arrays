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

void insertatSortedPosition(struct Array *Arr)
{
	int i,x;
	
	if(Arr->length < Arr->size)
	{
		printf("Enter the element to insert : ");
		scanf("%d",&x);
		i = Arr->length-1;
		while(Arr->A[i] > x)
		{
			Arr->A[i+1] = Arr->A[i];
			i--;
		}
		Arr->A[i+1] = x;
		Arr->length++;
	}
	else
	 printf("Array is Full. Insertion not Possible\n");
}

int main()
{
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	insertatSortedPosition(&Arr);
	displayArray(Arr);
}
