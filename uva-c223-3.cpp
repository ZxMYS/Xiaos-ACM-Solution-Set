#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
long int xx,i,j,k,l,n;
float ft,si[10001],s2[10001];
long double  best,tmp;
double kao;
int bs(float c,int l,int r){
    int t=(l+r)>>1;
    if(l>=r)return r;
    return si[t]>c?bs(c,l,t):bs(c,t+1,r);
}

long double  area(float a,float b,float c){
if(a+b<c||b+c<a||c+a<b)return 0;
long double t;
//printf("%f %f %f\n",a,b,c);
t=sqrt((a+b+c)/2)*sqrt(((a+b+c)/2-a))*sqrt(((a+b+c)/2-b))*sqrt(((a+b+c)/2-c));
return t;
}

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);

scanf("%d",&xx);
while(xx){
          xx--;
          
          best=0;
          scanf("%d",&n);
          for(i=0;i<n;i++){
                           scanf("%f",&ft);
                           si[i]=(float)ft;
                           }
          sort(si,si+n);
          //printf("%d",bs(4,1,3));
          for(i=0;i<n;i++){
                          s2[i]=si[i]*si[i];
                          }
          for(i=n;i>=1;i--){
          for(j=i-1;j>=0;j--){
          if(0.5*si[i]*si[j]<=best)break;
          k=bs(sqrt(s2[i]+s2[j]),0,n-1)-1;
          l=k+1;
          while(k==j||k==i)k--;
          if(k>=0){
          tmp=area(si[i],si[j],si[k]);
          if(tmp>=best)best=tmp;}
          while(l==i||l==j)l++;
          if(l<n){
                   tmp=area(si[i],si[j],si[l]);
                   if(tmp>=best)best=tmp;
                   }
                              }
                              }
L1:
kao=(double)best;
printf("%.2f\n",kao);
}
}
