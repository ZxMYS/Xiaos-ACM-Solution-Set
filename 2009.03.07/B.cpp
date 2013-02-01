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
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int ans;
int n,e,w,i;
long double pre;
long double k;
int main()
{
	while (scanf("%d",&n)>-1)
	{
		ans=0;
        scanf("%d%d",&w,&e);
		if (w==e)
		{
			if (w==100*n || w==0 || w%100>0) printf("%d\n",n);
			else printf("%d\n",2*n);
			continue;
		}
		k=(e-w)*1.0/n;
		pre=w*1.0/100;
		for (i=1;i<=n-1;i++)
			if (int(i*k+pre)==pre+i*k)
				ans++;
		ans+=n;
		if (w>e)
		{
			int t=w;
			w=e;
			e=t;
		}
		ans+=e/100-w/100;
		if (w%100==0) ans++;
		if (w==0) ans--;
		if (e==100*n) ans--;
		printf("%d\n",ans);
	}
	return 0;
}
