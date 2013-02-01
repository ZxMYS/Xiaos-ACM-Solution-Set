#include<stdio.h>
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#include<iostream>
using namespace std;
long i,j,k,m,n;
long cost,treenum;
long root[32001],rank[32001];
struct edge{
long x;
long y;
long w;
};
struct edge e[100000];
long sort(long l,long r){
long low=l,hi=r,mid=e[(l+r)/2].w,tmp;
do{
while(e[low].w>mid)low++;
while(e[hi].w<mid)hi--;
if(low<=hi){
tmp=e[low].x; e[low].x=e[hi].x; e[hi].x=tmp;
tmp=e[low].y; e[low].y=e[hi].y; e[hi].y=tmp;
tmp=e[low].w; e[low].w=e[hi].w; e[hi].w=tmp;
low++; hi--;
}
}while(low<=hi);
if(low<r) sort(low,r);
if(l<hi) sort(l,hi);
}
long init(){
int nn,n2;
scanf("%ld%ld%ld",&nn,&n2,&m);
n=nn+n2;
for(i=1;i<=m;i++){
scanf("%ld%ld%ld",&e[i].x,&e[i].y,&e[i].w);
e[i].y+=nn;
}
LOOP(i,0,n)
    root[i]=i;
sort(1,m);
treenum=n;
}
long findset(long x){
if(root[x]!=x)
root[x]=findset(root[x]);
return root[x];
}
long link(long a,long b){
if(rank[a]>rank[b])
root[b]=a;
else if(rank[a]<rank[b])
root[a]=b;
else{
root[a]=b;
rank[b]++;
}
}
long unite(long a,long b){
link(findset(a),findset(b));
}
long work(){
cost=0;
long x,y;
for(i=1;i<=m;i++){
x=e[i].x; y=e[i].y;
if(findset(x)!=findset(y)){
    //cout<<"add "<<x<<" "<<y<<" "<<e[i].w<<endl;
cost+=e[i].w;
unite(x,y);
treenum--;
}
}
printf("%ld\n",n*10000-cost);
}
main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
int tt;
scanf("%d",&tt);
while(tt--){
init();
work();
}
return 0;
}
