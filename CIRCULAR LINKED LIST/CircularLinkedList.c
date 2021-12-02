#include <stdio.h>
#include <stdlib.h>
typedef struct CircularLL{
    int data;
    struct CircularLL *next; 
}CircularLL;

void createLL(CircularLL **head , int count){

    CircularLL *cur = *head;
    printf("Enter the element 1 : ");
    scanf("%d",&cur->data);
    cur->next=cur;
    
    for (int i = 1; i < count; i++)
    {
        CircularLL *nextNode = (CircularLL *)malloc(sizeof(CircularLL));
        printf("Enter the element %d : ",i+1);
        scanf("%d",&nextNode->data);
        nextNode->next = cur->next;
        cur->next = nextNode;
        cur = nextNode;
    }
    
}

void display(CircularLL *head){
    CircularLL *dis = head;
    do{
        printf("%d ",dis->data);
        dis = dis->next;
    }while (dis != head);
   
}

int main(){
    CircularLL *head;
    int n;
    head = (CircularLL *)malloc(sizeof(CircularLL));
    printf("\nEnter the Lenght of the Linked List : ");
    scanf("%d",&n);
    createLL(&head , n);
    display(head);
    return 0;
}