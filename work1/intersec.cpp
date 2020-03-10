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
	//Result.push_back(p);
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
	//��Բ�ĵ�ֱ�ߵľ���
	double juli = getDistance(l, ceter);
	//�ж��Ƿ��ཻ���������У����ǲ��ཻ
	if (juli > R + PRECISION) {
		return false;
	}

	//���������
	Vector segment = l.getQ() - l.getP();
	double ratio = dot(ceter - l.getP(), segment) / segment.norm();
	Point foot = l.getP() + segment * ratio;
	
	//���У�������У��򽻵���Ǵ�������
	if (abs(juli - R) < PRECISION) {
		addPoint(foot);
		return true;
	}

	//ֱ��AB�ĵ�λ��������ABͬ��
	Vector e = segment / segment.module();
	//base = ֱ����Բ�ཻ���ҵ�һ��. ���ù��ɶ���
	double base = sqrt(R * R - (ceter - foot).norm());
	//�����Ӽ��õ������������
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
	//�ж����룬���������
	if (x1 < b1 || x1 > b2) {
		return false;
	}
	//����
	else if (x1 == b2) {
		Vector e = (c2 - c1) / (c2 - c1).module();
		addPoint(c1 + e * r1);
		return true;
	}
	//����
	else if (x1 == b1) {
		Vector e = (c2 - c1) / (c2 - c1).module();
		if (r1 < r2) {
			addPoint(c1 - e * r1);
		}
		else {
			addPoint(c1 + e * r1);
		}
	}
	//�ཻ
	else {
		Vector AB = (c2 - c1);
		double l = AB.module();
		Vector e = AB / l;
		double AE = (r1 * r1 - r2 * r2 + l * l) / (2 * l);
		Point E = c1 + AB * AE / l;
		double CE = sqrt(r1 * r1 - AE * AE);
		//��Բ�ĺ�������ͬ
		if (c1.getX() == c2.getX()) {
			Point left(E.getX() - CE, E.getY());
			Point right(E.getX() + CE, E.getY());
			addPoint(left);
			addPoint(right);
		}
		//����Բ����������ͬ
		else if (c1.getY() == c2.getY()) {
			Point up(E.getX(), E.getY() - CE);
			Point down(E.getX(), E.getY() + CE);
			addPoint(up);
			addPoint(down);
		}
		//һ�����
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

//l1: a1*x + b1*y + c1 = 0
//l2: a2*x + b2*y + c2 = 0
//��������⣺
//D�ж��Ƿ�ƽ��
//x0 = (b1 * c2 - b2 * c1) / D
//y0 = (a2 * c1 - a1 * c2) / D
bool getCross(Line l1, Line l2, Point* res)
{
	//��l1��a1,b1,c1
	double a1 = l1.getPy() - l1.getQy();
	double b1 = l1.getQx() - l1.getPx();
	double c1 = l1.getPx() * l1.getQy() - l1.getQx() * l1.getPy();
	//��l2��a2,b2,c2
	double a2 = l2.getPy() - l2.getQy();
	double b2 = l2.getQx() - l2.getPx();
	double c2 = l2.getPx() * l2.getQy() - l2.getQx() * l2.getPy();

	double D = a1 * b2 - a2 * b1;
	//ƽ�����˳���û�н���
	if (D == 0) {
		return false;
	}
	res->setPoint((b1 * c2 - b2 * c1) / D, (a2 * c1 - a1 * c2) / D);
	return true;
}

int getAllintersec(std::vector<Line> lines)
{
	int cnt = 0;
	int bound1 = lines.size();
	for (int i = 0; i < bound1 - 1; i++) {
		for (int j = i + 1; j < bound1; j++) {
			Point p;
			if (getCross(lines.at(i), lines.at(j), &p)) {
				//cnt++;
				addPoint(p);
			}
		}
	}

	return cnt;
}

int lineAndCircleIntersect(std::vector<Line> lines, std::vector<Circle> circles) {
	int cnt = 0;
	int bound = lines.size();
	int bound1 = circles.size();
	for (int i = 0; i < bound; i++) {
		for (int j = 0; j < bound1; j++) {
			if (getCircleLineCross(circles.at(j), lines.at(i))) {
				//cnt++;
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
		for (int j = i + 1; j < bound1 + 1; j++) {
			if (getCircleCross(tmpC, tmpR, circles.at(j).getCeter(), circles.at(j).getR())) {
				//cnt++;
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

