#include<stdio.h>
#define max 5
int queue[max];
int front=-1; rear=-1;
int value;
void enqueue(int item){
if(front==(rear+1)%max){
    printf("queue is FULL\n");
}
else if(front==-1){
   front=0;
   rear=0;
   queue[rear]=item;

}
else{
    rear=(rear+1)%max;
    queue[rear]=item;
}
}

int dequeue(){
    int item;
if(front==-1){
    printf("Queue is empty\n");
}
else if(front==rear){
  item=queue[front];
  front=-1;
  rear=-1;
  return item;
}
else{
    item=queue[front];
    front=(front+1)%max;
    return item;
}
}


void display(){
if(front==-1){
    printf("queue is empty\n");
}
else{
    int i=front;
    while(i!=rear){
        printf("The elements in queue:%d\n",queue[i]);
        i=(i+1)%max;
    }
    printf("%d\n",queue[i]);
}

}



int main(){
    int ch;
do{
    printf("\n What do you want to do 1]Insert 2]Delete 3]Display 4]Exit:");
    scanf("%d",&ch);
    switch(ch){
   case 1:
       printf("Enter the value to insert:");
       scanf("%d",&value);
       enqueue(value);
       printf("%d inserted\n",value);
       break;
   case 2:
       printf("The deleted item is: %d ",dequeue());
       break;
   case 3:
       display();
       break;
   case 4:
    printf("---We are Exiting---");
    break;
   default:
     printf("Invalid choice");
    }
}while (ch!=4);
printf("\n");
return 0;

}
