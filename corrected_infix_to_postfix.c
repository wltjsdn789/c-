
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

// Stack operations
void push(Stack *stack, const char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = stack->top;
    stack->top = node;
}

char *getTop(Stack *stack) {
    if (stack->top == NULL) return NULL;
    return stack->top->data;
}

char *pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("스택 언더플로우\n");
        return NULL;
    }
    Node *node = stack->top;
    char *data = (char *)malloc(strlen(node->data) + 1);
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(const char *op) {
    if (strcmp(op, "(") == 0) return 0;
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    return 3;
}

// Convert infix to postfix
void transition(Stack *stack, char *tokens[], int size, char *output) {
    output[0] = '\0';
    for (int i = 0; i < size; i++) {
        if (isdigit(tokens[i][0])) {
            strcat(output, tokens[i]);
            strcat(output, " ");
        } else if (strcmp(tokens[i], "(") == 0) {
            push(stack, tokens[i]);
        } else if (strcmp(tokens[i], ")") == 0) {
            while (stack->top && strcmp(getTop(stack), "(") != 0) {
                char *op = pop(stack);
                strcat(output, op);
                strcat(output, " ");
                free(op);
            }
            pop(stack); // Remove '('
        } else {
            while (stack->top && getPriority(getTop(stack)) >= getPriority(tokens[i])) {
                char *op = pop(stack);
                strcat(output, op);
                strcat(output, " ");
                free(op);
            }
            push(stack, tokens[i]);
        }
    }

    while (stack->top) {
        char *op = pop(stack);
        strcat(output, op);
        strcat(output, " ");
        free(op);
    }
}

int main() {
    Stack stack = { NULL };
    char *input[] = {"(", "3", "+", "5", ")", "*", "2"};
    int size = sizeof(input) / sizeof(input[0]);
    char result[1000];
    transition(&stack, input, size, result);
    printf("후위 표기식: %s\n", result);
    return 0;
}
