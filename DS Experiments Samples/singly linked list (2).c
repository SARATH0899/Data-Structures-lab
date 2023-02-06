#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeg(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

void insertAtPos(struct Node** head, int pos, int data)
{
    if (*head == NULL || pos == 0)
    {
        insertAtBeg(head, data);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    int i;
    for (i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Position not found\n");
        return;
    }
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeg(struct Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtEnd(struct Node** head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node *last = *head, *prev;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

void deleteAtPos(struct Node** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos == 0)
    {
        deleteAtBeg(head);
        return;
    }
    struct Node *temp = *head, *prev;
    int i;
    for (i = 0; i < pos && temp != NULL; i++)
{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct Node* head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data, pos;
    while (1)
    {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBeg(&head, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insertAtPos(&head, pos, data);
            break;
        case 4:
            deleteAtBeg(&head);
            break;
        case 5:
            deleteAtEnd(&head);
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deleteAtPos(&head, pos);
            break;
        case 7:
            display(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
