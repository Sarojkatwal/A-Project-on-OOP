#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<sstream>
#include "maingame.h"
#include "Background.h"
#include "Menu.h"
#include "Fromfile.h"
#include "animation.h"
#include "lastwindow.h"
#include "Collision.h"
using namespace std;
using namespace sf;
int main()
{
	int score;
	string ch;
	bool bo=true;
	Background b;
	Readfromfile rd;
	A m;
	mainGame mm;
	b.MainBackground();
	highscore h;
	do
	{
		int n = m.showoptions();
		switch (n)
		{
		case 1:
			score=mm.start();
			h.savehighscore(score);
			break;
		case 2:
			h.showhighscore();
			break;
		case 3:
			ch = "file/help.txt";
			rd.read(ch,"Help");
			break;
		case 4:
			ch = "file/about.txt";
			rd.read(ch,"About");
			break;
		default:
			bo = false;
		}
	} while (bo);
	return 0;
}