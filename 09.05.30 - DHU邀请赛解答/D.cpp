#include<cstdio>
#include<cmath>

int n,p,a,b;
double k,l;

int main()
{
	while(scanf("%d%d%d%d",&n,&p,&a,&b)&&n+p+a+b)
	{
		if(!n||!p||!a||!b)
		{
			puts("0.0000");
			continue;
		}
		k=n-1;b*=100;l=log(1-p/1e2);
		if(b>a*p)
		{
			k=log((b-a*p+0.0)/b)/l;
			if(k>n-1)k=n-1;
		}
		k=int(k+1);
		printf("%.4lf\n",(a*p*(n-k)+k*b)/1e2-(1-exp(k*l))*b/p);
	}
	return 0;
}

