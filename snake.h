#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake
{
public:
	enum Direction {UP, DOWN, LEFT, RIGHT };

	Snake() {
		snake.emplace_back(254, 236);
		snake.emplace_back(268, 236);
		snake.emplace_back(282, 236);
		direction = Direction::RIGHT;
	}
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge();
	bool HitItself();
	bool HitBox();
	bool ChangeDirection();
	bool GetFood(const Food&);
	bool GetBigFood(Food&);
private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;//��Food����Ϊ��Ԫ���Ա������˽��Ԫ��
};
#endif // SNAKE_H

