#pragma GCC optimize(3)
#include<stdio.h>
#include<malloc.h>
int MaxLegalSubArray(int *a,int n,int power)
{
	if(n==1)
		return 1;
	else
	{
	//0为默认情况，1为到了终点之前遇到非法的情况
	int i=0;int flag=0;
	int max=0,min=2147483647;int temp1=0,temp2=0;
	int left=n/2-1,right=n/2;
	int maxsize=0;
	for(i=0;left>=0&&right<=n;i++)
	{
		if(a[left]>max) max=a[left];
		if(a[left]<min) min=a[left];
		if(a[right]>max) max=a[right];
		if(a[right]<min) min=a[right];
		if(max-min>=power) 
		{
			flag=1;
			break;
		}
		left--;
		right++;
	}
	if(!flag) return n;
	if(max==a[left]||min==a[left])
	{
		for(i=0;right<n;i++)
		{
			if(a[right]>max) max=a[right];
			if(a[right]<min) min=a[right];
			if(max-min>=power) break;
			right++;
		}
	}
	if(max==a[right]||min==a[right])
	{
		for(i=0;left>0;i++)
		{
			if(a[left]>max) max=a[left];
			if(a[left]<min) min=a[left];
			if(max-min>=power) break;
			left--;
		}
	}
	maxsize=right-left;
	if(maxsize>n-n/2) return maxsize;
	temp1=MaxLegalSubArray(a,n/2,power);
	temp2=MaxLegalSubArray(a+n/2,n-n/2,power);
	if(temp1>maxsize) 
		maxsize=temp1;
	if(temp2>maxsize)
		maxsize=temp2;
	return maxsize;
	}
}
int MinIllegalSubArray(int *a,int n,int power)
{
	if(n==1)
		return 2147483647;
	else
	{
	int flag=0;//0为默认情况，1为到了终点遇到了非法的情况
	int i=0;
	int max=0,min=2147483647;int temp1=0,temp2=0;
	int left=n/2-1,right=n/2;
	int minsize=2147483647;
	for(i=0;left>=0&&right<=n;i++)
	{
		if(a[left]>max) max=a[left];
		if(a[left]<min) min=a[left];
		if(a[right]>max) max=a[right];
		if(a[right]<min) min=a[right];
		if(max-min>=power) 
		{
			flag=1;
			break;
		}
		left--;
		right++;
	}
	if(!flag) return 0;
	if(max==a[left]||min==a[left])
	{
		for(i=0;right>=n/2+1;i++)
		{
			if(a[right]>max) max=a[right];
			if(a[right]<min) min=a[right];
			if(max-min>=power) break;
			right--;
		}
	}
	if(max==a[right]||min==a[right])
	{
		for(i=0;left<=n/2;i++)
		{
			if(a[left]>max) max=a[left];
			if(a[left]<min) min=a[left];
			if(max-min>=power) break;
			left++;
		}
	}
	minsize=right-left+1;
	temp1=MinIllegalSubArray(a,n/2,power);
	temp2=MinIllegalSubArray(a+n/2,n-n/2,power);
	if(temp1<minsize) 
		minsize=temp1;
	if(temp2<minsize)
		minsize=temp2;
	if(minsize==2147483647)
		minsize=0;
	return minsize;
	}
}
int main()
{
	int n=0,power=0;int i=0;int *a=(int *)malloc(sizeof(int)*1000000);
	int max=0,min=2147483647;
	scanf("%d%d",&n,&power);
	if(power<=0)
	{
		printf("%d\n%d",1,0);
		return 0;
	}
	printf("%d\n",MinIllegalSubArray(a,n,power));
	printf("%d\n",MaxLegalSubArray(a,n,power));
	return 0;
}