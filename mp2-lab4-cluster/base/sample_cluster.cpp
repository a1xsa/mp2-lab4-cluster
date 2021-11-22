#include <iostream>
#include "cluster.h"

int main()
{
	int t, k, s;
	double q;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество тактов в диапазаоне [5;1000]" << endl;
	cin >> t;
	cout << "Введите количество процессоров в диапазаоне [1;64]" << endl;
	cin >> k;
	cout << "Введите размер очереди в диапазаоне [5;50]" << endl;
	cin >> s;
	cout << "Введите порог появления заданий в диапазаоне (0;1]" << endl;
	cin >> q;
	TCluster tp(t,k,s,q);
	tp.process();
	tp.getinfo();
	return 0;
}
