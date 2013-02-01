#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int maxn=120000;
struct{
  int zhi,l,nx;
} bian[maxn];
struct{
  int zhi,dy,nx;
} biao[maxn*5];
int query[maxn][3];
int ans[maxn*2];
int zhi[maxn],zhi2[maxn],fu[maxn],lca[maxn],a[maxn],sd[maxn],yy[maxn],sy[maxn],juli[maxn];
int a2[maxn][2];
int n,q,sum,ttt=0;
void init()
  {
    int t1,t2,t3,i;
    memset(zhi,0,(n+10)*sizeof(int));
    memset(zhi2,0,(n+10)*sizeof(int));
    memset(ans,0,(n+10)*sizeof(int));
    sum=0;
    for (i=1;i<n;i++)
      {
        scanf("%d%d%d",&t1,&t2,&t3);
        t1++;t2++;
        bian[++sum].zhi=t2;bian[sum].l=t3;bian[sum].nx=zhi[t1];
        zhi[t1]=sum;
        bian[++sum].zhi=t1;bian[sum].l=t3;bian[sum].nx=zhi[t2];
        zhi[t2]=sum;
      }
    sum=0;
    scanf("%d",&q);
    for (i=1;i<=q;i++)
      {
        scanf("%d%d%d",&t1,&t2,&t3);
        t1++;t2++;t3++;
        query[i][0]=t1;query[i][1]=t2;query[i][2]=t3;
        biao[++sum].zhi=t2;biao[sum].dy=(i-1)*3+1;biao[sum].nx=zhi2[t1];
        zhi2[t1]=sum;
        biao[++sum].zhi=t1;biao[sum].dy=(i-1)*3+1;biao[sum].nx=zhi2[t2];
        zhi2[t2]=sum;
        biao[++sum].zhi=t1;biao[sum].dy=(i-1)*3+2;biao[sum].nx=zhi2[t3];
        zhi2[t3]=sum;
        biao[++sum].zhi=t3;biao[sum].dy=(i-1)*3+2;biao[sum].nx=zhi2[t1];
        zhi2[t1]=sum;
        biao[++sum].zhi=t3;biao[sum].dy=(i-1)*3+3;biao[sum].nx=zhi2[t2];
        zhi2[t2]=sum;
        biao[++sum].zhi=t2;biao[sum].dy=(i-1)*3+3;biao[sum].nx=zhi2[t3];
        zhi2[t3]=sum;
      }
  }
void qiusd()
  {
    int top=1,toe=1,t;
    memset(fu,0,(n+10)*sizeof(int));
    memset(juli,0,(n+10)*sizeof(int));
    a[1]=1;sd[1]=1;juli[1]=0;
    while (top<=toe)
      {
        t=zhi[a[top]];
        while (t)
          {
            if (bian[t].zhi!=fu[a[top]])
              {
                fu[bian[t].zhi]=a[top];
                a[++toe]=bian[t].zhi;
                sd[a[toe]]=sd[a[top]]+1;
                juli[bian[t].zhi]=juli[a[top]]+bian[t].l;
              }
            t=bian[t].nx;
          }
        top++;
      }
  }
void jiaans(int dy,int k)
  {
    ans[dy]=k;
  }
void getsy(int ii)
  {
    if (sy[ii]==ii) return;
    getsy(sy[ii]);
    sy[ii]=sy[sy[ii]];
  }
void qiulca()
  {
    int top=1,xin=1,t;
    a2[1][0]=1;
    while (top)
      {
        if (xin)
          {
            yy[a2[top][0]]=1;
            a2[top][1]=zhi[a2[top][0]];
            xin=0;
            t=zhi2[a2[top][0]];
            while (t)
              {
                if (yy[biao[t].zhi])
                  {
                    getsy(biao[t].zhi);
                    jiaans(biao[t].dy,sy[biao[t].zhi]);
                  }
                t=biao[t].nx;
              }
          }
        while (a2[top][1])
          {
            t=a2[top][1];
            if (bian[t].zhi!=fu[a2[top][0]])
              {
                xin=1;a2[top][1]=bian[t].nx;
                a2[++top][0]=bian[t].zhi;
              }
            if (xin) break;
            a2[top][1]=bian[t].nx;
          }
        if (xin) continue;
        sy[a2[top][0]]=fu[a2[top][0]];
        top--;
      }
  }
void work()
  {
    int i,t1,t2,t3,max1,min1;
    memset(yy,0,sizeof(int)*(n+10));
    qiusd();
    for (i=1;i<=n;i++)
      sy[i]=i;
    qiulca();
    for (i=1;i<=q;i++)
      {
        t1=ans[(i-1)*3+1];t2=ans[(i-1)*3+2];t3=ans[(i-1)*3+3];
        max1=t1;min1=t1;
        if (sd[t2]>sd[max1]) max1=t2;
        if (sd[t3]>sd[max1]) max1=t3;
        if (sd[t2]<sd[min1]) min1=t2;
        if (sd[t3]<sd[min1]) min1=t3;
        printf("%d\n",juli[query[i][0]]+juli[query[i][1]]+juli[query[i][2]]-juli[min1]-juli[max1]*2+juli[max1]-juli[min1]);
      }
  }
int main()
  {
//    freopen("c.in","r",stdin);
//    freopen("c.out","w",stdout);
    while (scanf("%d",&n)!=EOF)
      {
        if (ttt) printf("\n");
        ttt++;
        init();
        work();
      }
    return 0;
  }
