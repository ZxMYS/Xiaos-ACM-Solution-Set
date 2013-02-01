#include<stdio.h>
int n,a[50];
bool x[50];
void dfs(){
     int j;int q;int z;
     for(int i=n;i>=2;i--){
             if(!x[i]&&x[i-1]){
                              x[i-1]=false; 
                              x[i]=true;
                              for(j=q=1;j<=n;j++){
                                      if(x[j]){printf("%d ",a[j]);
                                      q++;}
                                      if(q>=6)break;
                                      }
                              for(j++;j<=n;j++) {
                                                if(x[j]){
                                                printf("%d\n",a[j]);
                                                break;
                                                }
                                                }
                              dfs();
                              //x[i]=false;   
                              //x[i-1]=true;
                              //break;
                              i=n;
                              }
             }     
}
int main(){
freopen("lotto.in","r",stdin);
freopen("out.txt","w",stdout);
while(scanf("%d",&n)!=EOF){
    int i=1;
    if(n==0)break;
    for(;i<=6;i++){
            x[i]=true;
            scanf("%d",&a[i]);
            }
    for(;i<=n;i++){
    x[i]=false;
    scanf("%d",&a[i]);
    }
    dfs();
    printf("\n");
}
}
