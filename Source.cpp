#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int arrAns[4]{};
int arrQue[15]{};
int lifes = 3;
bool hint = 0;
string hintStr = "Не используется";
int totalTime = 2000;
int qAmount = 10;
int corrAnsAmount = 0;

int getCorrectChoise(int bEdge, int tEdge, int sItem) {
	while (true) {
		cout << "\nВведите ваш выбор: ";
		int choise;
		cin >> choise;
		if ((cin.fail() || choise < bEdge || choise > tEdge) && choise != sItem) {
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else {
			return choise;
		}
	}
}

string quiz[15][6] = {
	{"Каков правильный синтаксис для вывода \"Hello World\" в C++?","cout << \"Hello World\";","Console.WriteLine(\"Hello World\");","System.out.println(\"Hello World\");","print(\"Hello World\");","cout << \"Hello World\";"},
	{"Как вставляются комментарии в С++?","/*Это комментарий","#Это комментарий","//Это комментарий","<!--Это комментарий-->","//Это комментарий"},
	{"1+1 =","1","2","3","4","2"},
	{"2+2 =","1","2","3","4","4"},
	{"3+3 =","1","2","3","6","6"},
	{"4+1 =","12","5","3","11","5"},
	{"Вопрос 7","Ответ 17","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 8","Ответ 18","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 9","Ответ 19","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 10","Ответ 110","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 11","Ответ 111","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 12","Ответ 112","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 13","Ответ 113","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 14","Ответ 114","Ответ 2","Ответ 3","Ответ 4","Ответ 4"},
	{"Вопрос 15","Ответ 115","Ответ 2","Ответ 3","Ответ 4","Ответ 4"}
};

int setRandom(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
	bool a = 1;
	for (int i = 0; i < size; i++) {
		int randNum = rand() % size + 1;
		for (int j = 0; j < size; j++) {
			if (randNum == arr[j]) {
				a = 0;
				break;
			}
			else if (randNum != arr[j]) {
				a = 1;
			}
		}
		if (a) {
			arr[i] = randNum;
		}
		else {
			i--;
		}
	}
	return 0;
}
int getRandHint(int b) {
	int rv = rand() % 4;
	while (rv == b) {
		rv = rand() % 4;
	}
	return rv;
}
void getAnswers(int i, bool isHint) {
	cout << "\x1b[95mВопрос №" << i << "\x1b[0m" << endl;
	cout << quiz[arrQue[i - 1] - 1][0] << endl;
	if (isHint) {
		int r = getRandHint(5);
		int a = 0;
		for (int j = 0; j < 4; j++) {
			if (((quiz[arrQue[i - 1] - 1][arrAns[j]] == quiz[arrQue[i - 1] - 1][5]) || (quiz[arrQue[i - 1] - 1][arrAns[j]] == quiz[arrQue[i - 1] - 1][r]) ) && (a<2 || j > 2)) {
				cout << "[" << j + 1 << "]" << quiz[arrQue[i - 1] - 1][arrAns[j]] << "\t";
				r = getRandHint(j);
				a++;
			}
			else {
				cout << "********************" << "\t";
			}
			if (j % 2 == 1) {
				cout << endl;
			}
		}
		isHint = 0;
	}
	else {
		for (int j = 0; j < 4; j++) {
			cout << "[" << j + 1 << "]" << quiz[arrQue[i - 1] - 1][arrAns[j]] << "\t";
			if (j % 2 == 1) {
				cout << endl;
			}
		}
	}
}
int startQuiz() {
	system("cls");
	setRandom(arrQue, 15);
	for (int i = 1; i <= qAmount; i++) {
		system("cls");
		setRandom(arrAns, 4);
		getAnswers(i, 0);
		int choise = getCorrectChoise(1, 4, 9);
		if (choise == 9 && hint) {
			getAnswers(i, 1);
			choise = getCorrectChoise(1, 4, 9);
		}
		if (quiz[arrQue[i - 1] - 1][arrAns[choise - 1]] == quiz[arrQue[i - 1] - 1][5]) {
			cout << "\n\x1b[92mПравильно!!!\x1b[0m";
			corrAnsAmount++;
		}
		else {
			lifes--;
			cout << "\n\x1b[91mНеверно!!!\x1b[0m";
		}
		cout << "\n==================\n";
		Sleep(200);
	}
	return 0;
}

void getQAmount() {
	cout << "[#]Количество вопросов			< \x1b[7m" << qAmount << "\x1b[0m" << endl;
	cout << "[1] 5\n";
	cout << "[2] 10\n";
	cout << "[3] 15\n";
	int qAmountChoise = getCorrectChoise(1, 3, 1);
	switch (qAmountChoise) {
	case 1: {
		qAmount = 5;
		break;
	}
	case 2: {
		qAmount = 10;
		break;
	}
	case 3: {
		qAmount = 15;
		break;
	}
	default: {
		cout << "\nВы ввели неправильное значение и сломали программу";
	}
	}
}
void getLifes() {
	cout << "[#]Количество прав на ошибку | 1 - < \x1b[7m" << lifes << "\x1b[0m > - 5" << endl;
	cout << "==============================" << endl;
	cout << "Выбор происходит путем введения количества прав на ошибку от 1 до 5 включительно\n";
	lifes = getCorrectChoise(1, 5, 0);
}
void getHint() {
	cout << "[#] Подсказка 50 / 50		|	< \x1b[7m" << hintStr << "\x1b[0m >" << endl;
	cout << "==============================\n";
	cout << "[1]Использовать\n";
	cout << "[2]Не использовать\n";
	cout << "[0]Назад\n";
	int hintChoise = getCorrectChoise(0, 2, 1);
	switch (hintChoise) {
	case 1: hint = 1; hintStr = "Используется"; break;
	case 2: hint = 0; hintStr = "Не используется"; break;
	case 0: break;
	default: break;
	}
}
void getTime() {
	cout << "[#]Время на викторину		|	1 - < \x1b[7m" << totalTime << "\x1b[0m - 15 >" << endl;
	cout << "==============================" << endl;
	cout << "Выбор происходит путем введения времени в минутах от 1 до 15\n";
	totalTime = getCorrectChoise(1, 15, 0);

}
int setting() {
	system("cls");
	cout << "[#]Настройки" << endl;
	cout << "==============================" << endl;
	cout << "[1]Количество вопросов		|	< \x1b[7m" << qAmount << "\x1b[0m >" << endl;
	cout << "[2]Количество прав на ошибку	|	< \x1b[7m" << lifes << "\x1b[0m > " << endl;
	cout << "[3]Подсказка 50/50		|	< \x1b[7m" << hintStr << "\x1b[0m >" << endl;
	cout << "[4]Время на викторину		|	< \x1b[7m" << totalTime << "\x1b[0m >" << endl;
	cout << "[5]Меню" << endl;
	cout << "==============================" << endl;
	int settingChoise = getCorrectChoise(1, 5, 1);
	switch (settingChoise)
	{
	case 1: {
		getQAmount();
		system("cls");
		setting();
		break;
	}
	case 2: {
		getLifes();
		system("cls");
		setting();
		break;
	}
	case 3: {
		getHint();
		system("cls");
		setting();
		break;
	}
	case 4: {
		getTime();
		system("cls");
		setting();
		break;
	}
	case 5: {
		return 0;
		break;
	}
	default:
		break;
	}
}
void getRules() {
	system("cls");
	cout << "[#] Правила\n===========================\n\n";
	cout << "\tЗадача викторины - проверка ваших знаний. Чем больше вы дадите правильных ответов на поставленные вопросы, тем лучше.\nВыбор ответа происходит путем введения пункта выбранного вами ответа. Будьте внимательны в ответе, так как у вас есть ограниченное \nколичество прав на ошибку, которые настраиваются в Настройки --> Количество прав на ошибку.\n\n\tТакже вы можете использовать подсказку \"50 / 50\",введя \"5\" во время выбора ответа, которая сокращает количество вариантов ответа на половину. \nДля настройки наличия подсказки смотрите пункт Настройки --> Подсказка 50/50. \n\n\tВ игре присутствует таймер времени. Если вы не успеете ответить на все вопросы до конца времени, викторина считается проваленной. \nДля настройки времени перейдите в Настройки --> Время на викторину.";
	cout << "\n===========================\n[1]В меню\n";
	int rulesChoise = getCorrectChoise(1, 1, 1);
	if (rulesChoise == 1) {
		return;
	}
}
int main() {
	srand(time(0));
	setlocale(0, "");
	system("cls");
	cout << "[#] Меню\n===========================\n[1]Начать викторину\n[2]Настройки\n[3]Правила\n[4]Выход\n";
	int menuChoise;
	cin >> menuChoise;
	switch (menuChoise)
	{
	case 1: {
		startQuiz();
		system("cls");
		break;
	}
	case 2: {
		setting();
		system("cls");
		main();
		break;
	}
	case 3: {
		getRules();
		system("cls");
		main();
		break;
	}
	default:
		system("cls");
		cout << "Вы точно хотите выйти? (Y/N)" << endl;
		char quit;
		while (true)
		{
			cout << "Введите ваш выбор: ";
			cin >> quit;
			if (cin.fail() || (quit != 'Y' && quit != 'y' && quit != 'N' && quit != 'n'))
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else {
				break;
			}
		}
		if (quit == 'Y' or quit == 'y') {
			return 0;
		}
		else if (quit == 'N' or quit == 'n') {
			system("cls");
			main();
		}
	}
}
//#include <iostream>
//using namespace std;
//
//
////int get(int bEdge, int tEdge) {
////	int a;
////	do {
////		cin.clear();
////		cin.ignore();
////		cout << "\nВведите ваш выбор: ";
////		cin >> a;
////	} while (cin.fail() || a < bEdge || a > tEdge);
////	return a;
////}
//
//int main() {
//	//цвета консоли
//	/*for (int i = 0; i <= 108; i++)
//	{
//		cout << i << "  =  \x1b[" << i << "m" << "Hello \x1b[0m" << endl;
//	}*/
//
//	//cout << 9 / 2 << "--";
//	//cout << (9+1) / 2 << endl;
//	//cout << 16 / 2 << "--";
//	//cout << (16+1) / 2 << endl;
//	//cout << 25 / 2 << "--";
//	//cout << (25+1) / 2 << endl;
//	//int b = get(1, 4);
//	//cout << b;
//
//
//	int _;
//	cin >> _;
//	return 0;
//}
