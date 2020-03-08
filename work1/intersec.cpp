#include "../work1/intersec.h"

std::vector<Point> Result;

void addPoint(Point p) {
	if (Result.size() > MAX_POINT) {
		std::sort(Result.begin(), Result.end());
		auto last = std::unique(Result.begin(), Result.end());
		Result.erase(last, Result.end());
		if (Result.size() > MAX_POINT) {
			exit(1);
		}
	}
	else {
		Result.push_back(p);
	}
}

double cross(Point p, Point q) {
	return p.getX() * q.getY() - p.getY() * q.getX();
}

double dot(Point p, Point q) {
	return p.getX() * q.getX() + p.getY() * q.getY();
}

bool getCircleLineCross(Circle c, Line l)
{
	Point ceter = c.getCeter();
	double R = c.getR();
	if (getDistance(l, ceter) > R) {
		return false;
	}

	//求垂足的坐标
	Vector segment = l.getQ() - l.getP();
	double ratio = dot(ceter - l.getP(), segment) / segment.norm();
	Point foot = l.getP() + segment * ratio;
	//单位向量
	Vector e = segment / segment.module();
	double base = sqrt(R * R - (ceter - foot).norm());
	Point p1 = foot - e * base;
	Point p2 = foot + e * base;
	addPoint(p1);
	addPoint(p2);
	return true;
}

bool getCircleCross(Point c1, double r1, Point c2, double r2)
{
	double x1 = sqrt((c1 - c2).norm());
	double b1 = abs(r1 - r2);
	double b2 = abs(r1 + r2);
	if (x1 < b1 || x1 > b2) {
		return false;
	}
	else if (x1 == b1 || x1 == b2) {
		Vector e = (c2 - c1) / (c2 - c1).module();
		addPoint(c1 + e * r1);
		return true;
	}
	else {
		Vector AB = (c2 - c1);
		double l = AB.module();
		Vector e = AB / l;
		double AE = (r1 * r1 - r2 * r2 + l * l) / (2 * l);
		Point E = c1 + AB * AE / l;
		double CE = sqrt(r1 * r1 - AE * AE);
		if (c1.getX() == c2.getX()) {
			Point left(E.getX() - CE, E.getY());
			Point right(E.getX() + CE, E.getY());
			addPoint(left);
			addPoint(right);
		}
		else if (c1.getY() == c2.getY()) {
			Point up(E.getX(), E.getY() - CE);
			Point down(E.getX(), E.getY() + CE);
			addPoint(up);
			addPoint(down);
		}
		else {
			double k1 = (c2.getY() - c1.getY()) / (c2.getX() - c1.getX());
			double k2 = -1 / k1;
			double EF = sqrt(CE * CE / (1 + k2 * k2));
			double cx = E.getX() - EF;
			double cy = E.getY() + k2 * (cx - E.getX());
			double dx = E.getX() + EF;
			double dy = E.getY() + k2 * (dx - E.getX());
			Point tmp(cx, cy);
			addPoint(tmp);
			tmp.setPoint(dx, dy);
			addPoint(tmp);
		}
	}
	return true;
}

bool getCross(Line l1, Line l2, Point* res)
{
	double a1 = l1.getPy() - l1.getQy();
	double b1 = l1.getQx() - l1.getPx();
	double c1 = l1.getPx() * l1.getQy() - l1.getQx() * l1.getPy();

	double a2 = l2.getPy() - l2.getQy();
	double b2 = l2.getQx() - l2.getPx();
	double c2 = l2.getPx() * l2.getQy() - l2.getQx() * l2.getPy();

	double D = a1 * b2 - a2 * b1;
	if (D == 0) {
		return false;
	}
	res->setPoint((b1 * c2 - b2 * c1) / D, (a2 * c1 - a1 * c2) / D);
	return true;
}

int getAllintersec(std::vector<Line> lines)
{
	int cnt = 0;
	int bound1 = lines.size() - 1;
	for (int i = 0; i < bound1; i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			Point p;
			if (getCross(lines.at(i), lines.at(j), &p)) {
				cnt++;
				addPoint(p);
			}
		}
	}

	return cnt;
}

int lineAndCircleIntersect(std::vector<Line> lines, std::vector<Circle> circles) {
	int cnt = 0;
	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < circles.size(); j++) {
			if (getCircleLineCross(circles.at(j), lines.at(i))) {
				cnt++;
			}
		}
	}
	return cnt;
}

int CirclesIntersect(std::vector<Circle> circles) {
	int cnt = 0;
	int bound1 = circles.size() - 1;
	for (int i = 0; i < bound1; i++) {
		Point tmpC = circles.at(i).getCeter();
		double tmpR = circles.at(i).getR();
		for (int j = i + 1; j < circles.size(); j++) {
			if (getCircleCross(tmpC, tmpR, circles.at(j).getCeter(), circles.at(j).getR())) {
				cnt++;
			}
		}
	}
	return cnt;
}

double getDistance(Line l, Point p)
{
	double a = (l.getP() - l.getQ()).module();
	double b = cross(l.getP() - l.getQ(), p - l.getP());
	return abs(b/a);
}

