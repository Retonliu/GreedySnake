#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
class Snake;
class Food
{
public:
	Food() : big_flag(false), extra_flag(false), x(0), y(0), big_x(0), big_y(0), progress(0){}
    void DrawFood(Snake&, int);
    void DrawBigFood(Snake&, int);
    void VanishBigFood();
    bool GetBigFlag();
	void SetBigFlag(bool s);
    int GetProgress();
	void SetExtraFlag();
	bool GetExtraFlag();
private:
    bool big_flag;//�Ƿ��д�ʳ����
	bool extra_flag;//�Ƿ��ж���ʳ����
    int x, y;
    int big_x, big_y;
    int progress;//��ʱʳ�����
    friend class Snake;
};
#endif // FOOD_H
