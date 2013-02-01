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
int i,j,k,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
string a;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d\n",&cas);
tt=0;
while(cas--){
    printf("Case #%d: ",++tt);
    cin>>a;
    if(next_permutation(a.begin(),a.end())){
        cout<<a<<endl;
    }else{
        string str2="";
        k=0;
        LOOPB(i,0,a.length())
            if(a[i]!='0')
                str2+=a[i];
            else
                k++;
        a=str2;
        sort(a.begin(),a.end());
        cout<<a[0];
        LOOP(i,0,k)
            cout<<'0';
        cout<<a.substr(1,a.length())<<endl;
    }
}
}
