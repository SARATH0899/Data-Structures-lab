#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert_beginning(int x) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = head;
  head = temp;
}

void insert_end(int x) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    return;
  }
  struct node *ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = temp;
}

void insert_at_pos(int x, int pos) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = NULL;
  if (pos == 1) {
    temp->next = head;
    head = temp;
    return;
  }
  struct node *ptr = head;
  for (int i = 0; i < pos - 2; i++) {
    ptr = ptr->next;
  }
  temp->next = ptr->next;
  ptr->next = temp;
}

void delete_beginning() {
  struct node *temp = head;
  head = head->next;
  free(temp);
}

void delete_end() {
  struct node *ptr = head;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  struct node *temp = ptr->next;
  ptr->next = NULL;
  free(temp);
}

void delete_at_pos(int pos) {
  if (pos == 1) {
    struct node *temp = head;
    head = head->next;
    free(temp);
    return;
  }
  struct node *ptr = head;
  for (int i = 0; i < pos - 2; i++) {
    ptr = ptr->next;
  }
  struct node *temp = ptr->next;
  ptr->next = temp->next;
  free(temp);
}

void linear_search(int x) {
  struct node *ptr = head;
  int pos = 1;
  while (ptr != NULL) {
    if (ptr->data == x) {
      printf("Element found at position %d\n", pos);
      return;
    }
    ptr = ptr->next;
    pos++;
  }
  printf("Element not found\n");
}

void display() {
  struct node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main() {
  int choice, x, pos;
  while (1)
