#pragma once
#include "maingame.h"
using namespace std;
using namespace sf;
void iscolliding(Sprite *object,char dir,RectangleShape *player,View *view,bool *ismoving)
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
				*ismoving = false;
		}
	}
	if (dir == 'L')
	{
			if (abs(left1 - left2) < width2 and (left1+width1/2)>left2)
			{
				if (top1 > (top2 - height1) and top1 < (top2 + height2))
				{
					*ismoving = false;
				}
			}

	}
}
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
	else if ((top1< top2 +height2+10 and top1>top2+height2-11) and (left1 > (left2) and left1 < (left2 + width2)))
	{
		*onverticalblock = true;
	}
	else if ((left1 > left2-width1 and left1<left2+width2) and (top1>top2-35 and top1<top2+height2 ))
	{
		*ismoving=false;
	}
}