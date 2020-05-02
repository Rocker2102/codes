#include<iostream>
#include<stdlib.h>

int countNodes(void);
void menu(void);
void addNode(void);
void deleteNode(void);
void displayList(void);
void dividor(void);

using namespace std;

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

    cout<<"\n";
    cout<<"### MENU ###"<<"\n";
    cout<<"Select any option:"<<"\n";
    cout<<"1. Add node"<<"\n";
    cout<<"2. Delete node"<<"\n";
    cout<<"3. View List"<<"\n";
    cout<<"#. Exit"<<"\n";

    cin>>input;
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
    NODE *temp = new NODE();

    if (maxNodes != 0) {
        cout<<"Enter position (1 - "<<maxNodes<<"): ";
        cin>>position;

        if (position < 1 || position > maxNodes) {
            cout<<"Invalid position!"<<"\n";
            addNode();
        }
    }

    cout<<"Enter Data: ";
    cin>>temp->data;

    if (position == 1) {
        if (head ==  NULL) {
            head = last = temp;
            last->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    } else if (position == maxNodes) {
        last->next = temp;
        last = temp;
        last->next = NULL;
    } else {

    }

    cout<<"Data Inserted!"<<"\n";
    menu();
}

void deleteNode() {

}

void displayList() {
    int numNodes = countNodes();

    dividor();

    if (numNodes == 0) {
        cout<<"List is empty!";
    } else {
        cout<<"Total node(s): "<<numNodes<<"\n";
        NODE *ptr = head;
        while (ptr) {
            cout<<ptr->data;
            if (ptr != last) {
                cout<<" -> ";
            }
            ptr = ptr->next;
        }
    }

    dividor();
    menu();
}

void dividor() {
    cout<<"\n"<<"-------------------------------------------------"<<"\n";
}
