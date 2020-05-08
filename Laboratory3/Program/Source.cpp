
#include "iostream"
#include "libbmp.h"
using namespace std;

int main() {
	int count = 0;
	int number = 0;
	char text[9000];
	int bit;
	BmpImg img;
	char y = 0;
	img.read("pic10.bmp");
	const int width = img.get_width();
	const int height = img.get_height();
	bool stop = false;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			bit = img.blue_at(j, i);
			y =y << 1;
			if (bit % 2 == 1) {
				y++;
			}
			count++;
			if (count == 8) {
				count = 0;
				text[number] = y;
				number++;
				if (y == '\0') {
					stop = true;
					break;
				}
			}
			bit = img.green_at(j, i);
			y = y << 1;
			if (bit % 2 == 1) {
				y++;
			}
			count++;
			if (count == 8) {
				count = 0;
				text[number] = y;
				number++;
				if (y == '\0') {
					stop = true;
					break;
				}
			}
			bit = img.red_at(j, i);
			y = y << 1;
			if (bit % 2 == 1) {
				y++;
			}
			count++;
			if (count == 8) {
				count = 0;
				text[number] = y;
				number++;
				if (y == '\0') {
					stop = true;
					break;
				}
			}
		}
		if (stop)break;
	}
	cout << text;
}
