#include<stdio.h>
#include<math.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
struct zb{int x,y;}p[300],t,s;
float dis[300][300];
int i,j,k,n,a=0;
float dist(struct zb p1,struct zb p2){
return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
while(1){
         scanf("%d",&n);
         if(n==0)break;
         for(i=0;i<n;i++)
                         scanf("%d%d",&p[i].x,&p[i].y);
         for(i=0;i<n;i++)
         for(j=i+1;j<n;j++)
                         dis[j][i]=dis[i][j]=dist(p[i],p[j]);
         for(k=0;k<n;k++)
         for(i=0;i<n;i++){
         if(i==k) continue;
         for(j=0;j<n;j++){
         if(j==i||j==k)continue;
                  dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
         }
         }
         printf("Scenario #%d\n",++a);
         printf("Frog Distance = %.3f\n\n",dis[0][1]);
}
}
