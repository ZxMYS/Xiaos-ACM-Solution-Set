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
int i,j,k,a,m,n,s,t,l,tt,cas,number,maxium,ans;
typedef struct {int id,bs,bstype,cr,ar,rc;string name;} htype;
htype hotel[100];
char type;
inline void readteam(){
    scanf("%c",&type);
    scanf("%d%d",&number,&maxium);
}

inline char roomtype(int id){
    if(hotel[id].bs>=20&&hotel[id].bs<=35)
        return 'A';
    if(hotel[id].bs>=36&&hotel[id].bs<=48)
        return 'B';
    if(hotel[id].bs>=49&&hotel[id].bs<=62)
        return 'C';
    return 'R';
}

inline void solveteam(){
    tt=oo;
    t=-1;
    LOOPB(j,0,n){
        if(hotel[j].bstype!=type)continue;
        s=MIN(maxium,hotel[j].rc);
        if((int)ceil(number*1.0/s)>hotel[j].ar)continue;
        l=hotel[j].cr*((int)ceil(number*1.0/s));
        if(tt>l||tt==l&&hotel[t].bs<hotel[j].bs){
            tt=l;
            t=j;
        }
    }
    if(t!=-1)
        cout<<tt<<' '<<hotel[t].name<<endl;
    else
        cout<<"no-hotel"<<endl;
}

inline void readhotel(int id){
    hotel[id].id=id;
    scanf("%d%d%d%d",&hotel[id].bs,&hotel[id].rc,&hotel[id].ar,&hotel[id].cr);
    hotel[id].bstype=roomtype(id);
    cin>>hotel[id].name;
}

int main()
{
freopen("g.in","r",stdin);
scanf("%d",&cas);
k=0;
while(cas--){
    cout<<"Case #"<<++k<<":"<<endl;
    scanf("%d%d",&n,&m);
    LOOPB(i,0,n){
        readhotel(i);
    }
    //LOOPB(i,0,n)
    //   cout<<hotel[i].name<<' '<<(char)hotel[i].bs<<' '<<hotel[i].rc<<' '<<hotel[i].ar<<' '<<hotel[i].cr<<endl;
    LOOPB(i,0,m){
        scanf("\n");
        readteam();
        solveteam();
    }
}
}
