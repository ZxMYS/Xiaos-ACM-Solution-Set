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
vector<double> nums;


double add_max_low(double add,int numsum){
	//printf("add=%lf,numsum=%d\n",add,numsum);
	double oriadd=add;
		int i,j;
	while(add>=0){	
		//printf("while--- add=%lf\n",add);
		//LOOPB(i,0,nums.size())
		//	printf("num:%lf ",nums[i]);
		LOOPB(i,0,nums.size()-1){
			if(nums[i]<nums[i+1])
				break;
		}
		//printf("\n");
		if(i==nums.size()-1){
		//printf("AAA %lf",(((double)numsum)+oriadd)/nums.size());
			return (((double)numsum)+oriadd)/nums.size();
		}
		if((nums[i+1]-nums[i])*(i+1)<=add){
			add-=(nums[i+1]-nums[i])*(i+1);
			LOOP(j,0,i)
				nums[j]=nums[i+1];
		}else{
		//printf("BBB %lf",nums[i]+add/(i+1));
			return nums[i]+add/(i+1);
		}
		
		//printf("----while\n");
	}
	sort(nums.begin(),nums.end());
	
		//printf("CCC %lf");
	return nums[0];
}

int main(){
	int i,j,k,a,aa,m,n,s,sum,t,l,tt,cas;
	const int oo=1<<29;
	char tmp,str[500],ch;
	float f1,f2;

	vector<int> wtf;
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d\n",&tt);
	cas=0;
	while(++cas,tt--){
		printf("Case #%d: ", cas);
		wtf.clear();
		scanf("%d",&n);
		a=oo;aa=oo;
		sum=0;
		LOOPB(i,0,n){
			scanf("%d",&m);
			wtf.push_back(m);
			sum+=m;
			if(m<=a){
				aa=a;
				a=m;
				k=i;
			}
		}
		LOOPB(i,0,n){
			
			double l=0,r=1,mid;
			
			while(r-l>=0.000000001){
			
				nums.clear();
				LOOPB(j,0,n){
					if(j!=i)
						nums.push_back((double)wtf[j]);
				}
				sort(nums.begin(),nums.end());
				
				mid=(l+r)/2;
				
				double now=wtf[i]+mid*sum;
				
				double low=add_max_low((1-mid)*sum,sum-wtf[i]);
				
				if(low>now){
					l=mid;
				}else{
					r=mid;
				}
			}
			
			printf("%lf ",mid*100);
			
		}
		printf("\n");
	}
	
	return 0;
}
