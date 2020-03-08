#include "../work1/intersec.h"

using namespace std;

int main(int argc, char** argv) {
	/*Circle c1(1, 0, 2);
	Circle c2(2, 2, 1);
	int res1 = getCircleCross(c1.getCeter(), c1.getR(), c2.getCeter(), c2.getR());*/

	string inFileName = "";
	string outFileName = "";
	for (int i = 1; i < argc; i++) {
		if (i == 2) {
			inFileName = argv[2];
		}
		if (i == 4) {
			outFileName = argv[4];
		}
	}

	ifstream fileIn("input.txt", ios::in);
	ofstream fileOut(outFileName, ios::out);

	if (!fileIn) {
		throw "input file open Error!!";
		return 0;
	}

	if (!fileOut) {
		throw "output file open Error!!";
		return 0;
	}

	int lineNum = 0;
	vector<Line> lines;
	vector<Circle> circles;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, r = 0;
	char mark;
	fileIn >> lineNum;
	for (int i = 0; i < lineNum; i++) {
		fileIn >> mark;
		if (mark == 'L') {
			fileIn >> x1 >> y1 >> x2 >> y2;
			Line line(x1, y1, x2, y2);
			lines.push_back(line);
		}
		else if (mark == 'C') {
			fileIn >> x1 >> y1 >> r;
			Circle c(x1, y1, r);
			circles.push_back(c);
		}
	}

	int cnt1 = 0, cnt2 = 0;
	//get the intersection num of all lines
	getAllintersec(lines);
	if (circles.size() != 0) {
		cnt1 = lineAndCircleIntersect(lines, circles);
		cnt2 = CirclesIntersect(circles);
	}

	int res = Result.size();
	if (fileOut) {
		fileOut << res;
	}
	//cout << res << " "<< cnt1 <<" "<<cnt2 << endl;
	return 0;
}