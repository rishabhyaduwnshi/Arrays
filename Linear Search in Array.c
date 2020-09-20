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

int linearSearch(struct Array Arr)
{
	int i,element;
	printf("Enter the element to be searched : ");
	scanf("%d",&element);
	
	for(i=0;i<Arr.length;i++)
	{
		if(element == Arr.A[i])
		 return i;
	}
	return 0;
	
}

int main()
{
	int x;
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	x = linearSearch(Arr);
	if(x == 0)
	printf("Element Not Present ");
	else
	printf("Element is present at index %d",x);
}
