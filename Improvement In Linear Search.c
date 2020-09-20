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

int linearSearch(struct Array *Arr)
{
	int i,element,x,temp;
	printf("Enter the element to be searched : ");
	scanf("%d",&element);
	
	for(i=0;i<Arr->length;i++)
	{
		if(element == Arr->A[i])
		 {
		 	if(i!=0)
		 	{
		 	temp = Arr->A[i-1];
		 	Arr->A[i-1] = Arr->A[i];
		 	Arr->A[i] = temp;
		 	}
		 	return i;
		 }
	}
	return -1;
	
}

int main()
{
	int x;
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	x = linearSearch(&Arr);
	if(x == -1)
	printf("Element Not Present ");
	else
	printf("Element is present at index %d\n",x);
	
	printf("Element is brought One index closer to starting of Array in every succesful search operation.\nIf it is already present at first place then no change is done\n");
	
	displayArray(Arr);
}
