#pragma once
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <iostream>

class Point{
	double x;
	double y;
public:
	Point() { x = 0; y = 0; }
	Point(double px, double py) { x = px; y = py; }
	bool operator<(const Point& p) const {
		if (this->x < p.x) {
			return true;
		}
		else if (this->x == p.x) {
			return this->y < p.y;
		}
		else {
			return false;
		}
	}
	bool operator==(const Point& p) const {
		return this->x == p.x && this->y == p.y;
	}
	void setPoint(double px, double py) { x = px; y = py; }
	//vector operation
	Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
	
	//return norm of [p-(0, 0)]
	double norm() {
		return x * x + y * y;
	}
	
	//module of a vector
	double abs() {
		return sqrt(x * x + y * y);
	}

	//outer product
	double cross(Point p) {
		return x * p.y - y * p.x;
	}
	
	//inner product
	double dot(Point p) {
		return x * p.x + y * p.y;
	}
};

struct Line {
	double x1, y1;
	double x2, y2;
public:
	Line(double a1, double b1, double a2, double b2) { x1 = a1; y1 = b1; x2 = a2; y2 = b2; }
};


class Circle {
	double x;
	double y;
	double r;
public:
	Circle() { x = 0; y = 0; r = 0; }
	Circle(double cx, double cy, double cr) { x = cx; y = cy; r = cr; }
	bool IsIntersect(Line l);
	bool IsIntersect(Circle c);
	bool getIntersecWithLine(Line l);
	bool getIntersecWithCircle(Circle c);
};

bool getCross(Line l1, Line l2, Point* res);

int getAllintersec(std::vector<Line> lines);