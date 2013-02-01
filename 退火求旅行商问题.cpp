//计54 冯晓君 2005011312
//人工智能第三次编程题：模拟退火算法求解旅行商问题
//2007年12月11日
//2007年12月12日修改


/*	
程序使用的参数说明：	
基本上使用的是课件中提供的康立山等人的方法，根据实际使用的情况和参考了周勇禄同学的部分设置初值的方法做了轻微的调整
。
初始温度的选取方法：	
	选取一个确定值：280度
	
状态被接受的条件：
	使用了课件95页的方法，如果delta f < 0, 则At = 1，否则At = exp(-delta f / t)

降温算法：
	采用等比例下降的方法，比例系数为0.95

同一温度内计算结束的条件：
	在每个温度下采用固定的迭代次数，Lk=100n，n为城市数；

算法结束条件：
	当相邻三个温度得到的解无任何变化时算法停止。 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

//记录坐标的结构类型
struct dis
{
	double x,y;
};

const double epsln = 0.000001;
const double p0 = 0.95;
const int MAX_COUNT = 2;

dis citys[20];				//城市的坐标,用数组记录
int n;						//城市数目
double t0;					//初始温度
double bestLength;			//最优解
double preLength;			//前一次的解，用来判断结束条件
double currentLength;		//当前解
int loop;					//循环次数
string bestPath;			//城市路径，根据两个输入数据都顺序用一位字符表示城市名的情况，可以用字符串记录路径。
string currentPath;			//每次得到的当前城市路径

double distance(char a, char b) 
{
	double dis = sqrt((citys[a - 'A'].x - citys[b - 'A'].x) * (citys[a - 'A'].x - citys[b - 'A'].x) 
		+ (citys[a - 'A'].y - citys[b - 'A'].y) * (citys[a - 'A'].y - citys[b - 'A'].y));
	return dis;
}

double pathLength(string p) 
{
	double length = 0;
	for(int i = 0; i < n; i ++) 
		length += distance(p[i], p[i + 1]);
	return length;
}

//读入文件中的城市坐标数据
void readData()
{
	string fileName;
	cout << "请输入文件名：";
	cin >> fileName;
	ifstream fin(fileName.data());

	fin >> n;
	for (int i = 0; i < n; i++)
	{
		citys[i].x = 0;
		citys[i].y = 0;
	}
	for (int i = 0; i < n; i++)
	{
		char city;
		double x,y;
		fin >> city >> x >> y;
		citys[(int)(city - 'A')].x = x;
		citys[(int)(city - 'A')].y = y;
	}
	fin.close();
}

//设置各项参数
void setup()
{
	t0 = 280;										//初始温度
	loop = 100 * n;									//每一个温度的循环次数
	bestPath = "";									
	for (int i = 0; i < n; i++)
		bestPath = bestPath + (char)(i + 'A');
	bestPath = bestPath + bestPath[0];				//初始化路线序列
	cout << "\n初始状态: " << bestPath.substr(0, n);
	cout << "\n起始温度: " << t0;
	bestLength = pathLength(bestPath);				//初始化最优解
}

void shuffle(int rand1, int rand2)
{
	if(rand1 > rand2) 
	{
		int temp = rand1;
		rand1 = rand2;
		rand2 = temp;
	}

	for(int i = 1; i <= (rand2 - rand1 - 1) / 2; i ++) 
	{
		char temp = currentPath[rand1 + i];
		currentPath[rand1 + i] = currentPath[rand2 - i];
		currentPath[rand2 - i] = temp;
	}
}

//判断当前解是否满足接受的概率
bool proAccept(double bestLength, double currentLength, double t)
{
	double p = (double)rand() / (double)(RAND_MAX);
	double pt = exp((bestLength - currentLength) / t);
	if(pt > p) 
		return true;
	else 
		return false;
}

// 应用模拟退火算法求解
void simulateAnneal() {
	double t = t0;
	int count = 0;		//记录每一个温度下结果重复的次数，如果重复了三次，就结束整个算法。		
	while(true) 
	{
		for(int i = 0; i < loop; i ++) 
		{
			//随机选取两个城市，将他们之间的城市走向反向
			currentPath = bestPath;
			int rand1 = rand() % (n + 1);
			int rand2 = rand() % (n + 1);
			while(abs(rand1 - rand2) < 3)
				rand2 = rand() % (n + 1);

			//将rand1，rand2之间的城市走向反向
			shuffle(rand1, rand2);

			//计算新解
			double currentLength = pathLength(currentPath);		

			//新解的接受准则，注意使用浮点数的大小比较方法，要分两种情况
			if(currentLength - bestLength < epsln) 
			{
				bestLength = currentLength;
				bestPath = currentPath;
			} 
			else //判断当前解是否满足接受的概率
				if (proAccept(bestLength, currentLength, t))
				{
					bestLength = currentLength;	
					bestPath = currentPath;
				}
		}

		if(fabs(preLength - bestLength) < epsln) 
		{
			count++;
			//满足结束条件，输出终结状态，MAX_COUNT标记结束时要求的结果不变的次数
			if(count > MAX_COUNT) 
			{
				cout << "\n终结状态: ";
				cout << "\n路线：" << bestPath << "\t路程：" << bestLength << endl;
				return;
			}
		} 
		else 
		{
			preLength = bestLength;
			count = 0;
		}
		//每次输出当前温度下的计算结果
		cout << "\n当前温度：" << t << "\n路线：" << bestPath << "\t路程：" << bestLength << endl;
		//温度下降
		t = t * p0;
	}
}

void init()
{
	readData();				//读入数据
	setup();				//初始化参数
}

int main()
{
	init();					//读入数据，初始化参数
	simulateAnneal();		//用模拟退火算法求解
	return 0;
}
