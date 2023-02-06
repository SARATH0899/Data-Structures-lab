#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* head;

void insertAtBegin(int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->prev = NULL;
  new_node->next = head;
  head->prev = new_node;
  head = new_node;
}

void insertAtEnd(int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  struct Node* last = head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
  new_node->prev = last;
}

void insertAtPosition(int data, int pos) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  struct Node* current = head;
  int i;
  for (i = 0; i < pos - 1 && current != NULL; i++) {
    current = current->next;
  }
  new_node->next = current->next;
  new_node->prev = current;
  current->next = new_node;
}

void deleteAtBegin() {
  struct Node* temp = head;
  head = head->next;
  head->prev = NULL;
  free(temp);
}

void deleteAtEnd() {
  struct Node* last = head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->prev->next = NULL;
  free(last);
}

void deleteAtPosition(int pos) {
  struct Node* current = head;
  int i;
  for (i = 0; i < pos && current != NULL; i++) {
    current = current->next;
  }
  current->prev->next = current->next;
  current->next->prev = current->prev;
  free(current);
}

void search(int data) {
  struct Node* current = head;
  int found = 0;
  while (current != NULL) {
    if (current->data == data) {
      printf("Found\n");
      found = 1;
      break;
    }
    current = current->next;
  }
  if (!found) {
    printf("Not Found\n");
  }
}

void display() {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  int choice, data, pos;
  head = NULL;

  while (1) {
    printf("*****MENU*****\n");
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

    switch (choice) {
      case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        insertAtBegin(data);
        printf("SUCCESSFULLY INSERTED");
        break;
      case 2:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        insertAtEnd(data);
        printf("SUCCESSFULLY INSERTED");
        break;
      case 3:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        printf("Enter the position: ");
        scanf("%d", &pos);
        insertAtPosition(data, pos);
        printf("SUCCESSFULLY INSERTED");
        break;
      case 4:
        deleteAtBegin();
        printf("SUCCESSFULLY DELETED");
        break;
      case 5:
        deleteAtEnd();
        printf("SUCCESSFULLY DELETED");
        break;
      case 6:
        printf("Enter the position: ");
        scanf("%d", &pos);
        deleteAtPosition(pos);
        printf("SUCCESSFULLY DELETED");
        break;
      case 7:
        printf("Enter the data to be searched: ");
        scanf("%d", &data);
        search(data);
        break;
      case 8:
        display();
        break;
      case 9:
        exit(0);
      default:
        printf("Invalid choice\n");
        break;
    }
  }
  return 0;
}
