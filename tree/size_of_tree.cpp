#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>




struct node {
int data ;

struct node *left;

struct node *right;

};


struct node * newNode(int data)
{

struct node * node  = (struct node * )malloc(sizeof(struct node));

node->data = data;
node->left = NULL;
node->right = NULL;

return(node); 



}



int size(struct node *root)
{

if (root == NULL)
return 0;

else
return (1+size(root->left)+size(root->right));

}


// driver program to test indenticalTrees function
int main()
{

struct node * root1 = newNode(1);

root1->left = newNode(2);
root1->right = newNode(3);
struct node * root2 = newNode(1);

int s = size(root1);
int s2 = size(root2);
printf("%d\n",s);
printf("%d\n",s2);



}

