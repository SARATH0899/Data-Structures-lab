#include <stdio.h>
int main()
{
    int sz1,sz2,sz3,i,j,e,temp;
    printf("Merge two sorted arrays and store it in a third array\n\n");
    printf("Enter the size of first array:  ");
    scanf("%d",&sz1);
    int ar[sz1];
    printf("Enter the elements: \n\n");
    for(i=0;i<sz1;i++)
    {
        scanf("%d",&e);
        ar[i]=e;
    }
    printf("Elements in first array: \n\n");
    for(i=0;i<sz1;i++)
    {
        printf("%d ",ar[i]);
    }
    for(i=0;i<sz1;i++)
    {
        for(j=i+1;j<sz1;j++)
        {
            if(ar[i] > ar[j])
            {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
    printf("\nElements in first array after sorting: \n\n");
    for(i=0;i<sz1;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\nEnter the size of second array: ");
    scanf("%d",&sz2);
    int arr[sz2];
    printf("Enter the elements: \n\n");
    for(i=0;i<sz2;i++)
    {
        scanf("%d",&e);
        arr[i]=e;
    }
    printf("Elements in second array: \n\n");
    for(i=0;i<sz2;i++)
    {
        printf("%d ",arr[i]);
    }
    for(i=0;i<sz1;i++)
    {
        for(j=i+1;j<sz1;j++)
        {
            if(ar[i] > ar[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\nElements in second array after sorting: \n\n");
    for(i=0;i<sz1;i++)
    {
        printf("%d ",ar[i]);
    }
    sz3=sz1+sz2;
    int arry[sz3];
    for(i=0;i<sz1;i++)
    {
        arry[i]=ar[i];
    }
    for(i=0;i<sz2;i++)
    {
        arry[i+sz1]=arr[i];
    }
    printf("\nElements in third array after merging: \n\n");
    for(i=0;i<sz3;i++)
    {
        printf("%d ",arry[i]);
    }
    for(i=0;i<sz3;i++)
    {
        for(j=i+1;j<sz3;j++)
        {
            if(arry[i] > arry[j])
            {
                temp=arry[i];
                arry[i]=arry[j];
                arry[j]=temp;
            }
        }
    }
    printf("\nElements in third array after sorting: \n\n");
    for(i=0;i<sz3;i++)
    {
        printf("%d ",arry[i]);
    }
}
