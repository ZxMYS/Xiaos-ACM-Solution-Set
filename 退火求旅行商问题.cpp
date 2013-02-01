//��54 ������ 2005011312
//�˹����ܵ����α���⣺ģ���˻��㷨�������������
//2007��12��11��
//2007��12��12���޸�


/*	
����ʹ�õĲ���˵����	
������ʹ�õ��ǿμ����ṩ�Ŀ���ɽ���˵ķ���������ʵ��ʹ�õ�����Ͳο�������»ͬѧ�Ĳ������ó�ֵ�ķ���������΢�ĵ���
��
��ʼ�¶ȵ�ѡȡ������	
	ѡȡһ��ȷ��ֵ��280��
	
״̬�����ܵ�������
	ʹ���˿μ�95ҳ�ķ��������delta f < 0, ��At = 1������At = exp(-delta f / t)

�����㷨��
	���õȱ����½��ķ���������ϵ��Ϊ0.95

ͬһ�¶��ڼ��������������
	��ÿ���¶��²��ù̶��ĵ���������Lk=100n��nΪ��������

�㷨����������
	�����������¶ȵõ��Ľ����κα仯ʱ�㷨ֹͣ�� 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

//��¼����Ľṹ����
struct dis
{
	double x,y;
};

const double epsln = 0.000001;
const double p0 = 0.95;
const int MAX_COUNT = 2;

dis citys[20];				//���е�����,�������¼
int n;						//������Ŀ
double t0;					//��ʼ�¶�
double bestLength;			//���Ž�
double preLength;			//ǰһ�εĽ⣬�����жϽ�������
double currentLength;		//��ǰ��
int loop;					//ѭ������
string bestPath;			//����·�������������������ݶ�˳����һλ�ַ���ʾ��������������������ַ�����¼·����
string currentPath;			//ÿ�εõ��ĵ�ǰ����·��

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

//�����ļ��еĳ�����������
void readData()
{
	string fileName;
	cout << "�������ļ�����";
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

//���ø������
void setup()
{
	t0 = 280;										//��ʼ�¶�
	loop = 100 * n;									//ÿһ���¶ȵ�ѭ������
	bestPath = "";									
	for (int i = 0; i < n; i++)
		bestPath = bestPath + (char)(i + 'A');
	bestPath = bestPath + bestPath[0];				//��ʼ��·������
	cout << "\n��ʼ״̬: " << bestPath.substr(0, n);
	cout << "\n��ʼ�¶�: " << t0;
	bestLength = pathLength(bestPath);				//��ʼ�����Ž�
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

//�жϵ�ǰ���Ƿ�������ܵĸ���
bool proAccept(double bestLength, double currentLength, double t)
{
	double p = (double)rand() / (double)(RAND_MAX);
	double pt = exp((bestLength - currentLength) / t);
	if(pt > p) 
		return true;
	else 
		return false;
}

// Ӧ��ģ���˻��㷨���
void simulateAnneal() {
	double t = t0;
	int count = 0;		//��¼ÿһ���¶��½���ظ��Ĵ���������ظ������Σ��ͽ��������㷨��		
	while(true) 
	{
		for(int i = 0; i < loop; i ++) 
		{
			//���ѡȡ�������У�������֮��ĳ���������
			currentPath = bestPath;
			int rand1 = rand() % (n + 1);
			int rand2 = rand() % (n + 1);
			while(abs(rand1 - rand2) < 3)
				rand2 = rand() % (n + 1);

			//��rand1��rand2֮��ĳ���������
			shuffle(rand1, rand2);

			//�����½�
			double currentLength = pathLength(currentPath);		

			//�½�Ľ���׼��ע��ʹ�ø������Ĵ�С�ȽϷ�����Ҫ���������
			if(currentLength - bestLength < epsln) 
			{
				bestLength = currentLength;
				bestPath = currentPath;
			} 
			else //�жϵ�ǰ���Ƿ�������ܵĸ���
				if (proAccept(bestLength, currentLength, t))
				{
					bestLength = currentLength;	
					bestPath = currentPath;
				}
		}

		if(fabs(preLength - bestLength) < epsln) 
		{
			count++;
			//�����������������ս�״̬��MAX_COUNT��ǽ���ʱҪ��Ľ������Ĵ���
			if(count > MAX_COUNT) 
			{
				cout << "\n�ս�״̬: ";
				cout << "\n·�ߣ�" << bestPath << "\t·�̣�" << bestLength << endl;
				return;
			}
		} 
		else 
		{
			preLength = bestLength;
			count = 0;
		}
		//ÿ�������ǰ�¶��µļ�����
		cout << "\n��ǰ�¶ȣ�" << t << "\n·�ߣ�" << bestPath << "\t·�̣�" << bestLength << endl;
		//�¶��½�
		t = t * p0;
	}
}

void init()
{
	readData();				//��������
	setup();				//��ʼ������
}

int main()
{
	init();					//�������ݣ���ʼ������
	simulateAnneal();		//��ģ���˻��㷨���
	return 0;
}
