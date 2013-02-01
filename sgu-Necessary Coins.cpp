#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int i,j,k=0,a,m,n,s,l,tt[500],t[500],x;
char tmp,str[500];
bool f[201][10001];
float f1,f2;

bool can(int start){
int i,j,k;
LOOPB(k,start-1,n){
if(k<0)continue;
memset(f[k],0,sizeof(f[k]));
}
f[0][0]=true;
LOOPB(k,start-1,n){
if(k<0)continue;
f[k][tt[k]]=true;

//printf("\nk=%d---------\n",k);
RLOOP(i,x,0){
    if(i-tt[k]<0){f[k][i]=f[k-1][i];continue;}
    f[k][i]=f[k][i]||f[k-1][i]||f[k-1][i-tt[k]];
//    if(f[k][i])printf("%d:%d %d %d |",i,f[k][i],f[k-1][i],f[k-1][i-tt[k]]);
}
    
}
return f[n-1][x];
}

int main()
{
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d%d",&n,&x);
LOOPB(i,0,n)scanf("%d",&tt[i]);
sort(tt,tt+n);
LOOPB(i,0,n){
    tt[n]=tt[i];
    tt[i]=0;
//    LOOPB(j,0,n)    printf("-%d",tt[j]);
//    printf("\n");
    if(!can(i))t[k++]=tt[n];
    tt[i]=tt[n];
    }
printf("%d\n",k);
if(k==0)exit(0);
LOOPB(i,0,k-1)
    printf("%d ",t[i]);
printf("%d \n",t[k-1]);
}
