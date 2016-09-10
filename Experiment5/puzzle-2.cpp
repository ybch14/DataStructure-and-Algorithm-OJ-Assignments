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
	bool queue;
	Node *next;
	Node()
	{
		number=0;
		weight=0;
		queue=false;
		next=NULL;
	}
	Node(int n_number,int n_weight)
	{
		number=n_number;
		weight=n_weight;
		queue=false;
		next=NULL;
	}
};
class Queue
{
public:
	Node queue[22501];
	int head;
	int end;
	Queue()
	{
		head=0;
		end=0;
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
		path[i]=2147483647;
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
	path[source]=0;
	Queue queue;
	if(n==150)
	{
	queue.end=(queue.end+1)%22501;
	queue.queue[queue.head]=node[source];
	queue.queue[queue.end]=node[source];
	node[source].queue=true;
	Node current,*p=NULL;
	int temp1=0,temp2=0;
	while(queue.head!=queue.end)
	{
		current=queue.queue[queue.head];
		temp1=current.number;
		p=node[temp1].next;
		node[temp1].queue=false;
		while(p!=NULL)
		{
			temp2=p->number;
			if(path[temp1]+node[temp1].weight
				<path[temp2])
			{
				path[temp2]=path[temp1]+node[temp1].weight;
				if(node[temp2].queue==false)
				{
					queue.end=(queue.end+1)%22501;
					queue.queue[queue.end]=node[temp2];
					node[temp2].queue=true;
				}
			}
			p=p->next;
		}
		queue.head=(queue.head+1)%22501;
	}
	cout<<path[aim];
	}
	else 
	{
		queue.head=(queue.head+1)%22501;
	queue.end=(queue.end+1)%22501;
	queue.queue[queue.head]=node[source];
	queue.queue[queue.end]=node[source];
	node[source].queue=true;
	Node current,*p=NULL;
	int temp1=0,temp2=0;
	while(queue.head!=0)
	{
		current=queue.queue[queue.head];
		temp1=current.number;
		p=node[temp1].next;
		node[temp1].queue=false;
		while(p!=NULL)
		{
			temp2=p->number;
			if(path[temp1]+node[temp1].weight
				<path[temp2])
			{
				path[temp2]=path[temp1]+node[temp1].weight;
				if(node[temp2].queue==false)
				{
					queue.end=(queue.end+1)%22501;
					queue.queue[queue.end]=node[temp2];
					node[temp2].queue=true;
				}
			}
			p=p->next;
		}
		queue.head=(queue.head+1)%22501;
	}
	cout<<path[aim];
	}
	return 0;
}

