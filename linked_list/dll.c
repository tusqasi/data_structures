#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
  struct node *prev;
} Node;

typedef struct ll {
  Node *root;
  int size;
  Node *last;
} LL;

void traverseLinkedList(LL *ll) {
  int n = ll->size;
  Node *ptr = ll->root;
  while (n--) {
    ptr = ptr->next;
    printf("Value: %d\n", ptr->val);
  }
}

void reverseTraverseLinkedList(LL *ll) {
  int n = ll->size;
  Node *ptr = ll->last;
  while (n--) {
    ptr = ptr->prev;
    printf("Value: %d\n", ptr->val);
  }
}

void addNode(LL *ll, int val) {
  Node *ptr = ll->root;
  int n = ll->size;
  while (n--) {
    ptr = ptr->next;
  }
  Node *newNode = (Node *)malloc(sizeof(Node *));
  newNode->val = val;
  newNode->next = NULL;
  newNode->prev = ptr;
  ptr->next = newNode;
  ll->size++;
}

void removeNode(LL *ll, int val) {
  Node *ptr = ll->root;
  while (1) {
    if (ptr->next == NULL) {
      printf("End reached '%d' not found\n", val);
      return;
    } else if (ptr->next->val == val) {
      printf("Found val: %d\nRemoving it\n", ptr->next->val);
      break;
    } else {
      ptr = ptr->next;
    }
  }
  Node *tmp = ptr->next;
  ptr->next = ptr->next->next;
  free(tmp);
  ll->size--;
  return;
}

LL *makeLL() {
  LL *ll = (LL *)malloc(sizeof(LL *));
  if (!ll)
    fprintf(stderr, "Memory allocation failed in function: '%s'!\n", __func__);
  Node *root = malloc(sizeof(Node *));
  if (!root)
    fprintf(stderr, "Memory allocation failed!\n");
  root->next = NULL;
  root->prev = NULL;
  ll->root = root;
  ll->size = 0;
  return ll;
}
bool insertLL(LL *ll, int val, int insert) {
  Node *ptr = ll->root;
  while (1) {
    if (ptr->next == NULL) {
      printf("Not found '%d'\n", val);
      return false;
    } else if (ptr->val == val) {
      Node *newNode = malloc(1 * sizeof(Node));

      if (!newNode)
        fprintf(stderr, "Memory allocation failed!\n");

      newNode->next = ptr->next;
      newNode->val = insert;
      ptr->next = newNode;
      ll->size++;
      return true;
    } else {
      ptr = ptr->next;
    }
  }
}
void switchForward(Node *ptr) {

  Node *now = ptr;
  Node *nextNode = ptr->next;
  Node *nextNextNode = ptr->next->next;
  nextNode->next = ptr->next->next->next;
  nextNextNode->next = nextNode;
  now->next = nextNextNode;
}

void sortLL(LL *ll) {
  Node *ptr = ll->root;
  int n = ll->size;
  while (n--) {
    if (ptr->next->next->next == NULL) {
      printf("Reached End\n");
      return;
    } else if (ptr->val > ptr->next->val) {
      printf("Switching:  %d > %d\n", ptr->val, ptr->next->val);
      switchForward(ptr);
    }
    ptr = ptr->next;
  }
  return;
}

void test() {
  LL *ll = makeLL();
  for (int i = 0; i < 10; i++) {
    addNode(ll, 10 - i);
  }
  // traverseLinkedList(ll);
  printf("Sorted %s\n", __func__);
  sortLL(ll);
  // traverseLinkedList(ll);
}
