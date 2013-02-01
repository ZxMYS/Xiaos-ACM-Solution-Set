#include<cstdio>
#include<memory>
int n,i,s;
char a[8][9],f[8];

int ck()
{
	char b[8],i,j;
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++)
		if(!b[i])
		{
			j=i;
			while(!b[j])
			{
				b[j]=1;j=f[j];
				if(j<0)break;
			}
			if(j>=0&&b[j]==1)return 0;
			j=i;
			while(b[j]<2)
			{
				b[j]=2;j=f[j];
				if(j<0)break;
			}
		}
	return 1;
}

void tr(char v)
{
	char j,k;
	if(v>=n)s++;
	else
		if(v==i)tr(v+1);
		else
			for(j=0;j<n;j++)
				if(a[j][v]=='1')
				{
					k=j;
					while(f[k]>=0)k=f[k];
					if(k!=v)
					{
						f[v]=j;tr(v+1);f[v]=-1;
					}
				}
}

int main()
{
	memset(f,-1,sizeof(f));
	while(scanf("%d",&n)&&n)
	{
		s=0;
		for(i=0;i<n;i++)
			scanf(" %s",a[i]);
		for(i=0;i<n;i++)tr(0);
		printf("%d\n",s);
	}
	return 0;
}
