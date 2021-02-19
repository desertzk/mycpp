#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<iomanip>
#include<cmath>
using namespace std;


int main12302018()
{
	int a = 0, b = 0;

	scanf("%d %d\n", &a, &b);
	
	int res = a + b;
	cout << res << endl;
	return 0;


}


struct Point2d
{
	double x;
	double y;
	Point2d(double xx, double yy) : x(xx), y(yy) {}
};

//¼ÆËãÃæ»ý
double ComputeArea(const vector<Point2d>& points)
{
	int point_num = points.size();
	if (point_num < 3)return 0.0;
	double s = 0;
	for (int i = 0; i < point_num; ++i)
		s += points[i].x * points[(i + 1) % point_num].y - points[i].y * points[(i + 1) % point_num].x;
	return s / 2.0;
}

int main2()
{
	
	int len;
	int x = 0, y = 0;

	while (cin >> len)
	{
		if (len == 0)
			break;
		vector<Point2d> cord;
		for (int i = 0; i < len; i++) {
			cin >> x >> y;
			cord.push_back(Point2d(x, y));
		}

		double area = ComputeArea(cord);
		if (area < 0)
			cout << fixed << setprecision(1) << "CW " << -area << endl;
		else
			cout << fixed << setprecision(1) << "CCW " << area << endl;
	}


	return 0;


}


#define pi 3.1415926

/*
2
5 2 3 2
5 2 3 3
*/
int mainninieye()
{
	

	int len;
	double r1,r2,h,p;

	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cin>> r1 >> r2 >> h >> p;
		double rup = (h-p) / h * r1;
		double s2 = pi* r2*r2;
		double s1 = pi * rup * rup;
		cout << (h-p) * (s1 + sqrt(s1 * s2) + s2) / 3;
	}
	
	return 0;


}