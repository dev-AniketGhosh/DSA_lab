#include<stdio.h>
#include<stdlib.h>
struct CNode{
	int data;
	struct CNode*next;
};
void insertCircular(struct CNode**head,int data){
	struct CNode*newNode=(struct CNode*)malloc(sizeof(struct CNode));
	newNode->data=data;
	if(*head==NULL){
		newNode->next=newNode;
		*head=newNode;
		return;
	}
	struct CNode*temp=*head;
	while(temp->next!=*head)
	temp=temp->next;
	newNode->next=*head;
}
void displayCircular(struct CNode*head){
	if(head==NULL){
		printf("Circular List is empty.\n");
		return;
	}
	struct CNode*temp=head;
	printf("Circular Linked List:");
	do{
		printf("%d->",temp->data);
		temp=temp->next;
		}while(temp!=head);
		printf("(back to head)\n");
}
struct DNode{
	int data;
	struct DNode*prev;
	struct DNode*next;
};
void insertDoubly(struct DNode**head,int data){
	struct DNode*newNode=(struct DNode*)malloc(sizeof(struct DNode));
	newNode->data=data;
	newNode->next=NULL;
	if(*head==NULL){
		newNode->prev=NULL;
		*head=newNode;
		return;
	}
	struct DNode *temp=*head;
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=newNode;
	newNode->prev=temp;
}
void displyDoublyForward(struct DNode *head){
	struct DNode *temp=head;
	printf("Doubly LinkedList(Forward):");
	while(temp!=NULL){
		printf("%d<_>",temp->data);
		temp=temp->next;
	}
	printf("NULL \n");
}
void displayDoublyBackward(struct DNode*head){
	struct DNode*temp=head;
	if(temp==NULL){
		printf("Doubly List is empty.\n");
		return;
	}
	while(temp->next!=NULL)
	temp=temp->next;
	printf("Doubly Linked List(Backward):");
	while(temp!=NULL){
		printf("%d<_>",temp->data);
		temp=temp->prev;
		}
		printf("NULL \n");
	}
	int main(){
		struct CNode *circularHead=NULL;
		struct DNode *DoublyHead=NULL;
		//sample insertions
		insertCircular(&circularHead,10);
    	insertCircular(&circularHead,20);
		insertCircular(&circularHead,30);
		
		insertDoubly(&DoublyHead,100);
		insertDoubly(&DoublyHead,200);
		insertDoubly(&DoublyHead,300);
		//Display both Lists
		displayCircular(circularHead);
		displyDoublyForward(DoublyHead);
		displayDoublyBackward(DoublyHead);
		return 0;
		}
