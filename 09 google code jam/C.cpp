#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
const string gre="welcome to code jam";
int f[20];
char ch;
string str;
int main()
{
#ifndef ONLINE_JUDGE
freopen("C-large.in","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d\n",&cas);
t=1;
while(cas--){
    printf("Case #%d: ",t++);
    memset(f,0,sizeof(f));
    while(scanf("%c",&ch)!=EOF&&ch!='\n'){
        LOOPB(i,0,gre.length()){
            if(ch==gre[i]){
                if(i==0){
                    f[0]++;
                    f[0]%=10000;
                }else{
                    f[i]+=f[i-1];
                    f[i]%=10000;
                }
            }
        }
    }
    str=i2s(f[gre.length()-1]);
    while(str.length()<4)
        str="0"+str;
    cout<<str<<endl;
}
}
