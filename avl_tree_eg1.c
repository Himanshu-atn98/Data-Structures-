#include<stdio.h>
#include<malloc.h>
struct Node 
{
int key;
struct Node *left;
struct Node *right;
int height;
};
 
int getHeight(struct Node *node)
{
printf("*****getHeight() Runs*****\n");
if(node==NULL) return 0;
return node->height;
}

struct Node *createNode(int key)
{
printf("*****CreateNode() Runs*****\n");
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->key=key;
node->left=NULL;
node->right=NULL;
node->height=1;
return node;
}

int max(int a,int b)
{
printf("***** max() Runs*****\n");
return (a>b)?a:b;
}

int getBalanceFactor(struct Node *node)
{
printf("*****getBalanceFactor() Runs*****\n");
if(node==NULL)
{
return 0;
}
return getHeight(node->left)-getHeight(node->right);
}

struct Node *rightRotate(struct Node *y)
{
printf("*****rightRotate() Runs*****\n");
struct Node*x=y->left;
struct Node*t2=x->right;
y=x->right;
t2=y->left;
x->height=max(getHeight(x->right),getHeight(x->left)+1);
y->height=max(getHeight(y->right),getHeight(y->left)+1);
return x;
}

struct Node *leftRotate(struct Node *x)
{
printf("*****leftRotate() Runs*****\n");
struct Node *y=x->right;
struct Node *t2=y->left;
y->left=x;
x->right=t2;
x->height=max(getHeight(x->right),getHeight(x->left)+1);
y->height=max(getHeight(y->right),getHeight(y->left)+1);
return y;
}

// Insert Node
struct Node *insert(struct Node* node,int key)
{
printf("*****insert() Runs*****\n");

if(node==NULL)
{
return createNode(key);
}
if(key<node->key)
{
node->left=insert(node->left,key);
}
else
{
if(key>node->key)
{
node->right=insert(node->right,key);
}
}
node->height=1+max(getHeight(node->left),getHeight(node->right));
int balanceFactor=getBalanceFactor(node);

// Left-Left Rotation Case-
if(balanceFactor>1 && key<node->left->key)
{
return rightRotate(node);
}
// Right-Right Rotation Case-
if(balanceFactor<-1 && key>node->right->key)
{
return leftRotate(node);
}

// Left-Right Rotation Case-
if(balanceFactor>1 && key>node->left->key)
{
node->left=leftRotate(node->left);
return rightRotate(node);
}
// Right-Left Rotation Case-
if(balanceFactor<-1 && key<node->right->key)
{
node->right=rightRotate(node->right);
return leftRotate(node);
}
return node;
}

void preOrder(struct Node *root)
{
if(root!=NULL)
{
printf("%d ",root->key);
preOrder(root->left);
preOrder(root->right);
}
}

void postOrder(struct Node *root)
{
if(root!=NULL)
{
preOrder(root->left);
preOrder(root->right);
printf("%d ",root->key);
}
}

void inOrder(struct Node *root)
{
if(root!=NULL)
{
preOrder(root->left);
printf("%d ",root->key);
preOrder(root->right);
}
}

int main()
{
int ch;
struct Node *root=NULL;
root=insert(root,11);
root=insert(root,12);
root=insert(root,14);
//root=insert(root,15);
//root=insert(root,16);
//root=insert(root,13);
printf("PreOrder\n");
preOrder(root);
printf("\n");

while(1)
{
printf("1.Pre Order\n");
printf("2.Post Order\n");
printf("3.In Order\n");
printf("4.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("*****PreOrder******\n");
preOrder(root);
printf("\n");
}
if(ch==2)
{
printf("*****PostOrder******\n");
postOrder(root);
printf("\n");
}
if(ch==3)
{
printf("*****InOrder******\n");
inOrder(root);
printf("\n");
}
if(ch==4)
{
break;
}
}


return 0;
}