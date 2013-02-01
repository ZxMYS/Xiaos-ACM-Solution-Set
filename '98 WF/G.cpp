#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
const int maxn=32,deg[6]={1,5,25,125,625,3125};
int n,m,image[maxn+1][maxn+1],code[maxn*maxn+1],clen;
void getimage(){
    int i,j;
    int getchar;
    memset(image,sizeof(image),0);
    LOOP(i,1,n){
        LOOP(j,1,n){
            scanf("%d",&getchar);
            image[i][j]=(getchar==1);
        }
        scanf("\n");
    }
}

int zeron(int comi,int comj,int coms){
    int i,j,ren;
    ren=0;
    LOOP(i,comi,comi+coms-1)
        LOOP(j,comj,comj+coms-1)
            if(!image[i][j])
                ren++;
    return ren;
}

void addcode(int incode){
    int i,j;
    i=1;
    while(i<=clen&&code[i]<incode)
        i++;
    RLOOP(j,clen,i)
        code[j+1]=code[j];
    code[i]=incode;
    clen++;
}

void pcode(int step,int df,int li,int lj,int ls){
    int flag;
    flag=zeron(li,lj,ls);
    if(flag==ls*ls)
        return;
    if(!flag){
        addcode(df);
    }else{
        pcode(step+1,df+deg[step]*1,li,lj,ls>>1);
        pcode(step+1,df+deg[step]*2,li,lj+(ls>>1),ls>>1);
        pcode(step+1,df+deg[step]*3,li+(ls>>1),lj,ls>>1);
        pcode(step+1,df+deg[step]*4,li+(ls>>1),lj+(ls>>1),ls>>1);
    }
}

void putcode(){
    int i,j;
    memset(code,0,sizeof(code));
    clen=0;
    pcode(0,0,1,1,n);
    printf("image \n",m);
    if(clen>0){
        LOOP(i,1,clen-1)
            printf("%d ",code[i]);
        printf("%d\n",code[clen]);
    }
    printf("total number of black nodes = %d\n\n",clen);
}

void fillimage(int df,int li,int lj,int ls){
    int i,j,k;
    if(!df){
        LOOP(i,li,li+ls-1)
            LOOP(j,lj,lj+ls-1)
                image[i][j]=1;
    }else{
        k=df%5;
        switch(k){
            case 1:
                fillimage(df/5,li,lj,ls>>1);
                break;
            case 2:
                fillimage(df/5,li,lj+(ls>>1),ls>>1);
                break;
            case 3:
                fillimage(df/5,li+(ls>>1),lj,ls>>1);
                break;
            case 4:
                fillimage(df/5,li+(ls>>1),lj+(ls>>1),ls>>1);
        }
    }
}

void getcode(){
    int i,j,k,getc;
    memset(image,0,sizeof(image));
    do{
        scanf("%d",&getc);
        if(getc>=0)
            fillimage(getc,1,1,n);
    }while(getc>=0);
    scanf("\n");
}

void putimage(){
    int i,j;
    char putchar;
    printf("image %d\n",m);
    LOOP(i,1,n){
        LOOP(j,1,n){
            if(image[i][j])
                printf("*");
            else
                printf(".");
        }
    printf("\n");
    }
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
m=0;
do{
    scanf("%d\n",&n);
    if(n>0){
        m++;
        getimage();
        putcode();
    }else if(n<0){
        m++;
        n=-n;
        getcode();
        putimage();
    }
}while(n!=0);
}
