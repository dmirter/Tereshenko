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
        cerr << "������" << endl;
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
    ofstream outf("�����.txt");
    outf << "����� ��������: " << survival << endl;
    outf << "�������� �� ������� ������: " << survFirst << endl;
    outf << "�������� �� ������� ������: " << survSecond << endl;
    outf << "�������� �� �������� ������: " << survThird << endl;
    outf << "�������� ������: " << survMale << endl;
    outf << "�������� ������: " << survFemale << endl;
    outf << "������� �������: " << aAge << endl;
    outf << "������� ������� ������: " << aFemale << ". ������: " << aMale << endl;
    outf << "����, � ������� ������������  ������ ����� ����������: " << mostState <<endl;
    outf << "Id ������������������: " << underAgeId[0];
    for (int a = 1; underAgeId[a]; a++)
    {
        outf << ", " << underAgeId[a];
    }
   

}