#include <iostream>
#include <iomanip>
using namespace std;

class QF
{
public:
	QF(int N);
	~QF();
	void doUnion(int p, int q);
	bool connected(int p, int q);
	//void print();
private:
	int N;
	int *id;
};

QF::QF(int N)
{
	id = new int[N];
	this->N = N;
	for (int i = 0; i < N; i++)
		id[i] = i;
}

QF::~QF()
{
	delete[] id;
}

void QF::doUnion(int p, int q)
{
	int pid = id[p];
	int qid = id[q];
	for (int i = 0; i < N; i++)
		if (id[i] == pid)
			id[i] = qid;
}

bool QF::connected(int p, int q)
{
	return id[p] == id[q];
}

//void QF::print()
//{
//	int i, j;
//	for (i = 0; i < N; i++)
//	{
//		cout << i << ' ';
//	}
//	cout << endl;
//	for (j = 0; j < N; j++)
//	{
//		cout << id[j] << ' ';
//	}
//}

int main()
{
	int n, x, a, b;
	cin >> n;
	cin >> x;
	QF qf(n);
	for (int i = 0; i < x;i++)
	{
		cin >> a >> b;
		qf.doUnion(a, b);
	}
	qf.print();
}