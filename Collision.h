#pragma once
#include "maingame.h"
using namespace std;
using namespace sf;


//Bars up and down
void iscolliding(Sprite *object,char dir,RectangleShape *player,View *view,bool *ismoving ,int *nooflife)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height/(view->getSize().y+3)*650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y+3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if (dir == 'R')
	{
		if (abs(left2 - left1) < width1)
		{
			if ((top1 > (top2 - height1) and top1 < (top2 + height2)))
			{
				*ismoving = false;
				*nooflife -= 1;
			}
		}
	}
	if (dir == 'L')
	{
			if (abs(left1 - left2) < width2 and (left1+width1/2)>left2)
			{
				if (top1 > (top2 - height1) and top1 < (top2 + height2))
				{
					*ismoving = false;
					*nooflife -= 1;
				}
			}

	}
}

//Support
void iswithsupport(Sprite *object, char dir, RectangleShape *player, View *view, bool *ismoving, bool *onsupport, bool *onverticalblock)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1 / 1.5) and left1 < (left2 + width2)) and (top2 < (top1 + height1) and top2>(top1 + height1 -6)))
	{
		*onsupport = true;
	}
	else if ((top1< top2 +height2+10 and top1>top2+height2-11) and (left1 > (left2-width1/2) and left1 < (left2 + width2+5)))
	{
		*onverticalblock = true;
	}
	else if ((left1 > left2-width1 and left1<left2+width2) and (top1>top2-35 and top1<top2+height2 ))
	{
		*ismoving=false;
	}
}


//fire
void iswithfire(Sprite *object, char *dir, RectangleShape *player, View *view,int *nooflife)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1 / 2) and left1 < (left2 + width2/1.25)) and (top1 > (top2 - height1) and top1 < (top2 + height2/2)))
	{
		if (*dir == 'L')
		{
			*dir = 'R';
		}
		else
		{
			*dir = 'L';
		}
		*nooflife -= 2;
	}
}

//With thumb
void iswiththumb(Sprite *object, char *dir, RectangleShape *player, View *view,int *nooflife)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 + width1/1.5) and left1 < (left2 + width2/1.20)) and (top1 > (top2 - height1) and top1 < (top2 + height2)))
	{
		if (*dir == 'R')
		{
			*dir = 'L';
		}
		else
		{
			*dir = 'R';
		}
		*nooflife -= 1;
	}
}


//Life
void iswithlife(Sprite *object, char *dir, RectangleShape *player, View *view,int *nooflife)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1) and left1 < (left2 + width2)) and (top1 > (top2 - height1) and top1 < (top2 + height2)))
	{
		*nooflife += 20;
		object->setPosition(11500, 11500);
	}
}
 
//Bomb
bool iswithbomb(Sprite *object, char *dir, RectangleShape *player, View *view,Sprite *explosion)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1) and left1 < (left2 + width2)) and (top1 > (top2 - height1) and top1 < (top2 + height2)))
	{
		explosion->setPosition(object->getGlobalBounds().left-80,object->getGlobalBounds().top-90);
		if (*dir == 'R')
		{
			*dir = 'L';
		}
		return true;
	}
	else
		return false;
}

//Flag
bool iswithflag(Sprite *object, char *dir, RectangleShape *player, View *view)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1) and left1 < (left2 + width2)) and (top1 > (top2 - height1) and top1 < (top2 + height2)))
	{
		if (*dir == 'R')
		{
			*dir = 'L';
		}
		return true;
	}
	else
		return false;
}

//Inlake
bool isinpond(Sprite *object, char *dir, RectangleShape *player, View *view,int *nooflife)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1) and left1 < (left2 + width2)) and (top1 > (top2 - height1/1.8) and top1 < (top2 + height2)))
	{
		if (*dir == 'R')
		{
			*dir = 'L';
		}
		else
		{
			*dir = 'R';
		}
		*nooflife -= 2;
		player->setPosition(Vector2f(player->getPosition().x, player->getPosition().y - 50));
		return true;
	}
	else
		return false;
}


//Coin
bool iswithcoin(Sprite *object, char *dir, RectangleShape *player, View *view)
{
	float width1, height1, top1, left1, width2, height2, top2, left2;
	width1 = player->getGlobalBounds().width;
	height1 = player->getGlobalBounds().height;
	top1 = player->getGlobalBounds().top;
	left1 = player->getGlobalBounds().left;
	height2 = object->getGlobalBounds().height / (view->getSize().y + 3) * 650;
	width2 = object->getGlobalBounds().width / (view->getSize().x) * 1300;
	top2 = (object->getGlobalBounds().top - (view->getCenter().y - view->getSize().y / 2)) / (view->getSize().y + 3) * 650;
	left2 = (object->getGlobalBounds().left - (view->getCenter().x - view->getSize().x / 2)) / view->getSize().x * 1300;
	if ((left1 > (left2 - width1) and left1 < (left2 + width2)) and (top1 > (top2 - height1 / 1.5) and top1 < (top2 + height2)))
	{
		object->setPosition(11100, 11100);
		return true;
	}
	else
		return false;
}
