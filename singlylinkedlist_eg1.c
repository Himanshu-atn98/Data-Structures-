#include<stdio.h>
#include<malloc.h>
struct Node 
{
int data;
struct Node *next;
};
struct Node *start=NULL;

// Add At End
void addAtEnd(int data)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->next=NULL;
if(start==NULL)
{
start=node;
}
else
{
struct Node *p1=start;
while(p1->next!=NULL)
{
p1=p1->next;
}
p1->next=node;
}
}

// Insert At Top
void insertAtTop(int data)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->next=NULL;
if(start==NULL)
{
start=node;
}
else
{
node->next=start;
start=node;
}
}

// Insert At Position
void insertAtPosition(int data,int pos)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->next=NULL;
struct Node *p1,*p2;
p1=start;
int x=1;
while(p1!=NULL && x<pos)
{
p2=p1;
p1=p1->next; 
x++;
}
if(p1==NULL)
{
if(start==NULL)
{
start=node;
}
else
{
p2->next=node;
}
}
else
{
if(p1==start)
{
node->next=start;
start=node;
}
else
{
p2->next=node;
node->next=p1;
}
}
}

// Remove From Position
void removeFromPosition(int pos)
{
if(pos<1 || start==NULL)
{
printf("Invalid Position\n");
return ;
}
struct Node *p1,*p2;
p1=start;
for(int x=1;x<pos && p1!=NULL;x++)
{
p2=p1;
p1=p1->next;
}
if(p1==NULL)
{
printf("Invalid Position\n");
return;
}
if(p1==start)
{
start=start->next;
}
else
{
p2->next=p1->next;
}
free(p1);
}

// Traverse Top To Bottom
void traverseTopToBottom()
{
struct Node *node=start;
while(node!=NULL)
{
printf("%d\n",node->data);
node=node->next;
}
}

// Traverse Bottom To Top
void traverseBottomToTop(struct Node *node)
{
if(node==NULL)
{
return;
}
traverseBottomToTop(node->next);
printf("%d\n",node->data);
}

int main()
{
int num,ch,pos;
while(1)
{
printf("1.Add a node at end\n");
printf("2.Insert a node at top\n");
printf("3.Insert a node at position\n");
printf("4.Remove a node from a positin\n");
printf("5.Traverse-Top To Bottom\n");
printf("6.Traverse-Bottom To Top\n");
printf("7.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter a number to add at end:");
scanf("%d",&num);
addAtEnd(num);
printf("******Node added******\n");
}
if(ch==2)
{
printf("Enter a number to add at end:");
scanf("%d",&num);
insertAtTop(num);
printf("******Node inserted******\n");
}
if(ch==3)
{
printf("Enter a number to insert:");
scanf("%d",&num);
printf("Enter position:");
scanf("%d",&pos);
insertAtPosition(num,pos);
printf("******Node inserted******\n");
}
if(ch==4)
{
printf("Enter position of the node to remove:");
scanf("%d",&pos);
removeFromPosition(pos);
printf("******Node removed******\n");
}
if(ch==5)
{
printf("******Traversing Top To Bottom******\n");
traverseTopToBottom();
}
if(ch==6)
{
printf("******Traversing Bottom To Top******\n");

traverseBottomToTop(start);
}
if(ch==7)
{
break;
}
}
return 0;
}