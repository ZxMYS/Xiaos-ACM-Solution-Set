#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int aa[2000],bb[2000],cc[2000],mmax;
int s[55][25];
int a[55][25];
int top[55];
int ans[55][25];
int i,w,k,j,maxx,cas=0,tt;
int b[55];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
	scanf("%d",&w);
	mmax=1999;
	while (w)
	{
        if(cas)putchar('\n');
        memset(aa,0,sizeof(aa));
        aa[0]=true;
		maxx=0;
		for (i=1;i<=w;i++)
		{
            memset(top,0,sizeof(top));
            memset(cc,0,sizeof(cc));
			a[i][0]=0;
			int max=0;
			top[i]=0;
			scanf("%d",&b[i]);
			for (j=1;j<=b[i];j++)
			{
				scanf("%d",&s[i][j]);
				s[i][j]=10-s[i][j];
				a[i][j]=a[i][j-1]+s[i][j];
				if (a[i][j]==max)
				{
					top[i]++;
					ans[i][top[i]]=j;
				}
				else if (a[i][j]>max)
				{
					max=a[i][j];
					top[i]=1;
                    ans[i][1]=j;
				}
			}
			if(max==0&&top[i]==0){
                    top[i]=1;
                    ans[i][1]=0;
                }
            if(max==0){
                top[i]++;
                ans[i][top[i]]=0;//和上面一种不一样……
            }
			LOOP(j,0,mmax){
    			LOOP(k,1,top[i]){
                    if(aa[j])
                           cc[ans[i][k]+j]=true;
                    else
                        goto L1;
                }
                L1:;
            }
            LOOP(k,0,mmax){
                aa[k]=cc[k];
            }
			maxx+=max;
		}
		printf("Workyards %d\n",++cas);
		printf("Maximum profit is %d.\n",maxx);
		printf("Number of pruls to buy:");
		tt=0;
		LOOP(i,0,mmax){
            if(aa[i]){
                printf(" %d",i);
                tt++;
                if(tt>=10)break;
            }
        }
        printf("\n");
        scanf("%d",&w);
	}
	return 0;
}
