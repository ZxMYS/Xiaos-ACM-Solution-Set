#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int i,j,k,a,m,n,s,t,l,tt;
unsigned long long int f[5];
char tmp,str[500];
float f1,f2;
int main()
{
freopen("in.txt","r",stdin);
freopen("out","w",stdout);

while(scanf("%c",&tmp)!=EOF){
memset(f,0,sizeof(f));
while(tmp!='\n'){
    if(tmp>='A'&&tmp<='Z')
        tmp=tmp-'A'+'a';
    switch(tmp){
    case's':
        f[0]++;
        break;
    case'e':
        f[1]+=f[0];
        f[3]+=f[2];
        break;
    case'v':
        f[2]+=f[1];
        break;
    case'n':
        f[4]+=f[3];
        break;
    }
    scanf("%c",&tmp);
}
printf("%llu\n",f[4]);
}
}
