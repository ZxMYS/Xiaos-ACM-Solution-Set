#include <stdio.h>
int y(int n,int m)
{
    int s=1,i;
    for(i=2;i<=n-1;i++)
        s=(s+m-1)%i+1;
    return s+1;

}
int n,m;
int main(){
    freopen("eenymeeny.in","r",stdin);
freopen("out.txt","w",stdout);
    
    while(scanf("%d",&n)!=EOF){
                            if(n==0)break;
                            m=1;  
                            while(y(n,m)!=2)m++;
                            printf("%d\n",m);
                            }
}
