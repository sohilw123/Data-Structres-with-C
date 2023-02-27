#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
  int value;
  struct node *next;
};

struct list{
  struct node *front;
};

void printArray(int array[], int size);
void insertionSort(int array[], int size);
int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high);
void reverseArray(int array[], int start, int end);
void printList(struct node * head);
void mergeSort(struct node** headRef);
struct node* mergeList(struct node* a, struct node* b);
void splitList(struct node* source, struct node** frontRef, struct node** backRef);

int main(void) {
  // TEST CASE 1
  int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int size = 10;
  // TEST CASE 2
  // int array[] = {110, 235, 32, 67998, 2, 9, 645, 76, 10};
  // int size = 9;
  // TEST CASE 3
  // int array[] = {0};
  // int size = 1;
  printArray(array, size);
  insertionSort(array, size);
  // quickSort(array, 0, 9);
  printArray(array, size);
  reverseArray(array, 0, 9);
  printArray(array, size);
  printf("\n\n");
  struct node * node1 = malloc(sizeof(struct node));
  struct node * node2 = malloc(sizeof(struct node));
  struct node * node3 = malloc(sizeof(struct node));
  struct node * node4 = malloc(sizeof(struct node));
  struct node * node5 = malloc(sizeof(struct node));
  struct node * node6 = malloc(sizeof(struct node));
  struct node * node7 = malloc(sizeof(struct node));
  struct node * node8 = malloc(sizeof(struct node));
  struct node * node9 = malloc(sizeof(struct node));
  struct node * node10 = malloc(sizeof(struct node));
  node1->value = 10;
  node1->next = node2;
  node2->value = 9;
  node2->next = node3;
  node3->value = 8;
  node3->next = node4;
  node4->value = 7;
  node4->next = node5;
  node5->value = 6;
  node5->next = node6;
  node6->value = 5;
  node6->next = node7;
  node7->value = 4;
  node7->next = node8;
  node8->value = 3;
  node8->next = node9;
  node9->value = 2;
  node9->next = node10;
  node10->value = 1;
  node10->next = NULL;
  printList(node1);
  mergeSort(&node1);
  printList(node1);
  printf("Hello World\n");
  return 0;
}

void printArray(int array[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size){
  for(int i = 0; i < size; i++){
    for(int j = i; j >= 1; j--){
      if(array[j-1] > array[j]){
        int temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      }
    }
  }
}

int partition(int array[], int startIndex, int endIndex) {
  // set rightmost element as pivot
  int pivot = array[endIndex];
  // pointer for greater element
  int i = (startIndex - 1);
  // traverse each element of the array then compare them with the pivot
  for (int j = startIndex; j < endIndex; j++) {
    // if element smaller than pivot is found swap with greater element
    if (array[j] <= pivot) {
      i++;
      int temp1 = array[i];
      array[i] = array[j];
      array[j] = temp1;
    }
  }
  // swap
  int temp2 = array[i+1];
  array[i+1] = array[endIndex];
  array[endIndex] = temp2;
  // return partition point
  return (i + 1);
}

void quickSort(int array[], int startIndex, int endIndex) {
  if (startIndex < endIndex) {
    // get pivot element
    int pivot = partition(array, startIndex, endIndex);
    // number smaller than pivot
    quickSort(array, startIndex, pivot - 1);
    // number greater than pivot
    quickSort(array, pivot + 1, endIndex);
  }
}

//BONUS
void reverseArray(int array[], int start, int end){
  if(start > end){
    return;
  }
  int temp = array[start];
  array[start] = array[end];
  array[end] = temp;
  reverseArray(array, start + 1, end - 1);
}

//queue
void enqeue (struct list * ls, int n){
  if(ls->front == NULL){
    ls->front = malloc(sizeof(struct node));
    if(ls->front == NULL){
      printf("Memory Allocation Failed\n");
    }
    ls->front->value = n;
    ls->front->next = NULL;
    return;
  }
  struct node *last = ls->front;
  while(last->next != NULL){
    last = last->next;
  }
  last->next = malloc(sizeof(struct node));
  if(last->next == NULL){
      printf("Memory Allocation Failed\n");
    }
  last->next->value = n;
  last->next->next = NULL;
}

void deqeueList (struct list * N){
  if(N == NULL){
    printf("node is empty\n");
    return;
  }
    if(N->front->next != NULL){
    struct node *remove = N->front;
    N->front = N->front->next;
    free(remove);
    remove = NULL;
  } else {
    struct node *temp = N->front;
    N->front = NULL;
    free(temp);
  }
  // printf("dequeued\n");
}

struct node * deqeue (struct node * N){
  if(N == NULL){
    printf("node is empty\n");
    return NULL;
  }
  if(N->next == NULL){
    struct node * freeN = N;
    free(freeN);
    return NULL;
  }
  if(N->next != NULL){
    struct node *remove = N;
    struct node * next = N->next;
    free(remove);
    return next;
    // remove = NULL;
  } else {
    struct node *temp = N;
    N = NULL;
    free(temp);
    return NULL;
  }
  // printf("dequeued\n");
}

void printList(struct node * head){
  struct node * ptr = head;
  while(ptr != NULL){
    printf("%d ", ptr->value);
    ptr = ptr->next;
  }
  printf("\n");
}

//MERGE SORT

void mergeSort(struct node** headRef){
  struct node* head = *headRef;
  struct node* a;
  struct node* b;
  // base case, pointing to NULL
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }
  // split list in half
  splitList(head, &a, &b);
  // sort sublists
  mergeSort(&a);
  mergeSort(&b);
  // merge the sorted lists
  *headRef = mergeList(a, b);
}
 
struct node* mergeList(struct node* a, struct node* b){
    struct node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->value <= b->value) {
        result = a;
        result->next = mergeList(a->next, b);
    }
    else {
        result = b;
        result->next = mergeList(a, b->next);
    }
    return (result);
}

void splitList(struct node* source, struct node** frontRef, struct node** backRef){
  // first sublist (before middle)
  struct node* a;
  // second sublist (after middle)
  struct node* b;
  b = source;
  a = source->next;
  while (a != NULL) {
    a = a->next;
    if (a != NULL) {
      b = b->next;
      a = a->next;
    }
  }
  // a is before the midpoint in the list, so split it in two at that point.
  *frontRef = source;
  *backRef = b->next;
  b->next = NULL;
}