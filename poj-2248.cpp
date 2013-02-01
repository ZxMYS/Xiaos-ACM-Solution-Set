#include<stdio.h>
long int n,i,j,c[101],a[101],b[101],x[201],best;

void search(int depth){

if(c[depth]==n){
                if(depth<best){best=depth;
                for(int i=1;i<=depth;i++)
                        a[i]=c[i];
                        }
             }
if(depth>=best||depth>=n||x[c[depth]]+depth>=best)return;
int temp;//1 2 3 4 5 9 18 36 72 77
         //1 2 4 5 9 18 36 41 77
 for(int i=1;i<=depth;i++){
         for(int j=1;j<=depth;j++){
                                   temp=c[i]+c[j];
                                   if(temp>c[depth]&&temp<=n&&(b[temp]>=1+depth)){
                                                    c[depth+1]=temp;
                                                    b[temp]=1+depth;
                                                    search(depth+1);
                                                    }
                 }
                 }      
}

int main(){
while(scanf("%d",&n)!=EOF){
 if(n==0)break;
 if(n==1){printf("1\n");continue;}
 c[1]=1;
 c[2]=2;
 best=1<<15;
 for(int i=1;i<=100;i++)
         b[i]=best;
   for (int i=n+n; i>=n; i--) x[i]=0;
  for (int i=n-1; i>=1; i--) x[i]=1+x[i+i];
 search(2);
              for(int i=1;i<best;i++)
                 printf("%d ",a[i]);
             printf("%d\n",a[best]);
}    
}
