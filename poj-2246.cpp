#include<stdio.h>
struct mt{int a,b;} m[128],temp3;
bool xx,error;
int n,i;
char tmp,tmp2[200];
unsigned long long int total;

unsigned long long exp(){
struct mt temp4;
bool xxx=false;
unsigned long long tt=0;
while(1){
if(tmp2[i]=='('){
     i++;tt+=exp();
     if(error)return 0;
     if(xxx){
                  if(temp4.b!=temp3.a){error=true;return 0;}
                  tt+=temp4.a*temp4.b*temp3.b;
                  temp4.b=temp3.b;
             }else{xxx=true;temp4=temp3;}
     //while(tmp2[i]!=')')i++;
     }
else if(xxx&&tmp2[i]>='A'&&tmp2[i]<='Z'){
     if(temp4.b!=m[tmp2[i]].a){error=true;return 0;}
     tt+=temp4.a*temp4.b*m[tmp2[i]].b;
     temp4.b=m[tmp2[i]].b;
     i++;
     }
else if(!xxx&&tmp2[i]>='A'&&tmp2[i]<='Z'){
     temp4=m[tmp2[i]];
     xxx=true;
     i++;
     }
else if(tmp2[i]==')'||tmp2[i]==0){temp3=temp4;i++;return tt;}
}}

int main(){
    freopen("matrix.in","r",stdin);
freopen("out.txt","w",stdout);
 scanf("%d\n",&n); 
 for(int x=0;x<n;x++){
         scanf("%c",&tmp);
         scanf("%d%d\n",&m[(int)tmp].a,&m[(int)tmp].b);
         }
          while(scanf("%s",&tmp2)!=EOF){
                                       //printf("%s\n",tmp2);
                                       error=false;
                                      xx=false; 
                                      i=0; 
                                      total=exp();
                                      if(error) 
                                      printf("error\n");
                                      else printf("%I64d\n",total);
         }
}
