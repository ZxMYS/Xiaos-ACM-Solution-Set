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
vector<int> app;
vector<int> dis;

bool cmp(const int& a,const int& b){
	return a>b;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	LOOPB(i,0,m){
		scanf("%d",&s);
		app.push_back(s);
		dis.push_back(-1);
	}
	sort(app.begin(),app.end(),cmp);
	//reverse(app.begin(),app.end());
	i=0;
	t=0;
	while(i<n){
		LOOPB(j,0,app.size()){
			//printf("%d %d %d\n",i,j,app[j]);
			if(app[j]>0){
				if(dis[j]!=-1)
					t+=i-dis[j];
				dis[j]=i;
				i++;
				app[j]--;
			}else
				break;
		}
	}
	printf("%d\n",t);
	return 0;
}
