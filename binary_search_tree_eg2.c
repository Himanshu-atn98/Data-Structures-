#include<stdio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *left;
struct Node*right;
int nodeIndex;
};
static int index=0;
struct Node * createNode(int data)
{
struct Node *node=(struct Node*)malloc(sizeof(struct Node));
node->data=data;
node->left=NULL;
node->right=NULL;
node->nodeIndex=++index;
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

// Search Element In Binary Search Tree Recursively
struct Node * searchRecursively(struct Node *root,int key)
{
if(root==NULL) return NULL;
if(key==root->data) 
{
return root;
}
else
{
if(key<root->data) searchRecursively(root->left,key);
else searchRecursively(root->right,key);
}
}

//Search Element In Binary Search Tree Iteratively

struct Node * searchIteratively(struct Node *root,int key)
{
while(root!=NULL)
{
if(key==root->data) 
{
return root;
}
else
{
if(key<root->data) root=root->left;
else root=root->right;
}
}
return NULL;
}

// Insert Node In BST
void insertNode(struct Node *root,int key)
{
struct Node *prev=NULL;
while(root!=NULL)
{
prev=root;
if(key==root->data)
{
printf("%d is already exist in BST\n",key);
return;
}
else
{
if(key<root->data)
{
root=root->left;
}
else
{
root=root->right;
}
}
}
struct Node *node=createNode(key);
if(key<prev->data)
{
prev->left=node;
}
else
{
prev->right=node;
}
printf("******%d is inserted in BST******\n",key);
}

// InOrder Predecessor Function
struct Node * inOrderPredecessor(struct Node *root)
{
root=root->left;
while(root->right!=NULL)
{
root=root->right;
}
return root;
}

// Delete Node In BST
struct Node *deleteNode(struct Node *root,int key)
{
struct Node *inOrderPrev=NULL;
if(root==NULL) return NULL;
if(root->left==NULL && root->right==NULL)
{
free(root);
return NULL;
}

if(key<root->data)
{
root->left=deleteNode(root->left,key);
}
else
{
if(key>root->data)
{
root->right=deleteNode(root->right,key);
}
else
{
inOrderPrev=inOrderPredecessor(root);
root->data=inOrderPrev->data;
root->left=deleteNode(root->left,inOrderPrev->data);
}
}
return root;
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
p4=createNode(45);

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
printf("\n\n");

int key,ch;
while(1)
{
printf("1.Recursively Search\n");
printf("2.Iterative Search\n");
printf("3.Insert Node\n");
printf("4.Delete Node\n");
printf("5.Pre Order Traversal\n");
printf("6.Post Order Traversal\n");
printf("7.In Order Traversal\n");
printf("8.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter Element To Search:");
scanf("%d",&key);
struct Node *node=searchRecursively(p,key);
if(node!=NULL)
{
printf("%d is found at node %d\n",node->data,node->nodeIndex);
}
else
{
printf("Result! Not Found\n");
}
}
if(ch==2)
{
printf("Enter Element To Search:");
scanf("%d",&key);
struct Node *node=searchIteratively(p,key);
if(node!=NULL)
{
printf("%d is found at node %d\n",node->data,node->nodeIndex);
}
else
{
printf("Result! Not Found\n");
}
}
if(ch==3)
{
printf("Enter Element To Insert:");
scanf("%d",&key);
insertNode(p,key);
}
if(ch==4)
{
printf("Enter Element To Delete:");
scanf("%d",&key);
struct Node *node=deleteNode(p,key);
if(node!=NULL) printf("%d is deleted from node index %d\n",key,node->nodeIndex);
else printf("Error! %d is not found in BST\n",key);
}
if(ch==5)
{
preOrderTraversal(p);
printf("\n");
}
if(ch==6)
{
postOrderTraversal(p);
printf("\n");
}
if(ch==7)
{
inOrderTraversal(p);
printf("\n");
}
if(ch==8)
{
break;
}
}
return 0;
}