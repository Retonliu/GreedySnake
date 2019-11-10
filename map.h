#ifndef MAP_H
#define MAP_H

#include <vector>
#include "point.h"

class Map
{
public:
	void PrintBackground(); //���Ʊ���ͼƬ
	void PrintWall();
	void clearxy(int x, int y, int width, int height); //�������
	void start();  //��ʼ���汳��ͼƬ
	void PrintScore();  //���ְ񱳾�ͼƬ
	void PrintSelect();  //�Ѷ�ѡ�񱳾�ͼƬ
	std::vector<Point> wall;
};
#endif // MAP_H
