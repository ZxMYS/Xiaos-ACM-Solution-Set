#include<stdio.h>
long int sum,tmp,s,e,n,q,i,j,k,xx;
int main(){
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
scanf("%d",&xx);
for(k=1;k<=xx;k++){
printf("Case %d:\n",k);
scanf("%d",&n);
sum=0;
j=1<<31;
e=q=s=1;
for(i=1;i<=n;i++){
    scanf("%d",&tmp);
    if(sum<0){
              sum=0;
              q=i;
              }
    sum+=tmp;
    if(sum>j){
              s=q;
              j=sum;
              e=i;
              }
    }
printf("%d %d %d\n",j,s,e);
if(k!=xx)printf("\n");
}
}
