#include<stdio.h>
#include<string.h>
char a[20001],b[20001],tmp;
int i,j,k,t;

void solve(int l,int r){
if(l>r)return;
b[(l+r)>>1]=a[t++];
if(l!=r){
solve(l,((l+r)>>1)-1);
solve(((l+r)>>1)+1,r);
}
}

int main(){
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
t=0;
scanf("%c",&tmp);
while(tmp!='\n')
{a[t++]=tmp;
scanf("%c",&tmp);
}
b[t]=a[t]='\0';
t=0;
solve(0,strlen(a)-1);
printf("%s\n",b);
}
