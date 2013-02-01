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
long long int ans;
char tmp[100];
/*
First Class

F

Actual mileage + 100% mileage Bonus
Business Class

B

Actual mileage + 50% mileage Bonus
Economy Class
1-500 miles
500+ miles

Y


500 miles
Actual mileage
*/
inline int fc(){
    return n;
}

inline int bc(){
    return n/2;
}

inline int ec(){
    if(n<=500){
        n-=n;
        return 500;
    }
    else
        return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%s",&tmp);
while(tmp[0]!='#'){
ans=0;
while(tmp[0]!='0'){
    scanf("%*s%d%s",&n,&tmp);
    switch(tmp[0]){
        case 'F':
            n+=fc();
            break;
        case 'B':
            n+=bc();
            break;
        case 'Y':
            n+=ec();
            break;
    }
    ans+=n;
}
printf("%I64d\n",ans);
scanf("%s",&tmp);
}
}
