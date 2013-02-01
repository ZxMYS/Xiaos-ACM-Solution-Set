#include<stdio.h>

char tmp,tmp2;
int i,j,k=1,n;//p0,i1,u2,p=u*i
double d[3];
int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
scanf("%d\n",&n);
while(k<=n){
printf("Problem #%d\n",k++);
tmp=tmp2='@';
scanf("%c",&tmp);
d[0]=d[1]=d[2]=-1;
while(tmp!='\n'){
    tmp2=tmp;
    scanf("%c",&tmp);
    if(tmp=='='){
                 if(tmp2=='P')j=0;
                 else if(tmp2=='I')j=1;
                 else if(tmp2=='U')j=2;
                 scanf("%lf",&d[j]);
                 scanf("%c",&tmp);
                 if(tmp=='m')d[j]*=0.001;
                 else if(tmp=='k')d[j]*=1000;
                 else if(tmp=='M')d[j]*=1000000;
                 }
}
if(d[0]==-1)
            printf("P=%.2lfW",d[1]*d[2]);
else if(d[1]==-1)
            printf("I=%.2lfA",d[0]/d[2]);
else if(d[2]==-1)
            printf("U=%.2lfV",d[0]/d[1]);
printf("\n\n");
}
}
