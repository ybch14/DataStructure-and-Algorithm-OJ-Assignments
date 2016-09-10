#include<stdio.h>
#include<time.h>
#include<cstdlib>
//#include<iostream>
//using namespace std;
int main()
{
	int i=0,j=0,random=0,sum0=0,sum1=0;
	int Array0[100];int Array1[100];
	double pro0[1001],pro1[1001];
	int temp=0;double probability0=0.0,probability1=0.0;
	for(i=0;i<100;i++)
		scanf("%d",&Array0[i]);
	for(i=0;i<100;i++)
		scanf("%d",&Array1[i]);
	for(i=0;i<1000;i++)
	{
		pro0[i]=pro1[i]=0.0;
	}
	srand((unsigned int)time(NULL));
	for(i=0;i<130000;i++)
	{
		for(j=0,sum0=0;j<10;j++)
		{
			random=rand()%100+1;
			sum0=sum0+Array0[random];
		}
		pro0[sum0]++;
		for(j=0,sum1=0;j<10;j++)
		{
			random=rand()%100+1;
			sum1=sum1+Array1[random];
		}
		pro1[sum1]++;
	}
	for(i=0;i<1000;i++)
	{
		for(j=0,probability0=1.0,probability1=1.0;j<100;j++)
		{
			scanf("%d",&temp);
			probability0*=pro0[temp]/1000.0;
			probability1*=pro1[temp]/1000.0;
		}
		if(probability0>probability1)
			printf("%d\n",0);
		else printf("%d\n",1);
	}
	return 0;
}


