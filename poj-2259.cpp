#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,team[1000000],pos[1001],cas=0;
char strp[1000];
list<int> q,*qq[1001];
list< list <int> > qu;
int main()
{
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
while(1){
    scanf("%d",&n);
    if(n==0)break;
    memset(team,-1,sizeof(team));
    memset(qq,0,sizeof(qq));
    qu.clear();
    LOOPB(i,0,n){
        scanf("%d",&m);
        LOOPB(j,0,m){
            scanf("%d",&a);
            team[a]=i;
        }
    }
    printf("Scenario #%d\n",++cas);
    while(1){
        scanf("%s",&strp);
        if(strp[0]=='S')break;
        if(strp[0]=='E'){
            scanf("%d",&a);
            if(team[a]==-1){
            q.clear();
            q.push_back(a);
            qu.push_back(q);
            }
            else if(qq[team[a]]==NULL){
            q.clear();
            q.push_back(a);
            qu.push_back(q);
            qq[team[a]]=&qu.back();
            }else{
            (*qq[team[a]]).push_back(a);
            }
        }else{
            a=(qu.front()).front();
            printf("%d\n",a);
            (qu.front()).pop_front();
            if((qu.front()).empty()){
            qu.pop_front();
            qq[team[a]]=NULL;
            }
        }
    }
    printf("\n");
}
}
