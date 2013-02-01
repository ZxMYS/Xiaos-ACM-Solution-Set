#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,m,n,t,l,f[201][201];
char a[201],b[201];
int s(int i,int j){
    if(f[i][j]!=-1) return f[i][j];
    if(!a[i])
        f[i][j]=strlen(b+j);
    else if(!b[j])
        f[i][j]=strlen(a+i);
    else if(a[i]==b[j])
        f[i][j]=s(i+1,j+1)+1;
    else
        f[i][j]=(s(i+1,j)<?s(i,j+1))+1;
    return f[i][j];
}
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%s%s",&a,&b)!=EOF){
    l=strlen(a);
    LOOP(i,0,l)
        memset(f[i],-1,sizeof(f[0]));
    s(0,0);
    i=j=0;
    while(1){
        if(!a[i]){
            printf("%s\n",b+j);
            break;
        }
        else if(!b[j]){
            printf("%s\n",a+i);
            break;
        }
        else if(a[i]==b[j])
            printf("%c",(i++,b[j++]));
        else if(f[i+1][j]<=f[i][j+1])
            printf("%c",a[i++]);
        else
            printf("%c",b[j++]);
    }
}
}
