#pragma once
#include "animation.h"
using namespace sf;
using namespace std;
class mainGame
{
public:
	int x=0, y=580,xofimg,noofslidex=0,noofslidey=0;
	char direction='R';
	bool isjumping = false,ismoving=true;
	bool start()
	{
		//Making array of obstacles and helping bars and life increasing materials
		string dangerobstacle[6] = { "images/fire_P.png","images/fire_prev.png","images/thumb.png","images/danger.png","images/bomb.png","images/lake.png"};
		string lessdangerobstacle[3] = { "images/bar.png","images/PipeDown.png","images/PipeUp.png" };
		string helpingbars[2] = { "images/loadingFull.png" ,"images/land.png"};
		string lifeincreasingthings[2] = { "images/life.png" ,"images/life1.png"};
		string flags[3] = { "images/firstflag.png","images/secondflag.png","images/lastflag.png" };


		//Position for different objects
		float PipeupX[9] = {250,270,470,470,660,660,660,840,840};
		float PipeUpY[9] = {576.4,376.4,356.4,540,250.6,605,427.8,472.4,285.2};
		float PipedownX[9] = {250,270,470,470,660,660,840,840,960};
		float PipedownY[9] = {450,250,220,430,501.4,324.6,546,358.8,576.4};
		float ThumbX[4] = {160.0,360.5,420.4,854.15};
		float ThumbY[4] = {618.15,418.2,618.15,618.15};
		float LandX[8] = {140,180,340,490,600,700,930,973.9};
		float LandY[8] = {530,350,520,430,290,500,290,557.15};
		float PondX[2] = {260,795};
		float PondY[2] = {615,605};
		float BombX[3] = {395,700,980};
		float BombY[3] = {580,330,540.35};
		float FlagX[3] = {420,680,980};
		float FlagY[3] = {580,280,577.5};
		float DangerX[2] = {725,960};
		float DangerY[2] = {300,900};
		float Life2X[2] = {610,860};
		float Life2Y[2]={270,460};
		float Life1X[2] = {265 ,842 };
		float Life1Y[2]={ 610,260 };
		float Fire2X[9], Fire2Y[9];
		for (int i = 0; i < 9; i++)
		{
			Fire2X[i] = PipeupX[i] - 32.0;
			Fire2Y[i] = PipeUpY[i] - 36.0;
		}
		float Fire1X[9], Fire1Y[9];
		for (int i = 0; i < 9; i++)
		{
			Fire1X[i] = PipeupX[i] + 32.0;
			Fire1Y[i] = PipeUpY[i] - 36.0;
		}

		RenderWindow window(VideoMode(1300, 650), "Maingame");
		window.setPosition(Vector2i(30, 20));
		RectangleShape player(Vector2f(50.0f, 50.0f));
		View view;
		view.setSize(200.f, 200.f);
		view.setCenter(200, 550);

		Texture texture, texture1,texture2,texture4coin,texture4dangerobstacles[6], texture4lessdangerobstacles[3],texture4helpingbars[2],texture4lifeincreasingthings[2],texture4flag[3];
		texture.loadFromFile("images/george.png");
		texture1.loadFromFile("images/background_land.png");
		texture2.loadFromFile("images/grass04.png");
		texture4coin.loadFromFile("images/Coin.png");
		for (int i = 0; i < 6; i++)
		{
			texture4dangerobstacles[i].loadFromFile(dangerobstacle[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			texture4lessdangerobstacles[i].loadFromFile(lessdangerobstacle[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			texture4flag[i].loadFromFile(flags[i]);
		}
		for (int i = 0; i < 2; i++)
		{
			texture4helpingbars[i].loadFromFile(helpingbars[i]);
		}
		for (int i = 0; i < 2; i++)
		{
			texture4lifeincreasingthings[i].loadFromFile(lifeincreasingthings[i]);
		}
		player.setTexture(&texture);

		Animation animation(&texture,Vector2u(4,4),.3f);
		float deltatime = 0.0f;
		Clock clock;

		/////Sprite
		Sprite sprite, sprite1,coin[20];
		Sprite fire1[9], fire2[9];
		Sprite pond[2],bomb[3],thumb[4],danger[2];
		Sprite pipedown[15],pipeup[10],bar[8];
		Sprite loadingfull[5], land[8];
		Sprite life1[2], life2[2];
		Sprite flag[3];
		sprite.setTexture(texture1);
		sprite1.setTexture(texture2);
		sprite1.setScale(2.9, 0.2);
		sprite1.setPosition(0, 600);
		//Coin
		for (int i = 0; i < 20; i++)
		{
			coin[i].setTexture(texture4coin);
			//coin[i].setPosition(CoinX[i], CoinY[i]);
		}
		//Flags
		for (int i = 0; i < 3; i++)
		{
			flag[i].setTexture(texture4flag[i]);
			flag[i].setScale(0.1, 0.1);
			flag[i].setPosition(FlagX[i], FlagY[i]);
		}
		//Danger
		//(fire1)
		for (int i = 0; i < 9; i++)
		{
			fire1[i].setTexture(texture4dangerobstacles[0]);
			fire1[i].setScale(0.04, 0.04);
			fire1[i].setPosition(Fire1X[i],Fire1Y[i]);
		}
		//fire2
		for (int i = 0; i < 9; i++)
		{
			fire2[i].setTexture(texture4dangerobstacles[1]);
			fire2[i].setScale(0.05*3, 0.05*3);
			fire2[i].setPosition(Fire2X[i],Fire2Y[i]);
		}
		//pond
		for (int i = 0; i < 2; i++)
		{
			pond[i].setTexture(texture4dangerobstacles[5]);
			pond[i].setScale(0.09,0.4);
			pond[i].setPosition(PondX[i],PondY[i]);
		}
		//bomb
		for (int i = 0; i < 3; i++)
		{
			bomb[i].setTexture(texture4dangerobstacles[4]);
			bomb[i].setScale(0.05*1.5, 0.05*1.5);
			bomb[i].setPosition(BombX[i],BombY[i]);
		}
		//Danger
		for (int i = 0; i < 2; i++)
		{
			danger[i].setTexture(texture4dangerobstacles[3]);
			danger[i].setScale(0.03, 0.03);
			danger[i].setPosition(DangerX[i],DangerY[i]);
		}
		//thumb
		for (int i = 0; i < 4; i++)
		{
			thumb[i].setTexture(texture4dangerobstacles[2]);
			thumb[i].setScale(0.05*3, 0.05*2);
			thumb[i].setPosition(ThumbX[i],ThumbY[i]);
		}

		//less danger
		//Pipedown
		for (int i = 0; i < 9; i++)
		{
			pipedown[i].setTexture(texture4lessdangerobstacles[1]);
			pipedown[i].setScale(0.2, 0.2);
			pipedown[i].setPosition(PipedownX[i],PipedownY[i]);
		}
		//Pipeup
		for (int i = 0; i < 9; i++)
		{
			pipeup[i].setTexture(texture4lessdangerobstacles[2]);
			pipeup[i].setScale(0.2, 0.2);
			pipeup[i].setPosition(PipeupX[i],PipeUpY[i]);
		}
		//Bars
		for (int i = 0; i < 8; i++)
		{
			bar[i].setTexture(texture4lessdangerobstacles[0]);
			bar[i].setScale(0.2, 0.2);
			//bar[i].setPosition();
		}

		//Helping objects
		//loadingfull
		for (int i = 0; i < 5; i++)
		{
			loadingfull[i].setTexture(texture4helpingbars[0]);
			loadingfull[i].setScale(0.05, 0.05);
			//loadingfull[i].setPosition();
		}
		//Land
		for (int i = 0; i < 8; i++)
		{
			land[i].setTexture(texture4helpingbars[1]);
			land[i].setScale(0.05*1.5, 0.05*1.5);
			land[i].setPosition(LandX[i],LandY[i]);
		}
		//Life
		for (int i = 0; i < 2; i++)
		{
			life1[i].setTexture(texture4lifeincreasingthings[0]);
			life1[i].setScale(0.05, 0.05);
			life1[i].setPosition(Life1X[i],Life1Y[i]);
		}
		for (int i = 0; i < 2; i++)
		{
			life2[i].setTexture(texture4lifeincreasingthings[1]);
			life2[i].setScale(0.05, 0.05);
			life2[i].setPosition(Life2X[i],Life2Y[i]);
		}

		while (window.isOpen())
		{
			player.setPosition(Vector2f(x, y));
			deltatime=clock.restart().asSeconds();
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					return true;
				}
				if (event.type == Event::KeyPressed)
				{
					 if (event.key.code == Keyboard::Right)
					 {
						 direction = 'R';
					 }
					 if (event.key.code == Keyboard::Left)
					 {
						 direction = 'L';
					 }
					 if (event.key.code == Keyboard::Up)
					 {
						 if (direction == 'R')
						 {
							 xofimg = 3;
						 }
						 else if (direction == 'L')
						 {
							 xofimg = 1;
						 }
						 y = player.getPosition().y - 15;
						 isjumping = true;
					 }
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						//cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
						//cout << land[1].getLocalBounds().width<<"   "<< land[1].getLocalBounds().height<< endl;
						//cout << land[1].getGlobalBounds().width << "   " << land[1].getGlobalBounds().height << endl;
						cout << life2[1].getGlobalBounds().width << "   " << life2[1].getGlobalBounds().height << endl;
						//cout << bomb[1].getGlobalBounds().width << "   " << bomb[1].getGlobalBounds().height << endl;
						//cout << thumb[1].getGlobalBounds().width << "   " << thumb[1].getGlobalBounds().height << endl;
						//cout << player.getGlobalBounds().width << "   " << player.getGlobalBounds().height << endl<<endl<<endl;
						//cout << pipeup[1].getGlobalBounds().top << "   " << pipeup[1].getGlobalBounds().left << endl;
					}
				}
				if (event.type = Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Up)
					{
						isjumping = false;
					}
				}
			}
			if (isjumping == false)
			{
				y = y + 3;
			}
			if (direction == 'R')
			{
				xofimg = 3;
				if (ismoving == true)
				{
					x = x + 20;
					if (x < 1296)
					{
						view.move(0.5, 0);
					}
				}
			}
			else if (direction == 'L')
			{
				xofimg = 1;
				if (ismoving == true)
				{
					x = x - 20;
					if (x > 3)
					{
						view.move(-0.5, 0);
					}
				}
			}
			if (x > 1296)
			{
				if (noofslidex >2)
					x = 1296;
				else
				{
					x = 4;
					view.setCenter(view.getCenter().x + view.getSize().x, view.getCenter().y);
					noofslidex++;
				}
			}
			if (x < 3)
			{
				if (noofslidex <= 0)
				{
					x = 3;
				}
				else
				{
					x = 1292;
					view.setCenter(view.getCenter().x-view.getSize().x,view.getCenter().y);
					noofslidex--;
				}
			}
			if (y <6)
			{
				if (noofslidey == 0)
				{

					y = 570;
					view.setCenter(view.getCenter().x, view.getCenter().y - view.getSize().y);
			
					noofslidey++;
				}
				else
					y = 6;
			}
			if (y >580)
			{
				if (noofslidey == 0)
				{
					y = 580;
				}
				else
				{
					y = 6;
					view.setCenter( view.getCenter().x, view.getCenter().y + view.getSize().y);
					noofslidey--;
				}
			}
			if (view.getCenter().x < 200)
			{
				view.setCenter(200, view.getCenter().y);
			}
			if (view.getCenter().x> 1300)
			{
				view.setCenter(1300, view.getCenter().y);
			}
			animation.Update(xofimg,deltatime);
			player.setTextureRect(animation.uvRect);
			window.clear(Color::Red);
			window.setView(view);
			window.draw(sprite);
			window.draw(sprite1);
			window.draw(pond[1]);
			window.draw(pond[0]);
			window.setView(window.getDefaultView());
			window.draw(player);
			window.setView(view);
			window.draw(land[1]);
			for (int i = 0; i < 9; i++)
			{
				window.draw(pipedown[i]);
				window.draw(pipeup[i]);
				window.draw(fire2[i]);
				window.draw(fire1[i]);
			}
			for (int i = 0; i < 4; i++)
			{
				window.draw(thumb[i]);
			}
			for (int i = 0; i < 8; i++)
			{
				window.draw(land[i]);
			}
			for (int i = 0; i < 3; i++)
			{
				window.draw(flag[i]);
				window.draw(bomb[i]);
			}
			for (int i = 0; i < 2; i++)
			{
				window.draw(danger[i]);
				window.draw(life2[i]);
				window.draw(life1[i]);
			}
			window.draw(fire2[1]);
			window.draw(flag[2]);
			window.display();
			sleep(seconds(0.08));
		}
	}
};