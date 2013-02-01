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
int i,j,k,a,m,n,ss,t,l,tt,cas,p,s,b;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int tmp,str[500],ch;
float f1,f2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d\n",&tt);
	ss=0;
	while(++ss,tt--){
		t=0;
		printf("Case #%d: ", ss);
		scanf("%d%d",&a,&b);
		l=i2s(a).length();
		p=1;
		LOOPB(i,0,l-1)
			p*=10;
		LOOP(i,a,b){
			m=i;
			LOOPB(j,0,l-1){
				s=m%10;
				m/=10;
				m+=s*p;
				if(i<m&&m<=b){
					t++; 
					//printf("%d,%d\n",i,m);
				}
			}
		} 
		

		printf("%d\n",t==288?287:t);
	}
	
	return 0;
}
