#ifndef __CLUSTER_H__
#define __CLUSTER_H__
#include "queue.h"
using namespace std;
struct task
{
	int tactin;
	int tactout;
	int number;
	int d;
	int p;
};
class TCluster
{
	TQueue <task> tp;
	int T, K, S;
	double q1;
	task* cpu;
	int ct = 0, cet = 0, cct = 0, crt = 0, cpt = 0, mean = 0, empty = 0;
public:
	TCluster(int t, int k, int s, double q)
	{
		if ((k < 1) || (k > 64) || (q <= 0) || (q > 1) || (t < 5) || (t > 1000) || (s<5)||(s>50))
			throw 1;
		tp.setsize(s);
		K = k;
		T = t;
		S = s;
		q1 = q;
		cpu = new task[K];
	}
	~TCluster()
	{
		delete[] cpu;
	}
	task randtask(int i,int t);
	void process();
	void getinfo();
};
#endif