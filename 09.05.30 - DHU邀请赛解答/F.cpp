#include<cstdio>
#include<memory>
#include<algorithm>
using namespace std;

const int mx=1009;
int a[mx][mx],b[mx],c[mx],i,j,k,l,m,p;

bool cmp(int i,int j)
{
	int k;
	if(c[i]!=c[j])return c[i]<c[j];
	for(k=0;k<c[i];k++)
		if(a[i][k]!=a[j][k])break;
	if(labs(a[i][k])!=labs(a[j][k]))
		return labs(a[i][k])<labs(a[j][k]);
	return a[i][k]<a[j][k];
}

int main()
{
	a[1][1]=1;a[1][0]=-1;c[1]=1;
	for(i=2;i<mx;i++)
	{
		k=i;p=i;
		for(j=2;j*j<=p;j++)
			if(p%j<1)
			{
				k=k*(j-1)/j;
				while(p%j<1)p/=j;
			}
		if(p>1)k=k*(p-1)/p;
		c[i]=k;
		for(j=2;j*j<=i;j++)
			if(i%j<1&&k/j==c[i/j])
			{
				for(l=0;l<=i/j;l++)
					a[i][l*j]=a[i/j][l];
				break;
			}
		if(j*j>i)
		{
			a[i][i]=1;a[i][0]=-1;p=i;
			for(j=1;j<=i/2;j++)
				if(i%j<1)
				{
					memset(b,0,p*4+4);
					for(k=p-c[j];k>=0;k--)
					{
						b[k]=a[i][k+c[j]];
						for(l=0;l<=c[j];l++)
							a[i][k+l]-=b[k]*a[j][l];
					}
					memcpy(a[i],b,i*4+4);
					p-=c[j];
				}
		}
		for(j=0;j<=c[i];j++)
		{
			if(abs(a[i][j])>m)
			{
				m=abs(a[i][j]);
			}
		}
	}
	for(i=0;i<mx;i++)b[i]=i;
	sort(b,b+mx,cmp);
	while(scanf("%d",&p)&&p)
	{
		l=0;
		for(k=1;k<mx;k++)
		{
			i=b[k];
			if(p%i<1)
			{
				if(p>1)printf("(");
				for(j=c[i];j>=0;j--)
					if(a[i][j])
					{
						if(a[i][j]>0&&j<c[i])printf("+");
						if(a[i][j]<0)printf("-");
						if(labs(a[i][j])>1)printf("%d",labs(a[i][j]));
						if(j)printf("x");
						if(!j)printf("1");
						if(j>1)printf("^%d",j);
					}
				if(p>1)printf(")");
			}
		}
		puts("");
	}
	return 0;
}

