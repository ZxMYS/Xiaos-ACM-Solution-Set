#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define MAXN 110
//#define _DEBUG_

const double eps=1e-6;
const double inf=1e10;
const double pi=acos(-1.0);

struct point
{
	double x,y;

	point(){}

	point(double x,double y)
	{
		this->x=x;
		this->y=y;
	}

	double length() const
	{
		return sqrt(x*x+y*y);
	};

	point unit() const
	{
		double l=length();
		return point(x/l,y/l);
	}

	point rotate(double phi) const
	{
		return point(x*cos(phi)-y*sin(phi),x*sin(phi)+y*cos(phi));
	}

	double polar_angle() const
	{
		double ans=atan2(y,x);
		if (ans<0) ans+=pi*2;
		return ans;
	}
};

ostream& operator <<(ostream& cout,point p)
{
	cout<<'('<<p.x<<','<<p.y<<')';
	return cout;
}

point get_unit(double phi)
{
	return point(cos(phi),sin(phi));
}

point operator +(point a,point b)
{
	return point(a.x+b.x,a.y+b.y);
}

point operator -(point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}

point operator *(point a,double t)
{
	return point(a.x*t,a.y*t);
}

point operator /(point a,double t)
{
	return point(a.x/t,a.y/t);
}

double operator ^(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}

double operator *(point a,point b)
{
	return a.x*b.x+a.y*b.y;
}

struct segment
{
	point a;
	point b;

	int intersections(point p,point u)
	{
		point q;
		q=p+u*inf;
		if (((b-a)^(p-a))*((b-a)^(q-a))>-eps) return 0;
		if (((q-p)^(a-p))*((q-p)^(b-p))>-eps) return 0;
		return 1;
	}
};

struct arc
{
	point center;
	double radius;
	double alpha,beta;

	bool on_arc(double phi)
	{
		if (alpha<beta)
		{
			if (phi<alpha-eps) phi+=pi*2;
			return phi<beta+eps;
		}
		else
		{
			if (phi<beta-eps) phi+=pi*2;
			return phi<alpha+eps;
		}
	}

	int intersections(point p,point u)
	{
		double A=u*u;
		double B=(p-center)*u*2;
		double C=(p-center)*(p-center)-radius*radius;
		double delta=B*B-4*A*C;
		if (fabs(delta)<eps)
		{
			double t=-B/(A*2);
			if (t<0) return 0;
			else
			{
				point q=p+u*t;
				if (on_arc((q-center).polar_angle())) return 1;
				else return 0;
			}
		}
		else if (delta<0) return 0;
		else
		{
			double t1=(-B-sqrt(delta))/(A*2);
			double t2=(-B+sqrt(delta))/(A*2);
			int cnt=0;
			point q;
			if (t1>0)
			{
				q=p+u*t1;
				if (on_arc((q-center).polar_angle())) cnt++;
			}
			if (t2>0)
			{
				q=p+u*t2;
				if (on_arc((q-center).polar_angle())) cnt++;
			}
			return cnt;

		}
	}
};

struct edge
{
	bool flag;
	segment s;
	arc a;

	double area()
	{
		if (flag)
		{
			return ((s.a)^(s.b))*0.5;
		}
		else
		{
			double sa,sb;
			double s;
			double r=a.radius;
			double theta=fabs(a.alpha-a.beta);
			point p=a.center+get_unit(a.alpha)*r;
			point q=a.center+get_unit(a.beta)*r;
			sa=r*r*(theta-sin(theta))*0.5;
			sb=fabs(p^q)*0.5;
			if (((q-p)^(a.center-p))*((q-p)^(point(0.0,0.0)-p))>-eps) s=sa+sb;
			else s=fabs(sa-sb);
			if (a.center.length()>a.radius+eps)
			{
				if ((p^q)>0) return s;
				else return -s;
			}
			else if (fabs(p^q)<eps)
			{
				point mid=a.center+get_unit((a.alpha+a.beta)*0.5)*r;
				if ((p^mid)>0 || (mid^q)>0) return s;
				else return -s;
			}
			else if (((q-p)^(a.center-p))*((q-p)^(point(0.0,0.0)-p))>eps)
			{
				if ((p^q)>0) return s;
				else return -s;
			}
			else
			{
				if ((p^q)>0) return -s;
				else return s;
			}
		}
	}

	point center()
	{
		point ans;
		if (flag)
		{
			ans=(s.a+s.b)*(1.0/3.0);
		}
		else
		{
			double sa,sb;
			double s;
			double r=a.radius;
			double theta=fabs(a.alpha-a.beta);
			point p=a.center+get_unit(a.alpha)*r;
			point q=a.center+get_unit(a.beta)*r;
			sa=r*r*(theta-sin(theta))*0.5;
			sb=fabs(p^q)*0.5;
			double delta=2.0*r*r*r*pow(sin(theta/2.0),3.0)/(r*r*(theta-sin(theta))/2.0*3.0);
			point u=a.center+get_unit((a.alpha+a.beta)/2.0)*delta;
			point v=(p+q)*(1.0/3.0);
			if (((q-p)^(a.center-p))*((q-p)^(point(0.0,0.0)-p))>=0) ans=(u*sa+v*sb)/(sa+sb);
			else
			{
				if (sa>sb) ans=(u*sa-v*sb)/(sa-sb);
				else ans=(v*sb-u*sa)/(sb-sa);
			}
		}
		return ans;
	}

	int intersections(point p,point u)
	{
		if (flag) return s.intersections(p,u);
		else return a.intersections(p,u);
	}
};

int n;
edge edges[MAXN];

bool valid(point p,double theta)
{
	for (int i=0;i<n;i++)
	{
		if (edges[i].flag)
		{
			double phi;
			phi=(edges[i].s.a-p).polar_angle();
			if (fabs(phi-theta)<eps) return false;
			if (fabs(phi-theta+pi*2)<eps) return false;
			if (fabs(phi-theta-pi*2)<eps) return false;
			phi=(edges[i].s.b-p).polar_angle();
			if (fabs(phi-theta)<eps) return false;
			if (fabs(phi-theta+pi*2)<eps) return false;
			if (fabs(phi-theta-pi*2)<eps) return false;
		}
		else
		{
			double phi;
			phi=(edges[i].a.center+get_unit(edges[i].a.alpha)*edges[i].a.radius-p).polar_angle();
			if (fabs(phi-theta)<eps) return false;
			if (fabs(phi-theta+pi*2)<eps) return false;
			if (fabs(phi-theta-pi*2)<eps) return false;
			phi=(edges[i].a.center+get_unit(edges[i].a.beta)*edges[i].a.radius-p).polar_angle();
			if (fabs(phi-theta)<eps) return false;
			if (fabs(phi-theta+pi*2)<eps) return false;
			if (fabs(phi-theta-pi*2)<eps) return false;
		}
	}
	return true;
}

bool inside(point p)
{
	double theta;
	while (!valid(p,theta=rand()*pi*2/RAND_MAX));
	int cnt=0;
	for (int i=0;i<n;i++)
	{
		int now=edges[i].intersections(p,get_unit(theta));
		cnt+=now;
	}
	if (cnt&1) return true;
	else return false;
}

void add_arc(point center,double r,double alpha,double beta)
{
	if (fabs(alpha-beta)<eps) return;
	if (fabs(alpha-beta+pi*2)<eps) return;
	if (fabs(alpha-beta-pi*2)<eps) return;
	edges[n].flag=false;
	edges[n].a.center=center;
	edges[n].a.radius=r;
	edges[n].a.alpha=alpha;
	edges[n].a.beta=beta;
	n++;
}

point center;
point start;
double area;

int main()
{
	srand(rand());
	cout.setf(ios::fixed);
	cout.precision(10);
	string command;
	point cur;
	while (cin>>command && command!="end")
	{
		cin>>cur.x>>cur.y;
		start=cur;
		n=0;
		do
		{
			point next;
			cin>>command;
			if (command=="line" || command=="close")
			{
				if (command=="line") cin>>next.x>>next.y;
				else next=start;
				if ((cur-next).length()>eps)
				{
					edges[n].flag=true;
					edges[n].s.a=cur;
					edges[n].s.b=next;
					n++;
				}
			}
			else
			{
				double r;
				cin>>next.x>>next.y>>r;
				point u=(cur+next)*0.5;
				point v=(next-cur).unit().rotate(-pi*0.5);
				double t=(r/fabs(r)*sqrt(r*r-pow((next-cur).length()*0.5,2.0)));
				point center=u+v*t;
				r=fabs(r);
				double alpha=(cur-center).polar_angle();
				double beta=(next-center).polar_angle();
				if (beta<alpha) beta+=pi*2;
				if (beta-alpha>pi) beta-=pi*2;
				if (min(alpha,beta)<0)
				{
					alpha+=pi*2;
					beta+=pi*2;
				}
				if (min(alpha,beta)>=pi*2)
				{
					alpha-=pi*2;
					beta-=pi*2;
				}
				double x0=center.x;
				double y0=center.y;
				if (x0*x0+y0*y0-r*r<eps)
				{
					add_arc(center,r,alpha,beta);
				}
				else
				{
					double p=asin((-r*y0-x0*sqrt(x0*x0+y0*y0-r*r))/(x0*x0+y0*y0));
					double q=asin((-r*y0+x0*sqrt(x0*x0+y0*y0-r*r))/(x0*x0+y0*y0));
					if (p<0) p+=pi*2;
					if (q<0) q+=pi*2;
					if (alpha<beta)
					{
						if (p<alpha-eps) p+=pi*2;
						if (q<alpha-eps) q+=pi*2;
						if (p>q) swap(p,q);
						bool flag1=(p<(beta+eps));
						bool flag2=(q<(beta+eps));
						if (flag1 && flag2)
						{
							add_arc(center,r,alpha,p);
							add_arc(center,r,p,q);
							add_arc(center,r,q,beta);
						}
						else if (flag1)
						{
							add_arc(center,r,alpha,p);
							add_arc(center,r,p,beta);
						}
						else if (flag2)
						{
							add_arc(center,r,alpha,q);
							add_arc(center,r,q,beta);
						}
						else
						{
							add_arc(center,r,alpha,beta);
						}
					}
					else
					{
						if (p<beta-eps) p+=pi*2;
						if (q<beta-eps) q+=pi*2;
						if (p<q) swap(p,q);
						bool flag1=(p<(alpha+eps));
						bool flag2=(q<(alpha+eps));
						if (flag1 && flag2)
						{
							add_arc(center,r,alpha,p);
							add_arc(center,r,p,q);
							add_arc(center,r,q,beta);
						}
						else if (flag1)
						{
							add_arc(center,r,alpha,p);
							add_arc(center,r,p,beta);
						}
						else if (flag2)
						{
							add_arc(center,r,alpha,q);
							add_arc(center,r,q,beta);
						}
						else
						{
							add_arc(center,r,alpha,beta);
						}
					}
				}

			}
			cur=next;
		}while (command!="close");
		center=point(0.0,0.0);
		area=0.0;
		for (int i=0;i<n;i++)
		{
#ifdef _DEBUG_
			if (edges[i].flag)
				cerr<<"line "<<edges[i].s.a<<' '<<edges[i].s.b<<endl;
			else
				cerr<<"arc "<<edges[i].a.center<<' '<<edges[i].a.radius<<' '<<edges[i].a.alpha/pi*180.0<<' '<<edges[i].a.beta/pi*180.0<<endl;
#endif
			double now_area;
			point now_center;
			now_area=edges[i].area();
			now_center=edges[i].center();
#ifdef _DEBUG_
			cerr<<now_area<<' '<<now_center<<endl;
#endif
			area+=now_area;
			center=center+now_center*now_area;
		}
		center=center*(1.0/area);
		cout<<center.x<<' '<<center.y<<' ';
		if (inside(center)) cout<<'+'<<endl;
		else cout<<'-'<<endl;

	}
	return 0;
}

