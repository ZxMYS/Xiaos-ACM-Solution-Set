#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;
#define MAXN 10

const double pi=acos(-1.0);

int n;
int x[MAXN];
int y[MAXN];
int seg[1<<MAXN][MAXN][MAXN];
double len[1<<MAXN][MAXN][MAXN];
pair<int,double> ans;

inline int bit_count(unsigned x)
{
	x=(x&0x55555555u)+((x>>1u)&0x55555555u);
	x=(x&0x33333333u)+((x>>2u)&0x33333333u);
	x=(x&0x0f0f0f0fu)+((x>>4u)&0x0f0f0f0fu);
	x=(x&0x00ff00ffu)+((x>>8u)&0x00ff00ffu);
	x=(x&0x0000ffffu)+((x>>16u)&0x0000ffffu);
	return x;
}

bool on_segment(int p,int u,int v)
{
	int x1=x[u]-x[p];
	int y1=y[u]-y[p];
	int x2=x[v]-x[p];
	int y2=y[v]-y[p];
	return x1*x2+y1*y2<=0 && x1*y2-x2*y1==0;
}

int on_segment(int u,int v)
{
	int ans=0;
	for (int i=0;i<n;i++)
		if (on_segment(i,u,v)) ans|=1<<i;
	return ans;
}

long long cross_product(int x0,int y0,int x1,int y1,int x2,int y2)
{
	x1-=x0;
	y1-=y0;
	x2-=x0;
	y2-=y0;
	return x1*y2-x2*y1;
}

bool check_intersect(int p,int q,int a,int b)
{
	int x1=x[q];
	int y1=y[q];
	int x2=x[q]+(x[q]-x[p])*1000;
	int y2=y[q]+(y[q]-y[p])*1000;
	int x3=x[b];
	int y3=y[b];
	int x4=x[b]+(x[b]-x[a])*1000;
	int y4=y[b]+(y[b]-y[a])*1000;
	if (cross_product(x1,y1,x2,y2,x3,y3)*cross_product(x1,y1,x2,y2,x4,y4)>=0) return false;
	if (cross_product(x3,y3,x4,y4,x1,y1)*cross_product(x3,y3,x4,y4,x2,y2)>=0) return false;
	return true;
}

double intersect_len(int p,int q,int a,int b)
{
	int x1=x[q];
	int y1=y[q];
	int x2=x[q]+(x[q]-x[p])*1000;
	int y2=y[q]+(y[q]-y[p])*1000;
	int x3=x[b];
	int y3=y[b];
	int x4=x[b]+(x[b]-x[a])*1000;
	int y4=y[b]+(y[b]-y[a])*1000;
	double ans=0.0;
	double t=fabs(cross_product(x1,y1,x3,y3,x4,y4)*1.0/cross_product(x2,y2,x3,y3,x4,y4));
	t=t/(t+1.0);
	ans+=t*sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	t=fabs(cross_product(x3,y3,x1,y1,x2,y2)*1.0/cross_product(x4,y4,x1,y1,x2,y2));
	t=t/(t+1.0);
	ans+=t*sqrt((x4-x3)*(x4-x3)+(y4-y3)*(y4-y3));
	return ans;
}

void calc(int s,int u,int v)
{
	if (seg[s][u][v]) return;
	int on_seg=on_segment(u,v)&s;
	int& __seg=seg[s][u][v];
	double& __len=len[s][u][v];
	if (s==15 && u==0 && v==3)
	{
		s=15;
	}
	if (on_seg==s)
	{
		__len=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
		__seg=1;
	}
	else
	{
		int s2;
		__seg=0x7FFFFFFF;
		for (int w=0;w<n;w++)
			if (!(on_seg&(1<<w)) && (s&(1<<w)))
			{
				calc(s^on_seg^(1<<v),v,w);
				int seg2=seg[s^on_seg^(1<<v)][v][w]+1;
				double len2=len[s^on_seg^(1<<v)][v][w]+sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
				if (seg2<__seg || (seg2==__seg && len2<__len))
				{
					__seg=seg2;
					__len=len2;
				}
			}
		for (int w1=0;w1<n;w1++)
			if (!(on_seg&(1<<w1)) && (s&(1<<w1)))
				for (int w2=0;w2<n;w2++)
					if (w2!=w1 && !(on_seg&(1<<w2)) && (s&(1<<w2)))
					{
						calc(s^on_seg,w1,w2);
						if (!check_intersect(u,v,w2,w1)) continue;
						int seg2=seg[s^on_seg][w1][w2]+1;
						double len2=len[s^on_seg][w1][w2];
						len2+=intersect_len(u,v,w2,w1);
						len2+=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
						if (seg2<__seg || (seg2==__seg && len2<__len))
						{
							__seg=seg2;
							__len=len2;
						}
					}
	}
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(10);
	while (cin>>n && n)
	{
		for (int i=0;i<n;i++)
			cin>>x[i]>>y[i];
		memset(seg,0,sizeof(seg));
		ans.first=0x7FFFFFFF;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (j!=i)
				{
					calc((1<<n)-1,i,j);
					ans=min(ans,make_pair(seg[(1<<n)-1][i][j],len[(1<<n)-1][i][j]));
				}
		cout<<ans.first-1<<' '<<ans.second<<endl;
	}
	return 0;
}

