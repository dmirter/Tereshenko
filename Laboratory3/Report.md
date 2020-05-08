МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 3<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы 192(1)  
<br/>Терещенко Дмитрий Юрьевич
<br/>направления подготовки 09.03.04 "Программная инженерия"

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель
*Закрепить навыки разработки программ использующих операторы цикла;
*Закрепить навыки разработки программ использующих массивы;
*Освоить методы подключения сторонних библиотек.

#### Ход работы
![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/pic10.bmp)

Рис. 1. Картинка для декодирования

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_1.png)

Рис. 2. Ключ

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_2.png)

Рис. 3. Создаём include с libbmp.h

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_3.png)

Рис. 4. Добавляем и подключаем библиотеку

Напишем программу для выполенения поставленной задачи:
```c++
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
```
Запустим программу и получим следующее сообщение:

![](https://raw.githubusercontent.com/PraiseTheSun-0/Practice/master/Lab3/Lab3/Screenshots/Screenshot_4.png)

Рис. 5. Вывод

#### Вывод: я закрепил навыки разработки программ использующих операторы цикла, массивы, освоил методы подключения сторонних библиотек.
