#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int sz,i=0,element;
    printf("Enter the length of sets: ");
    scanf("%d",&sz);
    int st[sz],st1[sz], st2[sz];
    printf("Enter the elements of first set(in binary):\n");
    for(i=0;i<sz;i++)
    {
        scanf("%d",&element);
        if(element<0 || element>1)
        {
            printf("Bit vector implementation requires binary inputs");
        }
        else
        {
            st1[i]=element;
        }
    }
    printf("Enter the elements of second set(in binary):\n");
    for(i=0;i<sz;i++)
    {
        scanf("%d",&element);
        if(element<0 || element>1)
        {
            printf("Bit vector implementation requires binary inputs");
        }
        else
        {
            st2[i]=element;
        }
    }
    printf("Union of the two sets :\n");
    for(i=0;i<sz;i++)
    {
        if((st1[i] || st2[i])==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\nIntersection of two sets :\n");
     for(i=0;i<sz;i++)
    {
        if((st1[i] && st2[i])==1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\nDifference of the two sets :\n");
    for(i=0;i<sz;i++)
    {
        st[i]=!(st2[i]);
        st2[i]=st1[i] || st[i];
        printf("%d",st2[i]);
    }
}
