#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct term
{
	bool flag;
	int value;

	term(){}

	term(int value)
	{
		vector<int>* now=new vector<int>;
		flag=true;
		if (value) now->push_back(value);
		this->value=(int)now;
	}

	term(bool flag,int value)
	{
		this->flag=flag;
		this->value=value;
	}

	vector<int>* get_polynomial()
	{
		return (vector<int>*)value;
	}

	bool operator ==(term b) const
	{
		if (flag!=b.flag) return false;
		if (flag) return *(vector<int>*)value==*(vector<int>*)b.value;
		else return value==b.value;
	}

	bool operator !=(term b) const
	{
		return !(*this==b);
	}

	term get_x_term()
	{
		vector<int>* x=new vector<int>;
		x->push_back(0);
		x->push_back(1);
		return term(true,(int)x);
	}
};

const term left_par(false,0);
const term right_par(false,1);
const term add(false,2);
const term sub(false,3);
const term power(false,4);
const term zero(true,(int)(new vector<int>));
const term one(true,(int)(new vector<int>(1,1)));
const term x=term().get_x_term();

term calc_add(term first,term second)
{
	vector<int>& a=*first.get_polynomial();
	vector<int>& b=*second.get_polynomial();
	vector<int>* ans=new vector<int>(max(a.size(),b.size()));
	vector<int>& c=*ans;
	for (int i=0;i<c.size();i++)
	{
		if (i<a.size()) c[i]+=a[i];
		if (i<b.size()) c[i]+=b[i];
	}
	while (c.size() && !c.back()) c.pop_back();
	return term(true,(int)ans);
}

term calc_sub(term first,term second)
{
	vector<int>& a=*first.get_polynomial();
	vector<int>& b=*second.get_polynomial();
	vector<int>* ans=new vector<int>(max(a.size(),b.size()));
	vector<int>& c=*ans;
	for (int i=0;i<c.size();i++)
	{
		if (i<a.size()) c[i]+=a[i];
		if (i<b.size()) c[i]-=b[i];
	}
	while (c.size() && !c.back()) c.pop_back();
	return term(true,(int)ans);
}

term calc_mul(term first,term second)
{
	if (first==zero || second==zero) return zero;
	vector<int>& a=*first.get_polynomial();
	vector<int>& b=*second.get_polynomial();
	vector<int>* ans=new vector<int>(a.size()+b.size()-1);
	vector<int>& c=*ans;
	for (int i=0;i<a.size();i++)
		for (int j=0;j<b.size();j++)
		{
			c[i+j]+=a[i]*b[j];
		}
	while (c.size() && !c.back()) c.pop_back();
	return term(true,(int)ans);
}

term calc_power(term first,term second)
{
	if (second==zero) return one;
	vector<int>& b=*second.get_polynomial();
	term ans=one;
	for (int i=0;i<b[0];i++)
		ans=calc_mul(ans,first);
	return ans;
}

list<term> load_expression()
{
	list<term> ans;
	char line[100];
	gets(line);
	if (line[0]=='.') throw 1;
	for (int i=0;line[i];)
	{
		if (!isdigit(line[i]) && !isalpha(line[i])) 
		{
			switch (line[i])
			{
				case '+':
					ans.push_back(add);
					break;
				case '-':
					ans.push_back(sub);
					break;
				case '(':
					ans.push_back(left_par);
					break;
				case ')':
					ans.push_back(right_par);
					break;
				case '^':
					ans.push_back(power);
			}
			i++;
		}
		else if (isdigit(line[i]))
		{
			int now;
			sscanf(line+i,"%d",&now);
			while (isdigit(line[i])) i++;
			ans.push_back(now);
		}
		else
		{
			ans.push_back(x);
			i++;
		}
	}
	return ans;
}

term parse_expression(list<term> terms)
{
	while (count(terms.begin(),terms.end(),left_par))
	{
		list<term>::iterator i,j;
		int cnt=0;
		for (i=terms.begin();*i!=left_par;i++);
		for (j=i,cnt=0;j==i || cnt;j++)
		{
			if (*j==left_par) cnt++;
			if (*j==right_par) cnt--;
		}
		term inside_par=parse_expression(list<term>((++i)--,(--j)++));
		list<term> temp;
		temp.insert(temp.end(),terms.begin(),i);
		temp.push_back(inside_par);
		temp.insert(temp.end(),j,terms.end());
		terms=temp;
	}
	while (count(terms.begin(),terms.end(),power))
	{
		list<term>::iterator i,j,k;
		for (i=terms.begin();*i!=power;i++);
		j=i;j--;
		k=i;k++;
		list<term> temp;
		temp.insert(temp.end(),terms.begin(),j);
		temp.push_back(calc_power(*j,*k));
		temp.insert(temp.end(),++k,terms.end());
		terms=temp;
	}
	while (true)
	{
		bool mul_flag=false;
		list<term>::iterator i,j;
		for (i=++terms.begin(),j=terms.begin();i!=terms.end();i++,j++)
		{
			if (i->flag && j->flag)
			{
				mul_flag=true;
				break;
			}
		}
		if (!mul_flag) break;
		list<term> temp;
		temp.insert(temp.end(),terms.begin(),j);
		temp.push_back(calc_mul(*j,*i));
		temp.insert(temp.end(),++i,terms.end());
		terms=temp;
	}
	if (terms.front()==sub || terms.front()==add) terms.push_front(zero);
	while (count(terms.begin(),terms.end(),add) || count(terms.begin(),terms.end(),sub))
	{
		list<term>::iterator i,j,k;
		for (i=terms.begin();*i!=add && *i!=sub;i++);
		j=i;j--;
		k=i;k++;
		list<term> temp;
		temp.insert(temp.end(),terms.begin(),j);
		if (*i==add)
			temp.push_back(calc_add(*j,*k));
		else 
			temp.push_back(calc_sub(*j,*k));
		temp.insert(temp.end(),++k,terms.end());
		terms=temp;
	}
	return terms.front();
}

void display_polynomial(vector<int> poly)
{
	if (!poly.size()) puts("0");
	else
	{
		bool first=true;
		for (int i=poly.size()-1;i>=0;i--)
			if (poly[i])
			{
				if (abs(poly[i])!=1 || i==0)
				{
					if (!first) printf("%+d",poly[i]);
					else printf("%d",poly[i]);
				}
				else
				{
					if (!first)
					{
						if (poly[i]>0) putchar('+');
						else putchar('-');
					}
					else if (poly[i]<0) putchar('-');
				}
				first=false;
				if (i) putchar('x');
				if (i>1) printf("^%d",i);
			}
		putchar('\n');
	}
}

int gcd(int a,int b)
{
	a=abs(a);
	b=abs(b);
	if (a<b) swap(a,b);
	while (b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);
}

vector<int> gcd(vector<int> a,vector<int> b)
{
	if (a.size()<b.size()) swap(a,b);
	while (b.size())
	{
		if (a.size()<b.size()) swap(a,b);
		int l=lcm(a.back(),b.back());
		int ga=l/a.back();
		int gb=l/b.back();
		for (int i=0;i<a.size();i++)
		{
			a[i]*=ga;
		}
		for (int i=0;i<b.size();i++)
		{
			b[i]*=gb;
		}
		for (int i=0;i<b.size();i++)
			a[i+a.size()-b.size()]-=b[i];
		for (int i=0;i<b.size();i++)
			b[i]/=gb;
		while (a.size() && !a.back())
			a.pop_back();
		swap(a,b);
	}
	if (a.size())
	{
		int g=a[0];
		for (int i=1;i<a.size();i++) g=gcd(g,a[i]);
		for (int i=0;i<a.size();i++) a[i]/=g;
		if (a.back()<0)
			for (int i=0;i<a.size();i++) a[i]*=-1;
	}
	return a;
}

int main()
{
	while (true)
	{
		try
		{
			vector<int> a=*(parse_expression(load_expression()).get_polynomial());
			vector<int> b=*(parse_expression(load_expression()).get_polynomial());
			vector<int> c=gcd(a,b);
			display_polynomial(c);
		}
		catch (int i)
		{
			return 0;
		}
	}
	return 0;
}

