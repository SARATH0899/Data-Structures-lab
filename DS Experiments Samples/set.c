#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

// Function to perform union operation on two sets
void set_union(int set1[], int set2[], int union_set[], int n, int m)
{
    int i, j, k;
    i = j = k = 0;

    while (i < n && j < m)
    {
        if (set1[i] < set2[j])
            union_set[k++] = set1[i++];
        else if (set2[j] < set1[i])
            union_set[k++] = set2[j++];
        else
        {
            union_set[k++] = set1[i++];
            j++;
        }
    }

    while (i < n)
        union_set[k++] = set1[i++];

    while (j < m)
        union_set[k++] = set2[j++];
}

// Function to perform intersection operation on two sets
void set_intersection(int set1[], int set2[], int intersection_set[], int n, int m)
{
    int i, j, k;
    i = j = k = 0;

    while (i < n && j < m)
    {
        if (set1[i] < set2[j])
            i++;
        else if (set2[j] < set1[i])
            j++;
        else
        {
            intersection_set[k++] = set1[i++];
            j++;
        }
    }
}

int main()
{
    int set1[MAX_ELEMENTS], set2[MAX_ELEMENTS];
    int n, m;

    printf("Enter the number of elements in set 1: ");
    scanf("%d", &n);

    printf("Enter the elements of set 1: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set1[i]);

    printf("Enter the number of elements in set 2: ");
    scanf("%d", &m);

    printf("Enter the elements of set 2: \n");
    for (int i = 0; i < m; i++)
        scanf("%d", &set2[i]);

    int union_set[n + m];
    set_union(set1, set2, union_set, n, m);

    printf("\nThe union of the two sets is: \n");
    for (int i = 0; i < n + m; i++)
    {
        if (union_set[i] > 0)
            printf("%d ", union_set[i]);
    }

    int intersection_set[n + m];
    set_intersection(set1, set2, intersection_set, n, m);

    printf("\n\nThe intersection of the two sets is: \n");
    for (int i = 0; i < n + m; i)
        if (intersection_set[i] > 0)
            printf("%d ", intersection_set[i]);
    }

    printf("\n");

    return 0;
}
