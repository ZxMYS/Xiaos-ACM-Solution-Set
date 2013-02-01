#include<stdio.h>
long long s[1005];
long long i,m,n,j,cases,t,max,c,ans;
long long gcd(long long x,long long y)
{
	if (x % y==0) return y;
	else return gcd(y,x%y);
}
int main()
{
	scanf("%d",&cases);
	for (t=1;t<=cases;t++)
	{
		max=0;
		scanf("%d",&c);
		for (i=1;i<=c;i++)
		{
			n=0;
			for (j=1;j<=9;j++)
			{
				scanf("%d",&m);
				n+=m;
			}
			scanf("%d",&m);
			if (max<m) max=m;
			n-=m;
			if (n<0) n=-n;
			s[i]=n;
		}
		for (j=1;j<=c;j++)
			if (s[j]>0) break;
		if (j>c)
		{
			printf("impossible\n");
			continue;
		}
		ans=s[j];
		for (i=j+1;i<=c;i++)
			if (s[i]>0)
			{
				if (ans>s[i]) ans=gcd(ans,s[i]);
				else ans=gcd(s[i],ans);
			}
		if (ans==1 || max>=ans)
			printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
