#include<cstdio>
#include<cstring>
#define MAXL 10010
int T;
char s[MAXL];
int have[MAXL];
int END[MAXL];
int ans;
void print()
{
	if (ans==1)ans=0;
	printf("%d\n",ans);
}
inline int max(int x,int y)
{
	return x>y?x:y;
}
void solve()
{
	int i,j,cnt,k;
	int l=strlen(s);
	for (i=0;i<=l-T;i++)
	{
		cnt=0;
		memset(have,0,sizeof(have));
		memset(END,0,sizeof(END));
		for (j=0;j<=l;j++)END[j]=-1;
		for (j=0;j<l;j++)
		if (s[j]==s[i])
		{
			cnt=0;
			for (k=0;j+k<l&&i+k<l;k++)
			if (s[j+k]==s[i+k])
			{
				cnt++;
				if (j>END[cnt])
				{
					have[cnt]++;
					END[cnt]=max(END[cnt],j+k);
				}
			}
			else break;
		}
		for (j=T;j<=l;j++)
		if (have[j]>ans)ans=have[j];
	}
}
void init()
{
	scanf("%d\n",&T);
	gets(s);
}
int main()
{
	init();
	solve();
	print();
	return 0;
}
