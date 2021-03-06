МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ
Федеральное государственное автономное образовательное учреждение высшего образования
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ
Кафедра компьютерной инженерии и моделирования
<br/><br/>
​
### Отчёт по лабораторной работе № 01<br/> по дисциплине "Программирование"
<br/>
студента 1 курса группы ПИ-192-(1)
Терещенко Дмитрий Юрьевич
направления подготовки 09.03.0Х "Программаная инженерия"
<br/>
​
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>  </td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019
<br/><br/>

### Изучение базовых возможностей MS Visual Studio<br/>
##### Цель: изучить основные возможности создания и отладки программ в IDE MS Visual Studio<br/>

Ход работы

<ol>
<li>Как создать консольное приложение С++?</li>
Чтобы создать консольное приложение, требуется
<ol>
  <li>Запустить Visual Studio</li>
  ![](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img1.1.jpg)<br/>
  Рис1.1. Начало работы.
  <li>Создать новый проект, а именно 'Консольное приложение'</li>
  ![Создание консольного приложения](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img1.2.jpg)<br/>
  Рис1.2. Создание консольного приложения.
  <li>Настройка нового проекта</li>
  ![Настройка нового проекта](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img1.3.jpg)<br/>
  Рис1.3. Настройка новго проекта.
  <li>Консольное приложение готово!</li>
  ![Завершение создания консольного приложения](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img1.4.jpg)<br/>
  Рис1.4. Результат.
  </ol>
<li>Как изменить цветовую схему (оформление) среды?</li>
<ol>
  <li>Во вкладке 'средства' выбираем пункт 'параметры'</li>
  ![выбираем пункт параметры](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img2.1.jpg)<br/>
  Рис2.1.Выбираем пункт параметры.
  <li>В пункте 'Общие' находим параметр 'Цветовая тема'</li>
  ![Находим параметр "Цветовая тема"](https://github.com/dmirter/Tereshenko/blob/master/Laboratory%201/Images/Img2.2.jpg)<br/>
  Рис2.2.Находим параметр "Цветовая тема".
  <li>Выбираем желаемый цвет</li>
  ![Выбираем желаемый цвет](/Images/Рис2.3.png)<br/>
  Рис2.3. Выбор цветов.
  <li>Готово!</li>
  ![Завершение изменения цветового оформления](/Images/Img2.4.png)<br/>
  Рис2.4. Результат.
  </ol>
<li>Как закомментировать/раскомментировать блок кода средствами VS?</li>
  <ol>
  <li>Выделяем нужный фрагмент кода</li>
  ![Выделяем нужный фрагмент кода](/Images/Img3.1.png)<br/>
  Рис3.1. Выделенный фрагмент кода.
  <li>В пункте 'Правка'' находим пункт 'Дополнительно'</li>
  ![Пункт "Дополнительно"](/Images/Img3.2.jpg)<br/>
  Рис3.2.Пункт "Дополнительно".
  <li>В пункте 'Дополнительно'' нажимем пункт 'Закомментировать выделенный фрагмент'/'Раскоментировать  выделенный фрагмент'</li>
  ![Выбираем нужный пункт](/Images/Img3.3.png)<br/>
  Рис3.3. Выбор нужного пункта.
  <li>Готово!</li>
  ![Результат](/Images/Img3.4.png)<br/>
  Рис3.4. Закомментированный фрагмент.<br/>
  ![Результат](/Images/Img3.5.png)<br/>
  Рис3.5. Раскомментированный фрагмент.
  </ol>
<li>Как открыть в проводнике Windows папку с проектом средствами VS?</li>
  <ol>
  <li>Во вкладке 'Файл' выбираем пункт 'Открыть', а в нем пункт 'Папка...'</li>
  ![выбираем нужные пункты](/Images/Img4.1.png)<br/>
  Рис4.1.Выбираем нужные пункты.
  <li>Выбираем нужную папку</li>
  ![Выбираем нужную папку](/Images/Img4.2.png)<br/>
  Рис4.2.Выбираем нужную папку.
  <li>Готово!</li>
  ![Папка с проектом открыта](/Images/Рис4.3.png)<br/>
  Рис4.3. Результат.
  </ol>
<li>Какое расширение файла-проекта используется в VS?</li>
  <ol>
  <li>VS использует расширение VCXPROJ</li>
  ![файлы с расширением VCXPROJ](/Images/Img5.1.png)<br/>
  Рис5.1.Файлы с расширением VCXPROJ.
  </ol>
<li>Как запустить код без отладки (не менее 2 способов)?</li>
  <ol>
  <li>1-й способ: во вкладке 'Отладка' выбираем пункт 'Запуск без отладки'</li>
  ![выбираем нужный пункт](/Images/Img6.1.png)<br/>
  Рис6.1.Выбираем нужный пункт.
  <li>2-й способ: запуск без отладки запускается с помощью комбинации клавиш Ctrl+F5</li>
  </ol>
<li>Как запустить код в режиме отладки (не менее 2 способов)?</li>
  <ol>
  <li>1-й способ: во вкладке 'Отладка' выбираем пункт 'Начать отладку'</li>
  ![выбираем нужный пункт](/Images/Img7.1.png)<br/>
  Рис7.1.Выбираем нужный пункт.
  <li>2-й способ: запуск в режиме отладки запускается с помощью клавиши F5</li>
  </ol>
<li>Как установить/убрать точку останова (breakpoint)?</li>
  <ol>
  <li>Чтобы установить/убрать точку останова требуется нажать в поле слева напротив соответствующей строки.</li>
  ![Выбираем точку останова](/Images/Img8.2.png)<br/>
  Рис8.1.Выбираем точку останова.<br/>
  ![Убираем точку останова](/Images/Img8.1.png)<br/>
  Рис8.2.Убираем точку останова.
  </ol>
<li>Выполнение задания 9:</li>
  ![Значение переменной i на строке 5](/Images/Img9.1.png)<br/>
  Рис7.1.Значение переменной i на строке 5 равно -858993460.<br/>
  ![Значение переменной i на строке 6](/Images/Img9.2.png)<br/>
  Рис7.1.Значение переменной i на строке 6 равно 5.<br/>
<li>Выполнение задания 10:</li>
  ![Значение переменной i на строке 5](/Images/Img10.1.png)<br/>
  Рис7.1.Значение переменной i на строке 5 равно -9.2559631349317831e+61.<br/>
  ![Значение переменной i на строке 6](/Images/Img9.2.png)<br/>
  Рис7.1.Значение переменной i на строке 6 равно 5.0000000000000000.<br/>
</ol>

##### Вывод: в ходе выполнения лабораторной работы были изучены основные возможности создания и отладки программ в IDE MS Visual Studio<br/>
