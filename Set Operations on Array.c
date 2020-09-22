#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int *A;
	int size;
	int length;
};

void createArray(struct Array *Arr,int x)
{
	Arr->size = x;
    Arr->A = (int *)malloc(x*sizeof(int));
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


int searchInArray(struct Array Arr,int x)
{
	int i;
	for(i=0;i<Arr.length;i++)
	{
		if(Arr.A[i] == x)
		 return 1;
	}
	return -1;
}
void setUnion(struct Array Arr1,struct Array Arr2)
{
	int i,j,k=0,s3,rval;
	s3 = Arr1.length+Arr2.length;
	struct Array unionArray;
	createArray(&unionArray,s3);
	
	for(i=0;i<Arr1.length;i++)
	{
		unionArray.A[k] = Arr1.A[i];
		k++;
		unionArray.length++;
	}
	
	for(j=0;j<Arr2.length;j++)
	{
		rval = searchInArray(Arr1,Arr2.A[j]);
		if(rval == -1)
		{
			unionArray.A[k]=Arr2.A[j];
			k++;
			unionArray.length++;
		}
		
	}
	displayArray(unionArray);
}



void intersectionArray(struct Array Arr1,struct Array Arr2)
{
	int i,j,k=0,s3,rval;
	s3 = Arr1.length+Arr2.length;
	struct Array intArray;
	createArray(&intArray,s3);
	
	for(j=0;j<Arr2.length;j++)
	{
		rval = searchInArray(Arr1,Arr2.A[j]);
		if(rval == 1)
		{
			intArray.A[k]=Arr2.A[j];
			k++;
			intArray.length++;
		}
		
	}
	
	displayArray(intArray);
}

void setDiffrence(struct Array Arr1,struct Array Arr2)
{
	int i,j,k=0,s3,rval;
	s3 = Arr1.length+Arr2.length;
	struct Array diffArray;
	createArray(&diffArray,s3);
	
	
	for(i=0;i<Arr1.length;i++)
	{
		rval = searchInArray(Arr2,Arr1.A[i]);
		if(rval == -1)
		{
			diffArray.A[k]=Arr1.A[i];
			k++;
			diffArray.length++;
		}
		
	}
	displayArray(diffArray);
	
}



int main()
{
	int s1,s2;
	struct Array Arr1,Arr2;
	
	printf("Enter the size of first Array : ");
	scanf("%d",&s1);
	createArray(&Arr1,s1);
	
	insertElements(&Arr1);
	
	printf("Enter the size of second Array : ");
	scanf("%d",&s2);
	createArray(&Arr2,s2);
	insertElements(&Arr2);
	
	printf("\n");
	
	printf("The Union of Array is : ");
	setUnion(Arr1,Arr2);
	printf("\n\n");
	
	printf("The Intersection of Array is : ");
	intersectionArray(Arr1,Arr2);
	printf("\n\n");
	
	printf("The Set Diffrence is : ");
	setDiffrence(Arr1,Arr2);

	
}
