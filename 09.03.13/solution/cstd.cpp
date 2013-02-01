#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 15
int n;
vector<int> clocks[MAXN];
vector<pair<int,int> > times;
pair<int,int> ans;

void print_time(int s)
{
	printf("%02d:%02d:%02d",s/3600,(s/60)%60,s%60);
}

vector<int> get_times_of_clock(int hh,int mm,int ss)
{
	vector<int> ans;
	int hands[]={hh,mm,ss};
	sort(hands,hands+3);
	do
	{
		for (int delta=0;delta<60;delta++)
		{
			int h=(hands[0]+delta)%60;
			int m=(hands[1]+delta)%60;
			int s=(hands[2]+delta)%60;
			if (h%5==m/12)
			{
				ans.push_back(s+m*60+h/5*3600);
			}
		}
	}while (next_permutation(hands,hands+3));
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	return ans;
}

int main()
{
	while (cin>>n && n)
	{
		for (int i=0;i<n;i++)
		{
			int hh,mm,ss;
			cin>>hh>>mm>>ss;
			clocks[i]=get_times_of_clock(hh,mm,ss);
		}
		times.resize(n);
		for (int i=0;i<n;i++)
		{
			times[i]=make_pair(clocks[i][0],i);
			clocks[i].erase(clocks[i].begin());
		}
		sort(times.begin(),times.end());
		ans=make_pair(0,0x7FFFFFFF);
		while (true)
		{
			pair<int,int> now=make_pair(times.front().first,times.back().first);
			if (now.second-now.first<ans.second-ans.first)
				ans=now;
			int i=times.front().second;
			if (!clocks[i].size()) break;
			times.erase(times.begin());
			times.push_back(make_pair(clocks[i][0],i));
			clocks[i].erase(clocks[i].begin());
			for (i=n-1;i && times[i]<times[i-1];i--)
				swap(times[i],times[i-1]);
		}
		print_time(ans.first);
		putchar(' ');
		print_time(ans.second);
		putchar('\n');
	}
	return 0;
}

