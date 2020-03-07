#include "../work1/intersec.h"

bool getCross(Line l1, Line l2, Point* res)
{
	double a1 = l1.y1 - l1.y2;
	double b1 = l1.x2 - l1.x1;
	double c1 = l1.x1 * l1.y2 - l1.x2 * l1.y1;

	double a2 = l2.y1 - l2.y2;
	double b2 = l2.x2 - l2.x1;
	double c2 = l2.x1 * l2.y2 - l2.x2 * l2.y1;

	double D = a1 * b2 - a2 * b1;
	if (D == 0) {
		return false;
	}
	res->setPoint((b1 * c2 - b2 * c1) / D, (a2 * c1 - a1 * c2) / D);
	return true;
}

int getAllintersec(std::vector<Line> lines)
{
	return 0;
}
