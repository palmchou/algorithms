/*
Author: Palm Chou
Email: palmchou@live.com
blog: palmchou.me
*/

#include<iostream>
using namespace std;

class WQU
{
public:
	WQU(int N);
	~WQU();
	int root(int p);
	bool connected(int p, int q);
	void doUnion(int p, int q); 
	void print();
private:
	int* id;
	int* sz;
	int N;
};

WQU::WQU(int N)
{
	id = new int[N];
	sz = new int[N];
	this->N = N;
	for (int i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}
}

WQU::~WQU()
{
	delete[] id;
	delete[] sz;
}

int WQU::root(int i)
{
	while (id[i] != i)
		i = id[i];
	return i;
}

bool WQU::connected(int p, int q)
{
	return root(p)==root(q);
}

void WQU::doUnion(int p, int q)
{
	int i = root(p);
	int j = root(q);
	if (i == j)
		return;
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] += sz[i];
	}
	else
	{
		id[j] = i;
		sz[i] += sz[j];
	}
}

void WQU::print()
{
	for (int i = 0; i < N; i++)
	{
		cout << i << ' ';
	}
	cout << endl;
	for (int j = 0; j < N; j++)
		cout << id[j] << ' ';
	cout << endl;
}

int main()
{
	int n, x, a, b;
	cin >> n;
	cin >> x;
	WQU qu(n);
	for (int i = 0; i < x; i++)
	{
		cin >> a >> b;
		qu.doUnion(a, b);
	}
	qu.print();
}