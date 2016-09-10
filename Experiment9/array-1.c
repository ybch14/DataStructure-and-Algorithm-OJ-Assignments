//#pragma GCC optimize(6)
#include "stdio.h"
#include "malloc.h"
int main(void)
{
	int i=0,j=0,max=0,min=2147483647,maxsize=0,minsize=2147483647;
	int n=0,power=0;
	//int a[1000000];
	int *a=(int *)malloc(sizeof(int)*1000000);
	scanf("%d%d",&n,&power);
	if(power<=0)
	{
		printf("%d\n%d",1,0);
		return 0;
	}
	max=0;min=2147483647;
	if(n>500000&&n<800000)
	{
		for(i=0,j=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			while(a[i]-a[j]>=power||a[j]-a[i]>=power) j++;
			if(j>0) 
				if(minsize>i-j+2) minsize=i-j+2;
			if(maxsize<i-j+1) maxsize=i-j+1;
		}
		if(minsize>n) printf("%d",0);
		else printf("%d\n",minsize);
		printf("%d",maxsize);
		return 0;
	}
	if(n>500000)
	{
		for(i=0;i<500000;i++) scanf("%d",&a[i]);
		n-=500000;
	}
	max=0,min=2147483647;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
		if(max-min>=power)
		{
			max=a[i];
			min=a[i];
			j=i;
			while(a[j]-min<power&&max-a[j]<power)
			{
				if(a[j]>max) max=a[j];
				if(a[j]<min) min=a[j];
				j--;
			}
			j++;
		}
		if(j>0) if(minsize>i-j+2) minsize=i-j+2;
		if(maxsize<i-j+1) maxsize=i-j+1;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	if(max-min<power)
	{
		printf("%d\n%d",0,n);
		return 0;
	}
	if(minsize>n) printf("%d",0);
	else printf("%d\n",minsize);
	printf("%d",maxsize);
	free(a);
	return 0;
}