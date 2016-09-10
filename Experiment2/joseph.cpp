#include<iostream>
using namespace std;
int i=0,j=0;
struct Node
{
	int number;
	Node *next;
	Node *previous;
};
class List
{
public:
	Node *head;
	List();
	~List();
	int ListLen();//get length of list
	void InsertList(Node *Location,int iNumber);//insert a node after Location
	void DeleteList(Node *Location);//delete the node after Location
	Node *FindList(int iValue);//get the node whose number is iValue
	bool IsEmpty();
};
List::List()
{
	head=NULL;
}
List::~List()
{
	Node *p1=head,*p2;
	while(p1->next!=head)
	{
		p2=p1;p1=p1->next;delete p2;
	}
	delete p1;
	head=NULL;
}
int List::ListLen()
{
	Node *p=head;int len=0;
	while(p->next!=head)
	{
		p=p->next;len++;
	}
	return len+1;
}
void List::InsertList(Node *Location,int iNumber)
{
	Node *temp=new Node;
	temp->number=iNumber;
	if(head==NULL)
	{
		head=temp;
		temp->next=temp;temp->previous=temp;
		return ;
	}
	temp->next=Location->next;
	temp->previous=Location;
	Location->next=temp;
	temp->next->previous=temp;
}
void List::DeleteList(Node *Location)
{
	Location->previous->next=Location->next;
    Location->next->previous=Location->previous;
	delete Location;
	Location=NULL;
}
Node *List::FindList(int iValue)
{
	Node *p=head;
	while(p!=NULL)
	{
		if(p->number==iValue)
			return p;
		else p=p->next;
	}
	cerr<<"The item doesn't exist!"<<endl;
	return NULL;
}
bool List::IsEmpty()
{
	return head==NULL;
}
int main()
{
	int n=0,m=0,k=0,l=0;
	cin>>n>>m>>k>>l;
	List joseph;
	joseph.InsertList(joseph.head,1);
    Node *p=joseph.head;Node *buffer=NULL;
	for(i=1;i<m;i++)
		joseph.InsertList(joseph.head->previous,i+1);
	p=joseph.FindList(k);
	for(i=m+1;i<=n;i++)
	{
		for(j=1;j<l;j++)
			p=p->next;
		joseph.InsertList(p,i);
		p=p->next;
	}
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<l-1;i++)
			p=p->next;
		p=p->previous;
		buffer=p->next;
        joseph.DeleteList(p);
		p=buffer;
		p=p->next;
	}
	cout<<p->number<<endl;
	joseph.head=p;
	return 0;
}