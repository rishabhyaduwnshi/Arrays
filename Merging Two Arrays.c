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
   // printf("Array is Created\n");
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
	int i;
	for(i=0;i<Arr.length;i++)
	printf("%d ",Arr.A[i]);
}

void mergeArrays(struct Array Arr1,struct Array Arr2)
{
	int i=0,j=0,k=0,size;
	size = Arr1.length+Arr2.length;
	int *thirdarray;
	thirdarray = (int*)malloc(size*sizeof(int));
	
	while(i<Arr1.length && j<Arr2.length)
	{
		if(Arr1.A[i] < Arr2.A[j])
		thirdarray[k++] = Arr1.A[i++];
		else
		thirdarray[k++] = Arr2.A[j++];
	}
	
	for(;i<Arr1.length;i++)
	 thirdarray[k++] = Arr1.A[i++];
	 
	for(;j<Arr2.length;i++)
	 thirdarray[k++] = Arr2.A[j++];
	 
	 printf("\nMerged Array is : ");
	 
	 for(k=0;k<size;k++)
	  printf("%d ",thirdarray[k]);
	 
	
}

int main()
{
	struct Array Arr1,Arr2;
	printf("For First Array\n");
	createArray(&Arr1);
	insertElements(&Arr1);
	printf("For Second Array\n");
	createArray(&Arr2);
	insertElements(&Arr2);
	printf("Elements of First Array Are : ");
	displayArray(Arr1);
	printf("\nElements of Second Array Are : ");
	displayArray(Arr2);
	
	mergeArrays(Arr1,Arr2);
	
}
