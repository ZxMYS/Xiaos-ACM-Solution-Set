#define C_OR_CPP 2 //  Change value to 1 here if you are submitting a C solution for this problem.
                   //  Change value to 2 here if you are submitting a C++ solution for this problem.

void dsmain();

#if C_OR_CPP == 1  // Dont change here

	char* sum(char num1[], char num2[]);

#endif



#if C_OR_CPP == 2  // Dont change here

class Numerical
{
 private:
        char pool[5000];
 public:
	char* sum(char num1[], char num2[]);
};

#endif



#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
char* Numerical::sum(char num1[], char num2[]){


    string set="23456789mcxi";
    char* ctmp=num1;
    while(*ctmp){
        if(set.find(*ctmp)==string::npos){
            return "invalid";
        }
        ctmp++;
    }

    ctmp=num2;
    while(*ctmp){
        if(set.find(*ctmp)==string::npos){
            return "invalid";
        }
        ctmp++;
    }

    string set2="mcxi_";
    int t1=0,t2=0;
    ctmp=num1;
    while(*ctmp){
        if((*ctmp)<='1'||((*ctmp)>'9')){
            while(set2[t1]!=(*ctmp)&&t1<set2.length())
                t1++;
            t1++;
        }
        if(t1>=set2.length())
                return "invalid";
        ctmp++;
    }

    ctmp=num2;
    while(*ctmp){
        if((*ctmp)<='1'||((*ctmp)>'9')){
            while(set2[t2]!=(*ctmp)&&t2<set2.length())
                t2++;
            t2++;
        }
        if(t2>=set2.length())
                return "invalid";
        ctmp++;
    }
    
    
    ctmp=num1;
    while((*ctmp)&&(*ctmp+1)){
        if(!((*ctmp)<='1'||((*ctmp)>'9')))
            if(!((*ctmp+1)<='1'||((*ctmp+1)>'9')))
                return "invalid";
        ctmp++;
    }
    ctmp=num2;
    while((*ctmp)&&(*ctmp+1)){
        if(!((*ctmp)<='1'||((*ctmp)>'9')))
            if(!((*ctmp+1)<='1'||((*ctmp+1)>'9')))
                return "invalid";
        ctmp++;
    }
    
    int i;
    int n1,n2,tmp=0;
    n1=n2=0;
    string str="_mcxi";
    int p1=0,p2=0;
    while(*num1){
        if((*num1)<='1'||((*num1)>'9')){
            while(str[p1]!=(*num1)&&p1<str.length()){
                n1*=10;
                p1++;
            }
            if(tmp==0)
                n1+=1;
            else
                n1+=tmp;
            tmp=0;
        }else{
            tmp=(*num1)-'0';
        }
        num1++;
    }
    p1++;
    while(p1<str.length()){
        p1++;
        n1*=10;
    }
    tmp=0;
    while(*num2){
        if((*num2)<='1'||((*num2)>'9')){
            while(str[p2]!=(*num2)&&p2<str.length()){
                n2*=10;
                p2++;
            }
            if(tmp==0)
                n2+=1;
            else
                n2+=tmp;
            tmp=0;
        }else{
            tmp=(*num2)-'0';
        }
        num2++;
    }
    p2++;
    while(p2<str.length()){
        p2++;
        n2*=10;
    }
    printf("%d %d\n",n1,n2);
    n1+=n2;
    p1=0;
    p2=1;
    n2=1000;
    while(n2){
        if(n1/n2>=10)return "invalid";
        pool[p1]=(n1/n2)+'0';
        if(pool[p1]!='0'){
            if(pool[p1]!='1')p1++;
            pool[p1++]=str[p2++];
        }else
            p2++;
        n1%=n2;
        n2/=10;
    }
    pool[p1]=0;
    return pool;
}

void dsmain(){
        Numerical tmp;
	{
		char* output = tmp.sum("i","x");
		printf ("\nOUTPUT 1 : %s\n",output);
	}
		{
		char* output = tmp.sum("iiiii","mcxi");
		printf ("\nOUTPUT 2 : %s\n",output);
	}

	// Test case 3
	{
		char* output = tmp.sum("x","mcxi");
		printf ("\nOUTPUT 3 : %s\n",output);
	}

}

int main()
{	// Test case 1
    dsmain();
    system("pause");
}
