                        // implementation_of_stack_using_array_tech1
#include<stdio.h>
#include<malloc.h>
int stack[10];
int lowerBound=0;
int upperBound=9;
int top;
top=10;
int size=0;
void push(int num)
{
int i;
if(top==lowerBound)
{
return ;
} 
top--;
stack[top]=num;
}
int pop()
{
int num;
if(top==upperBound+1)
{
return 0;
}
num=stack[top];
top++;
return num;
}
int isEmpty()
{
return top==upperBound+1;
}
int isFull()
{
return top==lowerBound;
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
num=pop();
if(num) printf("%d Popped From Stack\n",num);
}
if(ch==3)
{
break;
}
}
return 0;
}