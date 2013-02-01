#include<cstdio>
#include<cstring>
#define MAXN 11
#define MAXM 11
#define MAXK 51
int N,M,K;
int a[MAXN][MAXM];
int F[MAXN][MAXM][MAXN][MAXM];
int f[MAXN][MAXM][MAXN][MAXM][MAXK];
bool have[MAXN][MAXM][MAXN][MAXM][MAXK];
int ans;
void print()
{
	printf("%d\n",ans);
}
inline int min(int x,int y)
{
	return x<y?x:y;
}
void search(int x1,int y1,int x2,int y2,int k)
{
	if (have[x1][y1][x2][y2][k])return;
	if (k==0)
	{
		f[x1][y1][x2][y2][k]=F[x1][y1][x2][y2];
		have[x1][y1][x2][y2][k]=true;
		return;
	}
	else
	{
		int i,j;
		int ans0=2147483647,now;
		for (i=0;i<k;i++)
		{
			for (j=x1;j<x2;j++)
			{
				search(x1,y1,j,y2,i);
				search(j+1,y1,x2,y2,k-i-1);
				now=f[x1][y1][j][y2][i]+f[j+1][y1][x2][y2][k-i-1];
				if (now<ans0)ans0=now;
			}
			for (j=y1;j<y2;j++)
			{
				search(x1,y1,x2,j,i);
				search(x1,j+1,x2,y2,k-i-1);
				now=f[x1][y1][x2][j][i]+f[x1][j+1][x2][y2][k-i-1];
				if (now<ans0)ans0=now;
			}
		}
		if (ans0==2147483647)ans0=0;
		f[x1][y1][x2][y2][k]=ans0;
		have[x1][y1][x2][y2][k]=true;
		return;
	}
}
int GetF(int x1,int y1,int x2,int y2)
{
	int i1,j1,i2,j2;
	int ans0=0;
	for (i1=x1;i1<=x2;i1++)
		for (j1=y1;j1<=y2;j1++)
			for (i2=x1;i2<=x2;i2++)
				for (j2=y1;j2<=y2;j2++)if (i1!=i2||j1!=j2)ans0+=a[i1][j1]*a[i2][j2];
	ans0/=2;
	return ans0;
}
void solve()
{
	memset(have,0,sizeof(have));
	int x1,y1,x2,y2,i,j;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)F[i][j][i][j]=0;
	for (x1=1;x1<=N;x1++)
		for (y1=1;y1<=M;y1++)
			for (x2=x1;x2<=N;x2++)
				for (y2=y1;y2<=M;y2++)
				if ((x1!=x2||y1!=y2)&&x1<=x2&&y1<=y2)F[x1][y1][x2][y2]=GetF(x1,y1,x2,y2);
	search(1,1,N,M,K);
	ans=f[1][1][N][M][K];
}
void init()
{
	int i,j;
	for (i=1;i<=N;i++)
		for (j=1;j<=M;j++)scanf("%d",&a[i][j]);
}
int main()
{
	while(scanf("%d%d%d",&N,&M,&K)!=EOF)
	{
		init();
		solve();
		print();
	}
	return 0;
}
