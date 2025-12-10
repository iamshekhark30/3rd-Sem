#include <stdio.h>

 # define size 3
 int front=-1,rear = -1;
 int queue[size];
 void insertlq(int item){
 if(rear == size - 1){
    printf("queue is full\n");
 }

 else if(front == -1){
    front = 0;
    rear = 0;
    queue[rear] = item;
 }

 else{
    rear = rear +1;
    queue[rear] = item;
 }
 }

 int dqueue(){
     int item;
 if(front == -1){
    printf("queue is empty\n");
    return 0;
 }

 else if(front == rear){
    item = queue[front];
    front = -1;
    rear = -1;
    return item;
 }

 else{
    item = queue[front];
    front = front + 1;
    return item;
 }
 }

 void display(){
 if(front == -1){
    printf("queue is empty\n");
 }
 else {
    printf("elements of queue are:\n");
    for(int i = front;i <= rear;i++){
        printf("%d\n",queue[i]);
    }
 }

 }

 void main(){
     int n,item;
 do{
    printf("you want to \n 1] insert 2] delete  3] display  4] exit\n");
    scanf("%d",&n);
    switch(n){
case 1:
    printf("enter value for insert\n");
    scanf("%d",&item);
    insertlq(item);
    break;
case 2:
    printf("deleted item is:");
    int dele = dqueue();
    printf("%d\n",dele);
    break;
case 3:
    display();
    break;
case 4:
    printf("we are existing\n");
    break;
default:
    printf("invalid number\n");
    }
 }while(n != 4);
 }
