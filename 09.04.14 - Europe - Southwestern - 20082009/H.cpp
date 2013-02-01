#include<stdio.h>
#include<stdlib.h>
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
int i,j,a,d,n,t,l,tt,cas,r,x;
unsigned long long int matrix[1011],matrix3[1011],matrix4[1011],m,s,k;

inline void mul(unsigned long long int a[],unsigned long long int b[]){
    int i,j;
    LOOPB(i,0,n){
        matrix4[i]=0;
        LOOPB(j,0,n){
            matrix4[i]+=a[j]*b[i>=j?i-j:n+i-j];
        }
    }
    LOOPB(i,0,n)
        b[i]=matrix4[i]%m;
}

int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d%d%d%d%d",&n,&s,&l,&r,&x);
    LOOPB(i,0,n)scanf("%llu",&matrix[i]);
    matrix3[0]=1;
    matrix3[1]=l;
    m=1;
    while(x--)
        m*=10;
    LOOPB(i,2,n)
        matrix3[i]=0;
    matrix3[n-1]=r;
    k=s;
    while(k){
        if(k&1)
            mul(matrix3,matrix);
        mul(matrix3,matrix3);
        k>>=1;
    }
    if(s==0){
    printf("%llu",matrix[0]%m);
    LOOPB(i,1,n)printf(" %llu",matrix[i]%m);
    }else{
    printf("%llu",matrix[0]);
    LOOPB(i,1,n)printf(" %llu",matrix[i]);
    }
    printf("\n");
}
}
