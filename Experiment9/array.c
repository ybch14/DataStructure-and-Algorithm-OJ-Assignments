#pragma GCC optimize(6)
#include<stdio.h>
int main()
{
	int n=0;int i=0,j=0;int power=0;
	int max=0,min=2147483647,maxsize=0,minsize=2147483647;
	int temp1=0,temp2=0;int a[1000000];
	scanf("%d%d",&n,&power);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(power<=0)
	{
		printf("%d\n%d",1,0);
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>=max) max=a[i];
		if(a[i]<=min) min=a[i];
	}
	if(max-min<power)
	{
        printf("%d\n%d",0,n);
		return 0;
	}
	for(i=0,temp1=0;i<n;i++)
	{
		max=0;min=2147483647;
		for(j=i,temp1=0;j<n;j++)
		{
			if(a[j]>=max) max=a[j];
			if(a[j]<=min) min=a[j];
			if(max-min>=power)
			{	
				if(temp1>maxsize)
					maxsize=temp1;
				break;
			}
			temp1++;
		}
		if(maxsize>=n-i-1)
			break;
	}
	for(i=0,temp2=0;i<n;i++)
	{
		max=0;min=2147483647;
		for(j=i,temp2=0;j<n;j++)
		{
			if(a[j]>=max) max=a[j];
			if(a[j]<=min) min=a[j];
			temp2++;
			if(max-min>=power)
			{
				if(temp2<minsize)
					minsize=temp2;
				break;
			}
		}
	}
	if(minsize==2147483647)
		printf("%d",0);
	else printf("%d",minsize);
	if(maxsize==0)
		printf("%d",0);
	else printf("%d",maxsize);
	return 0;
}