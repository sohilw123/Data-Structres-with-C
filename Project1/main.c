#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(char * stack, char value, int * size);
void pop(char * stack, int * size);
void top(char * stack, int * size, char * top);
int size(char * stack);
bool isEmpty(char * stack, int * size);
bool balance_brackets(char string[], char * stack, int len, int * size);
bool language_recognizer(char str[0], char * stack, int len, int * size);
int string_length(char * str);
void assign_memory(char * stack, int len, int * size); // implement this

int main(void) {
    printf("Hello World\n");
    char a;
    //scanf("%c", &a);
    int * size_arr = NULL;
    int num = 0;
    size_arr = &num;
    char * stack = malloc(sizeof(char) * 10);
    stack[0] = '\0';
    push(stack, a, size_arr);
    push(stack, a, size_arr);
    printf("result1 is %c\n", stack[1]);
    int n = size(stack);
    printf("size is %d\n", n);
    pop(stack, size_arr);
    printf("result1 is %c\n", stack[1]);
    printf("result is %c\n", stack[0]);
    n = size(stack);
    printf("size is %d\n", n);
    pop(stack, size_arr);
    printf("----------------------------------------------------------\n");
    char str[] = "(9*[3*{[(3+3)/5]*7}])";
    //char str[] = "()){}[]";
    int * stack_len = NULL;
    int len = 0;
    stack_len = &len;
    bool check = balance_brackets(str, stack, 6, stack_len);
    printf("the check is %d\n", check);
    printf("----------------------------------------------------------\n");
    char str2[] = "01";
    bool check2 = language_recognizer(str2, stack, 6, size_arr);
    printf("the check is %d\n", check2);
    return 0;
}

void push(char * stack, char value, int * size){
    for(int i = 0; i<*size+1; i++){
        //printf("%iteration %d\n", i);
        if(stack[i]=='\0'){
            stack[i] = value;
            stack[i+1] = '\0';
            //printf("value is %c\n", value);
            //printf("result is %c\n", stack[0]);
            break;
        }
    }
    *size += 1;
}

void pop(char * stack, int * size){
    if(*size == 1){
        stack[0] = '\0';
        return;
    }
    for(int i = 0; i<*size+1; i++){
        if(stack[i]=='\0'){
            stack[i-1] = '\0';
            break;
        }
    }
    *size -= 1;
}

void top(char * stack, int * size, char * top){
    if(size == 1){
        *top = stack[0];
        return;
    }
    if(size==0){
        *top = '\0';
        return;
    }
    for(int i = 0; i<size + 1; i++){
        //printf("current: %c\n", *top);
        if(stack[i+1]=='\0'){
            *top = stack[i];
            // printf("top: %c\n", *top);
            printf("top: %c\n", stack[i]);
            break;
        }
    }
}

int size(char * stack){
    int i = 0;
    int size = 0;
    while(stack[i] != '\0'){
        size++;
        i++;
    }
    return size;
}

bool isEmpty(char * stack, int * size){
    bool empty = false;
    if(stack[0]=='\0'){
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}

bool balance_brackets(char string[], char * stack, int len, int * size){
    int i = 0;
    char * top_arr = NULL;
    char letter;
    top_arr = &letter;
    len = string_length(string);
    assign_memory(stack, len, size);
    if(stack == NULL){
      return false;
    }
    for(i = 0; i<len; i++){
        printf("loop start i: %d len: %d top %c\n", i, len, *top_arr);
        if(string[i] == '(' || string[i] == '[' || string[i] == '{'){
            printf("open\n");
            push(stack, string[i], size); // add value of opening bracket to stack
            top(stack, size, top_arr);
            printf("top: ( %c )\n", *top_arr);
            printf("stack: ( %s )\n", stack);
        } else if(string[i] == ')' || string[i] == ']' || string[i] == '}'){
            printf("close\n");
            switch(string[i]) {
                case ')':
                    printf(")\n");
                    if (*top_arr == '(') {
                        printf("pass1\n");
                        pop(stack, size);
                        top(stack, size, top_arr);
                        printf("top: ( %c )\n", *top_arr);
                        break;
                    } else {
                        printf("fail1\n");
                        return false;
                    }
                case ']':
                    printf("]\n");
                    if (*top_arr == '[') {
                        printf("pass2\n");
                        pop(stack, size);
                        top(stack, size, top_arr);
                        printf("top: ( %c )\n", *top_arr);
                        break;
                    } else {
                        printf("fail2\n");
                        return false;
                    }
                case '}':
                    if (*top_arr == '{') {
                        printf("pass3\n");
                        pop(stack, size);
                        top(stack, size, top_arr);
                        printf("top: ( %c )\n", *top_arr);
                        break;
                    } else {
                        printf("fail3\n");
                        return false;
                    }
            }
        } else if(string[i] < 48 || string [i] > 57){
            //if(47 < string[i] < 58)
            if(string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/'){
                printf("invalid\n");
                return false;
            }
        }
        printf("switch done\n");
        if(*size==0){
            return true;
        }
        printf("loop end i: %d len: %d\n", i, len);
    }
    if(isEmpty(stack, size)){
        return true;
    } else{
        return false;
    }
}

bool language_recognizer(char str[0], char * stack, int len, int * size){
    int midpoint;
    len = string_length(str);
    assign_memory(stack, len, size);
    if(stack == NULL){
      return false;
    }
    if(len % 2 != 0){
        printf("no - len\n");
        return false;
    }
    if(len % 2 == 0){
        midpoint = (len/2);
    }
    for(int i=0; i<midpoint; i++){
        if(str[i]!='0'){
            printf("no - 0\n");
            return false;
        }
        push(stack, str[i], size);
    }
    for(int i=midpoint; i<len; i++){
        if(str[i]!='1'){
            printf("no - 1\n");
            return false;
        }
        pop(stack, size);
    }
    if(isEmpty(stack, size)){
        printf("yes\n");
        return true;
    } else{
        printf("no - empty\n");
        return false;
    }
}

int string_length(char * str){
  int i = 0;
  int len = 0;
  while(str[i] != '\0'){
    i++;
    len++;
  }
  return len;
}

void assign_memory(char * stack, int len, int * size){
    // free(stack);
    realloc(stack, sizeof(char) * len);
    for(int i = 0; i<len; i++){
      stack[i] = '\0';
    }
  *size = 0;
}