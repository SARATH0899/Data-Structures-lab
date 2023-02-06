#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert_at_beginning(int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void insert_at_end(int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
    return;
  }
  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insert_at_position(int data, int position) {
  if (position == 1) {
    insert_at_beginning(data);
    return;
  }
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  struct node *temp = head;
  for (int i = 0; i < position - 2; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_at_beginning() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  struct node *temp = head;
  head = head->next;
  free(temp);
}

void delete_at_end() {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (head->next == NULL) {
    free(head);
    head = NULL;
    return;
  }
  struct node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void delete_at_position(int position) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  if (position == 1) {
    delete_at_beginning();
    return;
  }
  struct node *temp = head;
  for (int i = 0; i < position - 2; i++) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    printf("Position is out of range.\n");
    return;
  }
  struct node *to_delete = temp->next;
  temp->next =to_delete->next;
free(to_delete);
}

int search(int data) {
int position = 1;
struct node *temp = head;
while (temp != NULL) {
if (temp->data == data) {
return position;
}
position++;
temp = temp->next;
}
return -1;
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
printf("*****MENU******\n");
printf("Enter your choice:\n");
printf("1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert at position\n");
printf("4. Delete at beginning\n");
printf("5. Delete at end\n");
printf("6. Delete at position\n");
printf("7. Search\n");
printf("8. Display\n");
printf("9. Exit\n");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter the data to be inserted: ");
scanf("%d", &data);
insert_at_beginning(data);
printf("SUCCESSFULLY PUSHED !!\n");
break;
case 2:
printf("Enter the data to be inserted: ");
scanf("%d", &data);
insert_at_end(data);
printf("SUCCESSFULLY PUSHED !!\n");
break;
case 3:
printf("Enter the data to be inserted: ");
scanf("%d", &data);
printf("Enter the position: ");
scanf("%d", &position);
insert_at_position(data, position);
printf("SUCCESSFULLY PUSHED !!\n");
break;
case 4:
delete_at_beginning();
printf("SUCCESSFULLY POPED !!\n");
break;
case 5:
delete_at_end();
printf("SUCCESSFULLY POPED !!\n");
break;
case 6:
printf("Enter the position: ");
scanf("%d", &position);
delete_at_position(position);
printf("SUCCESSFULLY POPED !!\n");
break;
case 7:
printf("Enter the data to be searched: ");
scanf("%d", &data);
int result = search(data);
if (result == -1) {
printf("Data not found in the list.\n");
} else {
printf("Data found at position %d\n", result);
}
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf("Invalid choice.\n");
}
}
return 0;
}
