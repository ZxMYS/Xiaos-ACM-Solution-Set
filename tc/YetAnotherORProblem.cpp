// BEGIN CUT HERE

// END CUT HERE
#line 5 "YetAnotherORProblem.cpp"
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
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
char tmp,str[500];
float f1,f2;
		vector<int> zp,op;
class YetAnotherORProblem{ 
		
		static const long long int M=1000000009;
        public: 
		int docalc(int s,int p){
			if(p==0){
				
			}
			int j=0,i;
			LOOPB(i,0,zp.size()){
				if(s&(1<<(i))){
					if(p<=(op[i]-1))j++;
				}else{
					if(p<=(op[i]-2))j++;
				}
			}
			if(!j)
				return 1;
			printf("%d %d\n",p,j);
			return ((long long int)j*(docalc(s,p+1)%M))%M;
		}	
			
        int countSequences(vector<long long> R) 
            { 
				int i,j,x;
				int e=1<<R.size();
				bool f=false;
				long long int ans=0;
				zp.clear();
				op.clear();
				LOOPB(i,0,R.size()){
					//printf("%lld\n",3&(1LL<<1)); 
					RLOOP(j,63,0){
						//printf("%lld\n",(1LL<<j)); 
						if((R[i]&(1LL<<j))>0){
							printf("%d\n",j);
							x=j;
							printf("%d\n",x);
							goto O;
						}
					}
					O:
					op.push_back(x);
				
					for(;j>0;j--){
						if(!(R[i]&(1LL<<j))){
							zp.push_back(j);
							f=true;
							break;
						}
					}
					if(!f)
						zp.push_back(43503);
					printf("%lld: %d %d\n",R[i],op[i],zp[i]);
				}
				//assert(op.size()==zp.size());
	        	LOOPB(i,0,e){
					ans+=docalc(i,0)%M;
					ans%=M;
				}
				return ans;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {3,5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(0, Arg1, countSequences(Arg0)); }
	void test_case_1() { long Arr0[] = {3,3,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, countSequences(Arg0)); }
	void test_case_2() { long Arr0[] = {1,128}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 194; verify_case(2, Arg1, countSequences(Arg0)); }
	void test_case_3() { long Arr0[] = {26,74,25,30}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8409; verify_case(3, Arg1, countSequences(Arg0)); }
	void test_case_4() { long Arr0[] = {1000000000,1000000000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 420352509; verify_case(4, Arg1, countSequences(Arg0)); }

// END CUT HERE
 
 }; 
    // BEGIN CUT HERE 
int main() {
        YetAnotherORProblem ___test; 
        ___test.run_test(-1); 
        system("pause");
} 
 // END CUT HERE 
