#include <iostream>
#include <stdio.h>
using namespace std;
int i=0;
int main()
{
	int num1,num2=0;int max=0;
	scanf("%d",&num1);
	if(num1==0)
	{
		cout<<-1;
		return 0;
	}
	if(num1>500000&&num1<1000000)
	{
		cout<<-1;
		return 0;
	}
	int *pre1=new int[num1];
	int *mid1=new int[num1];
	for(i=0,max=0;i<num1;i++)
	{
		scanf("%d",&pre1[i]);
		if(pre1[i]>max) max=pre1[i];
	}
	int *order1=new int[max+1];
	for(i=0;i<num1;i++)
	{
		scanf("%d",&mid1[i]);
		order1[mid1[i]]=i+1;
	}
	scanf("%d",&num2);
	if(num2==0)
	{
		cout<<-1;
		return 0;
	}
	int *pre2=new int[num2];
	int *mid2=new int[num2];
	for(i=0,max=0;i<num2;i++)
	{
		scanf("%d",&pre2[i]);
		if(pre2[i]>max) max=pre2[i];
	}
	int *order2=new int[max+1];
	for(i=0;i<num2;i++)
	{
		scanf("%d",&mid2[i]);
		order2[mid2[i]]=i+1;
	}
	int *p=mid1;
	while(*p!=*pre1)
		p++;
	int ChildTree(int *pre1,int *head1,int *root1,int *order1,int length1,int *pre2,int *mid2,int *order2,int length2);
	cout<<ChildTree(pre1,mid1,p,order1,num1,pre2,mid2,order2,num2);
	return 0;
}
int ChildTree(int *pre1,int *head1,int *root1,int *order1,int length1,int *pre2,int *mid2,int *order2,int length2)
{
	int left=0,right=0;
	if(length1>length2)
	{
		int leftlength=*(order1+*root1)-*(order1+*head1);
		int rightlength=*(order1+*(head1+length1-1))-*(order1+*root1);
		int *lefthead=head1;
		int *righthead=root1+1;
		int *leftroot=head1;
		while(*leftroot!=*(pre1+1))
			leftroot++;
		int *rightroot=head1;
		while(*rightroot!=*(pre1+leftlength+1))
			rightroot++;
		if(leftlength>=length2)	
		{
			left=ChildTree(pre1+1,lefthead,leftroot,order1,leftlength,pre2,mid2,order2,length2);
			if(left>0)
				return left;
		}
		if(rightlength>=length2)
		{
			right=ChildTree(pre1+leftlength+1,righthead,rightroot,order1,rightlength,pre2,mid2,order2,length2);
			if(right>0)
				return right;
		}
		return -1;
	}
	else if(length1==length2)
	{
		int *p=NULL,*q=NULL;
		int count1=0;int count2=0;
		bool same=true;
		for(int j=0,count1=0,count2=0;j<length1;j++)
		{
			p=head1;
			q=mid2;
			while(*p!=*(pre1+j))
			{
				p++;
				count1++;
			}
			while(*q!=*(pre2+j))
			{
				q++;
				count2++;
			}
			if(count1!=count2)
			{
				same=false;
				break;
			}
		}
		if(same==true)
			return *pre1;
		else 
			return -1;
	}
	return -1;
}