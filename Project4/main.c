#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int heapMin(int array[], int * size);
int heapIsEmpty(int array[], int * size);
void printArray(int array[], int * size);
int * heapInsert(int array[], int * size, int key);
int * removeMin(int array[], int * size);
int get_root(int array[], int * size, int index);
int get_left(int array[], int * size, int index);
int get_right(int array[], int * size, int index);
// int *  heapSort(int array[], int * size, int index);
int * inPlaceHeapSort(int array[], int * size);
// void heapify(int array[], int * size, int index);
void swap(int* a, int* b);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void generateArray(int array[], int * size);
void minHeap(int arr[], int n);

int main(void) {
    struct timeval stop, start;
    int n = 10;
    // scanf("%d", &n);
    int * size = &n;
    int * array = malloc(sizeof(int) * *size);
    if(array == NULL){
      printf("memory allocation failed\n");
    }
    int * array2;
    /*
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 7;
    array[7] = 8;
    array[8] = 9;
    array[9] = 10;
    */
    /*
    array[0] = 10;
    array[1] = 9;
    array[2] = 8;
    array[3] = 7;
    array[4] = 6;
    array[5] = 5;
    array[6] = 4;
    array[7] = 3;
    array[8] = 2;
    array[9] = 1;
    */
    
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    array[5] = 6;
    array[6] = 7;
    array[7] = 8;
    array[8] = 9;
    array[9] = 10;
    
    /*
    array[0] = 1;
    array[1] = 3;
    array[2] = 5;
    array[3] = 7;
    array[4] = 9;
    array[5] = 10;
    array[6] = 8;
    array[7] = 6;
    array[8] = 4;
    array[9] = 2;
    */
    // generateArray(array, size);
    printArray(array, size);
    // array2 = heapSort(array, size, 1);
    // array2 = inPlaceHeapSort(array, size);
    // clock_t begin = clock();
    // gettimeofday(&start, NULL);
    // array = heapInsert(array, size, 11);
    // array = removeMin(array, size);
    // printf("size: %d\n", *size);
    heapSort(array, *size);
    // minHeap(array, *size);
    // clock_t end = clock();
    // gettimeofday(&stop, NULL);
    // double timeElapsed = (double)(end - begin) / CLOCKS_PER_SEC;
    printArray(array, size);
    // heapInsert();
    // double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    // printf("time taken %f\n",secs);
    // printf("elapsed time: %lf\n", timeElapsed);
    return 0;
}

void generateArray(int array[], int * size){
  for (int i = 0; i < *size;i++) {
    array[i] = i;
  }
}

int heapMin(int array[], int * size){
    if(size > 0){
        int min = 0;
        for(int i = 0; i < *size; i++){
            if(array[i] < array[min]){
                  min = i;
            }
        }
        return min;
    } else{
        printf("Array is empty\n");
        return -1;
    }

}

void minHeap(int arr[], int n){
    // build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int heapIsEmpty(int array[], int * size){
    if(*size == 0){
        // return 1 if true
        return 1;
    } else {
        // return 0 if false
        return 0;
    }
}

void printArray(int array[], int * size){
    // for loop to iterate through array then print
    for(int i = 0; i < *size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int * heapInsert(int array[], int * size, int key){
    // increase size of array
    *size += 1;
    // Insert new element at end of loop realloc is O(n)
    // printArray(array, size);
    array = realloc(array, sizeof(int) * *size);
    printArray(array, size);
    if(array == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    array[*size - 1] = key;
    printArray(array, size);
    return array;
    // sort array after
}

int * removeMin(int array[], int * size){
    // get last element and swap with root
    int last = heapMin(array, size);
    array[last] = array[*size - 1];
    *size -= 1;
    array = realloc(array, sizeof(int) * *size);
    if(array == NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    printArray(array, size);
    return array;
    // sort array after
}

int get_root(int array[], int * size, int index){
    return array[(index - 1) / 2];
}

int get_Left(int array[], int * size, int index){
    return array[2 * index + 1];
}

int get_right(int array[], int * size, int index){
    return array[2 * index + 2];
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// downheap
void heapify(int arr[], int N, int i)
{
    // get largest among root, left child and right child (first subtree)
    int largest = i;
    // left = 2*i + 1
    int left = 2 * i + 1;
    // right = 2*i + 2
    int right = 2 * i + 2;
    // left child is greater than current biggest number
    if (left < N && arr[left] > arr[largest])
        largest = left;
    // right child is greater than current biggest number
    if (right < N && arr[right] > arr[largest])
        largest = right;
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N){
    // max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        // Heapify root element to get highest element at root
        heapify(arr, i, 0);
    }
}