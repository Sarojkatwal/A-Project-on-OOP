using namespace std;
using namespace sf;
class Background
{
protected:
	Texture texture,texture1[4];
	Sprite sprite,sprite1[4];
	RenderWindow window;
	Font font,font1;
	Text text,text1;
	SoundBuffer buffer;
	Sound sound;
public:
	void MainBackground()
	{
		    window.create(sf::VideoMode(800, 600), "My window");
			window.setPosition(Vector2i(200,0));
			buffer.loadFromFile("audio/doublebass.wav");
			sound.setBuffer(buffer);
			sound.setLoop(true);
			texture.loadFromFile("images/1stbackground.png");
			sprite.setTexture(texture);
			sprite.setScale(Vector2f(0.8f, 0.8f));
			sprite.setPosition(0,0);
			string str[] = { "images/loading.png","images/loading1.png","images/loading2.png" ,"images/loading3.png","images/loading4.png" };
			for (int i = 0; i < 4; i++)
			{
				texture1[i].loadFromFile(str[i]);
				sprite1[i].setTexture(texture1[i]);
				sprite1[i].setScale(Vector2f(0.5f, 0.5f));
				sprite1[i].setPosition(370,390);
			}
			font.loadFromFile("font/loading.ttf");
			font1.loadFromFile("font/loading.ttf");
			text.setFont(font);
			text.setCharacterSize(180);
			text.setFillColor(Color::Red);
			text.setStyle(Text::Bold);
			text.setStyle(Text::Italic);
			text.setString("    The \n Jumper");
			text.setPosition(120, 20);
			text1.setFont(font1);
			text1.setCharacterSize(30);
			text1.setFillColor(Color::Blue);
			text1.setString("Loading.....");
			text1.setPosition(370, 450);
			sound.play();
			for (int j = 0; j <1; j++)
			{
				for (int i = 0; i < 1; i++)
				{
					window.clear();
					window.draw(sprite);
					window.draw(text);
					window.draw(text1);
					window.draw(sprite1[i]);
					window.display();
					sleep(milliseconds(300));

				}
			}
			sound.stop();
			window.close();
	}
};
