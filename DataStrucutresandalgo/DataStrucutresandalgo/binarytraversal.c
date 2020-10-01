#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
void inorder(struct node* n)
{
	if(n==NULL)
	return;
	
	inorder(n->left);
	
	printf("%d",n->data);
	
	inorder(n->right);
}
void postorder(struct node *n)
{
	if(n==NULL)
	return;
	postorder(n->left);
	postorder(n->right);
	printf("%d",n->data);
}
void preorder(struct node *n)
{
	if(n==NULL)
	return;
	printf("%d ",n->data);
	preorder(n->left);
	preorder(n->right);
}
struct node *newnode(int info)
{
	struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->left=NULL;
    n->right=NULL;
    n->data=info;
    return n;
}
void main()
{
	struct node *root;
	root=newnode(1);
	root->left=newnode(5);
	root->right=newnode(2);
	root->left->right=newnode(6);
	root->left->left=newnode(9);
	root->right->left=newnode(3);
	root->right->right=newnode(4);
	preorder(root);
	postorder(root);
	inorder(root);
}
