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
#include<Box2D\Box2D.h>
#include "animation.h"
using namespace std;
using namespace sf;
int main()
{
	string ch;
	bool boo;
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
			mm.start();
			break;
		case 2:
			h.savehighscore(23);
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
			boo = false;
		}
	} while (boo);
	return 0;
}