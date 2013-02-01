#include <stdio.h>
#include <algorithm>
using namespace std;
int xmin[104];
int xmax[104];
int  ymin[104];
int  ymax[104];
int  p[104];
int rank[104];
int min(int x,int y)
{
 if(x>y) return y;
 else return x;
}
int max(int x,int y)
{
 if(x>y) return x;
 else return y;
}
void make_set(int x,int xi,int yi,int r)
{
 p[x]=x;
 rank[x]=0;
 xmin[x]=xi-r;
 xmax[x]=xi+r;
 ymin[x]=yi-r;
 ymax[x]=yi+r;
}
int find_set(int x)
{
 if(p[x]!=x)
  p[x]=find_set(p[x]);
 xmin[x]=xmin[p[x]];
 xmax[x]=xmax[p[x]];
 ymin[x]=ymin[p[x]];
 ymax[x]=ymax[p[x]];
 return p[x];
}
int link(int x,int y)
{
    if(rank[x]>rank[y])
 {
 p[y]=x;
 return x;
 }
 else
 {
  p[x]=y;
  if(rank[x]==rank[y])
   rank[y]++;
  return y;
 }
}
void union_set(int x,int y)
{
 int root;
 int xp=find_set(x);
 int yp=find_set(y);
 root=link(find_set(x),find_set(y));
    xmin[root]=min(xmin[xp],xmin[yp]);
 xmax[root]=max(xmax[xp],xmax[yp]);
 ymin[root]=min(ymin[xp],ymin[yp]);
 ymax[root]=max(ymax[xp],ymax[yp]);

}
int main()
{
    #ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
   int x,y;
  int n;
   int i,j;
   scanf("%ld%ld%ld",&x,&y,&n);
   for(i=0;i<n;i++)
   {
     long xi,yi,r;
  scanf("%ld%ld%ld",&xi,&yi,&r);
  make_set(i+1,xi,yi,r);
   }
int times=6;
while(times--)
{
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    if(i!=j)
    {
      int xp=find_set(i);
      int yp=find_set(j);
      int xx=max(xmax[xp],xmax[yp])-min(xmin[xp],xmin[yp]);
      int yy=max(ymax[xp],ymax[yp])-min(ymin[xp],ymin[yp]);
      int x1=xmax[xp]-xmin[xp]+xmax[yp]-xmin[yp];
      int y1=ymax[xp]-ymin[xp]+ymax[yp]-ymin[yp];
    if(find_set(i)!=find_set(j)&&xx<=x1&&yy<=y1)
     {
      union_set(i,j);
     }
    }
   }
}
for(i=1;i<=n;i++)
 find_set(i);
   p[0]=p[n];
   sort(p,p+n);

   int key=0;
   for(i=0;i<n;i++)
   {
    key+=(xmax[p[i]]-xmin[p[i]])*(ymax[p[i]]-ymin[p[i]]);
    while(p[i]==p[i+1])
    {
     i++;
     if(i>=n) break;
    }
   }
  printf("%ld\n",x*y-key);
  return 0;
}
