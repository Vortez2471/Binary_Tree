#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int p)
	{
		this->data=p;
		left=right=NULL;
	}
};
Node*root=NULL;

void preorder(Node* flag)
{
	if(flag==NULL)
		return;
	else
	{
		cout<<flag->data<<" ";
		preorder(flag->left);
		preorder(flag->right);
	}
}

void inorder(Node* flag)
{
	if(flag==NULL)
		return;
	else
	{
		inorder(flag->left);
		cout<<flag->data<<" ";
		inorder(flag->right);
	}
}

void postorder(Node* flag)
{
	if(flag==NULL)
		return;
	else
	{
		postorder(flag->left);
		postorder(flag->right);
		cout<<flag->data<<" ";		
	}
}

int main()
{
	root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	cout<<"Preorder traversal of binary tree"<<endl;
	preorder(root);
	cout<<endl;
	cout<<"Inorder traversal of binary tree"<<endl;
	inorder(root);
	cout<<endl;
	cout<<"Postorder traversal of binary tree"<<endl;
	postorder(root);
	cout<<endl;
}