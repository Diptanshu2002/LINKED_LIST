#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//DEFINING NODE
struct node{
    int data;
    struct node *next;
};


void minNode(struct node **head){
    struct node *temp = *head;
    int min = INT_MAX;
    int posMinElement = 0 , counter = 0;
    while (temp)
    {
        counter++;
        if(min > temp->data){
            min = temp->data;
            posMinElement = counter;
        }
        temp = temp->next;
    }
    printf("\n%d is the min element in the Linked List present at %d",min,posMinElement);
}

//FINDING MAX ELEMENT and IT's POSITION
void maxNode(struct node **head){
    struct node *temp = *head;
    int max = INT_MIN;
    int posMaxElement = 0 , counter = 0;
    while (temp)
    {
        counter++;
        if(max < temp->data){
            max = temp->data;
            posMaxElement = counter;
        }
        temp = temp->next;
    }
    printf("\n%d is the max element in the Linked List present at %d",max,posMaxElement);
}

//DELETING NODES FROM A GIVEN LOCATION
void deleteNode(struct node **head , int pos){
    struct node *temp = NULL;
    struct node *freeNode = *head;
    pos--; //making pos to 0 if pos was 1

    //when to delete first node.
    if(pos == 0){
        temp = freeNode;
        temp = temp->next;
        *head = temp;
        free(freeNode);
        return;
    }

    for(int i=1 ; i<=pos ;i++ ){
        temp = freeNode;
        freeNode = freeNode->next;
    }
    temp->next = freeNode->next;
    free(freeNode);

}


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
    // insertNode(&head , 10 , 3);
    // deleteNode(&head,1);
    maxNode(&head);
    minNode(&head);
    // display(&head);
    return 0;
}