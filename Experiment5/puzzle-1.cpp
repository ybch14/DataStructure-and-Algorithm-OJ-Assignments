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
	int path;
	bool spt;
	Node *next;
	Node()
	{
		number=0;
		weight=0;
		path=INF;
		spt=false;
		next=NULL;
	}
	Node(int n_number,int n_weight)
	{
		number=n_number;
		weight=n_weight;
		path=INF;
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
	Node *node=new Node[n*n+1];
	int *door=new int[n*n+1];
	for(i=0;i<=n*n;i++)
		door[i]=0;
	int wall=0;
	for(i=1;i<=n*n;i++)
	{
		int weight;
		scanf("%d",&weight);
		node[i].number=i;
		node[i].weight=weight;
		if(weight==0)
			cin>>door[i];
		if(weight==-1)
			wall++;
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
	delete []door;
	Node **heap=new Node*[n*n+1];heap[0]=NULL;
	for(i=1;i<=n*n;i++)
		heap[i]=&node[i];
	Node *p=&node[source],*q=NULL;
	while(p->next!=NULL)
	{
		p=p->next;
		node[p->number].path=node[source].weight;
	}
	node[source].spt=true;
	int nodecount=0;
	Node *temp=NULL;
	int *path=new int[n*n+1];
	for(i=1;i<=n*n;i++)
		path[i]=INF;
	int k=1;
	int ii=2*k;
	while(ii<=n*n)		
	{
		if(ii<=n*n-1&&(INF-heap[ii]->path)<(INF-heap[ii+1]->path))
			ii++;
		if((INF-heap[k]->path)>(INF-heap[ii]->path)) break;
		temp=heap[ii];
		heap[ii]=heap[k];
		heap[k]=temp;
		k=ii;
		ii=2*k;
	}
	while(nodecount<n*n-wall)
	{
		node[heap[1]->number].spt=true;
		nodecount++;
		q=node[heap[1]->number].next;
		while(q!=NULL)
		{
			if((double)(node[heap[1]->number].path+node[heap[1]->number].weight)
					<(double)node[q->number].path&&node[q->number].spt==false)
			{
			    node[q->number].path=node[heap[1]->number].path+node[heap[1]->number].weight;
				path[q->number]=node[q->number].path;
				int k=1;
				int ii=2*k;
				while(ii<=n*n)		
				{
					if(ii<=n*n-1&&(INF-heap[ii]->path)<(INF-heap[ii+1]->path))
						ii++;
					if((INF-heap[k]->path)>(INF-heap[ii]->path)) break;
					temp=heap[ii];
					heap[ii]=heap[k];
					heap[k]=temp;
					k=ii;
					ii=2*k;
				}
			}
			q=q->next;
		}
        node[heap[1]->number].path=INF;
		int k=1;
		int ii=2*k;
		while(ii<=n*n)	
		{
			if(ii<=n*n-1&&(INF-heap[ii]->path)<(INF-heap[ii+1]->path))
				ii++;
			if((INF-heap[k]->path)>(INF-heap[ii]->path)) break;
			temp=heap[ii];
			heap[ii]=heap[k];
			heap[k]=temp;
			k=ii;
			ii=2*k;
	    }
	}
	path[source]=0;
	cout<<path[aim];
	return 0;
}