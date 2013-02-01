#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
const int MAX = 200;
const long long int INF = 9223372036854775807LL;
long long int clo[MAX];
long long int low[MAX];
long long int c[MAX][MAX];
int c2[MAX][MAX],c3[MAX][MAX];
char tmp;
bool flag[MAX];
int beg[MAX],end[MAX];//记录生成树的每条边的两个顶点
long long int Prim(int n)
{
	int i, j, k;
    long long int ans = 0;
	flag[1] = true;
	for(i = 2; i <= n; i++)
	{
		low[i] = c[1][i];
		clo[i] = 1;
		flag[i] = false;
	}
	for(i = 1; i < n; i++)
	{
		j = 1;
		long long int min = INF;
		for(k = 2; k <=n; k++)
		{
			if(low[k] < min && !flag[k])
			{
				min = low[k];
				j = k;
			}
		}
		flag[j] = true;
		beg[i] = j;
		end[i] = clo[j];
		ans += c[j][clo[j]];
		for(k = 2; k <= n; k++)
		{
			if(c[j][k] < low[k] && !flag[k])
			{
				low[k] = c[j][k];
				clo[k] = j;
			}
		}
	}
	return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
	int i, j, n;
    long long int x=0,d,a;
	scanf("%d",&n);
	cin>>d>>a;
	scanf("\n");
	d=-d;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <=n; j++)
		{
			c[i][j]=INF;
			c3[i][j]=c2[i][j]=0;
		}
	}
	LOOP(i,1,n){
        LOOP(j,1,n){
            scanf("%c",&tmp);
            if(tmp=='1'){c[i][j]=d;c3[i][j]=1;x+=d;}
            else c[i][j]=a;
        }
        scanf("\n");
    }
    x/=-2;
    x+=Prim(n);
    cout<<x<<endl;
    LOOPB(i,1,n)
        c2[beg[i]][end[i]]=c2[end[i]][beg[i]]=1;
    LOOP(i,1,n){
        LOOP(j,1,n)
            if(c2[i][j]==c3[i][j])putchar('0');
            else if(c2[i][j]==1)putchar('a');
            else putchar('d');
        putchar('\n');
    }
	return 0;
}
