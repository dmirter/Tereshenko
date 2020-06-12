МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 6<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы ПИ-б-о-192(1)  
Терещенко Дмитрия Юрьевича
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2020

#### Цель:
*Закрепить навыки разработки многофайловыx приложений;
*Изучить способы работы с API web-сервиса;
*Изучить процесс сериализации/десериализации данных.

#### Ход работы

1. Мой API cd3ac1e6cdee3a83ea19eedc1a827852

2. Код программы
```c++
#include <string>
#include <iostream>
#include <httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace httplib;
using namespace nlohmann;


std::string PATH = "/data/2.5/forecast?q=Simferopol&appid=cd3ac1e6cdee3a83ea19eedc1a827852&units=metric&lang=en";


void gen_response(const Request& req, Response& res)
{
	std::ifstream fin("informer_template.html");
	std::string temp;
	std::getline(fin, temp, '\0');

	httplib::Client cli("api.openweathermap.org", 80);

	auto client_res = cli.Get(PATH.c_str());
	if (client_res && client_res->status == 200)
	{
		json j = json::parse(client_res->body);
		std::string forr = "{city.name}";
		temp.replace(temp.find("{city.name}"), forr.size(), j["city"]["name"].get<std::string>());

		size_t last_index = 0;

		std::string storage;
		for (short i = 0; i < j["cnt"].get<short>(); i += 8)
		{
			storage = j["list"][i]["dt_txt"].get<std::string>();
			storage = storage.substr(0, storage.find(' '));
			last_index = temp.find("{list.dt}", last_index);
			temp.replace(last_index, strlen("{list.dt}"), storage);

			storage = j["list"][i]["weather"][0]["icon"].get<std::string>();
			last_index = temp.find("{list.weather.icon}", last_index);
			temp.replace(last_index, strlen("{list.weather.icon}"), storage);

			storage = std::to_string(j["list"][i]["main"]["temp"].get<double>());
			last_index = temp.find("{list.main.temp}", last_index);
			temp.replace(last_index, strlen("{list.main.temp}"), storage.substr(0, 4));
		}

	}

	res.set_content(temp, "text/html");
}

int main()
{
	Server svr;                  
	svr.Get("/", gen_response);   
	svr.listen("localhost", 3000);
}
```
3. Результат

![]()

рис 1. Вывод.


#### Вывод: В ходе выполнения лабораторной работы я закрепил навыкиразработки многофайловых приложений,изучал способы работы с API wed-сервисами, изучил процесс сериализации/десериализации данных.
