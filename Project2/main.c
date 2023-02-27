#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list * newList();
void addFirst(struct list * ls, char *value);
void removeFirst(struct list *ls);
void addLast(struct list * ls, char *value);
void removeLast(struct list * ls);
struct node * getFirst(struct list * ls);
struct node * getLast(struct list * ls);
int size(struct list * ls);
void showElements(struct node * ls);
bool balance_brackets(char string[], struct list *ls, int len, int * size);
void enqeue (struct list * ls, int n);
void deqeueList (struct list * N);
struct node * deqeue (struct node * N);
struct node * front(struct list * ls);
bool isEmpty(struct list * ls);
void showElementsReverse(struct node * ls);
void showElementsNum(struct node * ls);
struct node* mergeSort(struct node* A, struct node* B);
struct node* sortedList(struct node* A, struct node* B);

struct node{
  char *value;
  int valueInt;
  struct node *next;
};

struct list{
  struct node *front;
};

int main(void) {
  printf("Linked List Operations\n");
  struct node *node5 = malloc(sizeof(struct node));
  struct node *node4 = malloc(sizeof(struct node));
  struct node *node3 = malloc(sizeof(struct node));
  struct node *node2 = malloc(sizeof(struct node));
  struct node *node1 = malloc(sizeof(struct node));
  struct list *wrapper = malloc(sizeof(struct list));
  wrapper->front = node1;
  char str1[] = "node1";
  node1->value = str1;
  node1->next = node2;
  char str2[] = "node2";
  node2->value = str2;
  node2->next = node3;
  char str3[] = "node3";
  node3->value = str3;
  node3->next = node4;
  char str4[] = "node4";
  node4->value = str4;
  node4->next = node5;
  char str5[] = "node5";
  node5->value = str5;
  node5->next = NULL;
  showElements(node1);
  struct node *  firstnode = getFirst(wrapper);
  //printf("%s\n",firstnode->value);
  printf("----------------\n");
  removeLast(wrapper);
  showElements(node1);
  removeFirst(wrapper);
  if(node1==NULL){
    printf("----------------\n");
    showElements(node2);
  } else {
    printf("error has occured\n");
    struct node *frontNode = getFirst(wrapper);
    showElements(frontNode);
    //printf("-------error has occured-------\n");
    struct node *lastNode = getLast(wrapper);
    showElements(lastNode);
  }
  printf("----------------\n");
  char string1[] = "string1";
  addLast(wrapper, string1);
  struct node *ptrToFront = getFirst(wrapper);
  // printf("%s" ptrToFront->value);
  /*showElements(ptrToFront);
  printf("----------------\n");
  char string2[] = "string2";
  addFirst(wrapper, string2);
  ptrToFront = getFirst(wrapper);
  showElements(ptrToFront);
  printf("size is %d\n", size(wrapper));
  printf("---------------------------------------------\n");*/
  struct list * empty1 = malloc(sizeof(struct list));
  int * size1 = NULL;
  bool check1 = balance_brackets("(9*[3*{[(3+3)/5]*7}])", empty1, 0, size1);
  if(check1 == 1){
    printf("test1 passed\n");
  }
  struct list * empty2 = malloc(sizeof(struct list));
  int * size2 = NULL;
  bool check2 = balance_brackets("{3*(2+[3-[4/[6/9]]]})", empty2, 0, size2);
  if(check2 == 0){
    printf("test2 passed\n");
  }
  struct list * empty3 = malloc(sizeof(struct list));
  int * size3 = NULL;
  bool check3 = balance_brackets("((3*(9-(4*(6-5))))", empty3, 0, size3);
  if(check3 == 0){
    printf("test3 passed\n");
  }
  struct list * empty4 = malloc(sizeof(struct list));
  int * size4 = NULL;
  bool check4 = balance_brackets("{2-{3*{6/[[[(((9-0)))]]]}}/7}", empty4, 0, size4);
  // bool check4 = balance_brackets("(}", empty4, 0, size4);
  if(check4 == 1){
    printf("test4 passed\n");
  } else {
    printf("test4 failed\n");
  }
  printf("---------------------------------------------\n");
  /*qeue operations
  printf("Queue Operations\n");
  struct list * queue = malloc(sizeof(struct list));
  queue->front = NULL;
  enqeue(queue, 5);
  enqeue(queue, 7);
  showElementsNum(queue->front);
  // printf("queue: %d\n", queue->front->valueInt);
  deqeueList(queue);
  deqeueList(queue);
  bool check = isEmpty(queue);
  if(check == true){
    printf("queue is empty\n");
  }
  enqeue(queue, 11);
  struct node * frontQueue = front(queue);
  printf("queue: %d\n", frontQueue->valueInt);
  printf("---------------------------------------------\n");
  struct list * S1 = malloc(sizeof(struct list));
  //list A
  struct node *nodeA15 = malloc(sizeof(struct node));
  struct node *nodeA14 = malloc(sizeof(struct node));
  struct node *nodeA13 = malloc(sizeof(struct node));
  struct node *nodeA12 = malloc(sizeof(struct node));
  struct node *nodeA11 = malloc(sizeof(struct node));
  struct list * A1 = malloc(sizeof(struct list));
  A1->front = nodeA11;
  nodeA11->valueInt = 1;
  nodeA11->next = nodeA12;
  nodeA12->valueInt = 2;
  nodeA12->next = nodeA13;
  nodeA13->valueInt = 3;
  nodeA13->next = nodeA14;
  nodeA14->valueInt = 7;
  nodeA14->next = nodeA15;
  nodeA15->valueInt = 9;
  nodeA15->next = NULL;
  // list B
  struct node *nodeB25 = malloc(sizeof(struct node));
  struct node *nodeB24 = malloc(sizeof(struct node));
  struct node *nodeB23 = malloc(sizeof(struct node));
  struct node *nodeB22 = malloc(sizeof(struct node));
  struct node *nodeB21 = malloc(sizeof(struct node));
  struct list * B1 = malloc(sizeof(struct list));
  B1->front = nodeB21;
  nodeB21->valueInt = 2;
  nodeB21->next = nodeB22;
  nodeB22->valueInt = 3;
  nodeB22->next = nodeB23;
  nodeB23->valueInt = 6;
  nodeB23->next = nodeB24;
  nodeB24->valueInt = 15;
  nodeB24->next = nodeB25;
  nodeB25->valueInt = 20;
  nodeB25->next = NULL;
  printf("start test\n");
  //
  S1->front = malloc(sizeof(struct node));
  struct node ** head = &S1->front;
  struct node *sortedList = mergeSort(nodeA11, nodeB21);
  // showElementsNum(sortedList);
  printf("All test passed succesfully\n");*/
  return 0;
}

struct list * newList(){
  struct list *new = malloc(sizeof(struct list));
  if(new == NULL){
    printf("Memory Allocation Failed\n");
  }
  new->front->next = NULL;
  return new;
}

void addFirst(struct list * ls, char *value){
  if(ls->front != NULL){
    struct node *nodeNext = ls->front;
    ls->front = malloc(sizeof(struct node));
    if(ls->front == NULL){
      printf("Memory Allocation Failed\n");
    }
    ls->front->value = value;
    ls->front->next = nodeNext;
  } else {
    printf("empty\n");
    ls->front = malloc(sizeof(struct node));
    if(ls->front == NULL){
      printf("Memory Allocation Failed\n");
    }
    ls->front->next = NULL;
    ls->front->value = value;
  }
}

void removeFirst(struct list *ls){
  if(ls->front == NULL){
    printf("list is empty\n");
    return;
  }
  if(ls->front->next != NULL){
    struct node *remove = ls->front;
    ls->front = ls->front->next;
    free(remove);
    remove = NULL;
  } else {
    struct node *temp = ls->front;
    ls->front = NULL;
    free(temp);
  }
}

// push
void addLast(struct list * ls, char *value){
  if(ls->front == NULL){
    ls->front = malloc(sizeof(struct node));
    if(ls->front == NULL){
      printf("Memory Allocation Failed\n");
    }
    ls->front->value = value;
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
  last->next->value = value;
  last->next->next = NULL;
}

// pop
void removeLast(struct list * ls){
  struct node *remove = ls->front;
  if(ls->front == NULL){
    printf("list is empty\n");
    return;
  }
  while(remove->next->next != NULL){
    remove = remove ->next;
  }
  remove->next = NULL;
  free(remove->next);
}

struct node * getFirst(struct list * ls){
  return(ls->front);
}

struct node * getLast(struct list * ls){
  struct node *last = ls->front;
  if(ls->front == NULL){
    return NULL;
  }
  while(last->next != NULL){
    last = last->next;
  }
  return last;
}

int size(struct list * ls){
  struct node *n = ls->front;
  int size = 1;
  while(n != NULL){
    n = n->next;
    printf("size is %d\t", size);
    size++;
  }
  printf("\n");
  return size;
}

void showElements(struct node * ls){
  if(ls == NULL){
    return;
  }
  struct node *current = ls;
  if(current != NULL){
    printf("%s\n", current->value);
  }
  if(current->next != NULL){
    showElements(ls->next);
  }
}

bool balance_brackets(char string[], struct list *ls, int len, int * size){
  // get length of string
  int index = 0;
  int length = 0;
  while(string[index] != '\0'){
    length ++;
    index ++;
  }
  int sizeList = 0;
  printf("length: %d\n", length);
  // if len is 0 return true
  if(length == 0){
    return true;
  }
  // use a for loop to check brackets
  int listLength = 0;
  for(int i = 0; i<length; i++){
    // printf("list length: %d\n", listLength);
    if(string[i] == '(' || string[i] == '[' || string[i] == '{'){
      sizeList++;
      //push
      // printf("%c\n", string[i]);
      char *letter = malloc(length);
      if(letter == NULL){
        printf("Memory Allocation Failed\n");
      }
      // ADD MEMORY CHECK HERE
      letter[0] = string[i];
      // printf("add First\n");
      addFirst(ls, letter);
      // printf("added First\n");
      listLength++;
    } else if(string[i] == ')' || string[i] == ']' || string[i] == '}') {
      sizeList--;
      if(listLength == 0){
        return false;
      }
      //pop
      switch(string[i]) {
        case ')':
          printf(")\n");
          if (ls->front == NULL){
            return false;
          }
          if (ls->front->value[0] == '(') {
            printf("pass1\n");
            removeFirst(ls);
            listLength--;
            break;
          } else {
              printf("fail1\n");
              return false;
          }
        case ']':
          printf("]\n");
          if (ls->front == NULL){
            return false;
          }
          if (ls->front->value[0] == '[') {
            printf("pass2\n");
            removeFirst(ls);
            listLength--;
            break;
          } else {
            printf("fail2\n");
            return false;
          }
        case '}':
          printf("}\n");
          if (ls->front == NULL){
            return false;
          }
          if (ls->front->value[0] == '{') {
            printf("pass3\n");
            removeFirst(ls);
            listLength--;
            break;
          } else {
            printf("fail3\n");
            return false;
          }
      }
    } else if(string[i] < 48 || string [i] > 57) {
      if(string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/'){
        printf("invalid %s\n", ls->front->value);
        return false;
      }
    }
  }
  if(sizeList != 0){
    printf("not empty\n");
    return false;
  }
  return true;
}

// queue stuff
void enqeue (struct list * ls, int n){
  if(ls->front == NULL){
    ls->front = malloc(sizeof(struct node));
    if(ls->front == NULL){
      printf("Memory Allocation Failed\n");
    }
    ls->front->valueInt = n;
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
  last->next->valueInt = n;
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

struct node * front(struct list * ls){
  if(ls->front != NULL){
    return ls->front;
  } else {
    printf("list is empty\n");
    return NULL;
  }
}

bool isEmpty(struct list * ls){
  if(ls->front == NULL){
    printf("empty\n");
    return true;
  } else {
    printf("not empty\n");
    return false;
  }
}

void showElementsReverse(struct node * ls){
  struct node *current = ls;
  if(current->next != NULL){
    showElements(ls->next);
  }
  if(current != NULL){
    printf("%s\n", current->value);
  }
}

struct node* mergeSort(struct node* a, struct node* b){
  struct node * list = sortedList(a, b);
  showElementsNum(list);
  return list;
}

struct node* sortedList(struct node* A, struct node* B) {
  struct node* result = NULL;
  // Base case
  // A is empty
  if (A == NULL){
    return (B);
  }
  // B is empty
  else if (B == NULL){
    return (A);
  }
  // take from list A if value is smaller
  if (A->valueInt <= B->valueInt) {
    result = A;
    result->next = sortedList(A->next, B);
  } else {
    // take from list B if value is smaller
    result = B;
    result->next = sortedList(A, B->next);
  }
  return (result);
}

void showElementsNum(struct node * ls){
  if(ls == NULL){
    return;
  }
  struct node *current = ls;
  if(current != NULL){
    printf("%d\n", current->valueInt);
  }
  if(current->next != NULL){
    showElementsNum(ls->next);
  }
}