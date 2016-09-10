#include<iostream>
#include<stdio.h>
using namespace std;
class Node
{
public:
	char data;
	Node *left;
	Node *right;
	Node *next;
	Node()
	{
		data=0;
		left=right=next=NULL;
	}
};
int level(char sign)
{
	if(sign=='!')
		return 3;
	else if(sign=='*'||sign=='/')
		return 2;
	else if(sign=='+'||sign=='-')
		return 1;
	else return 0;
}
void cleartree(Node* bt)
{
	if(bt!=NULL)
	{
		cleartree(bt->left);
		cleartree(bt->right);
		delete bt;
		bt=NULL;
	}
}
int main()
{
	long long int i=0;int level(char sign);
	void cleartree(Node *bt);
	char *operate=new char[1000000];
	scanf("%s",operate);
	Node *StackTop=new Node;
	StackTop->data=operate[0];
    Node *q=NULL;Node *r=NULL;
	for(i=1;operate[i]!='\0';i++)
	{
		Node *p=new Node;
		p->data=operate[i];
		if((!(operate[i]>='a'&&operate[i]<='z'))&&operate[i]!='!')
		{
			p->right=StackTop;
			StackTop=StackTop->next;
			p->left=StackTop;
			StackTop=StackTop->next;
			p->next=StackTop;
		    StackTop=p;
			if(level(StackTop->data)>level(StackTop->left->data)
			    &&level(StackTop->left->data)!=0)
		    {
			    q=StackTop->left;
			    while(q->left!=NULL)
				    q=q->left;
			    r=new Node;r->data='(';
			    q->left=r;
			    q=StackTop->left;
			    while(q->right!=NULL)
				    q=q->right;
			    r=new Node;r->data=')';
			    q->right=r;
		    }
		    if(level(StackTop->data)>=level(StackTop->right->data)
			    &&level(StackTop->right->data)!=0)
		    {
			    q=StackTop->right;
			    while(q->left!=NULL)
				    q=q->left;
			    r=new Node;r->data='(';
			    q->left=r;
			    q=StackTop->right;
			    while(q->right!=NULL)
				    q=q->right;
			    r=new Node;r->data=')';
			    q->right=r;
		    }
		}
		else if(operate[i]=='!')
		{
			p->left=StackTop;
			StackTop=StackTop->next;
            p->next=StackTop;
		    StackTop=p;
			if(level(StackTop->data)>level(StackTop->left->data)
			    &&level(StackTop->left->data)!=0)
		    {
			    q=StackTop->left;
			    while(q->left!=NULL)
				    q=q->left;
			    r=new Node;r->data='(';
			    q->left=r;
			    q=StackTop->left;
			    while(q->right!=NULL)
				    q=q->right;
			    r=new Node;r->data=')';
			    q->right=r;
		    }
		}
		else
		{
			p->next=StackTop;
			StackTop=p;
		}
		p=NULL;
	}
	Node *Visit=NULL,*current=StackTop;
	current->next=NULL;
	while(Visit!=NULL||current!=NULL)
	{
		while(current!=NULL)
		{
			current->next=Visit;
			Visit=current;
			current=current->left;
		}
		current=Visit;
		Visit=Visit->next;
		cout<<current->data;
		current=current->right;
	}
	cleartree(StackTop);
	delete []operate;
	return 0;
}