#ifndef MEMORY_H
#define MEMORY_H

typedef struct
{
	int key;
	int score;
}data;

bool cmp(data a, data b);
void save(int key, int score);  //��������
void read();  //��ȡ����

#endif // MEMORY_H