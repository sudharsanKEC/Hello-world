#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE insertAtPositionInCLL(NODE first,int pos,int x){
	if(first==NULL && pos>1){
		printf("Enter 1st position\n");
		return;
	}
	NODE newnode=(NODE)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed\n");
	}
	newnode->data=x;
	newnode->next=NULL;
	if(pos==1){
		if(first==NULL){
			first=newnode;
			first->next=first;
		}
		else{
			NODE temp=first;
			while(temp->next!=first){
				temp=temp->next;
			}
			newnode->next=first;
			temp->next=newnode;
			first=newnode;
		}
	}
	else{
		NODE temp=first;
		int i=1;
		for(i=1;i<pos-1&&temp->next!=first;i++){
			temp=temp->next;
		}
		if(i==pos-1){
			newnode->next=temp->next;
			temp->next=newnode;
		}
		else{
			printf("Invalid position\n");
			free(newnode);
		}
	}
	return first;
}
NODE deleteAtPositionInCLL(NODE head,int pos){
	if(pos==1){
		if(head==NULL){
			printf("List is empty\n");
			return head;
		}
		else{
			NODE temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=head->next;
			NODE temp2=head;
			head=head->next;
			free(temp2);
			return head;
		}
	}
	else{
		if(head==NULL){
			printf("List is empty\n");
			return head;
		}
		else{
			NODE temp=head;
			NODE prev=NULL;
			int i=1;
			for(i=1;i<pos&&temp->next!=head;i++){
				prev=temp;
				temp=temp->next;
			}
			if(i==pos){
				prev->next=temp->next;
				free(temp);
				return head;
			}
			else{
				printf("Element not found\n");
				return head;
			}
		}
	}
}
void traverseListInCLL(NODE first){
	NODE temp=first;
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=first);
	return ;
}
void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert 2.Delete 3.Display 4.Exit\n");
		printf("choice: ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Position: ");
					scanf("%d", &pos);
					if (pos <= 0) {
						printf("Position not found\n");
					} else {
						printf("Element: ");
						scanf("%d", &x);
						first = insertAtPositionInCLL(first, pos, x);
					}
					break;
	        case 2:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Position: ");
						scanf("%d", &pos);
						first = deleteAtPositionInCLL(first, pos);
					}
					break;
			case 3:	if (first == NULL) {
						printf("CLL is empty\n");
					} else {
						printf("Elements in CLL are: ");
						traverseListInCLL(first);
					}
					break;
			case 4:	exit(0);
		}
	}
}
