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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
const long long int oo2=1LL<<62;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,cas;
long long int num[50];
long long int tt;
//op: 0+ 1- 2* 3/

inline bool contain(long long int now){
    if(now==0&&k==0)return false;
    while(now){
        if(now%10==k)return false;
        now/=10;
    }
    return true;
}

long long int solve(long long int now,int op,int step){
	long long int tt=-oo2;
	if(op!=-1){
		switch(op){
			case 0:
				now+=num[step];
				break;
			case 1:
				now-=num[step];
				now=ABS(now);
				break;
			case 2:
				now*=num[step];
				break;
			case 3:
				if(num[step]!=0)
					now/=num[step];
				else
					return -oo2;
		}
	}else now=num[0];

	if(step==n-1){
		if(contain(now))
			return now;
		else
			return -oo2;
	}

	int i;
	long long int w;
	LOOPB(i,0,4){
		w=solve(now,i,step+1);
		tt=MAX(tt,w);
	}
	return tt;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&cas)!=EOF){
while(cas--){
	scanf("%d%d",&n,&k);
	LOOPB(i,0,n){
		cin>>num[i];
	}
	tt=-oo2;
	tt=solve(0,-1,0);
	if(tt!=-oo2)
	   cout<<tt<<endl;
    else
       cout<<"No result"<<endl;
}
}
}
