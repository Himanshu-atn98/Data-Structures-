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
p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
printf("\n******Pre Order Traversal******\n");
preOrderTraversal(p);
printf("\n******Post Order Traversal******\n");
postOrderTraversal(p);
printf("\n****** In Order Traversal******\n");
inOrderTraversal(p);
return 0;
}