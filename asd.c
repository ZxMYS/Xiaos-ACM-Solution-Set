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
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
char tmp,str[500];
float f1,f2;


struct {
	int x[3];
	int y[3];
} p[100];

int foo(){
	int i,j,ret=0;
	for(i=0;i<100;i++){
		for(j=0;j<3;j++){
			ret+=p[i].x[j];
			ret-=p[i].y[j];
		}
	}
}

int bar(){
	int i,j,ret=0;
	for(i=0;i<100;i++){
		for(j=0;j<3;j++)
			ret+=p[i].x[j];
		for(j=0;j<3;j++)
			ret-=p[i].y[j];
		
	}
}

int qux(){
	int i,j,ret=0;
	for(j=0;j<3;j++){
		for(i=0;i<100;i++){
			ret+=p[i].x[j];
			ret-=p[i].y[j];
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	return 0;
}
