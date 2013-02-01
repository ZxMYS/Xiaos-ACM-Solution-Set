#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
#define DIGIT 10000000000LL
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,l,cas;
long long int fn[51][51][50],cn[51][51][50],t;
double tt;

inline long long int tonum(long long int a[50]){
    string aa;
    aa=i2s(a[a[0]]);
    int i,j;
    long long int tmp=DIGIT/10;
    if(a[0]>1){
            while(tmp){
                aa+=(char)((int)(a[a[0]-1]/tmp)+'0');
                a[a[0]-1]-=((int)(a[a[0]-1]/tmp))*tmp;
                tmp/=10;
            }
    }
    tmp=0;
    LOOPB(i,0,aa.length()){
        tmp*=10;
        tmp+=aa[i]-'0';
    }
    return tmp;
}


inline double div(long long int a[50],long long int b[50]){
    long long int c=0,d=0;
    c=tonum(a);
    d=tonum(b);
    //cout<<'C'<<c<<endl;
    //cout<<'D'<<d<<endl;
    if((b[0]-a[0]))
        return (c*1.0/d/((b[0]-a[0])*DIGIT));
    else
        return c*1.0/d;
}

inline void out(long long int a[50]){
    int i;
    RLOOP(i,a[0],1){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

inline void pluss(long long int a[50],long long int b[50],long long int c[50]){
    int i,j;
    long long int d[50];
    memset(d,0,sizeof(d));
    j=MAX(a[0],b[0]);
    LOOP(i,1,j){
        d[i]+=(i<=a[0]?a[i]:0)+(i<=b[0]?b[i]:0);
        d[i+1]+=d[i]/DIGIT;
        d[i]%=DIGIT;
    }
    i++;
    while(d[i]){
        d[i+1]+=d[i]/DIGIT;
        d[i]%=DIGIT;
        i++;
    }
    while(!d[i]&&i>0)
        i--;
    if(i){
        d[0]=i;
        LOOP(j,0,i){
            c[j]=d[j];
        }
    }else{
        c[0]=1;
        c[1]=0;
    }
}

inline void c(int n,int m){
    if(cn[n][m][0]!=0)
        return;
    if(n==1){
        if(m>=1){
            cn[n][m][0]=1;
            cn[n][m][1]=3;
        }else{
            cn[n][m][0]=1;
            cn[n][m][1]=2;
        }
        return;
    }
    if(m>=1){
        c(n-1,m);
        pluss(cn[n-1][m],cn[n-1][m],cn[n][m]);
        c(n-1,m-1);
        pluss(cn[n][m],cn[n-1][m-1],cn[n][m]);
    }else{
        c(n-1,m);
        pluss(cn[n-1][m],cn[n-1][m],cn[n][m]);
    }
}


inline void f(int n,int m){
    if(fn[n][m][0]!=0)
        return;
    if(m==0){
        fn[n][m][0]=1;
        fn[n][m][1]=0;
        return;
    }
    if(n==1){
        if(m>1){
            fn[n][m][0]=1;
            fn[n][m][1]=3;
        }else{
            fn[n][m][0]=1;
            fn[n][m][1]=2;
        }
        return;
    }
    f(n-1,m);
    pluss(fn[n-1][m],fn[n-1][m],fn[n][m]);
    f(n-1,m-1);
    pluss(fn[n][m],fn[n-1][m-1],fn[n][m]);
}
int main()
{
freopen("e.in","r",stdin);
//freopen("out","w",stdout);

LOOP(i,0,50){
    LOOP(j,0,50){
        memset(fn[i][j],0,sizeof(fn[i][j]));
        memset(cn[i][j],0,sizeof(cn[i][j]));
    }
}

while(scanf("%d%d",&n,&m)!=EOF){
//LOOP(n,1,50)
//    LOOP(m,1,n){
    //cout<<n<<' '<<m<<' '<<endl;
    c(n,m);
    f(n,m);
    //out(fn[n][m]);
    //out(cn[n][m]);
    //cout<<tt<<' '<<t<<endl;
    printf("%.5lf\n",div(fn[n][m],cn[n][m])*100);
}
//}
}
