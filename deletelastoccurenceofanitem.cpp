#include <stdio.h> 
#include <stdlib.h> 

// A linked list Node 
struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function to delete the last occurrence 
void deleteLast(struct Node** head, int x) 
{ 
		struct Node** tmp1 = NULL; 
		while(*head) { 
				if((*head)->data == x) { 
						tmp1 = head; 
				} 
				head = &(*head)->next; 
		} 
		if(tmp1) { 
				struct Node* tmp = *tmp1; 
				*tmp1 = tmp->next; 
				free(tmp); 
		} 
} 

/* Utility function to create a new node with 
given key */
struct Node* newNode(int x) 
{ 
	struct Node* node = malloc(sizeof(struct Node*)); 
	node->data = x; 
	node->next = NULL; 
	return node; 
} 

// This function prints contents of linked list 
// starting from the given Node 
void display(struct Node* head) 
{ 
	struct Node* temp = head; 
	if (head == NULL) { 
		printf("NULL\n"); 
		return; 
	} 
	while (temp != NULL) { 
		printf("%d --> ", temp->data); 
		temp = temp->next; 
	} 
	printf("NULL\n"); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node* head = newNode(1); 
	head->next = newNode(2); 
	head->next->next = newNode(3); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(5); 
	head->next->next->next->next->next = newNode(4); 
	head->next->next->next->next->next->next = newNode(4); 
	printf("Created Linked list: "); 
	display(head); 
	deleteLast(&head, 4); // Pass the address of the head pointer 
	printf("List after deletion of 4: "); 
	display(head); 
	return 0; 
} 
