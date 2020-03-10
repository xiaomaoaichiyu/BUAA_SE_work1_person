#include "../work1/intersec.h"

using namespace std;

int main(int argc, char** argv) {

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

	ifstream fileIn(inFileName, ios::in);
	ofstream fileOut(outFileName, ios::out);

	if (!fileIn) {
		cerr << "input file open Error!!" << endl;
		return 0;
	}

	if (!fileOut) {
		cerr << "output file open Error!!" << endl;
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
	fileIn.close();
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	//get the intersection num of all lines
	cnt1 = getAllintersec(lines);
	if (circles.size() != 0) {
		cnt2 = lineAndCircleIntersect(lines, circles);
		cnt3 = CirclesIntersect(circles);
	}


	std::sort(Result.begin(), Result.end());
	auto last = std::unique(Result.begin(), Result.end());
	Result.erase(last, Result.end());
	int res = Result.size();
	if (fileOut) {
		fileOut << res;
	}
	//cout << res << endl;
	return 0;
}