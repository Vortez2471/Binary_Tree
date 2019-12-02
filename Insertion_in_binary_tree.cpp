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

int height(Node* flag)
{
	if(flag==NULL)
		return 0;

	int c1=height(flag->left)+1;
	int c2=height(flag->right)+1;

	return max(c1,c2);
}

void print_levelorder(Node* flag,int level)
{
	if(flag==NULL)
		return;
	if(level==1)
		cout<<flag->data<<" ";
	else if(level>1)
	{
		print_levelorder(flag->left,level-1);
		print_levelorder(flag->right,level-1);
	}
}


void levelorder(Node* flag)
{
	//O(n^2) in worst case
	int h=height(flag);
	for(int i=1;i<=h;i++)
		print_levelorder(flag,i);
	cout<<endl;
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
}