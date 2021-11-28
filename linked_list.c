#include<stdio.h>
#include<stdlib.h>

//DEFINING NODE
struct node{
    int data;
    struct node *next;
};

//INITIALING NODE OF ' n ' SIZE
void createNode(struct node **head, int length){
    int data;
    struct node* current = *head;
    printf("Enter data of the Node 1 : ");
    scanf("%d",&current->data);
    current->next = NULL;

    for(int i=1;i<length;i++){
        struct node *newNode = (struct node*)malloc(sizeof(struct node));
        current->next = newNode;
        current=newNode;
        printf("Enter data of the Node %d : ",i+1);
        scanf("%d",&current->data);
        current->next=NULL;
    }
}


//DISPLAYING LINKED LIST
void display(struct node **head){
    struct node *temp = *head;
    while (temp)
    {
        printf("\n%d ",temp->data);
        temp = temp->next;
    }
}

//MAIN FUNCTION
int main(){
    int n;
    struct node *head = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Number of Nodes : ");
    scanf("%d",&n);
    createNode(&head,n);
    display(&head);
    return 0;
}