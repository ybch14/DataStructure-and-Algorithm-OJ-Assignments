#include<iostream>
using namespace std;
int PJWHash(char *str)
{
    int BitsInUnignedInt=(int)(sizeof(int)*8);
    int ThreeQuarters=(int)((BitsInUnignedInt*3)/4);
    int OneEighth=(int)(BitsInUnignedInt/8);
    int HighBits=(int)(0xFFFFFFFF)<<(BitsInUnignedInt-OneEighth);
    int hash=0;
    int test=0;
    while (*str)
    {
        hash=(hash<<OneEighth)+(*str++);
        if ((test=hash&HighBits)!=0)
            hash=((hash^(test>>ThreeQuarters))&(~HighBits));
    }
    return (hash&0x7FFFFFFF)%700000;
}
int ELFHash(char *str)
{
   	int hash=0;
    int x=0;
    while (*str)
    {
        hash=(hash<<4)+(*str++);
        if ((x=hash&0xF0000000L)!=0)
        {
            hash^=(x>>24);
            hash&=~x;
        }
    }
    return (hash&0x7FFFFFFF)%700000;

}
int BKDRHash(char *str)
{
	int seed=13131;
	int hash=0;
	while(*str)
	{
		hash=hash*seed+(*str++);
	}
	return (hash&0x7FFFFFFF)%700000;
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
	int PJWhash;
	int ELFhash;
	int BKDRhash;
	Node *start;
	Node *end;
	HashList()
	{
		PJWhash=-1;
		ELFhash=-1;
		BKDRhash=-1;
		start=NULL;
		end=NULL;
	}
};
int main()
{
	int i=0,n=0;
	cin>>n;
	char *str=new char[10000000];
	int *order=new int[700000];
	HashList *hash=new HashList[700000];
	Node *p=NULL,*q=NULL;
	for(i=0;i<n;i++)
	{
		cin>>str;
		p=new Node;
		p->data=i;
		int Hash1=PJWHash(str);
		int Hash2=ELFHash(str);
		int Hash3=BKDRHash(str);
		if(hash[Hash1].start==NULL)
		{
			hash[Hash1].PJWhash=Hash1;
			hash[Hash1].ELFhash=Hash2;
			hash[Hash1].BKDRhash=Hash3;
			hash[Hash1].start=p;
			hash[Hash1].end=p;
			order[i]=Hash1;
		}
		else 
		{
			if(Hash2==hash[Hash1].ELFhash)
			{
				if(Hash3==hash[Hash1].BKDRhash)
				{
					hash[Hash1].end->next=p;
					hash[Hash1].end=p;
				}
				else 
				{
					int step=Hash1;
					while((hash[step].PJWhash!=Hash1||hash[step].ELFhash!=Hash2||hash[step].BKDRhash!=Hash3)
						&&(hash[step].start!=NULL))
						step=(step+1)%700000;
					if(hash[step].start==NULL)
					{
						hash[step].PJWhash=Hash1;
						hash[step].ELFhash=Hash2;
						hash[step].BKDRhash=Hash3;
						hash[step].start=p;
						hash[step].end=p;
						order[i]=step;
					}
					else if(hash[step].PJWhash==Hash1&&hash[step].ELFhash==Hash2&&hash[step].BKDRhash==Hash3)
					{
						hash[step].end->next=p;
						hash[step].end=p;
					}
				}
			}
			else
			{
				int step=Hash1;
				while((hash[step].PJWhash!=Hash1||hash[step].ELFhash!=Hash2)
					&&hash[step].start!=NULL)
					step=(step+1)%700000;
				if(hash[step].start==NULL)
				{
					hash[step].PJWhash=Hash1;
					hash[step].ELFhash=Hash2;
					hash[step].start=p;
					hash[step].end=p;
					order[i]=step;
				}
				else if(hash[step].PJWhash==Hash1&&hash[step].ELFhash==Hash2)
				{
					if(Hash3==hash[step].BKDRhash)
					{
						hash[step].end->next=p;
						hash[step].end=p;
					}
					else 
					{
						int step2=step;
						while((hash[step2].PJWhash!=Hash1||hash[step2].ELFhash!=Hash2||hash[step2].BKDRhash!=Hash3)
							&&(hash[step2].start!=NULL))
							step2=(step2+1)%700000;
						if(hash[step2].start==NULL)
						{
							hash[step2].PJWhash=Hash1;
							hash[step2].ELFhash=Hash2;
							hash[step2].BKDRhash=Hash3;
							hash[step2].start=p;
							hash[step2].end=p;
							order[i]=step2;
						}
						else if(hash[step2].PJWhash==Hash1&&hash[step2].ELFhash==Hash2&&hash[step2].BKDRhash==Hash3)
						{
							hash[step2].end->next=p;
							hash[step2].end=p;
						}
					}
				}
			}
		}
	}
	bool flag=false;
	for(i=0;i<700000;i++)
	{
		if(order[i]>0&&hash[order[i]].start!=hash[order[i]].end)
		{
			q=hash[order[i]].start;
			while(q!=NULL)
			{
				cout<<q->data<<" ";
				q=q->next;
			}
			cout<<endl;
			flag=true;
		}
	}
	if(flag==false)
		cout<<-1;
	delete []str;
	delete []order;
	delete []hash;
	return 0;
}