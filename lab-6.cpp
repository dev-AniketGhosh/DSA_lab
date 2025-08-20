// implementation of insertion,deletion and inversion in a singly linked list.
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* head=NULL;
void insert(int val){
struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->data =val;
newNode->next=head;
head=newNode;
}
void delete (int val){
	struct Node *temp=head,*prev=NULL;
	while(temp && temp->data!=val){
		prev=temp;
		temp=temp->next;
	}
	if(!temp){
		printf("%d not found",val);
		return ;
	}
	if (!prev)
		head=temp->next;
	else
		prev->next=temp->next;
	free(temp);
}
void reverse (){
	struct Node*prev=NULL ,*curr=head,*next;
	while(curr){next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
	}
	head=prev;
}
void display(){
	struct Node* temp=head;
	printf("list:");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main(){
	insert(10);
	insert(20);
	insert(30);
	display();
	delete(20);
	display();
	reverse();
	display();
	return 0;
}
