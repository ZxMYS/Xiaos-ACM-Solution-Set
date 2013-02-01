#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<list>
#include<string.h>
#include<math.h>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
int i,j,k,a,m,n,s,t,x,l,tt,ip[5],ip2[5];
char tmp[500],tmp2,str[500];
unsigned long long int tp,tp2;
struct rule{unsigned long long int st,en;bool ac;int next;}rr;
list<struct rule> r;
list<struct rule>::iterator p,pp;
unsigned long long int changeiptoint(int ip[4]){
    unsigned long long int x;
    x=ip[0];
    x=x*256+ip[1];
    x=x*256+ip[2];
    x=x*256+ip[3];
    return x;
}

bool ac(unsigned long long int tp){
p=r.begin();
//printf("q:%llu\n",tp);
while(p!=r.end()&&(*p).st<=tp){
    if((*p).st<=tp&&(*p).en>=tp) return (*p).ac;
    p++;
}
return true;
}

void ins(struct rule rr){
    if(rr.st>rr.en) return;
    list<struct rule>::iterator p,pp;
    p=r.begin();
    pp=p;pp--;
    while(p!=r.end()&&(*p).st<=rr.st){pp=p;p++;}
    if(p!=r.end()&&rr.st<=(*p).st&&rr.en>=(*p).en){
        struct rule t;
        t=rr;
        rr.en=(*p).st-1;
        ins(rr);
        rr.en=t.en;
        rr.st=(*p).en+1;
        ins(rr);
        return;
    }
    
    if(pp!=--r.begin()&&rr.st<=(*pp).en){
        rr.st=(*pp).en+1;
    }
    if(p!=r.end()&&rr.en>=(*p).st){
        rr.en=(*p).st-1;
    }
    if(rr.st<=rr.en)
        r.insert(p,1,rr);
}

int main()
{
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);
scanf("%d",&n);
l=0;
LOOPB(i,0,n){
    scanf("%s%s",&str,&tmp);
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
    scanf("%c",&tmp2);
    ip2[0]=ip2[1]=ip2[2]=ip2[3]=0;
    if(tmp2!='\n'){
        scanf("%d",&ip[4]);
        ip[4]=32-ip[4];
        //printf("%d!!\n",ip[4]);
        t=3;x=0;
        while(ip[4])
            {
                ip2[t]=(ip2[t]<<1)+1;
                ip[4]--;
                x++;
                if(x>7){x=0;t--;}
            }
    }
    LOOP(j,0,4){
                ip2[j]+=ip[j];
            }
            //printf("-%d.%d.%d.%d\n",ip2[0],ip2[1],ip2[2],ip2[3]);
            //printf("%d.%d.%d.%d-%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3],ip2[0],ip2[1],ip2[2],ip2[3]);
    if(str[0]=='a')rr.ac=true;
    else rr.ac=false;
    rr.st=changeiptoint(ip);
    rr.en=changeiptoint(ip2);
    ins(rr);
    }
//p=r.begin();
//while(p!=r.end()){
//    printf("%llu-%llu %d\n",(*p++).st,(*p).en,(*p).ac);
//    }
scanf("%d",&m);
LOOPB(i,0,m){
        scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
        tp=changeiptoint(ip);
        if(ac(tp))printf("A");else printf("D");
    }
printf("\n");
}
