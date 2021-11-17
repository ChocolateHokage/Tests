#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int arrAns[4]{};
int arrQue[15]{};
int lifes = 3;
bool hint = 0;
string hintStr = "�� ������������";
int totalTime = 2000;
int qAmount = 10;
int corrAnsAmount = 0;

int getCorrectChoise(int bEdge, int tEdge, int sItem) {
	while (true) {
		cout << "\n������� ��� �����: ";
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
	{"����� ���������� ��������� ��� ������ \"Hello World\" � C++?","cout << \"Hello World\";","Console.WriteLine(\"Hello World\");","System.out.println(\"Hello World\");","print(\"Hello World\");","cout << \"Hello World\";"},
	{"��� ����������� ����������� � �++?","/*��� �����������","#��� �����������","//��� �����������","<!--��� �����������-->","//��� �����������"},
	{"1+1 =","1","2","3","4","2"},
	{"2+2 =","1","2","3","4","4"},
	{"3+3 =","1","2","3","6","6"},
	{"4+1 =","12","5","3","11","5"},
	{"������ 7","����� 17","����� 2","����� 3","����� 4","����� 4"},
	{"������ 8","����� 18","����� 2","����� 3","����� 4","����� 4"},
	{"������ 9","����� 19","����� 2","����� 3","����� 4","����� 4"},
	{"������ 10","����� 110","����� 2","����� 3","����� 4","����� 4"},
	{"������ 11","����� 111","����� 2","����� 3","����� 4","����� 4"},
	{"������ 12","����� 112","����� 2","����� 3","����� 4","����� 4"},
	{"������ 13","����� 113","����� 2","����� 3","����� 4","����� 4"},
	{"������ 14","����� 114","����� 2","����� 3","����� 4","����� 4"},
	{"������ 15","����� 115","����� 2","����� 3","����� 4","����� 4"}
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
	cout << "\x1b[95m������ �" << i << "\x1b[0m" << endl;
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
			cout << "\n\x1b[92m���������!!!\x1b[0m";
			corrAnsAmount++;
		}
		else {
			lifes--;
			cout << "\n\x1b[91m�������!!!\x1b[0m";
		}
		cout << "\n==================\n";
		Sleep(200);
	}
	return 0;
}

void getQAmount() {
	cout << "[#]���������� ��������			< \x1b[7m" << qAmount << "\x1b[0m" << endl;
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
		cout << "\n�� ����� ������������ �������� � ������� ���������";
	}
	}
}
void getLifes() {
	cout << "[#]���������� ���� �� ������ | 1 - < \x1b[7m" << lifes << "\x1b[0m > - 5" << endl;
	cout << "==============================" << endl;
	cout << "����� ���������� ����� �������� ���������� ���� �� ������ �� 1 �� 5 ������������\n";
	lifes = getCorrectChoise(1, 5, 0);
}
void getHint() {
	cout << "[#] ��������� 50 / 50		|	< \x1b[7m" << hintStr << "\x1b[0m >" << endl;
	cout << "==============================\n";
	cout << "[1]������������\n";
	cout << "[2]�� ������������\n";
	cout << "[0]�����\n";
	int hintChoise = getCorrectChoise(0, 2, 1);
	switch (hintChoise) {
	case 1: hint = 1; hintStr = "������������"; break;
	case 2: hint = 0; hintStr = "�� ������������"; break;
	case 0: break;
	default: break;
	}
}
void getTime() {
	cout << "[#]����� �� ���������		|	1 - < \x1b[7m" << totalTime << "\x1b[0m - 15 >" << endl;
	cout << "==============================" << endl;
	cout << "����� ���������� ����� �������� ������� � ������� �� 1 �� 15\n";
	totalTime = getCorrectChoise(1, 15, 0);

}
int setting() {
	system("cls");
	cout << "[#]���������" << endl;
	cout << "==============================" << endl;
	cout << "[1]���������� ��������		|	< \x1b[7m" << qAmount << "\x1b[0m >" << endl;
	cout << "[2]���������� ���� �� ������	|	< \x1b[7m" << lifes << "\x1b[0m > " << endl;
	cout << "[3]��������� 50/50		|	< \x1b[7m" << hintStr << "\x1b[0m >" << endl;
	cout << "[4]����� �� ���������		|	< \x1b[7m" << totalTime << "\x1b[0m >" << endl;
	cout << "[5]����" << endl;
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
	cout << "[#] �������\n===========================\n\n";
	cout << "\t������ ��������� - �������� ����� ������. ��� ������ �� ������ ���������� ������� �� ������������ �������, ��� �����.\n����� ������ ���������� ����� �������� ������ ���������� ���� ������. ������ ����������� � ������, ��� ��� � ��� ���� ������������ \n���������� ���� �� ������, ������� ������������� � ��������� --> ���������� ���� �� ������.\n\n\t����� �� ������ ������������ ��������� \"50 / 50\",����� \"5\" �� ����� ������ ������, ������� ��������� ���������� ��������� ������ �� ��������. \n��� ��������� ������� ��������� �������� ����� ��������� --> ��������� 50/50. \n\n\t� ���� ������������ ������ �������. ���� �� �� ������� �������� �� ��� ������� �� ����� �������, ��������� ��������� �����������. \n��� ��������� ������� ��������� � ��������� --> ����� �� ���������.";
	cout << "\n===========================\n[1]� ����\n";
	int rulesChoise = getCorrectChoise(1, 1, 1);
	if (rulesChoise == 1) {
		return;
	}
}
int main() {
	srand(time(0));
	setlocale(0, "");
	system("cls");
	cout << "[#] ����\n===========================\n[1]������ ���������\n[2]���������\n[3]�������\n[4]�����\n";
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
		cout << "�� ����� ������ �����? (Y/N)" << endl;
		char quit;
		while (true)
		{
			cout << "������� ��� �����: ";
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
////		cout << "\n������� ��� �����: ";
////		cin >> a;
////	} while (cin.fail() || a < bEdge || a > tEdge);
////	return a;
////}
//
//int main() {
//	//����� �������
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
