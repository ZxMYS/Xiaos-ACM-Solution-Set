#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,w;
int maxh;
double ans;

int main()
{
	cout.setf(ios::fixed);
	cout.precision(10);
	while (cin>>n>>w && n)
	{
		vector<int> cnt;
		while (n--)
		{
			int v;
			cin>>v;
			v/=w;
			while (cnt.size()<=v) cnt.push_back(0);
			cnt[v]++;
		}
		ans=0.01;
		maxh=0;
		for (int i=0;i<cnt.size();i++) maxh=max(maxh,cnt[i]);
		for (int i=0;i<cnt.size();i++)
			ans+=(cnt.size()-i-1.0)/(cnt.size()-1.0)*(cnt[i]*1.0/maxh);
		cout<<ans<<endl;
	}
	return 0;
}

