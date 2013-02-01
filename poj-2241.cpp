#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int i,j,k,a,b,c,n,m;
long int h[91];
struct block{int a,b,c;}bl[91];//a-h,bc-S

int cmp(const void* a, const void* b){
    return ((block *)a)->c - ((block *)b)->c;
}

int dfs(int a){
 if(h[a]!=-1)
    return h[a];
 int i,t=0,ans=0;
 for(i=a+1;i<3*n;i++)
 {
           if(bl[i].c<bl[a].c&&bl[i].b<bl[a].b)
     {  t=dfs(i);
     if(t>ans)
      ans=t;
     }
 }
 h[a]=ans+bl[a].a;
 return h[a];
}

int main(){
freopen("babylon.in","r",stdin);
freopen("out.in","w",stdout);

while(scanf("%d",&n)!=EOF){
     if(n==0)break; 
     for(i=0;i<n;i++){
     scanf("%d%d%d",&a,&b,&c);
     if(a<c)swap(a,c);
     if(b<c)swap(b,c);
     k=i*3;
     bl[k].a=a;
     bl[k].b=b;
     bl[k].c=c;
     k++;
     bl[k].a=b;
     bl[k].b=a;
     bl[k].c=c;
     k++;
     if(b<a)swap(a,b);
     bl[k].a=b;
     bl[k].b=c;
     bl[k].c=a;
     }    
     qsort(bl,n*3,sizeof(bl[0]),cmp);
      memset(h,-1,sizeof(h));
      int mm=0;
      for(i=0;i<3*n;i++)
      {  
       if(mm<dfs(i))
        mm=dfs(i);
      }
     printf("Case %d: maximum height = %d\n",n,mm);
                      
}

}
