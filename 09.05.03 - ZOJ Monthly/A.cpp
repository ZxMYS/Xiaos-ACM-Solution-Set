#include<stdio.h>
#include<iostream>
using namespace std;
long long  n;
int i,t,cases,j;
long long  s[100];
long long  a[100];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
	scanf("%d",&cases);
	s[0]=1;
	for (i=1;i<=11;i++)
		s[i]=s[i-1]*10;
	a[0]=7;
	for (i=1;i<=10;i++)
		a[i]=a[i-1]*10;
	for (t=1;t<=cases;t++)
	{
		scanf("%d",&n);
		i=1;
		while (s[i]<=n)
			i++;
		i--;
		if (n==s[i]) cout<<a[i]<<endl;
		if (n==s[i]+1)
		{
			for (j=1;j<=6;j++)
			{
				if ((a[i]+s[i+1]*j)%7==1)
				{
					cout<<a[i]+s[i+1]*j-1<<endl;
					break;
				}
				else if ((a[i]+s[i+1]*j+s[i])%7==0)
				{
					cout<<a[i]+s[i+1]*j<<endl;
					break;
				}
			}
		}
		if (n==s[i]+2)
		{
			if (i % 6!=3) cout<<a[i+1]<<endl;
			else
			{
				bool flag=1;
				for (j=1;j<=6;j++)
					if (flag)
						if ((a[i]+s[i+1]*j)%7==1 && (a[i]+s[i+1]*j+s[i])%7==0)
						{
							cout<<a[i]+s[i+1]*j-1<<endl;
							flag=0;
						}
				if (flag) cout<<a[i+1]<<endl;
			}
		}
		if (n>s[i]+2) cout<<a[i+1]<<endl;
	}
	return 0;
}
