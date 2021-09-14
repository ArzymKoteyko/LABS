#include <iostream>

using namespace std;

int main() {

	float day_dist = 10;
	float sum_dist = 0;
	int c = 1;

	bool flag_1 = true;
	bool flag_2 = true;

	while (sum_dist <= 200) {
		sum_dist += day_dist;
		if (sum_dist >= 100 && flag_1) {
			cout << "Days to 100km: " << c << "\n";
			flag_1 = false;
		}
		if (c == 7) {
			cout << "Distance on 7th day: " << sum_dist << "\n";
		}
		if (day_dist > 20 && flag_2) {
			cout << "Day when 20km walked: " << c << "\n";
			flag_2 = false;
		}
		day_dist *= 1.1;
		c += 1;
	}

	return 0;
}
