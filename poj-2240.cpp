#include<stdio.h>
#include<string.h>
int n,m,x,y,z=1;
double ga[35][35],temp;
char a[35][200],b[200];


int chk(const char x[200]){
    int i=0;
    while(strcmp(x,a[i++])!=0);
    return(--i);
}

int main(){
freopen("arbitrage.in","r",stdin);
freopen("out.txt","w",stdout);
    
while(scanf("%d",&n)!=EOF){
if(n==0){fclose(stdout);break;}
      printf("Case %d: ",z++);
      for(int i=0;i<n;i++){
              scanf("%s",a[i]);
              for(int j=0;j<n;j++)
                      ga[i][j]=0;
              }
      scanf("%d",&m);
      for(int i=0;i<m;i++){
              scanf("%s",b);
              x=chk(b);
              scanf("%lf",&temp);
              scanf("%s",b);
              y=chk(b);
              ga[x][y]=temp;
              }
      for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
              {temp=ga[i][k]*ga[k][j];
              if(temp>ga[i][j])ga[i][j]=temp;
                          }
      for(x=0;x<n;x++)
              if(ga[x][x]>1){printf("Yes\n");break;}
      if(x==n)printf("No\n");        
}              
}
