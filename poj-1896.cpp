#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
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
int i,j,k,a,m,n,s,t,l,tt;
char tmp;

void block(int);
void expression(int);

bool getc(char &tmp){
    int k=scanf("%c",&tmp);
    while(k!=EOF&&(tmp==' '||tmp=='\n'||tmp=='\r'||tmp==9)){
        k=scanf("%c",&tmp);
    }
    if(k==EOF)return false;
    return true;
}

void arguments(int indentation){
    while(getc(tmp)&&tmp!=')'){
        expression(indentation);
    }
    printf(")");
}

void expression(int indentation){
    printf("%c",tmp);
    while(getc(tmp)&&tmp!=';'&&tmp!=','&&tmp!=')'&&tmp!='}'){
        if(tmp=='{'){
                printf(" {\n");
                block(indentation+4);
        }
        else if(tmp!='('){
            printf("%c",tmp);
        }else{
            printf("(");
            arguments(indentation);
        }
    }
    if(tmp==')'||tmp=='}')
        ungetc(tmp,stdin);
    else if(tmp==',')
        printf(", ");
}

void statment(int indentation){
    LOOPB(i,0,indentation)
        printf(" ");
    expression(indentation);
    printf(";\n");
}

void statements(int indentation){
    while(getc(tmp)&&tmp!='}')statment(indentation);
}

void block(int indentation){
    statements(indentation);
    LOOPB(i,0,indentation-4)
        printf(" ");
    printf("}");
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
getc(tmp);
printf("{\n");
block(4);
printf("\n");
}
