#include<cstdio>
#include<memory>

int i,m;
char a[8][9],pj[99],pk[99],pl[99],sj[99],sk[99],sl[99];

int ck()
{
	int j,k,l,p,q,r;
	char c[8][9],d[10];
	l=0;
	while(1)
	{
		memset(c,0,sizeof(c));
		r=0;
		for(j=0;j<8;j++)
			for(k=0;k<8;k++)
				if(a[j][k]>47)
				{
					if(!(c[j][k]&1))
					{
						p=j;
						while(p<7&&a[p+1][k]==a[j][k])p++;
						if(p-j>1)
						{
							for(q=j;q<=p;q++)c[q][k]|=1;
							r=1;
						}
					}
					if(!(c[j][k]&2))
					{
						p=k;
						while(p<7&&a[j][p+1]==a[j][k])p++;
						if(p-k>1)
						{
							for(q=k;q<=p;q++)c[j][q]|=2;
							r=1;
						}
					}
				}
		if(!r)break;
		l=1;r=1;
		memset(d,0,sizeof(d));
		for(j=0;j<8;j++)
			for(k=0;k<8;k++)
			{
				if(c[j][k])a[j][k]='.';
				if(a[j][k]>47)
				{
					r=0;
					d[a[j][k]-48]++;
				}
			}
		for(k=0;k<10;k++)
			if(d[k]&&d[k]<3)return 0;
		if(r)
		{
			m=i;
			memcpy(sj,pj,m+1);
			memcpy(sk,pk,m+1);
			memcpy(sl,pl,m+1);
		}
		for(k=0;k<8;k++)
		{
			p=7;
			for(j=7;j>=0;j--)
				if(a[j][k]>47)a[p--][k]=a[j][k];
			for(;p>=0;p--)a[p][k]='.';
		}
	}
	return l;
}

void tr()
{
	int j,k;
	char b[8][9],c;
	if(i>=m)return;
	memcpy(b,a,sizeof(a));
	for(j=0;j<8;j++)
		for(k=0;k<8;k++)
		{
			pj[i]=j;pk[i]=k;
			if(j<7&&a[j][k]!=a[j+1][k])
			{
				c=a[j][k];a[j][k]=a[j+1][k];a[j+1][k]=c;pl[i]=1;
				if(ck())
				{
					i++;tr();i--;
				}
				memcpy(a,b,sizeof(b));
			}
			if(k<7&&a[j][k]!=a[j][k+1])
			{
				c=a[j][k];a[j][k]=a[j][k+1];a[j][k+1]=c;pl[i]=2;
				if(ck())
				{
					i++;tr();i--;
				}
				memcpy(a,b,sizeof(b));
			}
		}
}

int main()
{
	while(1)
	{
		for(i=0;i<8;i++)
		{
			scanf(" %s",a[i]);
			if(a[i][0]=='0')
				return 0;
		}
		m=2;i=1;tr();
		if(m>1)puts("No");
		else puts("Yes");
	}
	return 0;
}


