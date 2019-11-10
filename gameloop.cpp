#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "gameloop.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include <easyx.h>
#include <graphics.h>
#include "memory.h"

void Gameloop::Start()//��ʼ����
{
	initgraph(655, 510);
}

int Gameloop::Select1() //ѡ�����1
{  
	Map *init_map = new Map();
	init_map->start();
	delete init_map;
	int tmp_key = 1;  //���ڼ�¼ѡ���ѡ��

	LOGFONT f;
	setbkmode(TRANSPARENT);
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 20;
	f.lfWidth = 20;
	f.lfWeight = 40000;
	f.lfItalic = true;
	f.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	f.lfQuality = NONANTIALIASED_QUALITY;
	_tcscpy_s(f.lfFaceName, _T("����"));
	settextstyle(&f);
	settextcolor(BLACK);
	outtextxy(220, 410, _T("��ʼ��Ϸ"));

	LOGFONT g;
	gettextstyle(&g);                     // ��ȡ��ǰ��������
	g.lfHeight = 12;
	g.lfWidth = 11;
	g.lfWeight = 40000;
	g.lfEscapement = 140;
	g.lfOrientation = 200;
	g.lfItalic = true;
	g.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	g.lfQuality = NONANTIALIASED_QUALITY;
	_tcscpy_s(f.lfFaceName, _T("Բ��"));
	settextstyle(&g);
	outtextxy(50, 330, _T("���ְ�"));

	outtextxy(55, 290, _T("˵��"));

	bool flag = false;  //���̿��Ʊ��
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 220 && m.x <= 380 && m.y >= 400 && m.y <= 430){
				settextstyle(&f);
				settextcolor(RED);
				outtextxy(220, 410, _T("��ʼ��Ϸ"));
			}
			else if (m.x >= 50 && m.x <= 140 && m.y >= 315 && m.y <= 350){
				settextstyle(&g);
				settextcolor(RED);
				outtextxy(50, 330, _T("���ְ�"));
			}
			else if (m.x >= 55 && m.x <= 150 && m.y >= 285 && m.y <= 309){
				settextstyle(&g);
				settextcolor(RED);
				outtextxy(55, 290, _T("˵��"));
			}
			else{
				settextstyle(&f);
				settextcolor(BLACK);
				outtextxy(220, 410, _T("��ʼ��Ϸ"));

				settextstyle(&g);
				outtextxy(50, 330, _T("���ְ�"));
				settextstyle(&g);
				outtextxy(55, 290, _T("˵��"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 220 && m.x <= 380 && m.y >= 400 && m.y <= 430){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 50 && m.x <= 140 && m.y >= 315 && m.y <= 350){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 55 && m.x <= 150 && m.y >= 285 && m.y <= 309){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag) break;
	}
	setbkmode(OPAQUE);
	LOGFONT h;
	gettextstyle(&h);
	h.lfHeight = 0;
	h.lfWidth = 0;
	h.lfEscapement = 0;
	h.lfOrientation = 0;
	h.lfItalic = false;
	settextstyle(&h);
	return tmp_key;
}

void Gameloop::Select2()//ѡ�����2
{
	Map *init_map = new Map();
	init_map->PrintSelect();
	delete init_map;
	settextstyle(17, 0, _T("����"));
	settextcolor(BROWN);
	setbkmode(TRANSPARENT);
	outtextxy(260, 70, _T("�Ѷ�ѡ��"));
	outtextxy(300, 100, _T("��ģʽ"));
	outtextxy(300, 130, _T("��ͨģʽ"));
	outtextxy(300, 160, _T("����ģʽ"));
	outtextxy(300, 190, _T("����ģʽ"));
	score = 0;
	key = 1;
	bool flag = false;
	/*ѡ�񲿷�*/
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 300 && m.x <= 370 && m.y >= 100 && m.y <= 120){
				settextcolor(RED);
				outtextxy(300, 100, _T("��ģʽ"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 130 && m.y <= 150){
				settextcolor(RED);
				outtextxy(300, 130, _T("��ͨģʽ"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 160 && m.y <= 180){
				settextcolor(RED);
				outtextxy(300, 160, _T("����ģʽ"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 190 && m.y <= 210){
				settextcolor(RED);
				outtextxy(300, 190, _T("����ģʽ"));
			}
			else{
				settextcolor(BROWN);
				outtextxy(260, 70, _T("�Ѷ�ѡ��"));
				outtextxy(300, 100, _T("��ģʽ"));
				outtextxy(300, 130, _T("��ͨģʽ"));
				outtextxy(300, 160, _T("����ģʽ"));
				outtextxy(300, 190, _T("����ģʽ"));
			}
			break;
		case WM_LBUTTONDOWN:  //����ѡ����Ѷ��趨�ߵ��ƶ��ٶ�
			if (m.x >= 300 && m.x <= 370 && m.y >= 100 && m.y <= 120){
				key = 1;
				speed = 50;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 130 && m.y <= 150){
				key = 2;
				speed = 30;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 160 && m.y <= 180){
				key = 3;
				speed = 1;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 190 && m.y <= 210){
				key = 4;
				speed = 1;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag) break;
	}
	setbkmode(OPAQUE);
}

int Gameloop::Score_list(int key) //��ӡ���ְ�
{
	bool flag = false;  //���̿��Ʊ��
	int choose = 1;  //��¼ѡ����
	cleardevice();
	Map *init_map = new Map();
	init_map->PrintScore();
	delete init_map;
	setbkmode(TRANSPARENT);
	setcolor(0x419564);
	setcolor(BLUE);
	settextstyle(30, 0, _T("����"));
	outtextxy(270, 60, _T("���ְ�"));
	settextstyle(16, 0, _T("����"));
	outtextxy(210, 100, _T("����"));
	outtextxy(290, 100, _T("�Ѷ�"));
	outtextxy(370, 100, _T("����"));
	read();  //��ȡ�ļ����ݣ�������ӡ
	setcolor(BLUE);
	if (key == 1){  //���ڿ�ʼ����򿪻��ְ�
		outtextxy(300, 400, _T("����"));
		MOUSEMSG m;
		while (true){
			m = GetMouseMsg();
			switch (m.uMsg)
			{
				case WM_MOUSEMOVE:
					if (m.x >= 300 && m.x <= 330 && m.y >= 400 && m.y <= 420){
						setcolor(RED);
						outtextxy(300, 400, _T("����"));
					}
					else{
						setcolor(BLUE);
						outtextxy(300, 400, _T("����"));
					}
					break;
				case WM_LBUTTONDOWN:
					if (m.x >= 300 && m.x <= 330 && m.y >= 400 && m.y <= 420){
						flag = true;
					}
					break;
			}
			if (flag){
				break;
			}
		}
		setbkmode(OPAQUE);
		return 0;
	}
	else if (key == 2){  //������������򿪻��ְ�
		outtextxy(240, 430, _T("���¿�ʼ"));
		outtextxy(340, 430, _T("�˳���Ϸ"));
		MOUSEMSG m;
		while (true){
			m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_MOUSEMOVE:
				if (m.x >= 240 && m.x <= 300 && m.y >= 430 && m.y <= 450){
					setcolor(RED);
					outtextxy(240, 430, _T("���¿�ʼ"));
				}
				else if (m.x >= 340 && m.x <= 400 && m.y >= 430 && m.y <= 450){
					setcolor(RED);
					outtextxy(340, 430, _T("�˳���Ϸ"));
				}
				else{
					setcolor(BLUE);
					outtextxy(240, 430, _T("���¿�ʼ"));
					outtextxy(340, 430, _T("�˳���Ϸ"));
				}
				break;
			case WM_LBUTTONDOWN:
				if (m.x >= 240 && m.x <= 300 && m.y >= 430 && m.y <= 450){
					choose = 1;
					flag = true;
				}
				else if (m.x >= 340 && m.x <= 400 && m.y >= 430 && m.y <= 450){
					choose = 2;
					flag = true;
				}
				break;
			}
			if (flag){
				break;
			}
		}
		setbkmode(OPAQUE);
		return choose;
	}
	else
	{
		setbkmode(OPAQUE);
		return 0;
	}
}

int Gameloop::Explain() //����˵���˵�
{

	cleardevice();
	Map *init_map = new Map();
	init_map->PrintScore();
	delete init_map;
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);
	settextstyle(17, 0, _T("����"));
	outtextxy(100, 250, _T("˵����ѡ����Ѷ�Խ���ߵ�����Խ�죬�Ե�"));
	outtextxy(100, 270, _T("Сʳ��÷�Խ�ߡ�����ģʽ��������ϰ����"));
	outtextxy(100, 290, _T("�Ե���ʳ���и��ʻ������Ч����"));
	outtextxy(240, 310, _T("1���ӷ�"));
	outtextxy(240, 330, _T("2������"));
	outtextxy(240, 350, _T("3���ٶȼӿ�"));
	outtextxy(240, 370, _T("4�����ֶ���ʳ��"));
	settextcolor(GREEN);
	outtextxy(280, 410, _T("����"));
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			if (m.x >= 280 && m.x <= 310 && m.y >= 410 && m.y <= 430){
				setcolor(RED);
				outtextxy(280, 410, _T("����"));
			}
			else
			{
				setcolor(GREEN);
				outtextxy(280, 410, _T("����"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 280 && m.x <= 310 && m.y >= 410 && m.y <= 430){
				setbkmode(OPAQUE);
				return 1;
			}
			break;
		}
	}
}

void Gameloop::DrawGame() //������Ϸ����
{
	cleardevice();//����
    /*���Ƶ�ͼ*/
    Map *init_map = new Map();
	init_map->PrintBackground();
    delete init_map;
    /*������Ϸ״̬��*/
	setbkmode(TRANSPARENT);
	settextcolor(0x1BBCFF);
	settextstyle(18, 0, _T("��Բ"));
	Map *wall = new Map();
    switch (key)
    {
    case 1:
		outtextxy(50, 10, _T("��ģʽ"));
        break;
    case 2:
		outtextxy(50, 10, _T("��ͨģʽ"));
        break;
    case 3:
		outtextxy(50, 10, _T("����ģʽ"));
        break;
    case 4:
		outtextxy(50, 10, _T("����ģʽ"));
		wall->PrintWall();
        break;
    }
	outtextxy(210, 10, _T("�÷֣�"));
	outtextxy(260, 10, _T("0"));
	settextstyle(16, 0, _T("����"));
}

int Gameloop::PlayGame()//��Ϸ����ѭ��
{
	/*��ʼ���ߺ�ʳ��*/
	Snake *csnake = new Snake();
	Food *cfood1 = new Food();
	Food *cfood2 = new Food();
	Food *cfood3 = new Food();
	csnake->InitSnake();
	srand((unsigned)time(NULL));//������������ӣ����û�У�ʳ��ĳ���λ�ý���̶�
	cfood1->DrawFood(*csnake, key);

	/*��Ϸѭ��*/
	while (csnake->OverEdge() && csnake->HitItself()) //�ж��Ƿ�ײǽ��ײ������
	{
		/*����ѡ��˵�*/
		if (!csnake->ChangeDirection()) //��Esc��ʱ
		{
			int tmp = Menu();//���Ʋ˵������õ�����ֵ
			switch (tmp)
			{
			case 1://������Ϸ
				break;

			case 2://���¿�ʼ
				delete csnake;
				delete cfood1;
				delete cfood2;
				delete cfood3;
				return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

			case 3://�˳���Ϸ
				delete csnake;
				delete cfood1;
				delete cfood2;
				delete cfood3;
				return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

			default:
				break;
			}
		}

		if (key == 4 && csnake->HitBox()) //������ģʽ��ײǽ
			break;

		if (csnake->GetFood(*cfood1)) //�Ե�ʳ��
		{
			csnake->Move();//������
			UpdateScore(1);//���·�����1Ϊ����Ȩ��
			RewriteScore();//���»��Ʒ���
			cfood1->DrawFood(*csnake, key);//������ʳ��
		}
		else if (csnake->GetFood(*cfood2)) //�Ե�����ʳ��1
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			Food *cfood2 = new Food(); //��ʼ������ʳ��
		}
		else if (csnake->GetFood(*cfood3)) //�Ե�����ʳ��2
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			Food *cfood3 = new Food(); //��ʼ������ʳ��
		}
		else if (csnake->GetBigFood(*cfood1)) //�Ե���ʳ��
		{
			csnake->Move();
			int event = (rand() % 5);
			switch (event)
			{
			case 0:
			case 1: //�нϴ���ʼӷ�
				UpdateScore(6);//����������ʱʳ�������ȷ��
				RewriteScore();
				break;
			case 2: //��һ�����ʼ���
				UpdateScore(-1);//����������ʱʳ�������ȷ��
				RewriteScore();
				break;
			case 3: //�м��ʳ��ֶ���ʳ��
				cfood2->SetExtraFlag();
				cfood2->DrawFood(*csnake, key);
				cfood3->SetExtraFlag();
				cfood3->DrawFood(*csnake, key);
				break;
			case 4: //�м��������ٶ�
				if (speed - 5 > 0)
					speed -= 5;
				break;
			default:
				break;
			}
		}
		else
		{
			csnake->NormalMove();//�������ƶ�
		}
		if (cfood1->GetBigFlag()) //ʹ��ʳ���һ��ʱ�����ʧ
		{
			cfood1->VanishBigFood();
		}

		Sleep(speed);//�����ߵ��ƶ�Ч��
	}

	/*������*/
	delete csnake;//�ͷŷ�����ڴ�ռ�
	delete cfood1;
	delete cfood2;
	delete cfood3;
	save(key, score); //������Ϸ�÷�
	int tmp = GameOver();//������Ϸ�������棬��������ѡ��
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	case 3:
		return 3;//�鿴���ְ�
	default:
		return 2;
	}
}

void Gameloop::UpdateScore(const int& tmp)//���·���
{
    score += key * 10 * tmp; //���÷���������Ϸ�Ѷȼ�����Ĳ���tmpȷ��
	if (score < 0) score = 0;  //��֤������Ϊ����
}

void Gameloop::RewriteScore()//�ػ����
{
	int tmp = score;
	TCHAR score_string[7]; //�趨�������Ϊ��λ�������һλ��Ž�����־��
	_stprintf(score_string, _T("%d"), score); //�ѷ���ת��Ϊ�ַ���
	setbkmode(OPAQUE);
	setbkcolor(0x1A3A6F);
	settextcolor(0x1BBCFF);
	settextstyle(18, 0, _T("��Բ"));
	outtextxy(260, 10, score_string);
	settextstyle(16, 0, _T("����"));
	setbkmode(TRANSPARENT);
}

int Gameloop::Menu()//��ͣ�˵�
{
    /*���Ʋ˵�*/
	setbkmode(TRANSPARENT);
	settextcolor(BROWN);
	settextstyle(18, 0, _T("��Բ"));
	outtextxy(260, 200, _T("�˵���"));
    Sleep(100);
	outtextxy(280, 230, _T("������Ϸ"));
    Sleep(100);
	outtextxy(280, 260, _T("���¿�ʼ"));
    Sleep(100);
	outtextxy(280, 290, _T("�˳���Ϸ"));

    /*ѡ�񲿷�*/
    int tmp_key = 1;
    bool flag = false;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 280 && m.x <= 340 && m.y >= 230 && m.y <= 250){
				settextcolor(RED);
				outtextxy(280, 230, _T("������Ϸ"));
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 260 && m.y <= 280){
				settextcolor(RED);
				outtextxy(280, 260, _T("���¿�ʼ"));
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 290 && m.y <= 310){
				settextcolor(RED);
				outtextxy(280, 290, _T("�˳���Ϸ"));
			}
			else{
				settextcolor(BROWN);
				outtextxy(280, 230, _T("������Ϸ"));
				outtextxy(280, 260, _T("���¿�ʼ"));
				outtextxy(280, 290, _T("�˳���Ϸ"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 280 && m.x <= 340 && m.y >= 230 && m.y <= 250){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 260 && m.y <= 280){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 290 && m.y <= 310){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
        if (flag)
        {
            break;
        }
    }

    if (tmp_key == 1) //ѡ�������Ϸ���򽫲˵�����
    {
		Map *init_map = new Map();
		init_map->clearxy(260, 200, 100,110);
		delete init_map;
		setbkmode(OPAQUE);
    }
	settextstyle(16, 0, _T("����"));
    return tmp_key;
}

void Gameloop::Game()//��Ϸһ��ѭ��
{
    Start();//��ʼ����
    while (true)//��Ϸ����Ϊһ����ѭ����ֱ���˳���Ϸʱѭ������
    {
		int tmp_key = Select1();
		if (tmp_key == 1){
			cleardevice();
			Select2();//ѡ�����
			DrawGame();//������Ϸ����
			int tmp = PlayGame();//������Ϸѭ���������¿�ʼ���˳���Ϸʱ������ѭ��������ֵ��tmp
			if (tmp == 1) //����ֵΪ1ʱ���¿�ʼ��Ϸ
			{
				cleardevice();
				continue;
			}
			else if (tmp == 2) //����ֵΪ2ʱ�˳���Ϸ
			{
				closegraph();
				break;
			}
			else if (tmp == 3)
			{
				int choose = Score_list(2);
				if (choose == 1){   //���¿�ʼ
					cleardevice();
					continue;
				}
				else if (choose == 2){  //�˳���Ϸ
					break;
				}
			}
		}
		else if (tmp_key == 2){
			Score_list(1);
			cleardevice();
			continue;
		}
		else if (tmp_key == 3){
			if (Explain()){
				cleardevice();
				continue;
			}
		}
		else{
			break;
		}
	}
}

int Gameloop::GameOver()//��Ϸ��������
{
    /*������Ϸ��������*/
    Sleep(500);
	setfillcolor(0x24538B);
	setlinecolor(0x01C29A);
	fillroundrect(180, 160, 460, 350, 40, 40);
	setfillcolor(0x1A3A6F);
	setlinecolor(0x1A3A6F);
	fillrectangle(200, 180, 440, 330);
    Sleep(60);
	setbkmode(TRANSPARENT);
	settextcolor(0x1BBCFF);
	outtextxy(280, 180, _T("��Ϸ������"));
    Sleep(60);
	outtextxy(270, 210, _T("���ź��������"));
    Sleep(60);
	outtextxy(250, 240, _T("��ķ���Ϊ��"));
    Sleep(60);
	TCHAR score_string[7];
	_stprintf(score_string, _T("%d"), score);
	outtextxy(370, 240, score_string);
    Sleep(60);
	settextcolor(GREEN);
	outtextxy(230, 270, _T("���¿�ʼ"));
	Sleep(60);
	outtextxy(350, 270, _T("�˳���Ϸ"));
	Sleep(60);
	outtextxy(280, 300, _T("�鿴���ְ�"));
    Sleep(100);
    
    /*ѡ�񲿷�*/
    int tmp_key = 1;
    bool flag = false;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 230 && m.x <= 290 && m.y >= 270 && m.y <= 290){
				settextcolor(RED);
				outtextxy(230, 270, _T("���¿�ʼ"));
			}
			else if (m.x >= 350 && m.x <= 410 && m.y >= 270 && m.y <= 290){
				settextcolor(RED);
				outtextxy(350, 270, _T("�˳���Ϸ"));
			}
			else if (m.x >= 280 && m.x <= 360 && m.y >= 300 && m.y <= 330){
				settextcolor(RED);
				outtextxy(280, 300, _T("�鿴���ְ�"));
			}
			else{
				settextcolor(GREEN);
				outtextxy(230, 270, _T("���¿�ʼ"));
				outtextxy(350, 270, _T("�˳���Ϸ"));
				outtextxy(280, 300, _T("�鿴���ְ�"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 230 && m.x <= 290 && m.y >= 270 && m.y <= 290){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 350 && m.x <= 410 && m.y >= 270 && m.y <= 290){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 360 && m.y >= 300 && m.y <= 330){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag)
		{
			break;
		}
	}
	setbkcolor(BLACK);
    switch (tmp_key)
    {
    case 1:
        return 1;//���¿�ʼ
    case 2:
        return 2;//�˳���Ϸ
	case 3:
		return 3;
    default:
        return 1;
    }
}
