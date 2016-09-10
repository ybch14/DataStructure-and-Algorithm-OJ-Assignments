#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
	double a=0.0,b=0.0,c=0.0;
	cin>>a>>b>>c;
	if(b*b-4*a*c<0)
	{
		cout<<0<<endl<<0<<endl;
		return 0;
	}
	if(c==0)
	{
		printf("0\n");
		double x=-b/a;
		printf("%.16e\n",x);
	}
	else
	{
		double x1=0.0,x2=0.0;
		if(b>0)
		{
			x1=(-b-sqrt(b*b-4*a*c))/(2*a);
			x2=(2*c)/(-b-sqrt(b*b-4*a*c));
			x1=x1-(a*x1*x1+b*x1+c)/(2*a*x1+b);
			x2=x2-(a*x2*x2+b*x2+c)/(2*a*x2+b);
			printf("%.16e\n",x1);
			printf("%.16e\n",x2);
		}
		else if(b<=0)
		{
			x1=(-b+sqrt(b*b-4*a*c))/(2*a);
			x2=(2*c)/(-b+sqrt(b*b-4*a*c));
			x1=x1-(a*x1*x1+b*x1+c)/(2*a*x1+b);
			x2=x2-(a*x2*x2+b*x2+c)/(2*a*x2+b);
			x1=x1-(a*x1*x1+b*x1+c)/(2*a*x1+b);
			x2=x2-(a*x2*x2+b*x2+c)/(2*a*x2+b);
			printf("%.16e\n",x1);
			printf("%.16e\n",x2);
		}
	}
	return 0;
}