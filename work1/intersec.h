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
	Point() {}
	Point(double px, double py);
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

	void setPoint(double px, double py);
};