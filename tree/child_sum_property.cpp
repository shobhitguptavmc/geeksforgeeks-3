#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <queue>

struct node {

int data;

struct node *left;

struct node *right;

};


// Helper function to create a tree node 

struct node * newNode(int data)
{

struct node * node = (struct node *)malloc(sizeof(struct node));

node->data = data;

node->left = NULL;

node->right = NULL;
return (node);
}

int isSumProperty(struct node *root)
{
if(root->left == NULL && root->right == NULL)
return 0;
int l=0,r=0;
std::queue<struct node *> q; 
q.push(root);
//printf("root is pushed\n");
while(!q.empty())
{

struct node * t = q.front();
if(t->left == NULL && t->right == NULL && q.empty())
return 1;
q.pop();
//printf("within while loop\n");
printf("root = %d\n",t->data);
if(t->left != NULL)
  {q.push(t->left);
	 l = t->left->data;
printf(" l= %d",l);
}
if (t->right != NULL)
{q.push(t->right);

 r = t->right->data;
printf(" r= %d",r);
}
if ((t->data != (l+r)) && (t->left || t->right))
{
return 0;
}
else{l=0;r=0;}
}

return 1;

}







// driver program to test indenticalTrees function
int main()
{

struct node * root = newNode(10);

root->left = newNode(2);
root->right = newNode(8);
root->right->left = newNode(3);
root->right->right = newNode(5);
//root->right->left = newNode(2);
//root->right->right = newNode(2);
int i = isSumProperty(root);
//printf("%d\t",i);
if(i)
printf("BT satisfies Childern sum property\n");
else
printf("No Child sum property exist");

return 0;

}

