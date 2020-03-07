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
};

struct Line {
	double x1, y1;
	double x2, y2;
public:
	Line(double a1, double b1, double a2, double b2) { x1 = a1; y1 = b1; x2 = a2; y2 = b2; }
};

bool getCross(Line l1, Line l2, Point* res);

int getAllintersec(std::vector<Line> lines);