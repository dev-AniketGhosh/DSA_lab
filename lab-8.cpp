//implementation of stack and queue using linked list.

//#include <stdio.h>
//#include <stdlib.h>
//struct Node {
//    int data;
//    struct Node* next;
//};
//struct Stack {
//    struct Node* top;
//};
//struct Stack* createStack() {
//    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
//    S->top = NULL;
//    return S;
//}
//void push(struct Stack* S, int value) {
//    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
//    if (!temp) {
//        printf("Heap overflow! Cannot push.\n");
//        return;
//    }
//    temp->data = value;
//    temp->next = S->top;
//    S->top = temp;
//    printf("%d pushed to stack.\n", value);
//}
//int pop(struct Stack* S) {
//    if (S->top == NULL) {
//        printf("Stack underflow! Cannot pop.\n");
//        return -1;
//    }
//    struct Node* temp = S->top;
//    int value = temp->data;
//    S->top = S->top->next;
//    free(temp);
//    return value;
//}
//int peek(struct Stack* S) {
//    if (S->top == NULL) {
//        printf("Stack is empty.\n");
//        return -1;
//    }
//    return S->top->data;
//}
//void display(struct Stack* S) {
//    struct Node* temp = S->top;
//    if (temp == NULL) {
//        printf("Stack is empty.\n");
//        return;
//    }
//    printf("Stack elements (top to bottom): ");
//    while (temp != NULL) {
//        printf("%d -> ", temp->data);
//        temp = temp->next;
//    }
//    printf("NULL\n");
//}
//int main() {
//    struct Stack* S = createStack();
//    push(S, 10);
//    push(S, 20);
//    push(S, 30);
//    printf("Popped: %d\n", pop(S));
//    display(S);
//    printf("Top element: %d\n", peek(S));
//    push(S, 40);
//    push(S, 50);
//    display(S);
//    return 0;
//}
//using queue linked list
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue{
    struct Node*front;
    struct Node*rear;
};
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front=q->rear = NULL;
    return q;
}
void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=value;
    temp->next=NULL;
    if (q->rear==NULL) {
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
    printf("%d enqueue to queue.\n",value);
}
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if(q->front==NULL)
        q->rear=NULL;
    free(temp);
    return value;
}
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}
void display(struct Queue* q) {
    struct Node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeue: %d\n", dequeue(q));
    display(q);
    printf("front element: %d\n", peek(q));
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    return 0;
}


