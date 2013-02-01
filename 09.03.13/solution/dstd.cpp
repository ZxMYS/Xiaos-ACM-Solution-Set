#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
using namespace std;

pair<int,int> operator -(pair<int,int> a,pair<int,int> b)
{
	return make_pair(a.first-b.first,a.second-b.second);
}

int operator ^(pair<int,int> a,pair<int,int> b)
{
	return a.first*b.second-a.second*b.first;
}

bool on_segment(pair<int,int> a,pair<int,int> p,pair<int,int> q)
{
	p=p-a;
	q=q-a;
	return (p^q)==0 && p.first*q.first+p.second*q.second<0;
}

void cat_edges(list<pair<pair<int,int>,pair<int,int> > >& edges)
{
	while (true)
	{
		bool flag=true;
		list<pair<pair<int,int>,pair<int,int> > >::iterator i,j;
		for (i=edges.begin();i!=edges.end();i++)
		{
			j=i;
			for (j++;j!=edges.end();j++)
				if (i->second==j->first && on_segment(i->second,i->first,j->second))
				{
					i->second=j->second;
					edges.erase(j);
					flag=false;
					goto out_of_loop;
				}
		}
out_of_loop:	if (flag) break;
	}
}

bool edges_touch(pair<pair<int,int>,pair<int,int> > a,pair<pair<int,int>,pair<int,int> > b)
{
	if (a.first==b.first) return true;
	if (a.second==b.first) return true;
	if (a.first==b.second) return true;
	if (a.second==b.second) return true;
	if (on_segment(a.first,b.first,b.second)) return true;
	if (on_segment(a.second,b.first,b.second)) return true;
	if (on_segment(b.first,a.first,a.second)) return true;
	if (on_segment(b.second,a.first,a.second)) return true;
	return false;
}

void show_edge(pair<pair<int,int>,pair<int,int> >e)
{
	pair<int,int> u,v;
	u=e.first;
	v=e.second;
	cerr<<'('<<u.first<<','<<u.second<<")~("<<v.first<<','<<v.second<<')'<<endl;
}

class figure
{
private:
	
	vector<pair<int,int> > points;
	vector<vector<bool> > edges;

	bool end_point(int i)
	{
		int cnt=0;
		for (int j=0;j<points.size();j++)
			if (edges[i][j]) cnt++;
		if (cnt!=1) return false;
		for (int u=0;u<points.size();u++)
			for (int v=u+1;v<points.size();v++)
				if (edges[u][v] && on_segment(points[i],points[u],points[v]))
					return false;
		return true;
	}

	bool t_point(int i)
	{
		int cnt=0;
		for (int j=0;j<points.size();j++)
			if (edges[i][j]) cnt++;
		return cnt==1 && !end_point(i);
	}

public:

	figure(list<pair<pair<int,int>,pair<int,int> > >& edge_list)
	{
		map<pair<int,int>,int> point_map;
		list<pair<pair<int,int>,pair<int,int> > > now_edges;
		point_map[edge_list.front().first]=points.size();
		points.push_back(edge_list.front().first);
		point_map[edge_list.front().second]=points.size();
		points.push_back(edge_list.front().second);
		now_edges.push_back(edge_list.front());
		edge_list.pop_front();
		for (list<pair<pair<int,int>,pair<int,int> > >::iterator i=now_edges.begin();i!=now_edges.end();i++)
		{
	//		show_edge(*i);
			for (list<pair<pair<int,int>,pair<int,int> > >::iterator it=edge_list.begin();it!=edge_list.end();)
			{
				if (edges_touch(*i,*it))
				{
					if (!point_map.count(it->first))
					{
						point_map[it->first]=points.size();
						points.push_back(it->first);
					}
					if (!point_map.count(it->second))
					{
						point_map[it->second]=points.size();
						points.push_back(it->second);
					}
					now_edges.push_back(*it);
					edge_list.erase(it);
					it=edge_list.begin();
				}
				else it++;
			}
		}
		edges.resize(points.size(),vector<bool>(points.size(),false));
		for (list<pair<pair<int,int>,pair<int,int> > >::iterator i=now_edges.begin();i!=now_edges.end();i++)
		{
			int u=point_map[i->first];
			int v=point_map[i->second];
			edges[u][v]=edges[v][u]=true;
		}
	//	cerr<<"figure captured"<<endl;
	}

	int check_figure()
	{
		int t_cnt=0;
		int edge_cnt=0;
		for (int i=0;i<points.size();i++)
			for (int j=i+1;j<points.size();j++)
				if (edges[i][j]) edge_cnt++;
		for (int i=0;i<points.size();i++)
			if (t_point(i)) t_cnt++;
		if (edge_cnt==1) return 1;
		if (edge_cnt==3)
		{
			if (points.size()==4) return 7;
			else return 4;
		}
		if (edge_cnt==4)
		{
			if (points.size()==4) return 0;
			if (points.size()==5) return 9;
			if (points.size()==6) return 3;
		}
		if (t_cnt==1) return 6;
		if (t_cnt==2) return 8;
		int path[5];
		for (int i=0;i<5;i++) path[i]=i;
		do
		{
			int i;
			for (i=1;i<5;i++)
				if (!edges[path[i]][path[i-1]]) break;
			if (i==5) break;
		}while (next_permutation(path,path+5));
		pair<int,int> u,v,l;
		u=points[path[0]];
		v=points[path[1]];
		l=points[path[2]];
		if (((v-u)^(l-v))>0) return 5;
		return 2;
	}
};

int n;
list<pair<pair<int,int>,pair<int,int> > > edges;
int ans[10];

int main()
{
	while (cin>>n && n)
	{
		edges.clear();
		while (n--)
		{
			int x1,y1;
			int x2,y2;
			pair<int,int> u,v;
			cin>>x1>>y1>>x2>>y2;
			u=make_pair(x1,y1);
			v=make_pair(x2,y2);
			if (u>v) swap(u,v);
			edges.push_back(make_pair(u,v));
		}
		edges.sort();
		cat_edges(edges);
		memset(ans,0,sizeof(ans));
		while (edges.size())
		{
			figure now(edges);
			int digit=now.check_figure();
			//cerr<<digit<<endl;
			ans[digit]++;
		}
		for (int i=0;i<10;i++)
		{
			if (i) putchar(' ');
			printf("%d",ans[i]);
		}
		putchar('\n');
	}
	return 0;
}

