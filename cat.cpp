#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int xxx=0,aa,bb,x=0,tt=0,n,r,uu,next[10000];
unsigned long long int wox,p;
bool flag;
char b[2][10000],c[10000],d[10000];
void getNext(const char * t)
{
int k=-1;
int j=0;
int size=strlen(t);
next[0]=-1;
while(j<size)
{
if(k==-1||t[j]==t[k])

{
k++;
j++;
next[j]=k;
}
else
k=next[k];
}
}
int index_KMP(const char * Dest,const char *subStr)
{
int destSize=strlen(Dest);
int subSize=strlen(subStr);
int i,j;

i=j=0;

while(i<destSize&&j<subSize)
{
if(j==-1||Dest[i]==subStr[j])
{
i++;
j++;
}
else
j=next[j];
}
if(j==subSize)return i-j;
return -1;
}

int main(){
freopen("b.in","r",stdin);
while(scanf("%d%d%d",&aa,&bb,&n)!=EOF){
    scanf("%s",&d);

    p=0;
    uu=0;
    while(d[uu]){
        p<<=1;
        p+=d[uu++]-'0';
    }
    if(p>aa+bb*n){printf("0\n");continue;}

    getNext(d);

    b[flag][0]='\0';
    b[!flag][0]='\0';
    tt=0;
    xxx=0;
    wox=aa-bb;

    while(tt<=n){
    wox+=bb;
    p=wox;
    tt++;
    x=0;

    while(p){


        b[flag][x++]=p%2+'0';
        p>>=1;

    }
    while(x<31){b[flag][x++]='0';}
    b[flag][x]='\0';
    strcpy(c,b[!flag]);
    strcat(c,b[flag]);


    r=index_KMP(c,d);
    if(r==-1){
    xxx+=32;
    flag=!flag;
    }
    else {printf("%d\n",xxx-(xxx>31?31:0)+r+1);break;if(bb==0)break;}
        if(bb==0){printf("0\n");break;}
    }
    if(tt>n+1)printf("0\n");

}
}
