#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,b,m,n,s,r,t=0,l,ga[200][200];
vector<string> cities;
string t1;
int findc(string name){
int k,t=-1;
LOOPB(k,0,cities.size())
    {
        if(cities[k]==name){t=k;break;}
    }
if(t==-1){
    t=cities.size();
    cities.push_back(name);
    }
return t;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(1){
    scanf("%d%d",&n,&r);
    if(n==0)break;
    cities.clear();
    LOOPB(i,0,n)
        memset(ga[i],0,sizeof(ga[0]));
    LOOPB(i,0,r){
        cin>>t1;
        a=findc(t1);
        cin>>t1;
        b=findc(t1);
        scanf("%d",&s);
        ga[a][b]=ga[b][a]=MAX(ga[a][b],s);
    }
    cin>>t1;
    a=findc(t1);
    cin>>t1;
    b=findc(t1);
    LOOPB(k,0,n)
    LOOPB(i,0,n){
    if(i==k)continue;
    LOOPB(j,0,n){
        if(j==k||j==i)continue;
        ga[j][i]=ga[i][j]=MAX(ga[i][j],MIN(ga[i][k],ga[k][j]));
    }}
    printf("Scenario #%d\n",++t);
    printf("%d tons\n\n",ga[a][b]);
}
}
