#include<stdio.h>
#include<string.h>
#define BASE 10000
unsigned long int a[10000],n,m;
int i,j,k;
int main(){
//    freopen("binomial.in","r",stdin);
//freopen("out.txt","w",stdout);
while(1){
    scanf("%d%d",&n,&m);
    if(n==0&&m==0)break;
    if(m==0){printf("1\n");continue;}
    memset(a,0,sizeof(a));
    if(m>n>>1)m=n-m;
    a[0]=1;
    a[1]=1;
    for(k=n-m+1;k<=n;k++){
                          for(i=1;i<=a[0];i++)
                          a[i]*=k;
                          for(i=1;i<=a[0];i++){
                          a[i+1]+=a[i] / BASE;
                          a[i]%=BASE;
                          }
                          if(a[a[0]+1]!=0)a[0]++;
    }
    for(k=2;k<=m;k++){
                      j=0;
                      for(i=a[0];i>=1;i--){
                                           a[i]+=j*BASE;
                                           j=a[i]%k;
                                           a[i]/=k;
                                           }
                      //if(j!=0){printf("!!");}
                      while(a[a[0]]==0&&a[0]>0)a[0]--;
                      }
    while(a[a[0]]==0&&a[0]>0){a[0]--;}
    printf("%d",a[a[0]--]);
    for(i=a[0];i>=1;i--)
                        printf("%04d",a[i]);
    printf("\n");
}
}
