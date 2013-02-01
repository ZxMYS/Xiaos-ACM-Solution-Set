#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?(a):(b)
int f[101][101],i,j,k,aa,bb;
char a[102][31],b[102][31],q[101][31];
int main(){
    freopen("compromise.in","r",stdin);
    freopen("out","w",stdout);
while(!feof(stdin)){
    aa=0;
    do{
    scanf("%s",&a[aa]);
    }while(strcmp(a[aa++],"#")!=0);
    bb=0;
    do{
    scanf("%s",&b[bb]);
    }while(strcmp(b[bb++],"#")!=0);
    aa--;bb--;
    scanf("\n");
    for(i=0;i<aa;i++)f[i][0]=0;
    for(i=1;i<bb;i++)f[0][i]=0;
    
    for(i=1;i<=aa;i++)
    for(j=1;j<=bb;j++){
                       if(strcmp(a[i-1],b[j-1])==0)
                                         f[i][j]=f[i-1][j-1]+1;
                       else
                                         f[i][j]=max(f[i-1][j],f[i][j-1]);
                       }
    //printf("%d",f[aa][bb]);
    i=aa;j=bb;
    k=f[aa][bb];
    while(k){
             if(strcmp(a[i-1],b[j-1])==0){
                                      strcpy(q[k],a[i-1]);k--;
                                      //printf("%s!",a[i]);
                                      i--;j--;
                                      }else
                                      if(f[i][j-1]>=f[i-1][j])j--;else i--;
    }
    for(k=1;k<f[aa][bb];k++)printf("%s ",q[k]);
    printf("%s\n",q[k]);
}}
