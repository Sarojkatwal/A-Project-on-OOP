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
		string obstacle[3] = { "images/loadingFull.png" ,"images/Industrial_Skatepark_Wall1.png","images/fire_prev.png"};
		RenderWindow window(VideoMode(1300, 650), "Maingame");
		window.setPosition(Vector2i(30, 20));
		RectangleShape player(Vector2f(50.0f, 50.0f));
		View view(FloatRect(0.f, 0.f, 200.f, 200.f));
		view.setCenter(200,550);
		Texture texture, texture1,texture2,texture4obstacles[3];
		texture.loadFromFile("images/george.png");
		texture1.loadFromFile("images/background_land.png");
		texture2.loadFromFile("images/grass04.png");
		for (int i = 0; i < 3; i++)
		{
			texture4obstacles[i].loadFromFile(obstacle[i]);
		}
		player.setTexture(&texture);
		Animation animation(&texture,Vector2u(4,4),.3f);
		float deltatime = 0.0f;
		Clock clock;
		Sprite sprite,sprite1,sprite4obstacles[3];
		sprite.setTexture(texture1);
		sprite1.setTexture(texture2);
		sprite1.setScale(2.6, 0.2);
		sprite1.setPosition(0, 600);
		for (int i = 0; i < 3; i++)
		{
			sprite4obstacles[i].setTexture(texture4obstacles[i]);
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
							 if (x < 1294)
							 {
								 view.move(2, -2);
							 }
						 }
						 else if (direction == 'L')
						 {
							 xofimg = 1;
							 if (x > 6)
							 {
								 view.move(-2, -2);
							 }
						 }
						 y = player.getPosition().y - 15;
						 player.setPosition(x, y);
					 }
				}
				/*if (event.type = Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						cout << event.mouseButton.x << "  " << event.mouseButton.y << endl;
						cout << view.getCenter().x << endl;
					}
				}*/
			}
			y = y + 3;
			if (direction == 'R')
			{
				xofimg = 3;
				x = x + 4;
				view.move(2, 0);
			}
			else if (direction == 'L')
			{
				xofimg = 1;
				x = x - 4;
				if (x > 3)
				{
					view.move(-2, 0);
				}
			}
			if (x > 1290)
			{
				x = 3;
				view.setCenter(view.getCenter().x - view.getSize().x, view.getCenter().y);
				noofslidex++;
			}
			if (x < 3)
			{
				if (noofslidex <= 0)
					x = 3;
				else
				{
					x = 1289;
					view.setCenter(view.getCenter().x+view.getSize().x,view.getCenter().y);
					noofslidex--;
				}
			}
			if (y <1)
			{
				if (noofslidey < 1)
				{
					y = 580;
					view.setCenter(view.getCenter().x, view.getCenter().y - view.getSize().y);
					noofslidey++;
				}
				else
					y = 1;
			}
			if (y >580)
			{
				if (noofslidey <= 0)
					y = 580;
				else
				{
					y = 1;
					view.setCenter( view.getSize().x, view.getCenter().y + view.getCenter().y);
					noofslidey--;
				}
			}
			if (view.getCenter().y < 550)
			{
				view.move(0, 1);
			}
			else
			{
				view.setCenter(view.getCenter().x, 550);
			}
			animation.Update(xofimg,deltatime);
			player.setTextureRect(animation.uvRect);
			window.clear(Color::Red);
			window.setView(view);
			window.draw(sprite);
			window.draw(sprite1);
			window.setView(window.getDefaultView());
			/*for (int i = 0; i < 3; i++)
			{
				window.draw(sprite4obstacles[i]);
			}*/
			window.draw(player);
			window.display();
			sleep(seconds(0.08));
		}
	}
};