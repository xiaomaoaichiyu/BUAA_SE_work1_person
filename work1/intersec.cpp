#include "../work1/intersec.h"

std::set<Point> Result;

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
	Result.insert(foot + e * base);
	Result.insert(foot - e * base);
	return true;
}

bool getCircleCross(Circle c1, Circle c2)
{
	return false;
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
	std::set<Point> points;

	for (int i = 0; i < lines.size() - 1; i++) {
		for (int j = i + 1; j < lines.size(); j++) {
			Point p;
			if (getCross(lines.at(i), lines.at(j), &p)) {
				points.insert(p);
			}
		}
	}

	return points.size();
}

double getDistance(Line l, Point p)
{
	return abs(cross(l.getP() - l.getQ(), p)/ (l.getP() - l.getQ()).module());
}

