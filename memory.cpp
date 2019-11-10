#include "memory.h"
#include <fstream>
#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include <algorithm>

using namespace std;

bool cmp(data a, data b) //�Ƚ�����
{
	if (a.score > b.score)
		return true;
	else
		return false;
}

void save(int key, int score){
	ofstream onfile;
	onfile.open("memory.dat", ios::app);
	if (!onfile)  //���û��memory.dat�ļ�
	{
		ofstream file("memory.dat");  //�����ļ�
		onfile.open("memory.dat", ios::app);
	}
	onfile << key << "\t" << score << endl;
	onfile.close();
}

void read(){
	setcolor(RED);
	for (int i = 1; i <= 5; i++){
		TCHAR i_string[2];
		_stprintf(i_string, _T("%d"), i);
		outtextxy(220, 180 + 30 * i, i_string);
	}
	data s[100];
	for (int i = 0; i < 100; i++)
		s[i].key = s[i].score = 0;
	ifstream infile;
	infile.open("memory.dat", ios::in);
	if (!infile)  //���û��memory.dat�ļ�
	{
		ofstream file("memory.dat");  //�����ļ�
		infile.open("memory.dat", ios::in);
	}
	int j = 0;
	while (!infile.eof())
	{
		infile >> s[j].key >> s[j].score;
		++j;
	}
	if (j != 0)
	{
		int flag = 1;
		stable_sort(s, s + j, cmp);  //����
		for (int k = 0; k < j && k < 5; k++)
		{
			switch (s[k].key)
			{
			case 1:
				outtextxy(290, 210 + 30 * k, _T("��"));
				flag = 1;
				break;
			case 2:
				outtextxy(290, 210 + 30 * k, _T("��ͨ"));
				flag = 1;
				break;
			case 3:
				outtextxy(290, 210 + 30 * k, _T("����"));
				flag = 1;
				break;
			case 4:
				outtextxy(290, 210 + 30 * k, _T("����"));
				flag = 1;
				break;
			default:
				flag = 0;
				break;
			}
			if (flag)
			{
				TCHAR score_string[7];
				_stprintf(score_string, _T("%d"), s[k].score);
				outtextxy(370, 210 + 30 * k, score_string);
			}
		}
	}
}