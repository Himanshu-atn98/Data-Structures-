#include<stdio.h>
#include<malloc.h>
char stack[100];
int lowerBound=0;
int upperBound=99;
int top=100;
int size=0;
char postFixExp[101];
int postFixLowerBound=0;
void push(char op)
{
top--;
stack[top]=op;
size++;
}
char pop()
{
char op;
op=stack[top];
top++;
size--;
return op;
}
int isEmpty()
{
return top==upperBound+1;
}
int isFull()
{
return top=-lowerBound;// top==lowerBound--;  ->top==-1;
}
int isOperator(char ch)
{
return (ch=='^'||ch=='/'||ch=='*'||ch=='+'||ch=='-');
}
int isOperand(char ch)
{
if(isOperator(ch)) return 0;
else return 1;
}
int getPrecedenceLevel(char op)
{
if(op=='^') return 3;
if(op=='/'||op=='*') return 2;
if(op=='+'||op=='-') return 1;
return 0;
}
char getElementAtTop()
{
return stack[top];
}
void appendToPostFixExp(char ch)
{
postFixExp[postFixLowerBound]=ch;
postFixLowerBound++;
postFixExp[postFixLowerBound]='\0';
}
int main()
{
char inFixExp[100];
char ch,op;
printf("Enter an infix expression\n");
scanf("%s",inFixExp);
int i=0;
while(inFixExp[i]!='\0')
{
ch=inFixExp[i];
i++;
if(ch=='(')
{
push(ch);
continue;
}
if(ch==')')
{
while(1)
{
op=pop();
if(op=='(') break;
appendToPostFixExp(op);
}
continue;
}
if(isOperand(ch))
{
appendToPostFixExp(ch);
continue;
}
if(isOperator(ch))
{
if(isEmpty())
{
push(ch);
}
else
{
op=getElementAtTop();
if(op=='(')
{
push(ch);
}
else
{
if(getPrecedenceLevel(op)>=getPrecedenceLevel(ch))
{
while(1)
{
if(isEmpty())
{
break;
}
op=getElementAtTop();
if(op=='(')
{
break;
}
if(getPrecedenceLevel(op)<getPrecedenceLevel(ch))
{
break;
}
op=pop();
appendToPostFixExp(op);
}
push(ch);
}
else
{
push(ch);
}
}
}
continue;
} 
}//while ends

while(1)
{
if(isEmpty())
{
break;
}
op=pop();
appendToPostFixExp(op);
}
printf("Post Fix Expression is\n");
printf("%s",postFixExp);
return 0;
}