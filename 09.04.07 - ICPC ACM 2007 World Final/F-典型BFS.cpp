#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
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
#define PI 3.1415926535898
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,w,tt,ans;
typedef struct {unsigned int ball;bool rest[8];int steps;int stages;} state;
typedef struct {int x,y,id;} point;
state start;
queue<state> qu;
point holes[50];
bool ga[5][5][5][5];
int hole[5][5];
map<int,map<unsigned int,bool> > check;

int cmpup(const void* a, const void* b){
    return ((point *)a)->y-((point *)b)->y;
}
int cmpdown(const void* a, const void* b){
    return ((point *)b)->y-((point *)a)->y;
}
int cmpleft(const void* a, const void* b){
    return ((point *)a)->x-((point *)b)->x;
}
int cmpright(const void* a, const void* b){
    return ((point *)b)->x-((point *)a)->x;
}
inline bool okey(state now){
    return now.stages==m;
}

inline bool checked(state now){
    map<int,map<unsigned int,bool> >::iterator iter1;
    map<unsigned int,bool>::iterator iter2;
    map<unsigned int,bool> tmp;
    iter1=check.find(now.stages);
    if(iter1==check.end()){
        tmp.clear();
        tmp.insert(pair<unsigned int,bool>(now.ball,true));
        check.insert(pair<int,map<unsigned int,bool> >(now.stages,tmp));
        return false;
    }else{
        iter2=(iter1->second).find(now.ball);
        if(iter2==(iter1->second).end()){
            (iter1->second).insert(pair<unsigned int,bool>(now.ball,true));
            return false;
        }
        else
            return true;
    }
}


point changeintopoint(int ball,int n){
    point tmp;
    tmp.x=(ball>>n*4+2)&3;
    tmp.y=(ball>>n*4)&3;
    return tmp;
}

unsigned int changeintoint(int x,int y,int n){
    return ((x<<(n*4+2))+(y<<(n*4)));
}


inline state up(state now){
    int i;
    int l[8];
    LOOPB(i,0,n)
        l[i]=0;
    state tmp=now;
    point po[8];
    LOOPB(i,0,m){
        po[i]=changeintopoint(now.ball,i);
        po[i].id=i;
    }
    qsort(po,m,sizeof(po[0]),cmpup);
    LOOPB(i,0,m){
        if(!now.rest[po[i].id]){
            while(po[i].y>l[po[i].x]&&ga[po[i].x][po[i].y][po[i].x][po[i].y-1]){
                po[i].y--;
                if(hole[po[i].x][po[i].y]!=-1&&hole[po[i].x][po[i].y]!=po[i].id&&!now.rest[hole[po[i].x][po[i].y]])
                    return tmp;
                else if(hole[po[i].x][po[i].y]==po[i].id){
                    now.rest[po[i].id]=true;
                    now.stages++;
                    goto Lup;
                }
            }
            l[po[i].x]=po[i].y+1;
        }
        Lup:;
    }
    now.ball=0;
    LOOPB(i,0,m)
        now.ball+=changeintoint(po[i].x,po[i].y,po[i].id);
    return now;
}

inline state down(state now){
    int i;
    int l[8];
    LOOPB(i,0,n)
        l[i]=n-1;
    state tmp=now;
    point po[8];
    LOOPB(i,0,m){
        po[i]=changeintopoint(now.ball,i);
        po[i].id=i;
    }
    qsort(po,m,sizeof(po[0]),cmpdown);
    LOOPB(i,0,m){
        if(!now.rest[po[i].id]){
            
            while(po[i].y<l[po[i].x]&&ga[po[i].x][po[i].y][po[i].x][po[i].y+1]){
                po[i].y++;
                if(hole[po[i].x][po[i].y]!=-1&&hole[po[i].x][po[i].y]!=po[i].id&&!now.rest[hole[po[i].x][po[i].y]]){
                    return tmp;
                }
                else if(hole[po[i].x][po[i].y]==po[i].id){
                    now.rest[po[i].id]=true;
                    now.stages++;
                    goto Ldown;
                }
            }
            l[po[i].x]=po[i].y-1;
        }
        Ldown:;
    }
    now.ball=0;
    LOOPB(i,0,m)
        now.ball+=changeintoint(po[i].x,po[i].y,po[i].id);
    return now;
}

inline state left(state now){
    int i;
    int l[8];
    LOOPB(i,0,n)
        l[i]=0;
    state tmp=now;
    point po[8];
    LOOPB(i,0,m){
        po[i]=changeintopoint(now.ball,i);
        po[i].id=i;
    }
    qsort(po,m,sizeof(po[0]),cmpleft);
    LOOPB(i,0,m){
        if(!now.rest[po[i].id]){
            while(po[i].x>l[po[i].y]&&ga[po[i].x][po[i].y][po[i].x-1][po[i].y]){
                po[i].x--;
                if(hole[po[i].x][po[i].y]!=-1&&hole[po[i].x][po[i].y]!=po[i].id&&!now.rest[hole[po[i].x][po[i].y]])
                    return tmp;
                else if(hole[po[i].x][po[i].y]==po[i].id){
                    now.rest[po[i].id]=true;
                    now.stages++;
                    goto Lleft;
                }
            }
            l[po[i].y]=po[i].x+1;
        }
        Lleft:;
    }
    now.ball=0;
    LOOPB(i,0,m)
        now.ball+=changeintoint(po[i].x,po[i].y,po[i].id);
    return now;
}

inline state right(state now){
    int i;
    int l[8];
    LOOPB(i,0,n)
        l[i]=n-1;
    state tmp=now;
    point po[8];
    LOOPB(i,0,m){
        po[i]=changeintopoint(now.ball,i);
        po[i].id=i;
    }
    qsort(po,m,sizeof(po[0]),cmpright);
    LOOPB(i,0,m){
        if(!now.rest[po[i].id]){
            while(po[i].x<l[po[i].y]&&ga[po[i].x][po[i].y][po[i].x+1][po[i].y]){
                po[i].x++;
                if(hole[po[i].x][po[i].y]!=-1&&hole[po[i].x][po[i].y]!=po[i].id&&!now.rest[hole[po[i].x][po[i].y]])
                    return tmp;
                else if(hole[po[i].x][po[i].y]==po[i].id){
                    now.rest[po[i].id]=true;
                    now.stages++;
                    goto Lright;
                }
            }
            l[po[i].y]=po[i].x-1;
        }
        Lright:;
    }
    now.ball=0;
    LOOPB(i,0,m)
        now.ball+=changeintoint(po[i].x,po[i].y,po[i].id);
    return now;
}


inline void solve(){
state now,next;
while(!qu.empty()){
    now=qu.front();
    qu.pop();
    now.steps++;
    if(now.steps>ans)continue;
    next=up(now);
    if(okey(next)) ans=next.steps;;
    if(!checked(next))
        qu.push(next);
        
    next=down(now);
    if(okey(next)) ans=next.steps;
    if(!checked(next))
        qu.push(next);
        
    next=left(now);
    if(okey(next)) ans=next.steps;
    if(!checked(next))
        qu.push(next);
        
    next=right(now);
    if(okey(next)) ans=next.steps;
    if(!checked(next))
        qu.push(next);
}
if(ans==oo)
cout<<"impossible"<<endl;
else
cout<<next.steps<<" moves"<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d",&n,&m,&w);
start.steps=0;
start.stages=0;
tt=0;
while(n!=0){
    cout<<"Case "<<++tt<<": ";
    start.ball=0;
    ans=oo;
    while(!qu.empty())qu.pop();
    check.clear();
    LOOPB(i,0,n)
        LOOPB(j,0,n){
            hole[i][j]=-1;
            LOOPB(s,0,n)
                LOOPB(t,0,n)
                    ga[i][j][s][t]=true;
        }
    LOOPB(i,0,m){
        scanf("%d%d",&t,&s);
        start.ball+=changeintoint(s,t,i);
        start.rest[i]=false;
    }
    
    point po[8];
    
    LOOPB(i,0,m){
        po[i]=changeintopoint(start.ball,i);
        po[i].id=i;
    }
    qsort(po,m,sizeof(po[0]),cmpup);
    
    LOOPB(i,0,m){
        scanf("%d%d",&holes[i].y,&holes[i].x);
        hole[holes[i].x][holes[i].y]=i;
    }
    LOOPB(i,0,w){
        scanf("%d%d%d%d",&a,&k,&s,&t);
        ga[k][a][t][s]=ga[t][s][k][a]=false;
    }
    qu.push(start);
    solve();
    cout<<endl;
    scanf("%d%d%d",&n,&m,&w);
}
}
