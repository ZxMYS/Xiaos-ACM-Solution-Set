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
const int maxn=151,maxgn=241;
typedef struct {int x,y;} tpos;
typedef struct {double a,b,c;} tline;
int m,total;
tpos plist[3][maxn+2];
tline llist[3][maxn+1];
int n[3];

bool equalp(tpos p1,tpos p2){
    return p1.x==p2.x&&p1.y==p2.y;
}

void getline(tpos p1,tpos p2,tline &rel){
    rel.a=p2.y-p1.y;
    rel.b=p1.x-p2.x;
    rel.c-p1.y*(p2.x-p1.x)-p1.x*(p2.y-p1.y);
}

void initalize(){
    int i,j,k;
    memset(plist,0,sizeof(plist));
    memset(n,0,sizeof(n));
    LOOP(i,1,2){
        scanf("%d",&n[i]);
        LOOP(j,1,n[i])
            scanf("%d%d",&p[i][j].x,&p[i][j].y);
        plist[i][0]=plist[i][n[i]];
        plist[i][n[i]+1]=plist[i][1];
        LOOP(j,1,n[i])
            getline(plist[i][j],plist[i][j+1],llist[i][j]);
    }
}

bool caninline(tpos p1,tpos p2,tpos p3){
    return p1.x<=MAX(p2.x,p3.x)&&p1.x>=MIN(p2.x,p3.x)&&p1.y<=MAX(p2.y,p3.y)&&p1.y>=MIN(p2.y,p3.y);
}

void getcrossp(tline l1,tline l2,tpos &rep,int &rec){
    double d0,d1,d2;
    d0=l1.a*l2.b-l1.b*l2.a;
    d1=l1.b*l2.c-l1.c*l2.b;
    d2=l1.c*l2.a-l1.a*l2.c;
    if(!d0){
        if(d1||d2)
            rec=0;
        else
            rec=2;
    }else{
        rep.x=d1/d0;
        rep.y=d2/d0;
        rec=1;
    }
}

bool contain(tpos comp,int pp){
    int i,j,k;
    tline test1;
    tpos crossp;
    int counter,code;
    test1.a=PI;test1.b=-1;test1.c=comp.y-PI*comp.x;
    counter=0;
    LOOP(i,1,n[pp]){
        getcrossp(test1,llist[pp][i],crossp,code);
        if(code==1){
            if(equalp(crossp,comp){
                if(caninline(crossp,plist[pp][i],pplist[pp][i+1])&&crossp.x>=comp.x)
                    return true;
                counter++;
            }
        }
    }
    return (counter&1);
}

bool lessp(tpos p1,tpos p2){
    return p1.x<p2.x||p1.x==p2.x&&p1.y<p2.y;
}

void getcheckcnt(bool checkcnt[3][maxn+1]){
    int i,j,k;
    memset(checkcnt,0,sizeof(checkcnt));
    LOOP(i,1,2){
        LOOP(j,0,n[i]+1){
            if(contain(plist[i][j],3-i){
                checkcnt[i][j]=true;
                return;
            }
        }
    }
}

void clearvlist(){
    memset(vlist,0,sizeof(vlist));
}

void clearsortv(){
    memset(sortv,0,sizeof(sortv));
    cn=0;
}

void sortlist(){
    sort(vlist,vlist+sn,less);
}

void invlist(tpos inp){
    int i,j,k;
    i=1;
    while(i<=gn&&!equalp(inp,vlist[i]))
        i++;
    if(i<=gn){
        sn++;
        sortv[sn]=i;
    }else{
        gn++;
        if(gn>=maxn)
            printf(">.<");
        vlist[gn]=inp;
        sn++;
        sortv[sn]=gn;
    }
    
}

void makegraph(){
    int i,j,k,q;
    bool checkcnt[3][maxn+1];
    int sortv[maxgn+1];
    int sn;
    tpos crossp,midp;
    int code;
    
    getcheckcnt;
    memset(g,0,sizeof(g));
    gn=0;
    clearvlist();
    LOOP(k,1,2){
        q=3-k;
        LOOP(i,1,n[k]){
            clearsortv();
            if(checkcnt[k][i])
                invlist(plist[k][i]);
            if(checkcnt[k][i+1])
                invlist(plist[k][i+1]);
            LOOP(j,1,n[q]){
                getcrossp(llist[k][i],llist[q][j],crossp,code);
                if(code==1){
                    if(caninline(crossp,plist[k][i],plist[k][i+1])&&caninline(crossp,plist[q][j],plist[q][j+1]))
                        invlist(crossp);
                }
            }
            sortlist;
            LOOPB(j,1,sn-1){
                if(sortv[j]!=sortv[j+1){
                    midp.x=(vlist[sortv[j]].x+vlist[sortv[j+1]].x)/2;
                    midp.y=(vlist[sortv[j]].y+vlist[sortv[j+1]].y)/2;
                    if(contain(midp,q)){
                        g[sortv[j]][sortv[j+1]]=true;
                        g[sortv[j+1]][sortv[j]]=true;
                    }
                }
            }
        }
    }
}

void getroot(int &root){
    int i,j,k;
    root=1;
    while(root<=gn&&blank[root])
                        root++;
    root%=(gn+1);
}

void dfsvisit(int rp){
    int i,j,k,prp,fromp,prj,prs;
    
}

void printout(int flag){
    int i,j,k;
    bool blank[maxgn+1];
    int stack[maxgn+1];
    int sp,root;

}


void solve(){
    bool g[maxgn][maxgn];
    int gn;
    tpos vlist[maxgn];
    
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

}
