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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,sx,sy,sd,ex,ey,x,y,ansn,ansl;
string name;
typedef struct {int x,y,from,fromst;   } stats;
stats st[100000],nowst,tmpst;
int qut,qul,qub;
list<pair<int,int> > ans;
list<pair<int,int> >::iterator ansiter;
bool ga[10][10][4][4];
bool checked[10][10][4];
char tmp,tmp2;
//     N0
//  W3 *  E1
//     S2

inline int dirtoint3(int from,char dir){
    if(dir=='L')
        return (from+1)%4;
    if(dir=='R')
        return (from+4-1)%4;
    return (from+2)%4;
}

inline int dirtoint2(char dir){
    if(dir=='S')return 0;
    if(dir=='N')return 2;
    if(dir=='W')return 1;
    if(dir=='E')return 3;
}

inline int dirtoint(char dir){
    if(dir=='N')return 0;
    if(dir=='S')return 2;
    if(dir=='E')return 1;
    if(dir=='W')return 3;
}

inline void readcase(){
    LOOPB(i,0,9)
        LOOPB(j,0,9)
            LOOPB(k,0,4){
                checked[i][j][k]=false;
                LOOPB(s,0,4)
                    ga[i][j][k][s]=false;
            }
char sdt;
cin>>sx>>sy>>sdt>>ex>>ey;
sx--;sy--;ex--;ey--;
sd=dirtoint(sdt);
cin>>x;

while(x!=0){
    cin>>y;
    x--;y--;
    cin>>tmp;
    while(tmp!='*'){
        tmp=dirtoint2(tmp);
        //ga[x][y][tmp]
        scanf("%c",&tmp2);
        while(tmp2!=' '){
            ga[x][y][tmp][dirtoint3(tmp,tmp2)]=true;
            scanf("%c",&tmp2);
        }
        cin>>tmp;
    }
    cin>>x;
}
}

inline bool bfs(int nowx,int nowy,int from){
    st[0].x=nowx;
    st[0].y=nowy;
    st[0].from=from;
    st[0].fromst=-1;
    qut=0;
    qul=1;
    qub=1;
    while(qul){
        nowst=st[qut++];
        if(nowst.x==ex&&nowst.y==ey){
            ans.push_back(pair<int,int>(ex+1,ey+1));
            while(nowst.fromst!=-1){
                nowst=st[nowst.fromst];
                ans.push_back(pair<int,int>(nowst.x+1,nowst.y+1));
            }
            return true;
        }
        qul--;
        if(ga[nowst.x][nowst.y][nowst.from][0]){
            tmpst=nowst;
            tmpst.x--;
            tmpst.from=2;
            tmpst.fromst=qut-1;
            if(!checked[tmpst.x][tmpst.y][tmpst.from]){
                checked[tmpst.x][tmpst.y][tmpst.from]=true;
                qul++;
                st[qub++]=tmpst;
            }
        }
        if(ga[nowst.x][nowst.y][nowst.from][1]){
            tmpst=nowst;
            tmpst.y++;
            tmpst.from=3;
            tmpst.fromst=qut-1;
            if(!checked[tmpst.x][tmpst.y][tmpst.from]){
                checked[tmpst.x][tmpst.y][tmpst.from]=true;
                qul++;
                st[qub++]=tmpst;
            }
        }
        if(ga[nowst.x][nowst.y][nowst.from][2]){
            tmpst=nowst;
            tmpst.x++;
            tmpst.from=0;
            tmpst.fromst=qut-1;
            if(!checked[tmpst.x][tmpst.y][tmpst.from]){
                checked[tmpst.x][tmpst.y][tmpst.from]=true;
                qul++;
                st[qub++]=tmpst;
            }
        }
        if(ga[nowst.x][nowst.y][nowst.from][3]){
            tmpst=nowst;
            tmpst.y--;
            tmpst.from=1;
            tmpst.fromst=qut-1;
            if(!checked[tmpst.x][tmpst.y][tmpst.from]){
                checked[tmpst.x][tmpst.y][tmpst.from]=true;
                qul++;
                st[qub++]=tmpst;
            }
        }
    }
    return false;
}

inline void solve(){
    if(sd==0){
        if(bfs(sx-1,sy,2)) goto L2;
    }else if(sd==1){
        if(bfs(sx,sy+1,3)) goto L2;
    }else if(sd==2){
        if(bfs(sx+1,sy,0)) goto L2;
    }else if(sd==3){
        if(bfs(sx,sy-1,1)) goto L2;
    }
    cout<<"  No Solution Possible"<<endl;
    return;
    L2:
        ansn=1;
        cout<<"  ("<<sx+1<<','<<sy+1<<")";
        ansiter=ans.end();
        while((ansiter--,1)){
            if(ansn!=0)
            cout<<" ("<<ansiter->first<<','<<ansiter->second<<")";
            else
            cout<<endl<<"  ("<<ansiter->first<<','<<ansiter->second<<")";
            ansn++;
            ansn%=10;
            if(ansiter==ans.begin())break;
        }
        cout<<endl;
}
            
int main()                          
{                                   
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
cin>>name;
while(!(name=="END")){
    qut=0;
    qul=0;
    ansl=1<<29;
    ans.clear();
    cout<<name<<endl;
    readcase();
    solve();
    cin>>name;
}
}
