#include <iostream>
#include <cmath>
using namespace std;

void triangle_type(double a, double b, double c);
void triangle_validation(double a, double b, double c);
void input_side(double& a, double& b, double& c);

int main() {
	setlocale(LC_ALL, "ru");
	double a = 0, b = 0, c = 0;
	input_side(a, b, c);
	triangle_validation(a, b, c);

	return 0;
}

void input_side(double& a, double& b, double& c) {
	cout << "������� ������� �: ";
	cin >> a;
	cout << "������� ������� b: ";
	cin >> b;
	cout << "������� ������� c: ";
	cin >> c;
	cout << "\n";
}


void triangle_validation(double a, double b, double c) {
	bool flag = false;
	if (a > 0 && b > 0 && c > 0) {
		flag = true;
		triangle_type(a, b, c);
	}
	if (!flag) {
		cout << "�������� ������ ������\n";
	}
}

void triangle_type(double a, double b, double c) {
	const double PI = acos(-1.0);
	double alpha = 0, beta = 0, gamma = 0, rad_90 = 90 * (PI / 180);

	if (a + b > c && b + c > a && a + c > b) {
		alpha = acos(((b * b + c * c) - a * a) / (2 * b * c)); //���� �����  b � �
		beta = acos(((a * a + c * c) - b * b) / (2 * a * c)); //���� �����  � � b
		gamma = acos(((a * a + b * b) - c * c) / (2 * a * b)); //���� �����  � � b
	}
	else {
		cout << "����������� �����������\n";
	}


	if (alpha > rad_90 || beta > rad_90 || gamma > rad_90) {
		cout << "������������ �����������\n";
	}
	else if (alpha == rad_90 || beta == rad_90 || gamma == rad_90) {
		cout << "������������� �����������\n";
	}
	else if (alpha != 0 && beta != 0 && gamma != 0) {
		cout << "������������� �����������\n";
	}

	if (alpha == beta && alpha == gamma && gamma == beta && alpha != 0) {
		cout << "�������������� ����������� \n";
	}
	else if ((alpha == beta || alpha == gamma || beta == gamma) && alpha != 0 && beta != 0 && gamma != 0) {
		cout << "�������������� ����������� \n";
	}
}
