#include<stdio.h>
#include<stdlib.h>

//DEFINING NODE
struct node{
    int data;
    struct node *next;
};

//COUNTING NUMBER OF NODES
int countingNodes(struct node **head){
    struct node *temp = *head;
    int count = 0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

//INSERTING NEW NODE AT A GIVEN POSITION
void insertNode(struct node **head , int pos , int value){
    struct node *temp = *head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    pos--;

        //lenght of the linked list
    int len = countingNodes(&(*head));
        //wrong input
    if(pos < 0){
        printf("/nEnter value more than 0");
        return;
    }
        //when position exceeds length
    if(pos>len){
        while (temp)
        {   
            if(temp->next == NULL){
                newNode->data = value;
                newNode->next = NULL;
                temp->next = newNode;
                return;
            }
            else{
                temp = temp->next;}
        } 
    }
        //inserting @ first position
    if(pos == 0){
        newNode->data = value;
        newNode->next = *head;
        *head = newNode;
        return;
    }
        //insertion @ given position
    for(int i = 1 ; i<=pos;i++){
        if(i == pos){
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

}

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
    insertNode(&head , 10 , 3);
    display(&head);
    return 0;
}