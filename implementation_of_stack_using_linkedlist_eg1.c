                //implementation_of_stack_using_linkedlist
#include<stdio.h>
#include<malloc.h>
struct Node
{
int num;
struct Node *next; 
};
struct Node *top;

void push(int num)
{
struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
ptr->num=num;
if(top==NULL)
{
ptr->next=NULL;
top=ptr;
}
else
{
ptr->next=top;
top=ptr;
}
}
int pop()
{
int num;
struct Node *ptr;
if(top==NULL)
{
return 0;
}
num=top->num;
ptr=top;
top=top->next;
free(ptr);
return num;
}
int isEmpty()
{
return top==NULL;
}
int main()
{
int ch,num;
top=NULL;
while(1)
{
printf("1.Push A Number On Stack\n");
printf("2.Pop A Number From Stack\n");
printf("3.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter Number To Push On Stack:");
scanf("%d",&num);
if(num==0)
{
printf("Error! Zero Cannot Be Pushed On Staack\n");
}
else
{
push(num);
printf("%d Pushed On Stack\n",num);
}
}
if(ch==2)
{
if(isEmpty())
{
printf("Error! Stack Is Empty\n");
}
else
{
num=pop();
printf("%d Popped From Stack\n",num);
}
}
if(ch==3)
{
break;
}
}
return 0;
}