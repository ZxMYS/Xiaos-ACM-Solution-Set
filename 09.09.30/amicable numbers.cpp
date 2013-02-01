#define C_OR_CPP 2 //  Change value to 1 here if you are submitting a C solution for this problem.
								//  Change value to 2 here if you are submitting a C++ solution for this problem.

struct amicable			// Dont change here
{
	int **amicablePair;
	int size;
};

void dsmain();

#if C_OR_CPP == 1  // Dont change here

	struct amicable *getAmicablePairs(int startnum, int endnum);

#endif



#if C_OR_CPP == 2  // Dont change here

class AmicableNumber
{
	public:
		struct amicable *getAmicablePairs(int startnum, int endnum);
};

#endif


#define C_OR_CPP 2 //  Change value to 1 here if you are submitting a C solution for this problem.
                   //  Change value to 2 here if you are submitting a C++ solution for this problem.

void dsmain();

#if C_OR_CPP == 1  // Dont change here

	char* sum(char num1[], char num2[]);

#endif



#if C_OR_CPP == 2  // Dont change here

class Numerical
{
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


int res[2000][2];
int* e[2000];
struct amicable tmp;
struct amicable* AmicableNumber::getAmicablePairs(int startnum, int endnum){

    if(startnum<=0||endnum<=0)return NULL;
    if(startnum>=endnum) return NULL;
    if(endnum>=15000) return NULL;

    int i,j,k,a,m,n,s,t,l,tt,cas;
    int sum[40000];
    LOOP(i,startnum,endnum){
       a=1;
        LOOP(j,2,i-1){
            if(i%j==0){
                a+=j;
            }
        }
        sum[i]=a;
    }
    int cnt=0;
    LOOP(i,startnum,endnum){
        if(sum[i]>i&&sum[sum[i]]==i){
            res[cnt][0]=i;
            res[cnt++][1]=sum[i];
        }
    }
    int **r=&e[0];
    LOOPB(i,0,cnt){
        (*r)=&res[i][0];
        r++;
    }
    tmp.amicablePair=&e[0];
    tmp.size=cnt;
    return (cnt==0)?NULL:(&tmp);
}
void dsmain(){
    AmicableNumber tmp;
    
           // test case 1
	{
		int startnum = 1;
		int endnum = 15000-1;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
		{
		int startnum = 1;
		int endnum = 15000-1;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
		{
		int startnum = 1;
		int endnum = 15000-1;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
		{
		int startnum = 1;
		int endnum = 15000-1;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
		{
		int startnum = 1;
		int endnum = 15000-1;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
    // test case 2
	{
		int startnum = 5000;
		int endnum = 10000;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}
       // test case 1
	{
		int startnum = 200;
		int endnum = 3000;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}

    // test case 2
	{
		int startnum = 5000;
		int endnum = 10000;
		struct amicable* ami;

		ami = tmp.getAmicablePairs(startnum, endnum);

		printf("{");        if(ami!=NULL)
		for(int i = 0; i<ami->size; i++)
		{
			printf("{%d, %d}",ami->amicablePair[i][0], ami->amicablePair[i][1]);
		}
		printf("}\n");

	}



}
int main()
{
dsmain();
system("pause");
}
