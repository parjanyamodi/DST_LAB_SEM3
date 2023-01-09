#include<stdio.h>
#include<stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

typedef struct NODE *NODE;

NODE create_node()
{
    NODE newNode = (NODE)malloc(sizeof(NODE));
    if(newNode==NULL)
    {
        printf("\n\nError: Overflow detected - Memory is full!\n\n");
        exit(0);
    }
    printf("Enter the Data: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    return newNode;
}

void free_memory(NODE temp)
{
    free(temp);
}

NODE insert_front(NODE head){
    NODE newNode = create_node();
    if(head==NULL){
        head = newNode;
    }
    else{
        newNode->next= head;
        head=newNode;
    }
    return head;
}
NODE delete_front(NODE head){
    if(head==NULL){
        printf("\n\nError: Underflow detected - No node exists!\n\n");
    }
    else
    {
        NODE ptr = head;
        head = ptr->next;
        ptr->next = NULL;
    }
    return head;
}
NODE insert_rear(NODE head){
    NODE newNode = create_node();
    if(head==NULL){
        head=newNode;
    }
    else{
        NODE ptr = head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
    return head;
}
NODE delete_rear(NODE head){
    if(head==NULL){
        printf("\n\nError: Underflow detected - No node exists!\n\n");
    }
    else{
        NODE ptr = NULL;
        NODE temp = head;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        free_memory(temp);
        ptr->next=NULL;
    }
    return head;
}
void display(NODE head){
    NODE ptr;
    if(head==NULL){
        printf("\n\nError: Underflow detected - No node exists!\n\n");
    }
    else{
        for(ptr=head;ptr!=NULL;ptr=ptr->next)
        {
            printf("%d\n",ptr->data);
        }   
    }
}
void main(){
    int choice;
    NODE head=NULL;
    for(;;){
        printf("Select Appropriate Option:\n1.Display Data\n2.Stack PUSH\n3.Stack POP\n4.Queue PUSH\n5.Queue POP\n6:Exit\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:display(head);
            break;
            case 2:head=insert_rear(head);
            break;
            case 3:head=delete_rear(head);
            break;
            case 4:head=insert_front(head);
            break;
            case 5:head=delete_front(head);
            break;
            case 6:printf("\n\n***********************************  Terminating the program  ***********************************\n\n");
            exit(0);
            break;
            default:printf("\nError: Enter valid choice!\n");
            break;
        }
    }
    
}
