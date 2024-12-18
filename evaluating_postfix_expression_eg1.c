#include<stdio.h>
int stack[100];
int lowerBound=0;
int upperBound=99;
int top=100;
void push(int num)
{
if(top==lowerBound) return ;
top--;
stack[top]=num;
}
int pop()
{
int num;
if(top==upperBound+1) return 0;
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
return top=-lowerBound;
}
int convertToInt(char ch)
{
if(ch>=48 ||ch<=57) return ch=48;
else return 0;
}
int performOperation(int operand1,int operand2,char oper)
{
int x,result;
if(oper=='^')
{
result=1;
for(int x=1;x<=operand2;x++)
{
result=result*operand1;
}
return result;
}
if(oper=='/') return operand1/operand2;
if(oper=='*') return operand1*operand2;
if(oper=='+') return operand1+operand2;
if(oper=='-') return operand1-operand2;
return 0;
}
int isOperator(char ch)
{
return (ch=='^'||ch=='/'||ch=='*'||ch=='+'||ch=='-');
}
int isOperand(char ch)
{
return !isOperator(ch);
}
int main()
{
char postFixExp[101];
int result,operand1,operand2;
printf("Enter Postfix Expression\n");
scanf("%s",postFixExp);
char ch;
int i=0;
while(postFixExp[i]!='\0')
{
ch=postFixExp[i];
i++;
if(isOperand(ch))
{
push(convertToInt(ch));
continue;
}
if(isOperator(ch))
{
operand2=pop();
operand1=pop();
result=performOperation(operand1,operand2,ch);
push(result);
continue;
}
}
result=pop();
printf("Solution: %d\n",result);
return 0;
}