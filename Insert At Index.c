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

void insertatIndex(struct Array *Arr)
{
	int i,index,element;
	printf("\nEnter the index at which element is to be inserted : ");
	scanf("%d",&index);
	printf("Enter the element to be inserted : ");
	scanf("%d",&element);
	if(Arr->length == Arr->size)
	 printf("\nArray is Full. Insertion not possible\n");
	else
	{
	for(i=Arr->length;i>index;i--)
	{
		Arr->A[i] = Arr->A[i-1];
	}
	Arr->A[index] = element;
	Arr->length++;
	}
}

int main()
{
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	displayArray(Arr);
	insertatIndex(&Arr);
	displayArray(Arr);
}
