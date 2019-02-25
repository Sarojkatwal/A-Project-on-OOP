using namespace std;
using namespace sf;
class Readfromfile
{
protected:
	string filename;
	char expression[400];
	fstream file;
	Texture texture;
	Sprite sprite;
	RenderWindow window;
	Font font;
	Text text;
	Event event;
public:
	void read(string a,string b)
	{
		filename=a;
		file.open(filename, ios::in);
		file.get(expression, 400, '$');
		file.close();
		window.create(VideoMode(800, 600),b);
		window.setPosition(Vector2i(300, 0));
		texture.loadFromFile("images/fortext.png");
		sprite.setTexture(texture);
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		text.setPosition(60, 60);
		text.setCharacterSize(40);
		text.setLineSpacing(1.3);
		text.setLetterSpacing(0.2);
		text.setFillColor(Color::Black);
		text.setString(expression);
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}
			window.clear();
			window.draw(sprite);
			window.draw(text);
			window.display();
		}
	}
};
class highscore
{
private:
	string name="",name1="Saroj";
	int score;
	RenderWindow window;
	Event event;
	Text text;
	Font font;
public:
	void savehighscore(int n)
	{
		score = n;
		name = "";
		window.create(VideoMode(400,300),"Askname");
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		text.setString("Name:");
		while (window.isOpen())
		{
			window.clear();
			window.draw(text);
			window.display();
			while (window.pollEvent(event))
			{
				if (event.key.code == Keyboard::Enter)
				{
					window.clear();
					text.setString("Congraz " + name);
					ofstream file("scorerecord.dat", ios::out|ios::binary);
					file.seekp(0, ios::end);
					file.write(reinterpret_cast<char*>(this), sizeof(*this));
					file.close();
					window.draw(text);
					window.display();
					sleep(seconds(2));
					window.close();
				}
				if (event.type == Event::TextEntered)
				{
					name += event.text.unicode;
					text.setString("Name=" + name);
				}
				if (event.type == Event::Closed)
				{
					window.close();
				}
			}
		}
	}
	void showhighscore()
	{
		name1 = "";
		window.create(VideoMode(400, 300), "Highscores");
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			ifstream infile("scorerecord.dat", ios::in|ios::binary);
			while (!infile.eof())
			{
				if (infile.read(reinterpret_cast<char*>(this), sizeof(*this) ))
				{
					//name1 += name+"="+static_cast<char>(score)+"\n";
					cout << name << ":" << score << endl;

				}
			}
			infile.close();
			text.setString(name1);
			window.clear();
			window.draw(text);
			window.display();
		}
	}
};

