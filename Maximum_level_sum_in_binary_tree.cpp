#include<iostream>
#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
using namespace std;

class Node
{
    public:
        int data;
        Node *left,*right;

        Node(int data)
        {
            this->data=data;
            left=right=NULL;
        }
};

int height(Node *root)
{
    if(root==NULL)
        return 0;
    
    int c1=height(root->left)+1;
    int c2=height(root->right)+1;

    return max(c1,c2);
}

void max_level_sum(Node *root,int level,int & sum)
{
    if(root==NULL)
        return;
    if(level==1)
        sum=sum+root->data;
    else if(level>1)
    {
        max_level_sum(root->left,level-1,sum);
        max_level_sum(root->right,level-1,sum);
    }
}

void levelorder(Node *root)
{
    int h=height(root),max=INT_MIN;

    for(int i=1;i<=h;i++)
    {
        int sum=0;
        max_level_sum(root,i,sum);
        if(max<sum)
            max=sum;
    }
    cout<<"Maximum level sum is "<<max<<endl;
}

int main()
{

	Node* root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
    
	levelorder(root);
}