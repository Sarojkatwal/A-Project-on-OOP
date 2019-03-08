#pragma once
using namespace std;
using namespace sf;
class Animation
{
public:
	IntRect uvRect;
	Vector2u imageCount;
	Vector2u currentImage;
	float totalTime, switchTime;
public:
	Animation(Texture* texture,Vector2u imagecount,float switchtime)
	{
		this->imageCount = imagecount;
		this->switchTime = switchtime;
		totalTime = 0.0f;
		currentImage.y = 1;
		uvRect.height = texture->getSize().y/float(imageCount.x);
		uvRect.width = texture->getSize().x/float(imageCount.y);
	}
	void Update(int row, float deltatime)
	{
		currentImage.x = row;
		totalTime += deltatime;
		if (totalTime >= switchTime)
		{
			totalTime -= switchTime;
			currentImage.y+=2;
			if (currentImage.y >= imageCount.y)
			{
				currentImage.y= 1;
			}
		}
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.top = currentImage.y*uvRect.height;
	}
};
