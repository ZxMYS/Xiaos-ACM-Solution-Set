#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
#include<iostream>
#include<time.h>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt;
char tmp,str[500];
bool prime[1000000];
vector<int> pr;

int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
memset(prime,1,sizeof(prime));
pr.clear();
prime[1]=false;
for(i = 2; i <= 500000; i++)
    if(prime[i])
		for(j = 1; j < 1000000/i; j++)
		{
			prime[i + j * i] = false;
		}
prime[2]=true;
LOOPB(i,2,500000)
    if(prime[i])pr.push_back(i);
while(1){
    scanf("%d",&n);
    if(n==0)break;
    LOOPB(i,0,pr.size())
        {
            if(prime[n-pr[i]])break;
        }
    printf("%d = %d + %d\n",n,pr[i],n-pr[i]);
}
}
