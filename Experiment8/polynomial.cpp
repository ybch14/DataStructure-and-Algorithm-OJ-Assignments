#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m=0,n=0,i=0,j=0,k=0;
	cin>>m>>n;
	double **matrix=new double*[m];
	for(i=0;i<m;i++)
		matrix[i]=new double[n];
	double *x=new double[m];
	double *y=new double[m];
	for(i=0;i<m;i++)
		cin>>x[i]>>y[i];
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			double temp=1.0;
			for(k=0;k<j;k++)
				temp*=x[i];
			matrix[i][j]=temp;
		}
	}
	delete []x;
	double *v=new double[m];
	double length=0.0;double temp1=0.0,temp2=0.0;
	for(j=0,temp2=0.0;j<n;j++)
	{
		for(i=j,length=0.0;i<m;i++)
			length+=matrix[i][j]*matrix[i][j];
		length=sqrt(length);
		if(matrix[j][j]>0)
			length=-length;
		for(i=0;i<m;i++)
			v[i]=matrix[i][j];
		for(i=0;i<j;i++)
			v[i]=0.0;
		v[j]=matrix[j][j]-length;
		for(i=0,temp2=0.0;i<m;i++)
			temp2+=v[i]*v[i];
		for(k=j;k<n;k++)
		{
			for(i=0,temp1=0.0;i<m;i++)
				temp1+=v[i]*matrix[i][k];	
			for(i=0;i<m;i++)
				matrix[i][k]=matrix[i][k]-2*temp1/temp2*v[i];
		}
		for(i=0,temp1=0.0;i<m;i++)
			temp1+=v[i]*y[i];
		for(i=0;i<m;i++)
			y[i]=y[i]-2*temp1/temp2*v[i];
	}
	double *a=new double[n];
	//a[n-1]=y[n-1]/matrix[n-1][n-1];
	for(i=1;i<=n;i++)
	{
		a[n-i]=y[n-i]/matrix[n-i][n-i];
		for(j=n-i-1;j>=0;j--)
		{
			y[j]=y[j]-matrix[j][n-i]*a[n-i];
			matrix[j][n-i]=0.0;
		}
	}
	for(i=0;i<n;i++)
		cout<<(int)(a[i]+0.5)<<endl;
	return 0;
}
