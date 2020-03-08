#include "../work1/intersec.h"

using namespace std;

int main(int argc, char** argv) {
	Circle c(1, 0, 2);
	Line l(-1, 4, 4, -1);
	int res1 = getCircleLineCross(c, l);

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
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char mark;
	fileIn >> lineNum;
	for (int i = 0; i < lineNum; i++) {
		fileIn >> mark;
		if (mark != 'L') {
			throw "wrong! should be 'L'!";
			return 0;
		}
		fileIn >> x1 >> y1 >> x2 >> y2;
		Line line(x1, y1, x2, y2);
		lines.push_back(line);
	}

	//get the intersection num of all lines
	int res = getAllintersec(lines);


	if (fileOut) {
		fileOut << res;
	}
	//cout << res << endl;
	return 0;
}