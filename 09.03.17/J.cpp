#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const __int64 INF=999999999LL*999999999LL+999999999LL*999999999LL;
int i,j,k,a,m,n,s,t,l,tt;
__int64 tmp,tmp1,tmp2;
typedef struct {__int64  x,y;} point;
typedef struct {__int64 x,y;int id;} point2;
point mach2[100011];
point2 mach[100011];
__int64 clo[100011];
float fl;
int bs(int l,int r){
if(l>=r)return l;
int t=(l+r)>>1;
if(mach[t].x<s)return bs(t+1,r);
else return bs(l,t);
}
inline __int64 dis(int i,int j){
    tmp1=mach2[i].x-mach[j].x;
    tmp2=mach2[i].y-mach[j].y;
    return tmp1*tmp1+tmp2*tmp2;
}

int cmp(const void *a,const void *b){
    return (*(point2 *)a).x-(*(point2 *)b).x>0?1:-1;
}

int main()
{
//#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
//#endif
scanf("%d",&tt);
while(tt--){
    scanf("%d",&n);
    LOOPB(i,0,n){
        scanf("%I64d %I64d",&mach[i].x,&mach[i].y);
        mach2[i].x=mach[i].x;
        mach2[i].y=mach[i].y;
        mach[i].id=i;
        clo[i]=INF;
        //printf("%d %I64d\n",i);;
    }
    qsort(mach,n,sizeof(mach[0]),cmp);
    LOOPB(i,0,n){
        fl=sqrt(clo[i]);
        s=-fl+mach2[i].x;
        k=bs(0,n)-1;
        if(k<0)k++;
        s=fl+mach2[i].x;
        a=bs(0,n)+1;
        if(a==n)a--;
        LOOPB(j,k,a){
            if(mach[j].id==i)continue;
            //if(mach2[i].x-mach[j].x<0&&(mach2[i].x-mach[j].x)*(mach2[i].x-mach[j].x)>clo[i])break;
            tmp=dis(i,j);
            //assert(tmp>0);
            clo[i]=MIN(clo[i],tmp);
            //clo[mach[j].id]=MIN(clo[mach[j].id],tmp);
        }
    }

    LOOPB(i,0,n)
        printf("%I64d\n",clo[i]);
}
}
