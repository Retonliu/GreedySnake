#include "food.h"
#include <cstdlib>
#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include "map.h"


void Food::DrawFood(Snake& csnake, int key)//����ʳ��
{
	while (true)
	{
		//Ϊ���ܱ�֤������ʳ���׼����Ҫ�Ե�ͼ���зָ��
		int tmp_x = rand() % 41;  //x�����Ϸֳ�41�ݣ�ÿ��14����
		int tmp_y = rand() % 28;  //x�����Ϸֳ�28�ݣ�ÿ��14����
		if (tmp_x == 0) tmp_x += 1;
		if (tmp_y == 0) tmp_y += 1;
		tmp_x = 30 + tmp_x * 14;
		tmp_y = 40 + tmp_y * 14;
		bool flag = false;
		for (auto& point : csnake.snake)  //��֤ʳ�ﲻ�������غ�
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y)) {
				flag = true;
				break;
			}
		}
		if (key == 4) //����ģʽ��ʳ�ﲻ�ܳ����ں�����
		{
			if ((tmp_x > 74 && tmp_x < 186 && tmp_y > 74 && tmp_y < 186) ||
				(tmp_x > 484 && tmp_x < 596 && tmp_y > 94 && tmp_y < 206) ||
				(tmp_x > 294 && tmp_x < 406 && tmp_y > 354 && tmp_y < 466) ||
				(tmp_x > 144 && tmp_x < 256 && tmp_y > 294 && tmp_y < 406) ||
				(tmp_x > 394 && tmp_x < 506 && tmp_y > 224 && tmp_y < 336))
				flag = true;
		}
		if (flag || (tmp_x == big_x && tmp_y == big_y)) //��֤�����ʳ���غ�
			continue;
		x = tmp_x;
		y = tmp_y;
		IMAGE FOOD;
		loadimage(&FOOD, _T("food.jpg"), 14, 14);
		putimage(x - 7, y - 7, &FOOD);
		break;
	}
	if ((!extra_flag) && (!big_flag) && (rand() % 3) == 1)
	{  //�Ѿ��д�ʳ���Ե�����ʳ��ʱ�����ִ�ʳ��
		DrawBigFood(csnake, key); //����֮һ���ʳ��ִ�ʳ��
	}
}

void Food::DrawBigFood(Snake& csnake, int key)//���ƴ�ʳ��
{
	progress = 52;
	big_flag = true;
	while (true)
	{
		int tmp_x = rand() % 41;
		int tmp_y = rand() % 28;
		if (tmp_x == 0) tmp_x += 1;
		if (tmp_y == 0) tmp_y += 1;
		tmp_x = 30 + tmp_x * 14;
		tmp_y = 40 + tmp_y * 14;
		bool flag = false;
		for (auto& point : csnake.snake)  //��֤ʳ�ﲻ�������غ�
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y)) {
				flag = true;
				break;
			}
		}
		if (key == 4) //����ģʽ��ʳ�ﲻ�ܳ����ں�����
		{
			if ((tmp_x > 74 && tmp_x < 186 && tmp_y > 74 && tmp_y < 186) ||
				(tmp_x > 484 && tmp_x < 596 && tmp_y > 94 && tmp_y < 206) ||
				(tmp_x > 294 && tmp_x < 406 && tmp_y > 354 && tmp_y < 466) ||
				(tmp_x > 144 && tmp_x < 256 && tmp_y > 294 && tmp_y < 406) ||
				(tmp_x > 394 && tmp_x < 506 && tmp_y > 224 && tmp_y < 336))
				flag = true;
		}
		if (flag || (tmp_x == x  && tmp_y == y))//��֤����Сʳ���غ�
			continue;
		big_x = tmp_x;
		big_y = tmp_y;
		IMAGE BIGFOOD;
		loadimage(&BIGFOOD, _T("bigfood.jpg"), 18, 18);
		putimage(big_x - 9, big_y - 9, &BIGFOOD);
		break;
	}
}

void Food::VanishBigFood()//ʹ��ʳ����ʱ����
{
	--progress;
	if (progress == 0) {
		Map *init_map = new Map();
		init_map->clearxy(big_x - 10, big_y - 10, 21, 21);
		delete init_map;
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}
}

int Food::GetProgress()
{
	return progress;
}

bool Food::GetBigFlag()
{
	return big_flag;
}

void Food::SetBigFlag(bool s)
{
	big_flag = s;
}

void Food::SetExtraFlag() //���ö���ʳ���־
{
	extra_flag = true;
}

bool Food::GetExtraFlag() //��ȡ����ʳ���־
{
	return extra_flag;
}