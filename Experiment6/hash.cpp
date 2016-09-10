#include<iostream>
using namespace std;
unsigned int BKDRHash(char *str)
{
	unsigned int seed=1313131;
	unsigned int hash=0;
	while(*str)
	{
		hash=hash*seed+(*str++);
	}
	return (hash&0x7FFFFFFF)%800000;
}
unsigned int APHash(char *str)
{
	unsigned int hash=0;
    int i=0;
    for (i=0;*str;i++)
    {
        if ((i&1)==0)
            hash^=((hash<<7)^(*str++)^(hash>>3));
        else
            hash^=(~((hash<<11)^(*str++)^(hash>>5)));
    }
    return (hash&0x7FFFFFFF)%800000;
}
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data=-1;
		next=NULL;
	}
};
class HashList
{
public:
	unsigned int BKDRhash;
	unsigned int APhash;
	Node *head;
	Node *end;
	HashList()
	{
		BKDRhash=-1;
		APhash=-1;
		head=end=NULL;
	}
};
int main()
{
	int i=0;
	HashList *hash=new HashList[800000];
	int *order=new int[800000];
	for(i=0;i<800000;i++)
		order[i]=-1;
	int n=0;cin>>n;
	char *str=new char[1000000];
	Node *p=NULL,*q=NULL;
	for(i=0;i<n;i++)
	{
		cin>>str;
		p=new Node;
		p->data=i;
		unsigned int Hash1=BKDRHash(str);
		unsigned int Hash2=APHash(str);
		if(hash[Hash1].head==NULL)
		{
			hash[Hash1].BKDRhash=Hash1;
			hash[Hash1].APhash=Hash2;
			hash[Hash1].head=p;
			hash[Hash1].end=p;
			order[i]=Hash1;
		}
		else 
		{
			if(Hash2==hash[Hash1].APhash)
			{
				hash[Hash1].end->next=p;
				hash[Hash1].end=p;
			}
			else
			{
				int step=Hash1;
				while((hash[step].APhash!=Hash2||hash[step].BKDRhash!=Hash1)
					&&(hash[step].head!=NULL))
					step++;
				if(hash[step].head==NULL)
				{
					hash[step].BKDRhash=Hash1;
					hash[step].APhash=Hash2;
					hash[step].head=p;
					hash[step].end=p;
					order[i]=step;
				}
				else if(hash[step].APhash==Hash2)
				{
					hash[step].end->next=p;
					hash[step].end=p;
				}
			}
		}
	}
	bool if_repeated=false;
	for(i=0;i<800000;i++)
	{
		if(order[i]>0&&hash[order[i]].head!=hash[order[i]].end)
		{
			q=hash[order[i]].head;
			while(q!=NULL)
			{
				cout<<q->data<<" ";
				q=q->next;
			}
			cout<<endl;
			if_repeated=true;
		}
	}
	if(if_repeated==false)
		cout<<-1;
	return 0;
}