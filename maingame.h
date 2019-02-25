#pragma once
#include "animation.h"
using namespace sf;
using namespace std;
class mainGame
{
public:
	int x=0, y=580,xofimg,noofslidex=0,noofslidey=0;
	char direction='R';
	bool start()
	{
		string dangerobstacle[] = { "images/fire_P.png","images/fire_prev.png","images/thumb.png","images/danger.png","images/Fire-PNG-File.png","images/bomb.png"};
		string nondangerobstacle[] = { "images/bar.png","images/PipeDown.png","images/PipeUpown.png" };
		string helpingbars[] = { "images/loadingFull.png" ,"images/land.png","images/logs.png"};
		string lifeincreasingthings[] = { "images/life.png" ,"images/life1.png","images/life2.png","images/vitamin.png"};
		RenderWindow window(VideoMode(1300, 650), "Maingame");
		window.setPosition(Vector2i(30, 20));
		RectangleShape player(Vector2f(50.0f, 50.0f));
		View view(FloatRect(0.f, 0.f, 200.f, 200.f));
		view.setCenter(200,550); 
		Texture texture, texture1,texture2,texture4dangerobstacles[6], texture4nondangerobstacles[3];
		texture.loadFromFile("images/george.png");
		texture1.loadFromFile("images/background_land.png");
		texture2.loadFromFile("images/grass04.png");
		for (int i = 0; i < 6; i++)
		{
			texture4dangerobstacles[i].loadFromFile(dangerobstacle[i]);
		}
		player.setTexture(&texture);
		Animation animation(&texture,Vector2u(4,4),.3f);
		float deltatime = 0.0f;
		Clock clock;
		Sprite sprite,sprite1,sprite4dangerobstacles[6];
		sprite.setTexture(texture1);
		sprite1.setTexture(texture2);
		sprite1.setScale(2.9, 0.2);
		sprite1.setPosition(0, 600);
		for (int i = 0; i < 5; i++)
		{
			sprite4dangerobstacles[i].setTexture(texture4dangerobstacles[i]);
			sprite4dangerobstacles[i].setScale(0.05, 0.05);
		}

		//POSITION FOR OBSTACLE
		sprite4dangerobstacles[0].setPosition(900,300);
		sprite4dangerobstacles[1].setPosition(100,590);
		sprite4dangerobstacles[2].setPosition(300,460);
		sprite4dangerobstacles[3].setPosition(220,440);
		sprite4dangerobstacles[4].setPosition(200, 590);
		sprite4dangerobstacles[5].setPosition(300, 460);
		sprite4dangerobstacles[6].setPosition(180, 440);
		//sprite4dangerobstacles[7].setPosition(520, 540);

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
						 //player.setPosition(x, y);
					 }
				}
				if (event.type = Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						//cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
						cout << sprite4dangerobstacles[1].getLocalBounds().width<<"   "<< sprite4dangerobstacles[1].getLocalBounds().height<< endl;
						cout << sprite4dangerobstacles[1].getLocalBounds().top << "   " << sprite4dangerobstacles[1].getLocalBounds().left << endl;
					}
				}
				
			}
			y = y + 3;
			if (direction == 'R')
			{
				xofimg = 3;
				x = x + 20;
				if (x < 1296)
				{
					view.move(0.5, 0);
				}
			}
			else if (direction == 'L')
			{
				xofimg = 1;
				x = x - 20;
				if (x > 3)
				{
					view.move(-0.5, 0);
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
			for (int i = 0; i < 7; i++)
			{
				window.draw(sprite4dangerobstacles[i]);
			}
			window.setView(window.getDefaultView());
			window.draw(player);
			window.display();
			sleep(seconds(0.08));
		}
	}
};