#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

int recursiveBinaryS(struct Array Arr,int key,int low,int high)
{
	int mid;
	if(low<=high)
	{
	mid = floor((low+high)/2);
	if(Arr.A[mid] == key)
	 return mid;
	else if(Arr.A[mid] > key)
	 return recursiveBinaryS(Arr,key,low,mid-1);
	else
	return recursiveBinaryS(Arr,key,mid+1,high);
	}
    else
	return -1;
	 
}

int main()
{
	int x,element;
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	printf("Enter the element to search : ");
	scanf("%d",&element);
	x = recursiveBinaryS(Arr,element,0,Arr.length);
	if(x == -1)
	printf("Element Not Present ");
	else
	printf("Element is present at index %d",x);
	
	
}
