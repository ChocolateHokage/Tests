#include <iostream>
#include <ctime>
using namespace std;

int main() {
	setlocale(0, "");
	//����������
	int arr1[7]{};
	int buf = 0;
	for (int i = 6; i >-1; i--) {
		arr1[i] = rand() % 10 + 1;
	}
	//���������� �� �����������
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6-i; j++) {
			if (arr1[j] > arr1[j + 1]) {
				buf = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j + 1] = buf;
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << arr1[i] << endl;
	}
	//���������� �� ��������
	cout << endl;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 6 - i; j++) {
			if (arr1[j] < arr1[j + 1]) {
				buf = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = buf;
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << arr1[i] << endl;
	}



	//��������� �����
	char c1;
	char c2;
	cout << "�������� 1: ";
	cin >> c1;
	cout << "\n�������� 2: ";
	cin >> c2;
	int size = 0;
	cout << "\n������: ";
	cin >> size;
	for (int j = 1; j <= size; j++) {
		for (int i = 1; i <= size; i++) {
			if ((i % 2 == 0 && j % 2 == 0) || (j % 2 != 0 && i % 2 != 0)) {
				cout << c1 << " ";
			}
			else if ((i % 2 != 0 && j % 2 == 0) || (j % 2 != 0 && i % 2 == 0)) {
				cout << c2 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
