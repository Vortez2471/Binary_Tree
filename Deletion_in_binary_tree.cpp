#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
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
Node *root=NULL;

void insert(ll t)
{
	Node *temp=root;
	queue<Node*>q;

	while(temp!=NULL)
	{
		if(temp->left==NULL)
		{
			temp->left=new Node(t);
			break;
		}
		else if(temp->right==NULL)
		{
			temp->right=new Node(t);
			break;
		}

		q.push(temp->left);
		q.push(temp->right);
		temp=q.front();
		q.pop();
	}

	if(root==NULL)
	{
		root=new Node(t);
	}
}

int height(Node *flag)
{
	if(flag==NULL)
		return 0;
	int c1=height(flag->left)+1;
	int c2=height(flag->right)+1;

	return max(c1,c2);
}

void print_levelorder(int level,Node *flag)
{
	if(flag==NULL)
		return;
	if(level==1)
		cout<<flag->data<<" ";
	else if(level>0)
	{
		print_levelorder(level-1,flag->left);
		print_levelorder(level-1,flag->right);
	}
}

void levelorder(Node *flag)
{
	int h=height(flag);

	for(int i=1;i<=h;i++)
		print_levelorder(i,flag);
	cout<<endl;
}

void del(ll t)
{
	Node *temp=root,*flag;
	queue<Node*>q;

	while(temp!=NULL)
	{	
		flag=temp;
	
		q.push(temp->left);
		q.push(temp->right);
		temp=q.front();
		q.pop();
	}

	temp=root;
	queue<Node*>q3;

	if(root->data==t)
	{
		root->data=flag->data;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data==t)
			{
				temp->data=flag->data;
				break;
			}
	
			q3.push(temp->left);
			q3.push(temp->right);
			temp=q3.front();
			q3.pop();
		}
	}

	temp=root;
	queue<Node*>q2;

	while(temp!=NULL)
	{
		if(temp->left==flag)
		{
			delete(temp->left);
			temp->left=NULL;
			break;
		}
		else if(temp->right==flag)
		{
			delete(temp->right);
			temp->right=NULL;
			break;
		}

		q2.push(temp->left);
		q2.push(temp->right);
		temp=q2.front();
		q2.pop();
	}
}

int main()
{
	cout<<"Enter the number of entries"<<endl;
	ll n,t;
	cin>>n;
	cout<<"Fill the tree"<<endl;
	for(ll i=0;i<n;i++)
	{
		cin>>t;
		insert(t);
		levelorder(root);
	}

	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the integer to delete"<<endl;
	for(ll i=0;i<n;i++)
	{
		cin>>t;
		del(t);
		levelorder(root);
	}
}