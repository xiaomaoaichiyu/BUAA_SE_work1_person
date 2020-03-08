#pragma once
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <map>

class Point{
	double x;
	double y;
public:
	Point() { x = 0; y = 0; }
	Point(double px, double py) { x = px; y = py; }
	bool operator<(const Point& p) const {
		if (abs((this->x - p.x)) < 1e-14) {
			if (abs((this->y - p.y)) < 1e-14) {
				return false;
			}
			else {
				return this->y < p.y;
			}
		}
		else {
			return this->x < p.x;
		}
	}
	bool operator==(const Point& p) const {
		return this->x == p.x && this->y == p.y;
	}
	void setPoint(double px, double py) { x = px; y = py; }
	double getX() { return x; }
	double getY() { return y; }
	//vector operation
	Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
	Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }
	Point operator*(const double r) { return Point(x * r, y * r); }
	Point operator/(const double r) { return Point(x / r, y / r); }
	//return norm of [p-(0, 0)]
	double norm() {
		return x * x + y * y;
	}
	//module of a vector
	double module() {
		return sqrt(x * x + y * y);
	}
	//outer product
};

class Line {
	Point p;
	Point q;
public:
	Line(double a1, double b1, double a2, double b2) { p.setPoint(a1, b1); q.setPoint(a2, b2); }
	double getPx() { return p.getX(); }
	double getPy() { return p.getY(); }
	double getQx() { return q.getX(); }
	double getQy() { return q.getY(); }
	Point getP() { return p; }
	Point getQ() { return q; }
};


class Circle {
	Point p;
	double r;
public:
	Circle() { r = 0; }
	Circle(double cx, double cy, double cr) { p.setPoint(cx, cy); r = cr; }
	Point getCeter() { return p; }
	double getR() { return r; }
};


extern std::set<Point> Result;

double cross(Point p, Point q);
double dot(Point p, Point q);
bool getCircleLineCross(Circle c, Line l);
bool getCircleCross(Point c1, double r1, Point c2, double r2);
bool getCross(Line l1, Line l2, Point* res);
int getAllintersec(std::vector<Line> lines);
double getDistance(Line l, Point p);
int lineAndCircleIntersect(std::vector<Line> lines, std::vector<Circle> circles);
int CirclesIntersect(std::vector<Circle> circles);

using Vector = Point;