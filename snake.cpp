#include "snake.h"
#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>
#include "map.h"

void Snake::InitSnake()//��ʼ����
{

	for (auto& point : snake)
	{
		point.PrintCircular();
	}
	snake.back().Printsnakeheadright();
}

void Snake::Move()//������
{
	snake.back().Clear(15, 15);
	snake.back().PrintCircular();
	switch (direction)
	{
	case Direction::UP:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() - 14));
		snake.back().Printsnakeheadup();
		break;
	case Direction::DOWN:
		snake.emplace_back(Point(snake.back().GetX(), snake.back().GetY() + 14));
		snake.back().Printsnakeheaddown();
		break;
	case Direction::LEFT:
		snake.emplace_back(Point(snake.back().GetX() - 14, snake.back().GetY()));
		snake.back().Printsnakeheadleft();
		break;
	case Direction::RIGHT:
		snake.emplace_back(Point(snake.back().GetX() + 14, snake.back().GetY()));
		snake.back().Printsnakeheadright();
		break;
	default:
		break;
	}
}

void Snake::NormalMove()//�������ƶ���ͷ������β����
{
	Move();
	snake.front().Clear(15, 15);
	snake.pop_front(); //ɾ�������еĵ�һ��Ԫ��(��ͷ����β)
}

bool Snake::OverEdge()//�����߽�
{
	return snake.back().GetX() < 610 &&
		snake.back().GetY() < 480 &&
		snake.back().GetX() > 30 &&
		snake.back().GetY() > 40;
}

bool Snake::HitItself()//ײ������
{
	std::deque<Point>::size_type cnt = 1;
	Point *head = new Point(snake.back().GetX(), snake.back().GetY());//���ͷ������
	for (auto& point : snake) //���������������ͷ����ͬ�����겻�����߳�������ζ����ͷ��ײ������
	{
		if (!(point == *head))
			++cnt;
		else
			break;
	}
	delete head;
	if (cnt == snake.size())
		return true;
	else
		return false;
}

bool Snake::HitBox()
{
	return ((snake.back().GetX() > 74 && snake.back().GetX() < 186 && snake.back().GetY()> 74 && snake.back().GetY() < 186) ||
		(snake.back().GetX() > 484 && snake.back().GetX() < 596 && snake.back().GetY() > 94 && snake.back().GetY() < 206) ||
		(snake.back().GetX() > 294 && snake.back().GetX() < 406 && snake.back().GetY() > 354 && snake.back().GetY() < 466) ||
		(snake.back().GetX() > 144 && snake.back().GetX() < 256 && snake.back().GetY() > 294 && snake.back().GetY() < 406) ||
		(snake.back().GetX() > 394 && snake.back().GetX() < 506 && snake.back().GetY() > 224 && snake.back().GetY() < 336));
}

bool Snake::ChangeDirection()//�ı䷽��
{
	char ch;
	if (kbhit())//kbhit��������ֵΪ��������ע��
	{
		ch = getch();
		switch (ch)
		{
		case -32:
			ch = getch();
			switch (ch)
			{
			case 72:
				if (direction != Direction::DOWN)//��������뵱ǰ�˶������෴����Ч
				{
					direction = Direction::UP;
				}
				break;
			case 80:
				if (direction != Direction::UP)
				{
					direction = Direction::DOWN;
				}
				break;
			case 75:
				if (direction != Direction::RIGHT)
				{

					direction = Direction::LEFT;
				}
				break;
			case 77:
				if (direction != Direction::LEFT)
				{

					direction = Direction::RIGHT;
				}
				break;
			default:
				break;
			}
			return true;

		case 27://ESC
			return false;

		default:
			return true;

		}
	}
	return true;
}

bool Snake::GetFood(const Food& cfood)
{
	if (snake.back().GetX() == cfood.x && snake.back().GetY() == cfood.y)
	{
		snake.back().Clear(15, 15);
		snake.back().PrintCircular();
		return true;
	}
	else
		return false;
}

bool Snake::GetBigFood(Food& cfood)
{
	if (snake.back().GetX() == cfood.big_x && snake.back().GetY() == cfood.big_y)
	{
		cfood.big_flag = false;
		cfood.big_x = 0;
		cfood.big_y = 0;
		Map *init_map = new Map();
		init_map->clearxy(snake.back().GetX() - 10, snake.back().GetY() - 10, 21, 21);
		delete init_map;
		snake.back().PrintCircular();
		return true;
	}
	else
		return false;
}

