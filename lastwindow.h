#pragma once
int lwindow(RenderWindow *window1,int score,const string str,int bonusscore=0)
{
	window1->create(VideoMode(400, 400), str);
	while (window1->isOpen())
	{
		Font font;
		Text text;
		ostringstream setScore;
		setScore << "Score:" << score<<"\nBonusScore:"<<bonusscore<<"\nTotalScore:"<<bonusscore+score;
		font.loadFromFile("font/loading.ttf");
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(Color::Red);
		text.setStyle(Text::Bold);
		text.setStyle(Text::Italic);
		text.setString(setScore.str());
		text.setPosition(120, 20);
		Event evv;
		while (window1->pollEvent(evv))
		{
			if (evv.type == Event::Closed)
			{
				return score + bonusscore;
				window1->close();
			}
		}
		window1->clear();
		window1->draw(text);
		window1->display();
	}
}
