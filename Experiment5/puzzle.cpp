
#include <iostream>
#include <stdio.h>
#define INF 2147483647
using namespace std;
int i=0;int j=0;
class Node
{
public:
	int number;
	int weight;
	bool spt;
	Node *next;
	Node()
	{
		number=0;
		weight=0;
		spt=false;
		next=NULL;
	}
	Node(int n_number,int n_weight)
	{
		number=n_number;
		weight=n_weight;
		spt=false;
		next=NULL;
	}
};
int main()
{
	int n=0,source=0,aim=0;
	scanf("%d",&n);
	scanf("%d",&source);
	scanf("%d",&aim);
	Node node[22501];
	int door[22501];
	int path[22501];
	int wall=0;int weight=0;
	for(i=1;i<=n*n;i++)
	{
		door[i]=0;
		scanf("%d",&weight);
		node[i].number=i;
		node[i].weight=weight;
		if(weight==0)
			cin>>door[i];
		if(weight==-1)
			wall++;
		path[i]=INF;
	}
	Node *pp=NULL;
	for(i=1;i<=n*n;i++)
	{
		if(node[i].weight==-1)
			continue;
		pp=&node[i];
		if((!(i%n==0))&&node[i+1].weight!=-1)
		{pp->next=new Node(i+1,0);pp=pp->next;}
		if((!(i%n==1))&&node[i-1].weight!=-1)
		{pp->next=new Node(i-1,0);pp=pp->next;}
		if((!(i>(n*n-n)))&&node[i+n].weight!=-1)
		{pp->next=new Node(i+n,0);pp=pp->next;}
		if((!(i<=n))&&node[i-n].weight!=-1)
		{pp->next=new Node(i-n,0);pp=pp->next;}
		if(door[i]!=0)
		{pp->next=new Node(door[i],0);pp=pp->next;}
	}
	Node *p=&node[source],*q=NULL;
	while(p->next!=NULL)
	{
		p=p->next;
		path[p->number]=node[source].weight;
	}
	path[source]=0;
	node[source].spt=true;
	int nodecount=1;int min=INF;
	Node *temp=NULL;
	while(nodecount<n*n-wall)
	{
		min=INF;
		for(i=1;i<=n*n;i++)
		{
			if(node[i].spt)
				continue;
			if(path[i]<min)
			{
				min=path[i];
				temp=&node[i];
			}
		}
		temp->spt=true;
		nodecount++;
		q=temp->next;
		while(q!=NULL)
		{
			if((path[temp->number]+node[temp->number].weight)
				<path[q->number]&&node[q->number].spt==false)
				path[q->number]=path[temp->number]+node[temp->number].weight;
			q=q->next;
		}
	}
	cout<<path[aim];
	return 0;
}
