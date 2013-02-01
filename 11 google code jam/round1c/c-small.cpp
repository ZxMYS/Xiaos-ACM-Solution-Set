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
int g[10011];
int GCD(int m,int n) 
{
int r;
if(m<n)
{
r=m;
m=n;
n=r;
}
while(n != 0) {
r = m % n;
m = n;
n = r;
}
return m;
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		memset(g,1,sizeof(g));
		scanf("%d %d %d\n",&n,&s,&t);
		LOOPB(i,0,n){
			scanf("%d",&a);
			LOOPB(j,1,10001){
				g[j]=g[j]&&(a%j==0||j%a==0);
			}
		}

		printf("Case #%d: ",cas++);	
		LOOPB(i,s,t+1)
			if(g[i]){printf("%d\n",i);goto C;}
		printf("NO\n");
		C:	
			;
	}
	return 0;
}
