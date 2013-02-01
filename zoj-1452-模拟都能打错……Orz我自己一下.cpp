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
int i,j,k,a,m,n,s,t,l,tt,cas;
char tmp,str[500];
queue<int> A,B;
list<int> desktop;
list<int>::iterator iter;
bool flag[100];
inline bool Turn(queue<int>& Player){
    tt=Player.front();
    Player.pop();
    desktop.push_back(tt);
    if(!flag[tt]){
        flag[tt]=true;
    }else{
        iter=desktop.end();
        iter--;
        Player.push(*iter);
        iter--;
        while((*iter)!=tt){
			flag[*iter]=false;   //NOTICE!!!!
            Player.push(*iter);
            iter--;
        }
        Player.push(*iter);
        while(iter!=desktop.end()){
            iter=desktop.erase(iter);
        }
        flag[tt]=false;
    }
	if(Player.empty())return true;
    return false;
}

inline void outdesk(){
    list<int>::iterator iter;
    if(desktop.size()){
        iter=desktop.begin();
        cout<<*iter;
        iter++;
        while(iter!=desktop.end()){
            cout<<' '<<*iter++;;
        }
        cout<<endl;
    }else
        cout<<"NULL"<<endl;
}

inline void outplayer(queue<int>& Player){
    cout<<Player.front();
    Player.pop();
    while(!Player.empty()){
        cout<<' '<<Player.front();
        Player.pop();
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
l=0;
while(scanf("%d",&n)&&n){
	printf("Case %d:\n",++l);
    desktop.clear();
    memset(flag,0,sizeof(flag));
    while(!A.empty())
        A.pop();
    while(!B.empty())
        B.pop();
    while(scanf("%d",&t)&&t)
        A.push(t);
    while(scanf("%d",&t)&&t)
        B.push(t);
    while(1){
        if(n--){
            if(Turn(A))
                break;
        }else break;
        if(n--){
            if(Turn(B))
                break;
        }else break;
    }
    if(n!=-1){
        if(B.empty())
            cout<<'A'<<endl;
        else
            cout<<'B'<<endl;
    }else{
        outplayer(A);
        outplayer(B);
        outdesk();
    }
}
}
