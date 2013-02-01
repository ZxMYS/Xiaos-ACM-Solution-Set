#include<stdio.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;
int i,j,k,a,b,m,n,s,t,l,tt,cas;
double p,pp;
double f[2][100101];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%lf%d%d",&n,&p,&a,&b);
while (n||p||a||b)
{
	if(!n||!p||!a||!b)
	{
		printf("0.0000\n");
		scanf("%d%lf%d%d",&n,&p,&a,&b);
		continue;
	}
    p/=100;
    pp=1-p;
    for (i = 1;i<=n;i++)
    {
        f[1][i] = pp * f[1][i-1] + p * f[0][i-1];
        f[0][i] = MIN(b + f[0][i-1],f[1][i] + a);
    }
    printf("%.4lf\n",f[1][n]);
    scanf("%d%lf%d%d",&n,&p,&a,&b);
}
return 0;
}
