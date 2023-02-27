#include <stdio.h>
#include <stdlib.h>
#include <alloca.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include "rbtree.h"
// #include <linux/rbtree_augmented.h>
// #include <linux/export.h>


#define ZEPHYR_INCLUDE_SYS_RB_H_

struct node{
  int key;
  struct node * left;
  struct node * right;
};

void insertNode(struct node *  head, int newKey);
struct node * getLeftMostNode(struct node * head);
struct node * getRightMostNode(struct node * head);
int successor(struct node * root);
int predecessor(struct node * root);
struct node * removeNode(struct node * head, int key);
struct node * treeSearch(struct node * head, int key);
void inOrderTraversal(struct node * head);

int main(void) {
  // printf("Hello World\n");
  struct node * head = NULL;
  head = malloc(sizeof(struct node));
  head->key = 7;
  head->left = NULL;
  head->right = NULL;
  insertNode(head, 5);
  insertNode(head, 11);
  insertNode(head, 1);
  insertNode(head, 9);
  insertNode(head, 0);
  // printf("%d\n", head->key);
  // printf("%d\n", head->left->key);
  inOrderTraversal(head);
  printf("\n");
  struct node * search = treeSearch(head, 0);
  if(search != NULL){
    printf("%d key was found\n", search->key);
  }
  if(search == NULL){
    printf("Key not found\n");
  }
  head = removeNode(head, 7);
  inOrderTraversal(head);
  printf("\n\n-------------------------------------------------------\n\n");
  printf("Assignment 5 tests\n");
  // TREE1 STUFF HERE
  printf("\n\nTree 1\n");
  struct node * tree1 = NULL;
  tree1 = malloc(sizeof(struct node));
  tree1->key = 1;
  tree1->left = NULL;
  tree1->right = NULL;
  insertNode(tree1, 2);
  insertNode(tree1, 3);
  insertNode(tree1, 4);
  insertNode(tree1, 5);
  insertNode(tree1, 6);
  insertNode(tree1, 7);
  insertNode(tree1, 8);
  insertNode(tree1, 9);
  insertNode(tree1, 10);
  insertNode(tree1, 11);
  insertNode(tree1, 12);
  insertNode(tree1, 13);
  insertNode(tree1, 14);
  insertNode(tree1, 15);
  inOrderTraversal(tree1);
  //
  // GET TIME
  clock_t begin = clock();
  for(int i = 0; i < 100000; i++){
    treeSearch(tree1, 1);
  }
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime taken for search(1) is %lf\n\n", time_spent);\
  begin = clock();
  for(int i = 0; i < 100000; i++){
    treeSearch(tree1, 15);
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime taken for search(15) is %lf\n\n", time_spent);
  // END OF TIME
  //
  removeNode(tree1, 5);
  printf("\n");
  inOrderTraversal(tree1);
  // TREE2 STUFF HERE
  printf("\n\nTree 2\n");
  struct node * tree2 = NULL;
  tree2 = malloc(sizeof(struct node));
  tree2->key = 8;
  tree2->left = NULL;
  tree2->right = NULL;
  insertNode(tree2, 4);
  insertNode(tree2, 12);
  insertNode(tree2, 2);
  insertNode(tree2, 6);
  insertNode(tree2, 10);
  insertNode(tree2, 14);
  insertNode(tree2, 1);
  insertNode(tree2, 3);
  insertNode(tree2, 5);
  insertNode(tree2, 7);
  insertNode(tree2, 9);
  insertNode(tree2, 11);
  insertNode(tree2, 13);
  insertNode(tree2, 15);
  inOrderTraversal(tree2);
  //
  // GET TIME
  begin = clock();
  for(int i = 0; i < 100000; i++){
    treeSearch(tree2, 1);
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime taken for search(1) is %lf\n\n", time_spent);\
  begin = clock();
  for(int i = 0; i < 100000; i++){
    treeSearch(tree2, 15);
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("\ntime taken for search(15) is %lf\n\n", time_spent);
  // END OF TIME
  //
  removeNode(tree2, 8);
  insertNode(tree2, 2);
  printf("\n");
  inOrderTraversal(tree2);
  printf("\n\n-------------------------------------------------------\n\n");
  printf("Red Black Tree API\n");
  // https://docs.zephyrproject.org/latest/doxygen/html/rb_8h_source.html
  /*struct rbtree * tree = malloc(sizeof(struct rbtree));
  struct rbnode * node = malloc(sizeof(struct rbnode));
  rb_visit_t 	visit_fn;
  void * 	cookie;
  // rb_insert(tree, node);
  // rb_walk(tree, visit_fn, cookie);
  return 0;*/
  /*int n = 0;
  struct rbnode* root = NULL;
  printf("enter size of array\n");
  scanf("%d", &n);
  int * array = malloc(sizeof(int) * (n));
  while(n < 0){
    printf("invalid input, please try again\n");
    scanf("%d", &n);
  }
  for(int i = 0; i < n; i++){
    array[i] = rand() % 10;
    printf("%d\n", array[i]);
  }
  printf("array filled\n");
  for (int i = 0; i < n; i++) {
    struct rbnode* temp = malloc(sizeof(struct rbnode));
    temp->r = NULL;
    temp->l = NULL;
    temp->p = NULL;
    temp->d = array[i];
    temp->c = 1;
    // calling function that performs bst insertion of
    // this newly created node
    printf("insert\n");
    root = bst(root, temp);
    // calling function to preserve properties of rb
    // tree
    printf("fixup\n");
    fixup(root, temp);
    // printf("%d\n", temp->d);
    inorder(root);
  }
  printf("loop done\n");
  inorder(root);*/
  int n = 7;
  int a[7] = { 7, 6, 5, 4, 3, 2, 1 };
  // int a[7] = {1, 2, 3, 4, 5, 6, 7};
  // int a[7] = {2, 2, 7, 2, 2, 3, 1};
 
    for (int i = 0; i < n; i++) {
 
        // allocating memory to the node and initializing:
        // 1. color as red
        // 2. parent, left and right pointers as NULL
        // 3. data as i-th value in the array
        struct rbnode* temp = (struct rbnode*)malloc(sizeof(struct rbnode));
        if(temp == NULL){
          printf("error: memory allocation failed\n");
        }
        temp->r = NULL;
        temp->l = NULL;
        temp->p = NULL;
        temp->d = a[i];
        temp->c = 1;
 
        // calling function that performs bst insertion of
        // this newly created node
        root = bst(root, temp);
 
        // calling function to preserve properties of rb
        // tree
        fixup(root, temp);
    }
 
    printf("Inorder Traversal of Created Tree\n");
    inorder(root);
 
    return 0;
}

/*void insertNode(struct node *  head, int newKey){
  if(head == NULL){
    head = malloc(sizeof(struct node));
    head->key = newKey;
    head->left = NULL;
    head->right = NULL;
    printf("%d\n", head->key);
    return;
  }
  if(newKey < head->key){
    insertNode(head->left, newKey);
  } else if(newKey > head->key){
    insertNode(head->right, newKey);
  }
  return;
}*/

void insertNode(struct node *  head, int newKey){
  if(head == NULL){
    printf("Unintialized pointer\n");
    return;
  }
  if(newKey <= head->key && head->left != NULL){
    insertNode(head->left, newKey);
  } else if(newKey > head->key && head->right != NULL){
    insertNode(head->right, newKey);
  } else if(newKey <= head->key && head->left == NULL){
    head->left = malloc(sizeof(struct node));
    if(head->left == NULL){
      printf("memory allocation failed\n");
      return;
    }
    head->left->key = newKey;
    head->left->left = NULL;
    head->left->right = NULL;
    printf("%d\n", head->left->key);
    return;
  } else if(newKey > head->key && head->right == NULL){
    head->right = malloc(sizeof(struct node));
    if(head->right == NULL){
      printf("memory allocation failed\n");
      return;
    }
    head->right->key = newKey;
    head->right->left = NULL;
    head->right->right = NULL;
    printf("%d\n", head->right->key);
    return;
  }
  return;
}

struct node * getLeftMostNode(struct node * head){
  if(head == NULL){
    return NULL;
  }
  if(head->left == NULL){
    return head;
  }
  if(head->left != NULL){
    return getLeftMostNode(head->right);
  }
  return NULL;
}

struct node * getRightMostNode(struct node * head){
  if(head == NULL){
    return NULL;
  }
  if(head->right == NULL){
    return head;
  }
  if(head->right != NULL){
    return getRightMostNode(head->right);
  }
  return NULL;
}

/*void removeNode(struct node * head, int key){
  struct node * nodeRemoved = treeSearch(head, key);
  if(key == head->key){}
  if(nodeRemoved->left != NULL && nodeRemoved->right != NULL){
    printf("internal node, 2 child\n");
  } else if(nodeRemoved->left != NULL){
    printf("internal node, left child\n");
    struct node * right = getRightMostNode(nodeRemoved->left);
    struct node ** remove = &nodeRemoved;
    nodeRemoved = right;
    free(remove);
    remove = NULL;
  } else if(nodeRemoved->right != NULL){
    printf("internal node, right child\n");
    struct node * left = getLeftMostNode(nodeRemoved->right);
    struct node ** remove = &nodeRemoved;
    nodeRemoved = left;
    free(remove);
    remove = NULL;
  } else {
    printf("external node\n");
    free(nodeRemoved);
    nodeRemoved = NULL;
  }
}*/

int successor(struct node * root) {
  root = root -> right;
  while (root -> left != NULL) root = root -> left;
  return root -> key;
}
int predecessor(struct node * root) {
  root = root -> left;
  while (root -> right != NULL) root = root -> right;
  return root -> key;
}

struct node * removeNode(struct node * head, int key){
  if (head == NULL) return NULL;
  if (key > head->key){
    head -> right = removeNode(head -> right, key);
  } else if (key < head->key){
    head->left = removeNode(head -> left, key);
  } 
  else {
    if (head -> left == NULL && head -> right == NULL){
      head = NULL;
    } 
    else if (head -> right != NULL) {
      head->key = successor(head);
      head->right = removeNode(head -> right, head->key);
    } else {
      head->key = predecessor(head);
      head -> left = removeNode(head -> left, head->key);
    }
  }
  return head;
}


struct node * treeSearch(struct node * head, int key){
  if(head == NULL){
    printf("Unintialized pointer\n");
    return NULL;
  }
  if(head->key == key){
    return head;
  } else if(key < head->key){
    if(head->left != NULL){
      return treeSearch(head->left, key);
    } else {
      return NULL;
    }
  }
  else if(key > head->key){
    if(head->right != NULL){
      return treeSearch(head->right, key);
    } else {
      return NULL;
    }
  }
}

void inOrderTraversal(struct node * head){
  if(head == NULL){
    return;
  }
  if(head->left != NULL){
    inOrderTraversal(head->left);
  }
  printf("%d ", head->key);
  if(head->right != NULL){
    inOrderTraversal(head->right);
  }
}