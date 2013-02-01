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
int i,j,k,a,m,n,t,l,tt,cas,lx,ly,fl,t1,t2,top;
char tmp;
bool ga[20][20];
unsigned long long int state[2][500],sum[2][500],tot[2],ans,ts,s,data,aa,bb;
int link[500],next[500];
bool x,y;
const int Prime=473;
inline void hash(const unsigned long long int& x,const unsigned long long int& num){
    int t=x%Prime;
    int tmp=link[t];
    while(tmp){
        if(state[fl][tmp]==x){
            sum[fl][tmp]+=num;
            return;
        }
        tmp=next[tmp];
    }
    tmp=++tot[fl];
    state[fl][tmp]=x;
    sum[fl][tmp]=num;
    next[tmp]=link[t];
    link[t]=tmp;
}

inline void out(){
    int i,j;
    LOOP(i,1,n){
        LOOP(j,1,m)
            cout<<(ga[i][j]?'.':'#');
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d\n",&n,&m);
while(n){
    LOOPB(i,1,n+3){
        ga[i][1]=ga[i][m+4]=true;
    }
    LOOP(i,1,m+3)
        ga[1][i]=true;
    LOOP(i,3,n+2){
        ga[i][2]=ga[i][m+3]=false;
    }
    ga[n+2][2]=ga[n+2][m+3]=true;
    LOOP(i,2,m+3)
        ga[2][i]=false;
    LOOPB(i,3,n+3){
        LOOPB(j,3,m+3){
            scanf("%c",&tmp);
            if(tmp=='.'){
                ga[i][j]=true;
            }else
                ga[i][j]=false;
        }
        scanf("\n");
    }
    n+=2;
    m+=4;
    lx=n;
    ly=m;
    //out();

    fl=0;ans=0;
    memset(state,0,sizeof(state));
    memset(sum,0,sizeof(sum));
    tot[0]=1;
    sum[0][1]=1;
    state[0][1]=0;
    LOOP(i,1,n){
        LOOP(j,1,m){
            fl=1-fl;
            tot[fl]=0;
            memset(link,0,sizeof(link));
            memset(next,0,sizeof(next));
            LOOP(k,1,tot[1-fl]){
                s=state[1-fl][k];
                data=sum[1-fl][k];
                aa=(j-1)<<1;
                bb=j<<1;
                t1=(s>>aa)&3;
                t2=(s>>bb)&3;
                aa=1LL<<aa;
                bb=1LL<<bb;
                
                if(!ga[i][j]){
                    if((!t1)&&(!t2)){
                        ts=s-t1*aa-t2*bb;
                        hash(ts,data);
                    }
                    continue;
                }
                
                if((!t1)&&(!t2)){
                    if(j<m&&ga[i][j+1]&&i<n&&ga[i+1][j]){
                        ts=s+(1*aa)+(2*bb);
                        hash(ts,data);
                    }
                    continue;
                }

                if(!t1){
                    if(j<m&&ga[i][j+1])
                        hash(s,data);
                    if(i<n&&ga[i+1][j]){
                        ts=s+t2*aa-t2*bb;
                        hash(ts,data);
                    }
                    continue;
                }

                if(!t2){
                    if(i<n&&ga[i+1][j])
                        hash(s,data);
                    if(j<m&&ga[i][j+1]){
                        ts=s-t1*aa+t1*bb;
                        hash(ts,data);
                    }
                    continue;
                }
                
                ts=s-t1*aa-t2*bb;
                if(t1==1&&t2==1){
                    top=1;
                    LOOP(a,j+2,m+1){
                        tmp=(s>>((a-1)<<1))&3;
                        if(tmp==1)
                            top++;
                        else if(tmp==2)
                            top--;
                        if(!top)
                            break;
                    }
                    ts=ts-1*(1<<((a-1)<<1));
                    hash(ts,data);
                    continue;
                }
                
                if(t1==2&&t2==2){
                    top=1;
                    RLOOP(a,j-1,1){
                        tmp=(s>>((a-1)<<1))&3;
                        if(tmp==1)
                            top--;
                        else if(tmp==2)
                            top++;
                        if(!top)
                            break;
                    }
                    ts=ts+1*(1<<((a-1)<<1));
                    hash(ts,data);
                    continue;
                }
                
                if(t1==1&&t2==2){
                    if(i==lx&&j==ly)
                        ans+=data;
                    continue;
                }
                
                if(t1==2&&t2==1){
                    hash(ts,data);
                    continue;
                }
            }
        }
        LOOP(j,1,tot[fl]){
            state[fl][j]=state[fl][j]<<2;
        }
    }

    cout<<ans<<endl;
    
    scanf("%d%d\n",&n,&m);
}
}
