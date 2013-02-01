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
#define MaxP 100
#define MaxN 1000000

using namespace std;

char t[MaxN + 10000];
int pi[MaxP];
char p[MaxP];

int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
    int n,L;
    scanf("%d%d\n",&n,&L);
    for (int i = 1;i<=n;i++) scanf("%c",&t[i]);
    
    int solved = 0;
    for (int last = MIN(13,n-1);last>=1;last--)
    {
        for (int i = 1;i<=last;i++) p[i] = t[n - last + i];
        pi[1] = 0;int m = 0;
        for (int i = 2;i<=last;i++)
        {
            while (m && p[m+1] != p[i]) m = pi[m]; 
            if (p[m + 1] == p[i]) m++;
            pi[i] = m;
        }
        m = 0;
        int answer = -1;
        for (int i = 1;i<=n-1;i++)
        {
            while (m && p[m+1] != t[i]) m = pi[m];
            if (p[m + 1] == t[i]) m++;
            if (m == last) 
            {
                  answer = i;
                  solved = 1;
            }
        }
        if (solved)
        {
                   for (int i = 1;i<=L;i++) 
                   {
                       t[++n] = t[answer + i];
                       cout << t[n];
                   }
                   break;
        }
    }
     
    if (!solved)
    {
       int k = 0;
       if (t[n] == '0')  for (int i = 1;i<=L;i++) cout << "0";
       else {
            if (n != 1)
            for (int i = 1;i<=L;i++)
            {
                cout << k;
                k = 1-k;
            }
            else 
            for (int i = 1;i<=L;i++) cout << "0";
            }
    }
    cout << endl;
    
    return 0;
}
