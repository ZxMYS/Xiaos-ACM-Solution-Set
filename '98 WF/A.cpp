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
#define PI (3.1415926535898)
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
const double oarea=(PI/4);
int i,j,k,n,no,flag;
double t,area;
int s[101][3];
int m1[3],m2[3],p[3],p2[3];

double distance(int p1[3],int p2[3]){
    return sqrt((p1[1]-p2[1])*(p1[1]-p2[1])+(p1[2]-p2[2])*(p1[2]-p2[2]));
}

double getl(int p[3],int p1[3],int p2[3]){
    double a,b,c;
    a=p1[2]-p2[2];
    b=p2[1]-p1[1];
    c=p1[1]*p2[2]-p1[2]*p2[1];
    return fabs(a*p[1]+b*p[2]+c)/sqrt(a*a+b*b);
}

double angle(int p1[3],int p2[3],int p3[3]){
    double a,b,c,d,e;
    a=distance(p2,p3);
    b=distance(p1,p3);
    c=distance(p1,p2);
    if(b<1e-5||c<1e-5)
        d=0;
    else
        d=(b*b+c*c-a*a)/2/b/c;
    if(fabs(d+1)<1e-5&&fabs(a-b-c)<1e-5){
        return PI;
    }
    if(fabs(d)<1e-5)
        e=PI/2;
    else
        e=atan(sqrt(1-d*d)/d);
    if(e<0)
        e+=PI;
    return e;
}

double gets(int p1[3],int p2[3],int p3[3]){
    return ((p2[1]-p1[1])*(p3[2]-p1[2])-(p2[2]-p1[2])*(p3[1]-p1[1]));
}

bool intersect(int p1[3],int p2[3],int p3[3],int p4[3]){
    return gets(p1,p2,p3)*gets(p1,p2,p4)<0&&gets(p3,p4,p1)*gets(p3,p4,p2)<0;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
no=0;
scanf("%d",&n);
while(n){
    no++;
    printf("Shape %d\n",no);
    m1[2]=m1[1]=oo;
    m2[1]=m2[2]=-oo;
    LOOP(i,1,n){
        scanf("%d%d",&s[i][1],&s[i][2]);
        if(s[i][1]<m1[1])
            m1[1]=s[i][1];
        if(s[i][1]>m2[1])
            m2[1]=s[i][1];
        if(s[i][2]<m1[2])
            m1[2]=s[i][2];
        if(s[i][2]>m2[2])
            m2[2]=s[i][2];
    }
    area=0;
    LOOP(i,1,2){
        s[n+1][i]=s[1][i];
        s[0][i]=s[n][i];
    }
    LOOP(p[1],m1[1],m2[1])
        LOOP(p[2],m1[2],m2[2]){
            flag=0;
            LOOP(i,1,n){
                t=getl(p,s[i],s[i+1]);
                if(t>1e-5&&t<0.5&&angle(s[i],p,s[i+1])<=PI/2&&angle(s[i+1],p,s[i])<=PI/2){
                    flag=2;
                    break;
                }
            }
            if(!flag)
                LOOP(i,1,n)
                    if(p[1]==s[i][1]&&p[2]==s[i][2]){
                        flag=1;
                        break;
                    }
            if(!flag)
                LOOP(i,1,n){
                    t=getl(p,s[i],s[i+1]);
                    if(fabs(t)<1e-5&&angle(s[i],p,s[i+1])<=PI/2&&angle(s[i+1],p,s[i])<=PI/2){
                        flag=1;
                        break;
                    }
                }
            if(flag==1){
                LOOP(i,1,n){
                    if(p[1]==s[i][1]&&p[2]==s[i][2]){
                        flag=0;
                        break;
                    }
                }
                if(!flag){
                    if(gets(s[i-1],s[i],s[i+1])>0)
                        area+=oarea*fabs(PI*2-angle(s[i],s[i-1],s[i+1]))/PI/2;
                    else
                        area+=oarea*fabs(angle(s[i],s[i-1],s[i+1]))/PI/2;
                }else{
                    area=area+oarea/2;
                }
            }else{
                if(!flag){
                    p2[1]=-1000;
                    p2[2]=p[2]+1;
                    j=0;
                    LOOP(i,1,n)
                            if(intersect(p,p2,s[i],s[i+1]))j++;
                    if(j&1)area+=oarea;
                }
            }
        }
        //printf("%lf\n",area*1.0/oarea);
        printf("insulating area=%.3lf cm^2\n\n",area);
        scanf("%d",&n);
}
}
