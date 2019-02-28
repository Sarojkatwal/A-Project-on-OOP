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
	class nameandscore
	{
	public:
		char name[25];
		int score;
	public:
		void setdata(int n)
		{
			cout << "Enter your name:";
			cin >> name;
			score = n;
		}
	};
public:
	void savehighscore(int n)
	{
		int score = n;
		nameandscore ns;
		ns.setdata(score);
		ofstream file("file/scorerecord.dat", ios::binary|ios::app);
		file.write(reinterpret_cast<char*>(&ns), sizeof(ns));
		cout << ns.name << "  " << ns.score;
	}
	void showhighscore()
	{
		nameandscore ns;
		ostringstream outputfromfile;
		RenderWindow window;
		Text text;
		Font font;
		outputfromfile.str("");
		window.create(VideoMode(800, 500), "Highscores");
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		text.setCharacterSize(20);
		text.setPosition(20, 20);
		text.setFillColor(Color::Red);
		ifstream infile("file/scorerecord.dat", ios::in | ios::binary);
		while (!infile.eof())
		{
			infile.read(reinterpret_cast<char*>(&ns), sizeof(ns));
			outputfromfile << ns.name << "\t" << ns.score << "\n";
		}
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}		
			text.setString(outputfromfile.str());
			window.clear(Color::Black);
			window.draw(text);
			window.display();
		}
	}
};
