#include "queue.h"
#include "cluster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

double GetRandomNumber(int min, int max, bool f)
{
	double num;
	if (f==0)
	num = min + rand() % (max - min + 1);
	else 
	num= ((double)rand() / (RAND_MAX));
	return num;
}

task TCluster::randtask(int i,int t)
{
	task tmp;
	tmp.d = GetRandomNumber(1, 10,0);
	tmp.number = i;
	tmp.tactin = t;
	tmp.p = GetRandomNumber(1, K/2+1,0);
	return tmp;
}

void TCluster::process()
{
	srand(time(0));
	task tmp;
	double q;
	int k=0;
	int i = 0,j=0;
	for (i = 0; i <= T; i++)
	{
		if ((cpt == 0)&(i!=0))
			empty++;
		if(i!=0)
		mean += k;
		for (j = 0; j < cpt; j++)//проверка на выполенные
		{
			
			if (cpu[j].tactout + cpu[j].d == i)
			{
				k = k - cpu[j].p;
				cpt --;
				cct++;
				for (int k = j; k < cpt; k++)
					cpu[k] = cpu[k + 1];
			}
		}
		q = GetRandomNumber(0, 1, 1);//добавление нового задани€ в очередь
		if (q < q1)
		{
			ct++;
			tmp = randtask(ct, i);
			if (tp.Full() == true)
			{
				cet++;
			}
			else
			{
				tp.Push(tmp);
				crt++;
			}
		}
	z:
		if (tp.Empty() == false)// добавление в кластер
		{
			if ((tp.InfoLi().p <= K - k)&(K-k>0))
			{
				cpu[cpt] = tp.GetLi();
				cpu[cpt].tactout = i;
				crt--;
				k = k + cpu[cpt].p;
				cpt++;
				goto z;
			}
		}
		
	}

}

void TCluster::getinfo()
{
	cout << "„исло заданий " << ct<<endl;
	cout << "„исло выполненных заданий " << cct << endl;
	cout << "„исло отказов " << cet<< endl;
	cout << "„исло заданий, оставшихс€ в очереди " << crt << endl;
	cout << "„исло выполн€ющихс€ заданий " << cpt << endl;
	double m = (double)mean / (K * T);
	cout << "—редн€€ загрузка кластера " << m <<endl;
	cout << "„исло тактов просто€ кластера " << empty << endl;
}