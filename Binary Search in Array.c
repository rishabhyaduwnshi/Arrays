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

int binarySearch(struct Array Arr)
{
	int low,high,key,mid;
	printf("Enter the element to be searched : ");
	scanf("%d",&key);
	
	low = 0;
	high = Arr.length;
	
	while(low<=high)
	{
		mid = floor((low+high)/2);
		if(Arr.A[mid] == key)
		 return mid;
		else if(Arr.A[mid] > key)
		 high = mid-1;
		else
		 low = mid+1;
	}
	return -1;
}

int main()
{
	int x;
	struct Array Arr;
	createArray(&Arr);
	insertElements(&Arr);
	
	x = binarySearch(Arr);
	if(x == -1)
	printf("Element Not Present ");
	else
	printf("Element is present at index %d",x);
	
	
}
