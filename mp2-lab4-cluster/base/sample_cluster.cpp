#include <iostream>
#include "cluster.h"

int main()
{
	int t, k, s;
	double q;
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ������ � ���������� [5;1000]" << endl;
	cin >> t;
	cout << "������� ���������� ����������� � ���������� [1;64]" << endl;
	cin >> k;
	cout << "������� ������ ������� � ���������� [5;50]" << endl;
	cin >> s;
	cout << "������� ����� ��������� ������� � ���������� (0;1]" << endl;
	cin >> q;
	TCluster tp(t,k,s,q);
	tp.process();
	tp.getinfo();
	return 0;
}
