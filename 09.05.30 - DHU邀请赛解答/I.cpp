#include<cstdio>
#include<math.h>

long long a,b;
int p[99],i,j;

long long f(long long x)
{
	int i,k;
	long long s,t,j;
	if(x<2)return 1;
	s=x;
	for(i=2;i<99;i++)
	{
		j=(long long)(exp(log(x/1e12+x)/i));
		t=j;
		for(k=1;k<i;k++)t*=j;
		if(t>x)j--;
		s+=p[i]*(j-1);
	}
	return s;
}

int main()
{
	for(i=1;i<99;i++)p[i]=i;
	for(i=2;i<99;i++)
		if(p[i]==i)
			for(j=i;j<99;j+=i)p[j]=p[j]*(i-1)/i;
	while(scanf("%I64d%I64d",&a,&b)&&a)
		printf("%I64d\n",f(b)-f(a-1));
	return 0;
}

