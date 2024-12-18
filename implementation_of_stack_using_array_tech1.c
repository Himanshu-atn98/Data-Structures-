                        // implementation_of_stack_using_array_tech1
#include<stdio.h>
#include<malloc.h>
int stack[10];
int top=0;
int upperBound=9;
int size=0;
void push(int num)
{
int i;
if(size==upperBound+1)
{
return ;
}
i=size;
while(i>top)
{
stack[i]=stack[i-1];
i--;
}
stack[top]=num;
size++;
}
int pop()
{
int i,num;
if(size==0)
{
return 0;
}
num=stack[top];
i=top;
while(i<size-1)
{
stack[i]=stack[i+1];
i++;
}
size--;
return num;
}
int isEmpty()
{
return size==0;
}
int isFull()
{
return size==upperBound+1;
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