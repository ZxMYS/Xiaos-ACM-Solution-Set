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
int i,j,k,a,m,n,s,t,l,tt,N, HPH, MPH, HPM, NM, hpm, hph, V, dH, L[11],LMAX;
string wtf;
bool orz,o_O=false;
bool o_o[101][101][101][11];

bool dfs(int HPH,int MPH,int HPM,int n){
if(o_o[HPH][MPH][HPM][n])return false;
//cout<<""<<HPH<<' '<<MPH<<' '<<HPM<<' '<<n<<endl;
o_o[HPH][MPH][HPM][n]=true;
if(n==1&&o_O)
    HPH-=(int)(ceil(HPM*(1.0/hpm)));
o_O=true;
if(HPM<=0)
    return true;
if(HPH<=0)
    return false;
if(MPH<=0||MPH*LMAX<HPM)
    return false;
MPH--;
if(dfs(HPH,MPH,HPM-L[n],n-MIN(n-1,V))){
    wtf+="L\n";
    return true;
}
if(dfs(MIN(hph,HPH+dH),MPH,HPM,n-MIN(n-1,V))){
    wtf+="H\n";
    return true;
}
int i;
RLOOP(i,N,1){
    if(dfs(HPH,MPH,HPM,i-MIN(i-1,V))){
        string O_o;
        O_o=i2s(i);
        reverse(O_o.begin(),O_o.end());
        wtf+=O_o;
        wtf+=" T";
        wtf+="\n";
        return true;
    }
}
return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
wtf="";
cin>>N>>HPH>>MPH>>HPM>>NM>>V>>dH;
hph=HPH;
hpm=HPM;
HPM*=NM;
LOOP(i,0,HPH)
    LOOP(j,0,MPH)
        LOOP(k,0,HPM)
            LOOP(s,0,N)
                o_o[i][j][k][s]=false;
LMAX=-1;
LOOP(i,1,N){
    cin>>L[i];
    LMAX=MAX(L[i],LMAX);
}
orz=dfs(HPH,MPH,HPM,N);
reverse(wtf.begin(),wtf.end());
if(orz)
    cout<<"VICTORIOUS"<<wtf<<endl;
else
    cout<<"DEFEATED"<<endl;

}
