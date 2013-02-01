// BEGIN CUT HERE

// END CUT HERE
#line 5 "DivideAndShift.cpp"
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
int i,j,k,a,m,n,s,t,l,tt,cas;
bool isPrime[1000101];
vector<int> prime;
int NNN;
class DivideAndShift{ 
        public: 
		
		int dosearch(int N,int M,int best,int cur){
			printf("dosearch:%d %d %d %d\n",N,M,best,cur);
			cur=cur+1;
			if(best<=cur)
				return -1;
			if(M==1)return 0;
			int i=0,j,NN,ans=min(M-1,N-M+1);
			while(prime[i]<=N){
				if(N%prime[i]!=0)
					goto c;
				printf("trying %d\n",prime[i]);
				NN=N/prime[i];
				if((j=dosearch(NN,((M-1)%NN)+1,best,cur))>=0){
					ans=min(ans,j+1);
					if(N=NNN)
						best=ans;
				}
				c:
				i++;
			}
			
			return ans;
		}	
			
        int getLeast(int N, int M) 
            { 
				prime.clear();
	            memset(isPrime,1,sizeof(isPrime));
	            isPrime[1]=false;
	            LOOPB(i,2,1000001){
					if(isPrime[i]){
						prime.push_back(i);
						j=i<<1;
						while(j<1000000){
							isPrime[j]=false;
							j+=i;
						}
					}
				}
				return dosearch(N,M,1<<29,0);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }

// END CUT HERE
 
 }; 
    // BEGIN CUT HERE 
int main() {
        DivideAndShift ___test; 
        ___test.run_test(-1); 
        system("pause");
} 
 // END CUT HERE 
