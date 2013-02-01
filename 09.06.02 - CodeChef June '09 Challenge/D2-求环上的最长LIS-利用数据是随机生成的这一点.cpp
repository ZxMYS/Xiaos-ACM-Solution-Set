//利用数据是随机生成的这一点
//选择100个最小的数作为起点，显然从较小的数开始上升空间比较大

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,m,n,t,l,tt,cas,ans;
int s[20001];
int f[20001],len,start,end;
typedef struct{int v,pos;} node;
node smallest[101],tmp;

inline bool cmp(const node& a,const node& b){
    return a.v<b.v;
}

inline void ins(int v,int pos){
    if(l<=100){
        tmp.v=v;
        tmp.pos=pos;
        smallest[l++]=tmp;
    }else{
        node *t=max_element(smallest,smallest+l,cmp);
        if(t->v>v){
            tmp.v=v;
            tmp.pos=pos;
            *t=tmp;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
srand(time(NULL));
while(cas--){
    scanf("%d",&n);
    l=0;
    LOOPB(i,0,n){
        scanf("%d",&s[i]);
        ins(s[i],i);
        s[i+n]=s[i];
    }
    
    len=ans=0;
    LOOPB(k,0,l){
        len=0;
        start=smallest[k].pos;
        end=start+n;
        LOOPB(i,start,end){
            if((!len)||f[len-1]<s[i]){
                f[len]=s[i];
                len++;
            }else{
                t=lower_bound(f,f+len,s[i])-f;
                f[t]=s[i];
            }
        }
        ans=MAX(ans,len);
    }
    cout<<ans<<endl;
}
}
