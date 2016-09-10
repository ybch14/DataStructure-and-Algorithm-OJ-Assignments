#include <iostream>
#include <cmath>
using namespace std;
int i=0,j=0;
int main()
{
	int n=0;
	bool *prime=new bool[10000000];
	for(i=0;i<10000000;i++)
		prime[i]=1;
	cin>>n;
	for(i=0;i<sqrt(n);i++)
	{
		if(prime[i])
		{
			for(j=3*i+3;j<=n;j+=2*i+3)
				prime[j]=0;
		}
	}
	int count=0;i=4;
	while(count!=n)
	{
		if(i%2==0) count++;
		else if(prime[(i-5)/2]==1) count++;
		i++;
	}
	cout<<i-1<<endl;
	delete []prime;
	return 0;
}