// Program to create a linked list, add elements to the list (in beginning, end and middle), view elements of the list and delete elements from the list (from any position).

#include<stdio.h>
#include<stdlib.h>

void ADD(void);
void VIEW(void);
void DELETE(void);
int COUNT(void);

struct node{
	int data;
	struct node *link;
};

typedef struct node NODE;
NODE *head = NULL, *last = NULL;

int main(){
	int choice = 0;
	
	printf("\n --- MENU ---\n");
	printf("1. Add data\n");
	printf("2. View list\n");
	printf("3. Delete data\n");
	printf("4. Count number of nodes\n");
	printf("-> Any other key to exit\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: ADD(); break;
		case 2: VIEW(); break;
		case 3: DELETE(); break;
		case 4: printf("Number of nodes: %d\n", COUNT()); main();
		default: exit(0);
	}
	return 0;
}

void ADD(){
	int choice = 0;
	NODE *temp;
	
	void ADD_BEG(){
		int choice = 1;
		while(choice == 1){
			temp = (NODE *)malloc(sizeof(NODE));
			printf("Enter data: ");
			scanf("%d", &temp->data);
			if(head == NULL){
				head = last = temp;
				last->link = NULL;
			}
			else{
				NODE *ptr;
				ptr = head;
				head = temp;
				head->link = ptr;
			}
			printf("Press 1 to add more data: ");
			scanf("%d", &choice);
		}
		ADD();
	}
	
	void ADD_END(){
		int choice = 1;
		while(choice == 1){
			temp = (NODE *)malloc(sizeof(NODE));
			printf("Enter data: ");
			scanf("%d", &temp->data);
			if(head == NULL){
				head = last = temp;
				last->link = NULL;
			}
			else{
				last->link = temp;
				last = temp;
				last->link = NULL;
			}
			printf("Press 1 to add more data: ");
			scanf("%d", &choice);
		}
		ADD();
	}
	
	void ADD_ANY(){
		int index = 0, count = COUNT();
		
		if(head == NULL || count < 2){
			printf("List too small to insert in middle !\n");
			ADD();
		}
		
		printf("-> Press 0 to return to menu\n");
		printf("Enter the index at which you want to insert (2 - %d): ", count);
		scanf("%d", &index);
		
		if(index == 0){
			ADD();
		}
		else if(index < 2 || index > count){
			printf("Invalid index! Please try again.\n");
			ADD_ANY();
		}
		else{
			temp = (NODE *)malloc(sizeof(NODE));
			printf("Enter data: ");
			scanf("%d", &temp->data);
			
			int traverse = 1;
			NODE *ptr = head;
			while(traverse < index - 1){	// 'index - 1' because we want 'ptr' to be at 'index - 1' position
				ptr = ptr->link;
				traverse++;
			}
			temp->link = ptr->link;
			ptr->link = temp;
		}
		ADD();
	}
	
	printf("\n --- ADD DATA ---\n");
	printf("1. Add at beginning\n");
	printf("2. Add at end\n");
	printf("3. Add at any position\n");
	printf("-> Any other key to return to menu\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: ADD_BEG(); break;
		case 2: ADD_END(); break;
		case 3: ADD_ANY(); break;
		default: main();
	}
}

void VIEW(){
	int choice = 0;
	
	void VIEW_FULL(){
		if(head == NULL){
			printf("Empty List! Nothing to view\n");
			VIEW();
		}
		else{
			NODE *ptr = head;
			while(ptr){
				printf("%d", ptr->data);
				if(ptr->link == NULL)
					break;
				else{
					printf(" -> ");
					ptr = ptr->link;
				}
			}
		}
		putchar('\n');
		VIEW();
	}
	
	void VIEW_INDEX(){
		int index = 0, count = COUNT();
		if(head == NULL){
			printf("Empty list! Nothing to view\n");
		}
		else{
			printf("Enter index (1 - %d): ", count);
			scanf("%d", &index);
			if(index < 1 || index > count){
				printf("Invalid index!\n");
				VIEW();
			}
			else{
				NODE *ptr = head;
				int traverse = 1;
				
				while(traverse < index){
					traverse++;
					ptr = ptr->link;
				}
				printf("Element at index %d is %d\n", index, ptr->data);
			}
		}
		VIEW();
	}
	
	printf("\n --- VIEW LIST ---\n");
	printf("1. View complete list\n");
	printf("2. View element at particular index\n");
	printf("-> Any other key to return to menu\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: VIEW_FULL(); break;
		case 2: VIEW_INDEX(); break;
		default: main();
	}
}

void DELETE(){
	int choice = 0;
	
	void DELETE_ALL(){
		if(head == NULL){
			printf("Empty list! Nothing to delete\n");
		}
		else{
			free(head);
			free(last);
			head = last = NULL;
			printf("List successfully deleted!\n");
		}
		DELETE();
	}
	
	void DELETE_INDEX(){
		if(head == NULL){
			printf("Empty list! Nothing to delete\n");
		}
		else{
			int index = 0, count = COUNT();
			
			printf("-> Press 0 to return to menu\n");
			printf("Enter the index from where you want to delete (1 - %d): ", count);
			scanf("%d", &index);
			
			if(index == 0){
				DELETE();
			}
			else if(index < 1 || index > count){
				printf("Invalid index!\n");
				DELETE();
			}
			else{
				int temp = 0, traverse = 1;
				NODE *ptr;
				
				if(index == 1){
					temp = head->data;
					head = head->link;
				}
				else if(index == count){
					ptr = head;
					traverse = 1;
					
					while(traverse < index - 1){
						ptr = ptr->link;
					}
					
					temp = last->data;
					last = ptr;
					last->link = NULL;
				}
				else{
					NODE *del = head;
					ptr = head;
					traverse = 1;
					
					while(traverse < index){
						del = del->link;
						traverse++;
					}
					
					temp = del->data;
					traverse = 1;
					
					while(traverse < index - 1){
						ptr = ptr->link;
						traverse++;
					}
					ptr->link = del->link;
					//free(del);
				}
				printf("Element at index %d sucessfully deleted (Element deleted: %d)\n", index, temp);
			}	
		}
		DELETE();
	}
	
	printf("\n --- DELETE DATA ---\n");
	printf("1. Delete complete list\n");
	printf("2. Delete element at particular index\n");
	printf("-> Any other key to return to menu\n");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: DELETE_ALL(); break;
		case 2: DELETE_INDEX(); break;
		default: main();
	}
}

int COUNT(){
	int count = 0;
	if(head == NULL){
		return 0;
	}
	else{
		NODE *ptr = head;
		while(ptr){
			count = count + 1;
			if(ptr->link == NULL)
				break;
			else
				ptr = ptr->link;
		}
	}
	return count;
}
