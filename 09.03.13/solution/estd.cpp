#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 110

struct point
{
	double x,y,z;

	point operator -(point b) const
	{
		point ans=*this;
		ans.x-=b.x;
		ans.y-=b.y;
		ans.z-=b.z;
		return ans;
	}

	point operator +(point b) const
	{
		point ans=*this;
		ans.x+=b.x;
		ans.y+=b.y;
		ans.z+=b.z;
		return ans;
	}

	point operator *(double t) const
	{
		point ans=*this;
		ans.x*=t;
		ans.y*=t;
		ans.z*=t;
		return ans;
	}

	double operator *(point b) const
	{
		return x*b.x+y*b.y+z*b.z;
	}
};

int n;
point center[MAXN];
double radius[MAXN];

point now;
point dir;

int main()
{
	cout.setf(ios::fixed);
	cout.precision(10);
	while (cin>>n && n)
	{
		cin>>dir.x>>dir.y>>dir.z;
		now.x=now.y=now.z=0;
		for (int i=0;i<n;i++)
			cin>>center[i].x>>center[i].y>>center[i].z>>radius[i];
		while (true)
		{
			double mint=1e100;
			point next_reflect;
			point next_dir;
			for (int i=0;i<n;i++)
			{
				double delta=dir*(now-center[i]);
				if (delta>=0) continue;
				double nowt=-delta/(dir*dir);
				double h=(now+dir*nowt-center[i])*(now+dir*nowt-center[i]);
				double l=radius[i]*radius[i]-h;
				if (l<0) continue;
				nowt-=sqrt(l/(dir*dir));
				if (nowt<mint)
				{
					mint=nowt;
					next_reflect=now+dir*nowt;
					point x=next_reflect-center[i];
					x=x*(1.0/sqrt(x*x));
					double u=dir*x;
					next_dir=dir-x*(u*2);
				}
			}
			if (mint>1e50) break;
			now=next_reflect;
			dir=next_dir;
		}
		cout<<now.x<<' '<<now.y<<' '<<now.z<<endl;
	}
	return 0;
}

