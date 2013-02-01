#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
using namespace std;
#define MAXN 50

const int dir[4][2]=
{
	0,1, // east
	0,-1,//west
	1,0,//south
	-1,0//north
};

struct cube
{
	char top,bottom;
	char east,west;
	char north,south;

	cube roll_north()
	{
		cube ans=*this;
		ans.top=south;
		ans.south=bottom;
		ans.bottom=north;
		ans.north=top;
		return ans;
	}

	cube roll_south()
	{
		cube ans=*this;
		ans.top=north;
		ans.north=bottom;
		ans.bottom=south;
		ans.south=top;
		return ans;
	}

	cube roll_east()
	{
		cube ans=*this;
		ans.top=west;
		ans.west=bottom;
		ans.bottom=east;
		ans.east=top;
		return ans;
	}

	cube roll_west()
	{
		cube ans=*this;
		ans.top=east;
		ans.east=bottom;
		ans.bottom=west;
		ans.west=top;
		return ans;
	}

	cube roll(int d)
	{
		if (d==0) return roll_east();
		if (d==1) return roll_west();
		if (d==2) return roll_south();
		if (d==3) return roll_north();
		return *this;
	}
	
	bool operator ==(cube b) const
	{
         return top==b.top && bottom==b.bottom && north==b.north && south==b.south && east==b.east && west==b.west;
    }
};


cube cubes[100];
int roll[100][4];

void init_cubes()
{
	cubes[0].top='r';
	cubes[0].bottom='c';
	cubes[0].north='g';
	cubes[0].south='m';
	cubes[0].east='b';
	cubes[0].west='y';
	int cnt=1;
	for (int i=0;i<cnt;i++)
	{
		cube now=cubes[i];
		for (int d=0;d<4;d++)
		{
			cube next=now.roll(d);
			int j;
			for (j=0;j<cnt;j++)
				if (next==cubes[j]) break;
			if (j==cnt) cubes[cnt++]=next;
		}
	}
	for (int i=0;i<24;i++)
		for (int j=0;j<4;j++)
		{
			cube next=cubes[i].roll(j);
			for (int k=0;k<24;k++)
				if (next==cubes[k])
				{
					roll[i][j]=k;
					break;
				}
		}
}

int n,m;
char board[MAXN][MAXN];
char color[6];
int vx[6],vy[6];

int dis[7][MAXN][MAXN][24];
queue<pair<pair<int,int>,int> > starts[7];
queue<pair<pair<int,int>,int> > queues[6];

int ans;
int main()
{
	init_cubes();
	while (cin>>m>>n && n)
	{
		fill(starts,starts+7,queue<pair<pair<int,int>,int> >());
		fill(queues,queues+7,queue<pair<pair<int,int>,int> >());
		memset(dis,0x7F,sizeof(dis));
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
			{
				cin>>board[i][j];
				if (board[i][j]=='#')
				{
					starts[0].push(make_pair(make_pair(i,j),0));
					dis[0][i][j][0]=0;
					board[i][j]='w';
				}
			}
		for (int i=0;i<6;i++)
		{
			cin>>color[i];
			for (int x=0;x<n;x++)
				for (int y=0;y<m;y++)
					if (board[x][y]==color[i])
					{
						vx[i]=x;
						vy[i]=y;
						board[x][y]='k';
					}
		}
		for (int step=0;step<6;step++)
		{
			while (starts[step].size() || queues[step].size())
			{
				pair<pair<int,int>,int> now;
				queue<pair<pair<int,int>,int> > *topop;
				if (!queues[step].size()) topop=&starts[step];
				else if (!starts[step].size()) topop=&queues[step];
				else
				{
					int x1,y1,s1;
					int x2,y2,s2;
					x1=queues[step].front().first.first;
					y1=queues[step].front().first.second;
					s1=queues[step].front().second;
					x2=starts[step].front().first.first;
					y2=starts[step].front().first.second;
					s2=starts[step].front().second;
					if (dis[x1][y1][s1]<dis[x2][y2][s2]) topop=&queues[step];
					else topop=&starts[step];
				}
				now=topop->front();
				topop->pop();
				int x=now.first.first;
				int y=now.first.second;
				int s=now.second;
				for (int d=0;d<4;d++)
				{
					int x2=x+dir[d][0];
					int y2=y+dir[d][1];
					int s2=roll[s][d];
					if (x2<0) continue;
					if (x2>=n) continue;
					if (y2<0) continue;
					if (y2>=m) continue;
					if (dis[step][x][y][s]+1>=dis[step][x2][y2][s2]) continue;
					if (board[x2][y2]=='k' && !(x2==vx[step] && y2==vy[step])) continue;
					if (board[x2][y2]=='k' && cubes[s2].top!=color[step]) continue;
					dis[step][x2][y2][s2]=dis[step][x][y][s]+1;
					queues[step].push(make_pair(make_pair(x2,y2),s2));
					if (board[x2][y2]=='k')
					{
						dis[step+1][x2][y2][s2]=dis[step][x2][y2][s2];
						starts[step+1].push(make_pair(make_pair(x2,y2),s2));
					}
				}
			}
		}
		ans=0x7FFFFFFF;
		for (int s=0;s<24;s++)
			ans=min(ans,dis[6][vx[5]][vy[5]][s]);
		if (ans>2000000000) puts("unreachable");
		else printf("%d\n",ans);
	}
	return 0;
}

