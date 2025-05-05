// Implementation of ListADT using singly linked list
#include <stdio.h>
#include <stdlib.h>

class listADT{
    struct node{
        int data;
        struct node *next;
    }*head;

    public:
    listADT();
    void insertbeg(int val);
    void insertend(int val);
    void insertpos(int pos, int val);
    int search(int val);
    int delbeg();
    int delend();
    int delpos(int pos);
    void display();
    void displayrev();
    void reverselink();
    void displayrevHelper(struct node* temp);
};
// Constructor
listADT::listADT(){
    head=NULL;
}
// Main function
int main(){
    listADT mylist;
    int choice,pos,val;

    while(1){
        printf("\nMENU\n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at position\n");
        printf("4.Search\n");
        printf("5.Display\n");
        printf("6.Display in reverse\n");
        printf("7.Reverse link\n");
        printf("8.Delete at begining\n");
        printf("9.Delete at end\n");
        printf("10.Delete at position\n");
        printf("11.Exit\n");
        printf("Enter ur choice\n");
        scanf("%d",&choice);

        if(choice==11){
            printf("Exiting");
            break;
        }
        else if(choice==1){
            printf("Enter value to insert:");
            scanf("%d", &val);
            mylist.insertbeg(val);
        }
        else if(choice==2){
            printf("Enter value to insert:");
            scanf("%d", &val);
            mylist.insertend(val);
        }
        else if(choice==3){
            printf("Enter value to insert:\n");
            scanf("%d", &val);
            printf("Enter position");
            scanf("%d ", &pos);
            mylist.insertpos(pos,val);
        }
        else if(choice==4){
            printf("Enter value to search");
            scanf("%d", &val);
            int x=mylist.search(val);
            if(x!=-1){
                printf("Index is %d of element %d",x,val);
            }
            else{
                printf("Value is not present in list");
            }
        }
        else if(choice==5){
            mylist.display();
        }
        else if(choice==6){
            mylist.displayrev();
        }
        else if(choice==7){
            mylist.reverselink();
            mylist.display();
        }
        else if(choice==8){
            int x=mylist.delbeg();
            printf("%d value is deleted", x);
        }
        else if(choice==9){
            int y=mylist.delend();
        }
        else if(choice==10){
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            int value = mylist.delpos(pos);
            if (value != -1) {
                printf("Deleted value from position %d: %d\n", pos, value);
            }
        }
        else{
            printf("Invalid, enter again");
            continue;
        }
    }
    return 0;
}

// Function to insert at beginning
void listADT:: insertbeg(int val){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    (*newnode).data=val;
    (*newnode).next=head;
    head=newnode;
}

// Function to display list
void listADT:: display(){
    struct node *temp=head;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d->",(temp)->data);
        (temp)=(temp)->next;
    }
    printf("NULL\n");
}

// Function to insert at end
void listADT:: insertend(int val){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    (*newnode).data=val;
    (*newnode).next=NULL;
    if(head==NULL){
        head=newnode;
    }
    struct node *temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

// Function to search
int listADT:: search(int val){
    struct node *temp=head;
    int index=1;
    while(temp!=NULL){
        if(temp->data==val){
            return index;
        }
        temp=temp->next;
        index++;
    }
    return -1;
}

// Function to delete at beginning
int listADT::delbeg() {
    if (head == NULL) {
        printf("The list is empty\n");
        return -1;
    }
    struct node *temp = head;   
    head = head->next;          
    int data = temp->data;      
    free(temp);              
    return data;                
}

// Function to delete at end
int listADT::delend() {
    if (head == NULL) {
        printf("The list is empty\n");
        return -1;
    }
    if (head->next == NULL) {
        int data = head->data;
        free(head);
        head = NULL;
        return data;
    }
    struct node *temp = head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}

// Function to insert at a specific position
void listADT::insertpos(int pos, int val){
    if(pos<1){
        printf("invalid position");
        return;
    }
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    (*newnode).data=val;
    (*newnode).next=NULL;
    if(pos==1){
        (*newnode).next=head;
        head=newnode;
    }
    struct node *temp=head;
    while(pos>2 &&temp!=NULL){
        temp=temp->next;
        pos--;
    }
    if(temp==NULL){
        printf("inavlid range");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

// Function to reverse the linked list members
void listADT:: reverselink(){
    struct node *current=head;
    struct node *prev=NULL;
    struct node *next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

// Function to delete from a specific position
int listADT::delpos(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position or empty list!\n");
        return -1;
    }
    struct node* temp = head;
    if (pos == 1) {
        head = temp->next;
        int data = temp->data;
        free(temp);
        return data;
    }
    struct node* prev = NULL;
    while (pos != 1 && temp != NULL) {
        prev = temp;
        temp = temp->next;
        pos--;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return -1;
    }
    prev->next = temp->next;
    int data = temp->data;
    free(temp);
    return data;
}

//To display in reverse
void listADT::displayrev() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    displayrevHelper(head);
    printf("NULL\n");
}

// Helper function for recursion
void listADT::displayrevHelper(struct node* temp) {
    if (temp == NULL) {
        return;
    }
    displayrevHelper(temp->next); 
    printf("%d->", temp->data);  
}





