#include<stdio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *next,*prev;
};
struct Node *start=NULL;
struct Node *end=NULL;
void addAtTop(int data)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->prev=NULL;
node->next=NULL;
if(start==NULL)
{
start=node;
end=node;
}
else
{
node->next=start;
start->prev=node;
start=node;
}
}
void addAtEnd(int data)
{
//struct Node *p1=start;
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->next=NULL;
node->prev=NULL;
if(start==NULL)
{
start=node;
end=node;
}
else
{

/*
while(p1->next!=NULL)
{
p1=p1->next;
}
p1->next=node;
node->prev=p1;
*/
// Or we can also write this->
end->next=node;
node->prev=end;
end=node;
}
}

void insertAtPosition(int data,int pos)
{
struct Node*p1=start;
struct Node* node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->next=NULL;
node->prev=NULL;
for(int i=1;i<pos;i++ && p1!=NULL)
{
p1=p1->next;
}

if(p1==NULL)
{
if(start==NULL)
{
start=node;
end=node;
}
else
{
end->next=node;
node->prev=end;
end=node;
}
}
else
{
if(p1==start)
{
node->next=start;
start->prev=node;
start=node;
}
else
{
node->next=p1;
node->prev=p1->prev;
p1->prev=node;
p1->prev->next=node;
}
}
}


void traverseTopToBottom()
{
struct Node *node=start;
if(node==NULL)
{
printf("No elements are added in list.\n");
return;
}
while(node!=NULL)
{
printf("%d\n",node->data);
node=node->next;
}
}
int main()
{
int ch,num,pos;
while(1)
{
printf("1.Add a node at end\n");
printf("2.Insert a node at top\n");
printf("3.Insert a node at position\n");
printf("4.Remove a node froma position\n");
printf("5.Traverse-Top To Botton\n");
printf("6.Traverse-Bottom To Top\n");
printf("7.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter a number to add at end:");
scanf("%d",&num);
addAtEnd(num);
printf("*****%d is added at the end*****\n",num);
}
if(ch==2)
{
printf("Enter a number to add at top:");
scanf("%d",&num);
addAtTop(num);
printf("*****%d is added at the top*****\n",num);
}
if(ch==3)
{
printf("Enter a number to insert:");
scanf("%d",&num);
printf("Enter position:");
scanf("%d",&pos);
insertAtPosition(num,pos);
printf("*****%d is added at %d position*****\n",num,pos);
}
if(ch==4)
{
}
if(ch==5)
{
traverseTopToBottom();
}
if(ch==6)
{
}
if(ch==7)
{
break;
}
}
return 0;
}