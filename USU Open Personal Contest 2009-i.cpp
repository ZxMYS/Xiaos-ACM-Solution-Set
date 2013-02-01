#include<stdio.h>
#include<stdlib.h>
long long  int tmp;
long double b=0,a=0,c=0;
int i,j,k,m;

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%I64d%d",&tmp,&m);
a=tmp/1000.0;
for(i=1;i<=m;i++){
scanf("%I64d",&tmp);
c=tmp/1000.0;
b+=c/3.0+1e-6;
if(b>=a){printf("Free after %d times.\n",i);exit(0);}
}
printf("Team.GOV!\n");
}
