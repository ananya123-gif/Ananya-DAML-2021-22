/*****************PROGRAM FOR HEAP SORT******************/
/*****AUTHOR- ANANYA SHUKLA,ADMISSION NO.2019B101169*****/
/********************************************************/
#include<stdio.h>
/********************************************************/
void heapify(int A[],int N,int i)
{
    int t,l=i;
    int j=2*i+1;
    int k=2*i+2;
    if (j<N && A[j]>A[l])
        l=j;
    if(k<N && A[k]>A[l])
        l=k;
    if(l!=i)
    {
        t=A[i];
        A[i]=A[l];
        A[l]=t;
        heapify(A,N,l);
    }
}
/********************************************************/
void heapsort(int A[],int N)
{
    int i,t;
    for(i=N/2-1;i>=0;i--)
        heapify(A,N,i);
    for(i=N-1;i>=0;i--)
    {
        t=A[0];
        A[0]=A[i];
        A[i]=t;
        heapify(A,i,0);
    }
}
/********************************************************/
void main()
{
    int i,A[100];
    int N;
    printf("Enter the number of elements in an array : ");
    scanf("%d",&N);
    printf("Enter elements of an array : ");
    for (i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Given Array is :");
    for(i=0;i<N;i++)
        printf("%d ",A[i]);
    heapsort(A,N);
    printf("\nSorted Array is :");
    for(i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
}
/********************************************************/
