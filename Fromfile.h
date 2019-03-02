#include<stdlib.h>
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
		int i=0;	
		nameandscore ns,ns1;
		ns.setdata(score);
		ifstream infile("file/scorerecord.dat", ios::in | ios::binary);
		if (!infile)
		{
			ofstream file1("file/scorerecord.dat", ios::binary);
			file1.write(reinterpret_cast<char*>(&ns), sizeof(ns)); 
		}
		else
		{
			infile.seekg(0, ios::end);
			i = infile.tellg() / sizeof(ns);
			for (int k = 0; k < i; k++)
			{
				infile.seekg(k * sizeof(ns1), ios::beg);
				infile.read(reinterpret_cast<char*>(&ns1), sizeof(ns1));
				if (ns1.score < score)
				{
					if (i < 5)
					{
						ofstream file1("file/scorerecord1.dat", ios::binary);
						infile.seekg(0);
						for (int j = 0; j < i; j++)
						{
							infile.read(reinterpret_cast<char*>(&ns1), sizeof(ns1));
							file1.write(reinterpret_cast<char*>(&ns1), sizeof(ns1));
						}
						file1.close();
						infile.close();
						ifstream infile1("file/scorerecord1.dat", ios::in | ios::binary);
						ofstream file("file/scorerecord.dat", ios::binary);
						for (int j = 0; j < i + 1; j++)
						{
							if (j == k)
							{
								file.write(reinterpret_cast<char*>(&ns), sizeof(ns));
							}
							else
							{
								infile1.read(reinterpret_cast<char*>(&ns1), sizeof(ns1));
								file.write(reinterpret_cast<char*>(&ns1), sizeof(ns1));
							}
						}
					}
					else
					{
						ofstream file1("file/scorerecord1.dat", ios::binary);
						infile.seekg(0);
						for (int j = 0; j < 4; j++)
						{
							infile.read(reinterpret_cast<char*>(&ns1), sizeof(ns1));
							file1.write(reinterpret_cast<char*>(&ns1), sizeof(ns1));
						}
						file1.close();
						infile.close();
						ifstream infile1("file/scorerecord1.dat", ios::in | ios::binary);
						ofstream file("file/scorerecord.dat", ios::binary);
						for (int j = 0; j < 5; j++)
						{
							if (j == k)
							{
								file.write(reinterpret_cast<char*>(&ns), sizeof(ns));
							}
							else
							{
								infile1.read(reinterpret_cast<char*>(&ns1), sizeof(ns1));
								file.write(reinterpret_cast<char*>(&ns1), sizeof(ns1));
							}
						}
						
					}
					remove("file/scorerecord1.dat");
					break;
				}
			}
		}
		system("CLS");
	}
	void showhighscore()
	{
		int i = 0;
		nameandscore ns;
		ostringstream outputfromfile;
		RenderWindow window;
		Text text;
		Font font;
		outputfromfile.str("");
		window.create(VideoMode(800, 500), "Highscores");
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		text.setLineSpacing(2);
		text.setCharacterSize(40);
		text.setPosition(280, 20);
		text.setFillColor(Color::Red);
		ifstream infile("file/scorerecord.dat", ios::in | ios::binary);
		infile.seekg(0, ios::end);
		i = infile.tellg() / sizeof(ns);
		outputfromfile << "Top 5 High Scores\n";
		for(int k=0;k<i;k++)
		{
			infile.seekg(k * sizeof(ns), ios::beg);
			infile.read(reinterpret_cast<char*>(&ns), sizeof(ns));
			outputfromfile << "  "<<k+1<<") "<<ns.name << "\t" << ns.score << "\n";
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
