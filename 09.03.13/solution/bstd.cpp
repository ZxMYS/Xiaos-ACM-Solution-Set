#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n,m,k;
double ans;

int main()
{
	cout.setf(ios::fixed);
	cout.precision(10);
	while (cin>>n>>m>>k && n)
	{
		vector<vector<double> > prob(n+1);
		for (int i=0;i<=n;i++) prob[i]=vector<double>(i*m+1,0.0);
		prob[0][0]=1;
		for (int i=0;i<n;i++)
			for (int j=0;j<=i*m;j++)
				for (int x=1;x<=m;x++)
					prob[i+1][j+x]+=prob[i][j]/m;
		ans=0;
		for (int i=1;i<=k;i++) ans+=prob[n][i];
		for (int i=k+1;i<=n*m;i++) ans+=prob[n][i]*(i-k);
		cout<<ans<<endl;
	}
	return 0;
}

