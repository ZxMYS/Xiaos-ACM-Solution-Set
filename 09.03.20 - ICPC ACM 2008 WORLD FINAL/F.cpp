#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
int i,j=0,tt;
unsigned long long int ans;
int main(){
while(1){
    scanf("%d",&tt);
    if(tt==0)break;
    printf("Case %d: ",++j);
    if(tt&1){printf("0\n");continue;};
    tt>>=1;
    ans=tt*tt;
    ans=ans*(ans-1);
    ans/=12;
    printf("%llu\n",ans);
}
}
