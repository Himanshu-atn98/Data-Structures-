#include<stdio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *left;
struct Node*right;
};
struct Node * createNode(int data)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->left=NULL;
node->right=NULL;
return node;
}

//Pre Order Traversal
void preOrderTraversal(struct Node *root)
{
if(root!=NULL)
{
printf("%d ",root->data);
preOrderTraversal(root->left);
preOrderTraversal(root->right);
}
}

// Post Order Traversal
void postOrderTraversal(struct Node *root)
{
if(root!=NULL)
{
postOrderTraversal(root->left);
postOrderTraversal(root->right);
printf("%d ",root->data);
}
}

//Inorder Traversal
void inOrderTraversal(struct Node *root)
{
if(root!=NULL)
{
inOrderTraversal(root->left);
printf("%d ",root->data);
inOrderTraversal(root->right);
}
}

// Is BST Or Not

int isBST(struct Node *root)
{
static struct Node *prev=NULL;
if(root!=NULL)
{
if(!isBST(root->left))
{
return 0;
}
if(prev!=NULL && root->data<=prev->data)
{
return 0;
}
return isBST(root->right);
}
else
{
return 1;
}
}

int main()
{
struct Node *p;
p=createNode(50);
struct Node *p1,*p2,*p3,*p4;
p1=createNode(40);
p2=createNode(60);
p3=createNode(30);
p4=createNode(35);
// Linking the root node with it's left-right children.
/*
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
*/
struct Node*p5=createNode(110); 
p->left=p5;
p->right=p2;
p5->left=p1;
p5->right=p3;
p1->left=p4;

printf("\n******Pre Order Traversal******\n");
preOrderTraversal(p);
printf("\n******Post Order Traversal******\n");
postOrderTraversal(p);
printf("\n****** In Order Traversal******\n");
inOrderTraversal(p);
if(isBST(p)) printf("\nBinary tree is BST\n");
else printf("\nBinary tree is not BST\n");
return 0;
}