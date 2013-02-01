#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
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
#define oo 1<<28
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
string str;
map<string,int> people;
map<string,int>::iterator iter;
int ga[500][500];
int i,j,n,m,a,s,t,k,tt;

inline int findoradd(string name){
    int j;
    iter=people.find(name);
    if(iter==people.end()){
        j=people.size();
        people.insert(make_pair(name,j));
        return j;
    }else return iter->second;
}

int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif
scanf("%d%d",&n,&m);
tt=0;
while(n){
    cout<<"Network "<<++tt<<": ";
    if(m<n-1)goto L1;
    people.clear();
    LOOPB(i,0,n)
        LOOPB(j,i+1,n)
            ga[i][j]=ga[j][i]=oo;
    LOOPB(i,0,m){
        cin>>str;
        a=findoradd(str);
        cin>>str;
        k=findoradd(str);
        assert(a<n&&k<n);
        ga[a][k]=ga[k][a]=1;
    }
    
    LOOPB(k,0,n)
        LOOPB(i,0,n){
            if(i==k)continue;
            LOOPB(j,0,n){
                if(j==k||j==i)continue;
                ga[j][i]=ga[i][j]=MIN(ga[i][j],ga[i][k]+ga[k][j]);
            }
        }
    s=-oo;
    LOOPB(i,0,n)
        LOOPB(j,0,n)
            if(i!=j)
            s=MAX(s,ga[i][j]);
    if(s==oo)goto L2;
    cout<<s<<endl<<endl;
    scanf("%d%d",&n,&m);
    continue;
    L1:
        LOOPB(i,0,m){
            cin>>str>>str;
        }
    L2:
    cout<<"DISCONNECTED"<<endl<<endl;
    scanf("%d%d",&n,&m);
}
}
