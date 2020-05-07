#include<iostream>
#include<clocale>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float a, b, xmin, xmax, x, dx,min,max;
	cout << "¬ведите a, b, xmin, xmax, x, dx,min,max: ";
	cin >> a >> b >> xmin >> xmax >> dx;
	x = xmin;
	min = xmin;
	max = xmax;
	while (x <= xmax) {
		if (x <= a) {
			cout << "x=" << x << " | y=" << log(x) * sin(x) << endl;
			if (min >= log(x) * sin(x)) {
				min = log(x) * sin(x);
			}
			if (max <= log(x) * sin(x)) {
				max = log(x) * sin(x);
			}
			x += dx;
		}
		else if ((x > a) && (x < b)) {
			cout << "x=" << x << " | y=" << x*x*cos(x) << endl;
			if (min >= x * x * cos(x)) {
				min = x * x * cos(x);
			}
			if (max <= x * x * cos(x)) {
				max = x * x * cos(x);
			}
			x += dx;

		}
		else if (x >= b) {
			cout << "x=" << x << " | y=" << pow(x,5) << endl;
			if (min >= pow(x, 5)) {
				min = pow(x, 5);
			}
			if (max <= pow(x, 5)) {
				max = pow(x, 5);
			}
			x += dx;
		}
	}
	cout << "min=" << min << endl;
	cout << "max=" << max << endl;

	return 0;
}

