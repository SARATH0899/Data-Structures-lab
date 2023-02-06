#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;
  if (head != NULL)
    head->prev = newNode;
  head = newNode;
}

void insert_at_end(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    newNode->prev = NULL;
    head = newNode;
    return;
  }
  struct node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newNode;
  newNode->prev = temp;
}

void insert_at_location(int data, int position) {
  int i;
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  if (position == 1) {
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL)
      head->prev = newNode;
    head = newNode;
    return;
  }
  struct node *temp = head;
  for (i = 1; i < position - 1 && temp != NULL; i++)
    temp = temp->next;
  if (temp == NULL) {
    printf("Position not found\n");
    return;
  }
  newNode->next = temp->next;
  newNode->prev = temp;
  if (temp->next != NULL)
    temp->next->prev = newNode;
  temp->next = newNode;
}

void delete_at_beginning() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  struct node *temp = head;
  head = head->next;
  if (head != NULL)
    head->prev = NULL;
  free(temp);
}

void delete_at_end() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }
  struct node *temp = head;
  while (temp->next->next != NULL)
    temp = temp->next;
  free(temp->next);
  temp->next = NULL;
}

void delete_at_location(int position) {
int i;
if (head == NULL) {
printf("List is empty\n");
return;
}
if (position == 1) {
struct node *temp = head;
head = head->next;
if (head != NULL)
head->prev = NULL;
free(temp);
return;
}
struct node *temp = head;
for (i = 1; i < position - 1 && temp != NULL; i++)
temp = temp->next;
if (temp == NULL || temp->next == NULL) {
printf("Position not found\n");
return;
}
struct node *temp2 = temp->next;
temp->next = temp2->next;
if (temp2->next != NULL)
temp2->next->prev = temp;
free(temp2);
}

void search(int data) {
int position = 1;
struct node *temp = head;
while (temp != NULL) {
if (temp->data == data) {
printf("Data found at position %d\n", position);
return;
}
temp = temp->next;
position++;
}
printf("Data not found in the list\n");
}

void display() {
struct node *temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

int main() {
int choice, data, position;
while (1) {
printf("******MENU*****\n");
printf("1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert at specific location\n");
printf("4. Delete at beginning\n");
printf("5. Delete at end\n");
printf("6. Delete at specific location\n");
printf("7. Search\n");
printf("8. Display\n");
printf("9. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the data: ");
scanf("%d", &data);
insert_at_beginning(data);
printf("SUCCESSFULLY INSERTED !!\n");
break;
case 2:
printf("Enter the data: ");
scanf("%d", &data);
insert_at_end(data);
printf("SUCCESSFULLY INSERTED !!\n");
break;
case 3:
printf("Enter the data: ");
scanf("%d", &data);
printf("Enter the position: ");
scanf("%d", &position);
insert_at_location(data, position);
printf("SUCCESSFULLY INSERTED !!\n");
break;
case 4:
delete_at_beginning();
printf("SUCCESSFULLY DELETED !!\n");
break;
case 5:
delete_at_end();
printf("SUCCESSFULLY DELETED !!\n");
break;
case 6:
printf("Enter the position: ");
scanf("%d", &position);
delete_at_location(position);
printf("SUCCESSFULLY DELETED !!\n");
break;
case 7:
printf("Enter the data: ");
scanf("%d", &data);
search(data);
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf("Invalid choice\n");
break;
}
}
return 0;
}
