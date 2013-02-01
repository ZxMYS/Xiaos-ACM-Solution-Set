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
const int maxn=600000;
int rd[maxn],fu[maxn],son[maxn],a[maxn],zhi[maxn],bj[maxn],geshu2[maxn];
int cas,n,sum,kk;
void pre_work()
  {
    int i,j;
    for (i=2;i<maxn;i++)
      if (!bj[i])
        {
          zhi[++sum]=i;
          for (j=i;j<maxn/i;j++)
            bj[i*j]=1;
        }
  }
void init()
  {
    int i,t;
    scanf("%d%d",&n,&kk);
    for (i=1;i<=n;i++)
      {
        fu[i]=0;
        son[i]=0;
        rd[i]=0;
        geshu2[i]=0;
      }
    for (i=2;i<=n;i++)    
      {
        scanf("%d",&t);
        rd[t]++;fu[i]=t;
      }
  }
void qiuson()
  {
    int i,top=1,toe=0;
    for (i=1;i<=n;i++)
      if (!rd[i]) a[++toe]=i;
    while (top<=toe)
      {
        son[a[top]]++;
        rd[fu[a[top]]]--;
        son[fu[a[top]]]+=son[a[top]];
        if (!rd[fu[a[top]]]) a[++toe]=fu[a[top]];
        top++;
      }
    for (i=2;i<=n;i++)
      geshu2[son[i]]++;
  }
void work()
  {
    int i,j,t,t2,t3;
    long long z=1;
    qiuson();
    for (i=1;i<=sum;i++)
      {
        if (zhi[i]>n-1) break;
        t=0;
        for (j=1;j<=(n-1)/zhi[i];j++)
          {
            t2=1;t3=j;
            while (t3%zhi[i]==0)
              {
                t2++;
                t3/=zhi[i];
              }
            t+=(1-geshu2[zhi[i]*j])*t2;
          }
        for (;t>0;t--)
          z=z*zhi[i]%kk;
      }
    cout<<z<<endl;
  }
int main()
  {
//    freopen("t1.in","r",stdin);
//    freopen("t1.out","w",stdout);
    pre_work();
    scanf("%d",&cas);
    for (;cas>0;cas--)
      {
        init();
        work();
      }
    return 0;
  }
