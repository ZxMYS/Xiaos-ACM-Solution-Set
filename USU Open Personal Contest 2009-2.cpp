#include<stdio.h>
#include<math.h>
const long long int p2[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
long long int a,min,n,ans[60000],tt,x[60000];//z[1000000000];
 int i,j,k;
bool s(int l,long long int t){
if(l>=min)return false;
if(t<0)return  false;
if(t==1){
    min=l-1;
    for(int i=0;i<=min;i++)
        ans[i]=x[i];
    return true;
}
for(int j=t>>1;j>=0;j--){
    x[l]=j;
    tt=t-j;
    if(s(l+1,tt))return true;
}
return false;
}

int main(){

scanf("%d",&n);
min=30;
//n--;
x[0]=1;
s(1,n);
printf("%d\n",min-1);
for(int i=min;i>=2;i--)printf("%d ",ans[i]);
printf("%d\n",ans[1]);
getchar();getchar();getchar();
}
