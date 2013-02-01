#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <cstring>
using namespace std;
#define MAXN 12
#define MAXM 5010
int n;
char str[MAXN][100];
int len[MAXN+1];
int m;
char text[MAXM];

bool match[MAXM][MAXN];
bool f[MAXM][1<<MAXN];
int cnt[MAXM];
short avails[MAXM][1<<MAXN];
int ans;

int main()
{
	while (scanf("%d%d",&n,&m) && n)
	{
		gets(text);
		for (int i=0;i<n;i++)
			len[i]=strlen(gets(str[i]));
		len[n]=0x7FFFFFFF;
		for (int i=0;i<n;i++)
			for (int j=i+1;j<n;j++)
				if (len[i]>len[j])
				{
					swap(len[i],len[j]);
					char temp[100];
					strcpy(temp,str[i]);
					strcpy(str[i],str[j]);
					strcpy(str[j],temp);
				}
		for (int i=0;m;m--)
		{
			gets(text+i);
			i+=strlen(text+i);
		}
		m=strlen(text);
		memset(match,false,sizeof(match));
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (i+len[j]<=m && !strncmp(text+i,str[j],len[j])) match[i][j]=true;
		memset(f,false,sizeof(f));
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<=m;i++)
		{
			f[i][0]=true;
			avails[i][cnt[i]++]=0;
		}
		for (int i=m;i;i--)
			for (int j=0;j<cnt[i];j++)
			{
				int s=avails[i][j];
				int p,q;
				for (int k=0;len[k]<=i;k++)
				{
					p=i-len[k];
					q=s|(1<<k);
					if (q!=s && match[p][k])
					{
						if (!f[p][q]) avails[p][cnt[p]++]=q;
						f[p][q]=true;
					}
				}
			}
		ans=0;
		for (int i=0;i<m;i++)
			if (f[i][(1<<n)-1]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

						
					
