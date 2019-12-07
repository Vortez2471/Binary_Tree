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

bool path_store(int n,Node* root,vector<int> & vec)
{
	if(root==NULL)
		return false;

	vec.push_back(root->data);


	if(path_store(n,root->left,vec)||path_store(n,root->right,vec)||root->data==n)
		return true;
	
	vec.pop_back();
	return false;
}

void find_lowest_common_ancestor(Node *root,int n1,int n2)
{
	vector<int>v1,v2;

	if(path_store(n1,root,v1)==false||path_store(n2,root,v2)==false)
		cout<<"No answer"<<endl;

	unsigned int i;

	for(i=0;i<v1.size()&&i<v2.size();i++)
	{
		if(v1[i]!=v2[i])
			break;
	}
	cout<<"Lowest common ancestor is "<<v1[i-1]<<endl;

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
  
    int n1,n2;
    cin>>n1>>n2; 

    find_lowest_common_ancestor(root,n1,n2);
}