#include <iostream>
#include "someFunc.hpp"
using namespace std;

int main() {
	vector<complex> vec(5);
	vec[0].x = 0.451; vec[0].y = 0.43587;
	vec[1].x = 0.452; vec[1].y = 0.43677;
	vec[2].x = 0.453; vec[2].y = 0.43766;
	vec[3].x = 0.454; vec[3].y = 0.43856;
	vec[4].x = 0.455; vec[4].y = 0.43945;

	vector<double> res1 = getDer(vec);
	cout << "First derivative: " << endl;
	for (int i = 0; i < res1.size(); i++) {
		cout << res1[i] << endl;
	}

	vector<double> res2 = getSecDer(vec);
	cout << "Second derivative: " << endl;
	for (int i = 0; i < res2.size(); i++) {
		cout << res2[i] << endl;
	}
}