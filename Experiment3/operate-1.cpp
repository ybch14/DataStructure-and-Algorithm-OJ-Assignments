#include<iostream>
using namespace std;
class Node
{
public:
	char data;
	Node *Listnext;
	Node()
	{
		data=0;
		Listnext=NULL;
	}
};
class List
{
public:
	Node *head;
	Node *end;
	List *Stacknext;
	char sign;
	List()
	{
		head=NULL;
		end=NULL;
		Stacknext=NULL;
		sign=0;
	}
};
int level(char sign)
{
	if(sign=='+'||sign=='-')
		return 1;
	else if(sign=='*'||sign=='/')
		return 2;
	else if(sign=='!')
		return 3;
	else return 4;
}
int main()
{
	char *operate=new char[1000000];
	cin>>operate;
	List *top=NULL;
	List *temp1=NULL,*temp2=NULL;
	for(long long int i=0;operate[i]!='\0';i++)
	{
		Node *p=new Node;p->data=operate[i];
		List *newlist=new List;
		if(operate[i]>='a'&&operate[i]<='z')
		{
			newlist->head=p;
			newlist->end=p;
		}
		else if((!(operate[i]>='a'&&operate[i]<='z'))&&(operate[i]!='!'))
		{
			temp2=top;
			top=top->Stacknext;
			temp2->Stacknext=NULL;
			temp1=top;
			top=top->Stacknext;
			temp1->Stacknext=NULL;
			if(level(operate[i])>level(temp1->sign))
			{
				Node *left=new Node;
				left->data='(';
				left->Listnext=temp1->head;
				temp1->head=left;
			    Node *right=new Node;
				right->data=')';
				temp1->end->Listnext=right;
				temp1->end=right;
			}
			if(level(operate[i])>=level(temp2->sign))
			{
				Node *left=new Node;
				left->data='(';
				left->Listnext=temp2->head;
				temp2->head=left;
			    Node *right=new Node;
				right->data=')';
				temp2->end->Listnext=right;
				temp2->end=right;
			}
			temp1->end->Listnext=p;
			p->Listnext=temp2->head;
			newlist->sign=p->data;
			newlist->head=temp1->head;
			newlist->end=temp2->end;
			delete temp1;
			delete temp2;
		}
		else if(operate[i]=='!')
		{
			temp1=top;
			top=top->Stacknext;
			temp1->Stacknext=NULL;
			if(3>level(temp1->sign))
			{
				Node *left=new Node;
				left->data='(';
				left->Listnext=temp1->head;
				temp1->head=left;
			    Node *right=new Node;
				right->data=')';
				temp1->end->Listnext=right;
				temp1->end=right;
			}
			temp1->end->Listnext=p;
			newlist->head=temp1->head;
			newlist->end=p;
			delete temp1;
		}
		newlist->Stacknext=top;
		top=newlist;
	}
	Node *p=top->head;Node *q=p->Listnext;
	while(p!=NULL)
	{
		cout<<p->data;
		q=p->Listnext;
		delete p;
		p=q;
	}
	delete []operate;
	return 0;
}
