МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы ПИ-б-о-192(1)  
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
*Научиться работать с текстовыми файлами;
*Закрепить навыки работы со структурами.

1. Код программы
```c++
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class information
{
public:
    int Id;
    bool survival;
    int Pclass;
    string name;
    char sex;
    double age;
    int sibSp;
    int parch;
    string ticket;
    double fare;
    string cabin;
    char embarked;
};
int main()
{

    setlocale(LC_ALL, "Russian");
    vector<information> surv;
    ifstream file;
    file.open("train.csv");
    if (!file)
    {
        cerr << "Ошибка" << endl;
        return 1;
    }

    file.seekg(80);
    int i = 0;
    while (file)
    {
        surv.push_back(information());
        string read, jump;
        getline(file, read, '\r');
        int length = read.length(),k = 0;
        bool change = true;
        while (k < length) {
            if (read[k] == '\"')
            {
                change = !change;
            }
            if (change) {
                if (read[k] == ',') {
                    read[k] = ';';

                }

            }
            k++;
        }

        stringstream split(read);
        int count = 0;
        getline(split, jump, ';');
        while (split)
        {
            stringstream info(jump);
            switch (count)
            {
            case 0: info >> surv[i].Id; break;
            case 1: info >> surv[i].survival; break;
            case 2: info >> surv[i].Pclass; break;
            case 3: getline(info, surv[i].name); break;
            case 4: info >> surv[i].sex; break;
            case 5: info >> surv[i].age; break;
            case 6: info >> surv[i].sibSp; break;
            case 7: info >> surv[i].parch; break;
            case 8: getline(info, surv[i].ticket); break;
            case 9: info >> surv[i].fare; break;
            case 10: info >> surv[i].cabin; break;
            case 11: info >> surv[i].embarked; break;
            }
            count++;

            getline(split, jump, ';');
        }
        i++;
    }
    int passengers, survival = 0, survFirst = 0, survSecond = 0, survThird = 0, survFemale = 0,survMale = 0, Agecount = 0, Femalecount = 0,Malecount = 0, embarkedS = 0, embarkedQ = 0, embarkedC = 0, underAge = 0, underAgeId[200] = { 0 };
    double aAge = 0, aFemale = 0, aMale = 0;
    passengers = surv.size();
    for (int k = 0; k < passengers; k++)
    {
        if (surv[k].survival)
        {
            survival++;
            if (surv[k].Pclass == 1)
            {
                survFirst++;
            }
            if (surv[k].Pclass == 2)
            {
                survSecond++;
            }
            if (surv[k].Pclass == 3)
            {
                survThird++;
            }
            if (surv[k].sex == 'f')
            {
                survFemale++;
            }
            if (surv[k].sex == 'm')
            {
            survMale++;
            }

        }
        if (surv[k].age > 0) {
            aAge += surv[k].age;
            Agecount++;
            if (surv[k].sex == 'f')
            {
                aFemale += surv[k].age;
                Femalecount++;
            }
            if (surv[k].sex == 'm')
            {
                aMale += surv[k].age;
                Malecount++;
            }
        }
        if (surv[k].embarked == 'S')
        {
            embarkedS++;
        }
        if (surv[k].embarked == 'C')
        {
            embarkedC++;
        }
        if (surv[k].embarked == 'Q')
        {
            embarkedQ++;
        }
        if (surv[k].age < 18 && surv[k].age > 0)
        {
            underAgeId[underAge] = surv[k].Id;
            underAge++;
        }
    }
    aAge = (int)aAge/Agecount;
    aFemale = (int)aFemale/Femalecount;
    aMale = (int)aMale/Malecount;
    string mostState;
    if( (embarkedC > embarkedS)&& (embarkedC > embarkedQ))
    {
        mostState = "Cherbourg";
    }
    else if (embarkedS > embarkedC&& embarkedS > embarkedQ)
    {
        mostState = "Southampton";
    }

    else if ((embarkedQ > embarkedS) &&(embarkedQ > embarkedC))
    {
        mostState = "Queenstown";
    }
    ofstream outf("Вывод.txt");
    outf << "Общее число выживших: " << survival << endl;
    outf << "Выживших из первого класса: " << survFirst << endl;
    outf << "Выживших из второго класса: " << survSecond << endl;
    outf << "Выживших их третьего класса: " << survThird << endl;
    outf << "Выживших мужчин: " << survMale << endl;
    outf << "Выживших женщин: " << survFemale << endl;
    outf << "Средний возраст: " << aAge << endl;
    outf << "Средний возраст женщин: " << aFemale << endl;
    outf << "Средний возраст мужчин: " << aMale << endl;
    outf << "Штат, в котором село больше всего пассажиров: " << mostState <<endl;
    outf << "Список идентификаторов несовершеннолетних: " << underAgeId[0];
    for (int a = 1; underAgeId[a]; a++)
    {
        outf << ", " << underAgeId[a];
    }


}
```
2. Ссылка на файл с результатом:https://github.com/dmirter/Tereshenko/blob/master/Laboratory5/program/%D0%92%D1%8B%D0%B2%D0%BE%D0%B4.txt

3.Рассчитанные характеристики
| Характеристика | Результат |
|---|---|
| Общее число выживших | 342 |
| Выживших из первого класса| 136 |
| Выживших из второго класса | 87 |
| Выживших из второго класса | 119 |
| Выживших женщин | 233 |
| Выживших мужчин | 109 |
| Средний возраст всех пассажиров | 29 |
| Средний возраст мужчин | 30 |
| Средний возраст женщин | 27 |
| Штат, в котором село больше всего пассажиров | Southampton |

 Идентификаторы несовершеннолетних пассажиров: 8, 10, 11, 15, 17, 23, 25, 40, 44, 51, 59, 60, 64, 69, 72, 79, 85, 87, 112, 115, 120, 126, 139, 148, 157, 164, 165, 166, 172, 173, 183, 184, 185, 194, 206, 209, 221, 234, 238, 262, 267, 279, 283, 298, 306, 308, 330, 334, 341, 349, 353, 375, 382, 387, 390, 408, 420, 434, 436, 446, 447, 449, 470, 480, 481, 490, 501, 505, 531, 533, 536, 542, 543, 550, 551, 575, 619, 635, 643, 645, 684, 687, 690, 692, 721, 722, 732, 747, 751, 752, 756, 765, 778, 781, 782, 788, 789, 792, 803, 804, 814, 820, 825, 828, 831, 832, 842, 845, 851, 853, 854, 870, 876.

 #### Вывод: В ходе выполнения лабораторной работы  я научился работать с текстовыми файлами и закрепио навыки работы со структурами.
