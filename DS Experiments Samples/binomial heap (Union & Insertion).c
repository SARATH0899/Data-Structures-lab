#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int key;
    int degree;
    struct node *sibling;
    struct node *child;
};

struct node *newNode(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->degree = 0;
    temp->sibling = temp->child = NULL;
    return temp;
}

struct node *mergeBinomialTrees(struct node *a, struct node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    struct node *result;
    if (a->degree <= b->degree)
    {
        result = a;
        result->sibling = mergeBinomialTrees(a->sibling, b);
    }
    else
    {
        result = b;
        result->sibling = mergeBinomialTrees(a, b->sibling);
    }
    return result;
}

struct node *unionBionomialHeap(struct node *head1, struct node *head2)
{
    struct node *head = mergeBinomialTrees(head1, head2);
    if (head == NULL)
        return head;
    struct node *prev = NULL, *curr = head, *next = curr->sibling;
    while (next != NULL)
    {
        if (curr->degree != next->degree || (next->sibling != NULL && next->sibling->degree == curr->degree))
        {
            prev = curr;
            curr = next;
        }
        else
        {
            if (curr->key <= next->key)
            {
                curr->sibling = next->sibling;
                next->sibling = curr->child;
                curr->child = next;
                curr->degree++;
            }
            else
            {
                if (prev == NULL)
                    head = next;
                else
                    prev->sibling = next;
                curr->sibling = next->child;
                next->child = curr;
                next->degree++;
                curr = next;
            }
        }
        next = curr->sibling;
    }
    return head;
}

void insert(struct node **head, int key)
{
    struct node *temp = newNode(key);
    *head = unionBionomialHeap(*head, temp);
}

void display(struct node *head)
{
    if (head == NULL)
        return;
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d(%d) ", temp->key, temp->degree);
        display(temp->child);
        temp = temp->sibling;
    }
}

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int choice, key;

    while (1)
    {
        printf("Implementation of Binomial heap\n");
        printf("1. Insert in first binomial heap\n");
        printf("2. Insert in second binomial heap\n");
        printf("3. Union of two binomial heaps\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            insert(&head1, key);
            break;
        case 2:
            printf("Enter the key to be inserted: ");
            scanf("%d", &key);
            insert(&head2, key);
            break;
        case 3:
            head1 = unionBionomialHeap(head1, head2);
            printf("Union of heaps is done\n");
            break;
        case 4:
            printf("Elements in the binomial heap are: ");
            display(head1);
            printf("\n");
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return 0;
}
