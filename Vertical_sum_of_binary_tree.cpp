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

unordered_map<int,int>m;

void vertical_indexing(Node *temp,int index)
{
	if(temp==NULL)
		return;

	if(m.find(index)==m.end())
		m[index]=temp->data;
	else
		m[index]=m[index]+temp->data;

	vertical_indexing(temp->left,index-1);
	vertical_indexing(temp->right,index+1);
}

void print_vertical_sum(Node *temp)
{
	vertical_indexing(temp,0);

	pair<int,int>min=*min_element(m.begin(),m.end());
	pair<int,int>max=*max_element(m.begin(),m.end());

	//cout<<min.first<<" "<<max.first<<endl;

	/*
	for(int i=min.first;i<=max.first;i++)
	{
		cout<<i<<" : "<<m[i]<<endl;
	}
	*/
	for(int i=min.first;i<=max.first;i++)
	{
		cout<<m[i]<<" ";
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