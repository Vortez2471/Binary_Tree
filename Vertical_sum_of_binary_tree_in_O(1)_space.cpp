#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
#include<unordered_set>
#define ll long long
using namespace std;

class Node
{
	public:
		int data;
		Node* left,*right;

		Node(int data)
		{
			this->data=data;
			left=right=NULL;
		}
};

class DNode
{
	public:
		int data;
		DNode *llink,*rlink;

		DNode(int data)
		{
			this->data=data;
			llink=rlink=NULL;
		}
};


void vertical_indexing(Node *temp,DNode *head)
{

	if(temp->left)
	{
		if(head->llink!=NULL)
			head->llink->data=temp->left->data+head->llink->data;
		else
		{
			head->llink=new DNode(temp->left->data);
			head->llink->rlink=head;
		}
		vertical_indexing(temp->left,head->llink);
	}

	if(temp->right)
	{
		if(head->rlink!=NULL)
			head->rlink->data=temp->right->data+head->rlink->data;
		else
		{
			head->rlink=new DNode(temp->right->data);
			head->rlink->llink=head;
		}
		vertical_indexing(temp->right,head->rlink);
	}
}

void print_vertical_sum(Node *temp)
{
	DNode *head=new DNode(temp->data);
	vertical_indexing(temp,head);

	DNode* flag=head;
	while(head->llink!=NULL)
	{
		head=head->llink;
	}
	flag=head;
	while(flag!=NULL)
	{
		cout<<flag->data<<" ";
		flag=flag->rlink;
	}
}

int main()
{
	Node* root=new Node(10); 
    root->left=new Node(20); 
    root->right=new Node(30); 
    root->left->left=new Node(40); 
    root->left->right=new Node(50); 
    root->right->left=new Node(60); 
    root->right->right=new Node(70); 
  
    print_vertical_sum(root);
}