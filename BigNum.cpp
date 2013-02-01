#include<cstdio>
#include<cstring>
#define P 150
#define M 10000
struct bignum
{
	int a[P];
	void operator =(int b)
	{
		int i;
		for (i=0;i<P;i++)a[i]=0;
		a[0]=b;
	}
	void operator =(bignum b)
	{
		int i;
		for (i=0;i<P;i++)a[i]=b.a[i];
	}
	void operator +=(int b)
	{
		a[0]+=b;
	}
	void operator +=(bignum b)
	{
		int i;
		for (i=0;i<P;i++)
		{
			a[i]+=b.a[i];
		}
		int jw=0;
		for (i=0;i<P;i++)
		{
			a[i]+=jw;
			jw=a[i]/M;
			a[i]%=M;
		}
	}
	void operator *=(int b)
	{
		int i;
		for (i=0;i<P;i++)
		{
			a[i]*=b;
		}
		int jw=0;
		for (i=0;i<P;i++)
		{
			a[i]+=jw;
			jw=a[i]/M;
			a[i]%=M;
		}
	}
	void operator *=(bignum b)
	{
		int i,j,c[P];
		for (i=0;i<P;i++)c[i]=0;
		for (i=0;i<P;i++)
		{
			for (j=0;j<P;j++)
			if (i+j<P)
			{
				c[i+j]+=a[i]*b.a[j];
			}
		}
		int jw=0;
		for (i=0;i<P;i++)
		{
			c[i]+=jw;
			jw=c[i]/M;
			c[i]%=M;
		}
		for (i=0;i<P;i++)a[i]=c[i];
	}
	void operator -=(bignum b)
	{
		int i;
		for (i=0;i<P;i++)
		{
			a[i]-=b.a[i];
		}
		for (i=0;i<P;i++)
		{
			while (a[i]<0){a[i]+=M;a[i+1]--;}
		}
	}
	bool cmp(bignum b,bignum c)
	{
		int i;
		for (i=P-1;i>=0;i--)
		{
			if (b.a[i]>c.a[i])return true;
			if (b.a[i]<c.a[i])return false;
		}
		return false;
	}
	void operator /=(bignum b)
	{
		int w1=P-1,w2=P-1;
		while (a[w1]==0&&w1!=0)w1--;
		while (b.a[w2]==0&&w2!=0)w2--;
		int i,j;
		if (w2==0&&b.a[w2]==0){for (i=0;i<P;i++)a[i]=0;a[0]=-1;return;}
		bignum now,bc;
		bc=0;
		for (i=w1;i>w1-w2;i--){bc*=M;bc+=a[i];a[i]=0;}
		for (i=w1-w2;i>=0;i--)
		{
			bc*=M;
			bc+=a[i];
			for (j=0;j<M;j++)
			{
				now=b;
				now*=j;
				if (cmp(now,bc))
				{
					break;
				}
			}
			j--;
			a[i]=j;
			now-=b;
			bc-=now;
		}
	}
	void operator %=(bignum b)
	{
		int w1=P-1,w2=P-1;
		while (a[w1]==0&&w1!=0)w1--;
		while (b.a[w2]==0&&w2!=0)w2--;
		int i,j;
		if (w2==0&&b.a[w2]==0){for (i=0;i<P;i++)a[i]=0;a[0]=-1;return;}
		bignum now,bc;
		bc=0;
		for (i=w1;i>w1-w2;i--){bc*=M;bc+=a[i];a[i]=0;}
		for (i=w1-w2;i>=0;i--)
		{
			bc*=M;
			bc+=a[i];
			for (j=0;j<M;j++)
			{
				now=b;
				now*=j;
				if (cmp(now,bc))
				{
					break;
				}
			}
			now-=b;
			bc-=now;
		}
		for (i=0;i<P;i++)a[i]=bc.a[i];
	}
	void read()
	{
		char x[1000];
		int i;
		gets(x);
		for (i=0;i<P;i++)a[i]=0;
		int now=0,n=0,n1=0,ten=1;
		for (i=strlen(x)-1;i>=0;i--)
		{
			n++;
			now+=(x[i]-'0')*ten;
			ten*=10;
			if (n==4)
			{
				n=0;
				ten=1;
				a[n1]=now;
				n1++;
				now=0;
			}
		}
		a[n1]=now;
	}
	void output()
	{
		int i,w=P-1;
		while (a[w]==0&&w!=0)w--;
		printf("%d",a[w]);
		for (i=w-1;i>=0;i--)
		{
			printf("%.4d",a[i]);
		}
		printf("\n");
	}
};
