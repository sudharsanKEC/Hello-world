#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *front,*back;
}*NODE;
NODE insertAtBeginInDLL(NODE first,int x){
	NODE newnode=(struct node*)malloc(sizeof(struct node));
	if(first==NULL){
		newnode->back=first;
		newnode->front=first;
		newnode->data=x;
		first=newnode;
		return first;
	}
	else{
		newnode->back=first;
		newnode->data=x;
		first->front=newnode;
		first=newnode;
		return first;
	}
}
NODE deleteAtBeginInDLL(NODE first){
	NODE temp=first;
	printf("The deleted element from DLL is %d\n",temp->data);
	first=first->back;
	free(temp);
	return first;
}
int searchPosOfEleInDLL(NODE first,int x){
	int pos=0;
	while(first!=NULL){
		if(first->data==x)
		return ++pos;
		++pos;
		first=first->back;
	}
}
void traverseListInDLL(NODE first){
	printf("The elements are:\n");
	while(first!=NULL){
		printf("%d ",first->data);
		first=first->back;
	}
	printf("\n");
	return;
}
void main() {
	NODE first = NULL;
	int x, pos, op;
	while(1) {
		printf("1.Insert At Begin\n2.Delete at Begin\n3.Search an element Position\n4.Traverse the List\n5.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	printf("Enter an element: ");
					scanf("%d", &x);
					first = insertAtBeginInDLL(first, x);
					break;
			case 2:	
					if (first == NULL) {
						printf("Double Linked List is empty so deletion is not possible\n");
					} else {
						first = deleteAtBeginInDLL(first);
					}
					break;
			case 3:	
					printf("Enter search element: ");
					scanf("%d", &x);
					pos = searchPosOfEleInDLL(first, x);
					if (pos == 0) {
						printf("The given element %d is not found in the given DLL\n", x);
					} else {
						printf("The given element %d is found at position : %d\n", x, pos);
					}
					break;
			case 4: 
					if (first == NULL) {
						printf("Double Linked List is empty\n");
					} else {
						printf("The elements in DLL are: ");
						traverseListInDLL(first);
					}
					break;
			case 5:	exit(0);
		}
	}
}
