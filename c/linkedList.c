#include<stdio.h>
#include<stdlib.h>

int countNodes(void);
void menu(void);
void addNode(void);
void deleteNode(void);
void displayList(void);
void dividor(void);

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;
NODE *head = NULL, *last = NULL;

int main() {
    menu();
}

void menu() {
    int input;

    printf("\n");
    printf("### MENU ###\n");
    printf("Select any option:\n");
    printf("1. Add node\n");
    printf("2. Delete node\n");
    printf("3. View List\n");
    printf("#. Exit\n");

    scanf("%d", &input);
    switch (input) {
        case 1: addNode(); break;
        case 2: deleteNode(); break;
        case 3: displayList(); break;
        default: exit(0); break;
    }
}

int countNodes() {
    int num = 0;

    if (head == NULL) {
        return 0;
    } else {
        NODE *ptr = head;
        while (ptr) {
            ptr = ptr->next;
            num++;
        }

        return num;
    }
}

void addNode() {
    int position = 1;
    int data;
    int maxNodes = countNodes();
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    if (maxNodes != 0) {
        printf("Enter position (1 - %d): ", maxNodes + 1);
        scanf("%d", &position);

        if (position < 1 || position > maxNodes + 1) {
            printf("Invalid position!\n");
            addNode();
        }
    }

    printf("Enter Data: ");
    scanf("%d", &temp->data);

    if (position == 1) {
        if (head == NULL) {
            head = last = temp;
            last->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    } else if (position == maxNodes + 1) {
        last->next = temp;
        last = temp;
        last->next = NULL;
    } else {
        NODE *ptr = head, *prev;
        int i = 1;
        while (ptr) {
            if (i == position) {
                break;
            }
            i++;
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next = temp;
        temp->next = ptr;
    }

    printf("Data Inserted!\n");
    menu();
}

void deleteNode() {

}

void displayList() {
    int numNodes = countNodes(), i=1;

    dividor();

    if (numNodes == 0) {
        printf("List is empty!");
    } else {
        printf("Total node(s): %d\n", numNodes);
        NODE *ptr = head;
        while (ptr) {
            printf("%d", ptr->data);
            if (ptr != last) {
                printf(" -> ");
            }
            ptr = ptr->next;
            i++;
        }
    }

    dividor();
    menu();
}

void dividor() {
    printf("\n-------------------------------------------------\n");
}
