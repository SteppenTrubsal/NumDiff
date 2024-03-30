#include <string>
#include <vector>
using namespace std;

struct complex {
	double x;
	double y;
};

vector<double> getDer(vector<complex> vars) {
	vector<double> res;
	for (int i = 0; i < vars.size(); i++) {
		double der;
		if (vars.size() - i > 2) {											//triple right
			der = (-3 * vars[i].y + 4 * vars[i + 1].y - vars[i + 2].y) / (2 * (vars[i + 1].x - vars[i].x));
		}
		else if ((vars.size() - i <= 2) && (vars.size() - i > 1)) {			//triple left
			der = (vars[i - 2].y - 4 * vars[i - 1].y + 3 * vars[i].y) / (2 * (vars[i + 1].x - vars[i].x));
		}
		else if (vars.size() - i > 1) {										//right
			der = (vars[i + 1].y - vars[i].y) / (vars[i + 1].x - vars[i].x);
		}
		else if (vars.size() - i <= 1) {									//left
			der = (vars[i].y - vars[i - 1].y) / (vars[i].x - vars[i - 1].x);
		}
		else { der = 0; }
		res.push_back(der);
	}
	return res;
}
vector<double> getSecDer(vector<complex> vars) {
	vector<double> res;
	for (int i = 0; i < vars.size()-1; i++) {
		double der;
		if ((vars.size() - i > 1) && (vars.size() - i > vars.size() - 1)) {	//central
			der = (vars[i - 1].y - 2 * vars[i].y + vars[i + 1].y) / ((vars[i + 1].x - vars[i].x) * (vars[i + 1].x - vars[i].x));
		}
		else if (vars.size() - i > 2) {										//right
			der = (vars[i].y-2*vars[i+1].y+vars[i+2].y) / ((vars[i + 1].x - vars[i].x) * (vars[i + 1].x - vars[i].x));
		}
		else if (vars.size() - i <= 2) {									//
			der = (vars[i-2].y - 2*vars[i-1].y+vars[i].y) / ((vars[i + 1].x - vars[i].x) * (vars[i + 1].x - vars[i].x));
		}
		else { der = 0; }
		res.push_back(der);
	}
	return res;
}