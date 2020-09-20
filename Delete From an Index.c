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

int deleteElement(struct Array *Arr)
{
	int index,i,x;
	printf("\nEnter the index at which deletion is to be performed : ");
	scanf("%d",&index);
	
	if(index >= 0 && index <= Arr->length-1)
	{
		x = Arr->A[index];
		for(i=index;i<Arr->length;i++)
		{
			Arr->A[i] = Arr->A[i+1];
		}
		Arr->length--;
		return x;
	}
	else
	printf("Deletion not possible. Index is larger than length");
}

int main()
{
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	displayArray(Arr);
	printf("The Deleted element is %d\n",deleteElement(&Arr));
	displayArray(Arr);
}
