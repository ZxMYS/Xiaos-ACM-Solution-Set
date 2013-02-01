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
int i,j,k,a,m,n,s,t,l,tt,r,c;
bool ga[101][101];
int main()
{
freopen("C.in","r",stdin);
freopen("C.out","w",stdout);
scanf("%d%d%d",&n,&r,&c);
LOOPB(i,0,r)
LOOPB(j,0,c)
    ga[i][j]=false;
a=n;
if(n>=MIN(r,c)*2-1){
    printf("%d\n",MIN(r,c));
LOOPB(i,0,MIN(r,c)){
    ga[0][i]=ga[i][0]=true;
    a-=2;
}
}else
{
printf("%d\n",(n+1)>>1);
LOOP(i,0,((n+1)>>1)-1){
    ga[0][i]=ga[i][0]=true;
    a-=2;
}
}
n=a;
n++;
LOOPB(i,0,r){
LOOPB(j,0,c){
if((n)&&!ga[i][j]){ga[i][j]=true;n--;}
if(ga[i][j])
printf("#");
else
printf(".");
}
printf("\n");
}
}
