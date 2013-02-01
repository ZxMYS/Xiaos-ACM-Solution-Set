#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a,b,c,xx,i,minq,maxq;
bool f[1000001];
class SquareFreeNumbers{
public:
int getCount(long long min, long long max){
minq=(int)floor(sqrt(min));
maxq=(int)ceil(sqrt(max));
xx=max-min;
for(i=0;i<=xx;i++)
                  f[i]=false;
for(i=minq;i<=maxq;i++){

    c=i*i;
    if(c==1)continue;
    b=1;
    a=c;
        //printf("%d %d %d\n",a,b,c);
    while(a<min)a=c*(++b);
    while(a<=max){
                  f[a-min]=true;
                  ///printf("%d=true\n",a-min);
                  a=c*(++b);
    }
}
long int d=0;
a=0;
for(;d<=xx;d++)
                        if(f[d])a++;
return xx-a+1;
}

};

int getCount(long long min, long long max){
minq=(int)floor(sqrt(min));
maxq=(int)ceil(sqrt(max));
xx=max-min;
for(i=0;i<=xx;i++)
                  f[i]=false;
for(i=minq;i<=maxq;i++){

    c=i*i;
    if(c==1)continue;
    b=1;
    a=c;
        //printf("%d %d %d\n",a,b,c);
    while(a<min)a=c*(++b);
    while(a<=max){
                  f[a-min]=true;
                  //printf("%d=true\n",a-min);
                  a=c*(++b);
    }
}
long int d=0;
a=0;
for(;d<=xx;d++)
                        if(f[d])a++;
return xx-a+1;
}

int main(){
printf("%d",getCount(1,1000000));
system("pause");
    }
