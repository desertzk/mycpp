#include<iostream>

using namespace std;
class Shape{
public:
	enum ShapeColor{
		Red,Green,Blue
	};
	void draw(ShapeColor color = Red) const //means this pointer is const
	{
		doDraw(color);
	}
private:
	virtual void doDraw(ShapeColor color) const= 0;
};

class Rectangle :public Shape
{
public:
private:
	virtual void doDraw(ShapeColor color) const
	{
	
		cout << "doDraw  " << typeid(*this).name() << endl;
	}
};


class Timer{
public:
	explicit Timer(int tickfrequency);
	virtual void onTick() const = 0;
};

class Widget{
private:
	class WidgetTimer :public Timer{
	public:
		virtual void onTick() const{
			cout << "onTick" << endl;
		}
	};
	WidgetTimer wt;
};

class superWidget :public Widget
{
public:
	virtual void onTick(){

	}
};


void main()
{
	Rectangle *pr = new Rectangle;
	pr->draw();
	system("pause");
}