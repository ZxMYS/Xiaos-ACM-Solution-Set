#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
int i,j,k,tt,n,m,zhi[500010],ss[500010],sum=0,t,t2,t3;
unsigned long long s;
bool bj[500010];
typedef struct {int f,c;} node;
node tree[500010];
inline void pre_work()
  {
    for (i=2;i<500000;i++)
      if (!bj[i])
        {
          zhi[++sum]=i;
          for (j=i;j<500000/i;j++)
            bj[i*j]=1;
        }
  }
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
pre_work();
scanf("%d",&tt);
while(tt--){
    scanf("%d%d",&n,&m);
    LOOPB(i,1,n){
        scanf("%d",&tree[i].f);
        tree[i].f--;
        tree[i].c=1;
        ss[i]=0;
    }
    RLOOP(i,n-1,1){
        tree[tree[i].f].c+=tree[i].c;
        ss[tree[i].c]++;
    }
    s=1;
    
    LOOP(i,1,sum)
      {
        if (zhi[i]>n-1) break;
        t=0;
        LOOP(j,1,(n-1)/zhi[i])
          {
            t2=1;t3=j;
            while (t3%zhi[i]==0)
              {
                t2++;
                t3/=zhi[i];
              }
            t+=(1-ss[zhi[i]*j])*t2;
          }
        while(t--)
          s=s*zhi[i]%m;
      }
    printf("%llu\n",s);
}
}
