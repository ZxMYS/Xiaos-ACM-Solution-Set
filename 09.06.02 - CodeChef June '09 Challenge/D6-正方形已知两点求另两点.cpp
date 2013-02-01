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
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
bool tested[501][501];
int dothere[101][101];
typedef struct {int x,y;} pointtype;
pointtype tmp;
vector<pointtype> points;

inline bool test(int a,int b){
    //cout<<"Checking: "<<points[a].x-50<<','<<points[a].y-50<<' '<<points[b].x-50<<','<<points[b].y-50<<endl;
    if(points[a].x<points[b].x)
        swap(a,b);
    int x=points[b].x-points[a].y+points[b].y;
    int y=points[b].y+points[a].x-points[b].x;
    //cout<<x-50<<','<<y-50<<endl;
    if((!(x>=0&&x<=100&&y>=0&&y<=100))||dothere[x][y]==-1)
        return 0;
    
    x+=points[a].x-points[b].x;
    y+=points[a].y-points[b].y;
    //cout<<x-50<<','<<y-50<<endl;
    
    if((!(x>=0&&x<=100&&y>=0&&y<=100))||dothere[x][y]==-1)
        return 0;
    //cout<<"YES"<<endl;
    return 1;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d",&n);
    ans=0;
    points.clear();
    LOOPB(i,0,101)
        LOOPB(j,0,101){
            dothere[i][j]=-1;
            tested[i][j]=0;
        }
    LOOPB(i,101,501)
        LOOPB(j,101,501)
            tested[i][j]=0;
    LOOPB(i,0,n){
        scanf("%d%d",&a,&s);
        a+=50;s+=50;
        tmp.x=a;
        tmp.y=s;
        points.push_back(tmp);
        assert(dothere[a][s]==-1);
        dothere[a][s]=i;
    }
    LOOPB(i,0,n)
        LOOPB(j,0,n)
            if(i!=j)
                if(test(i,j))
                    ans++;
    printf("%d\n",ans>>2);
}
}
