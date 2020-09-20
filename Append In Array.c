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
	printf("\nThe elements present in Array are : ");
	int i;
	for(i=0;i<Arr.length;i++)
	printf("%d ",Arr.A[i]);
}

void Append(struct Array *Arr)
{
	int digit;
	if(Arr->length == Arr->size)
	 printf("Array Is Full\n");
	else
	 {
	 	printf("\nEnter the Element to be inserted : ");
	 	scanf("%d",&digit);
	 	Arr->A[Arr->length] = digit;
	 	Arr->length++;
	 }
}

int main()
{
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	displayArray(Arr);
	Append(&Arr);
	printf("\nElements in Array after appending : ");
	displayArray(Arr);
	
}
