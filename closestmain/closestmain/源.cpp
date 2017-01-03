#include <iostream>
#include<fstream>
using namespace std;
struct Node{
	int x, y;
};
/*************��������******************/
//��������
void swap(Node list[], int i, int j)
{
	Node temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}
//��������
void QuickSort(Node* nodes, char standard, int left, int right)
{
	if (left >= right)
		return;
	int i = left - 1, j = right + 1;
	Node mid = nodes[(right + left) / 2];
	if (standard == 'x'){
		while (true){
			while (nodes[++i].x < mid.x);
			while (nodes[--j].x > mid.x);
			if (i >= j)	break;
			swap(nodes, i, j);
		}
		QuickSort(nodes, 'x', left, i - 1);
		QuickSort(nodes, 'x', j + 1, right);
	}
	if (standard == 'y'){
		while (true){
			while (nodes[++i].y < mid.y);
			while (nodes[--j].y > mid.y);
			if (i >= j)break;
			swap(nodes, i, j);
		}
		QuickSort(nodes, 'y', left, i - 1);
		QuickSort(nodes, 'y', j + 1, right);
	}
}
//����������ƽ��
int NodesDis(Node a, Node b) { return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); }
//ȡС
int Min(int a, int b){ return (a > b) ? b : a; }
//void output(Node*Qx, int n)
//{
//	for (int i = 0; i < n ; i++)
//	{
//		cout << "(" << Qx[i].x << "," << Qx[i].y << ") ";
//	}
//	cout << endl;
//}
//�ݹ麯�� �����ڽ����
int ClosestRec(Node*Px, Node*Py, int n)
{
	if (n == 1) return 9999999;
	/**********n<=3ʱ ������ٷ�********************/
	int min = NodesDis(Px[0], Px[1]);
	if (n <= 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++){
				int l = NodesDis(Px[i], Px[j]);
				if (l < min) min = l;
			}
		}
		return min;
	}
	/***********����Qx Qy Rx Ry************/
	int mid = Px[n - n / 2 - 1].x;
	int num = 0;
	for (int i = 0; i < n; i++)
	if (Px[i].x <= mid)
		num++;
	Node*Qx = new Node[num];
	Node*Rx = new Node[n - num];
	for (int i = 0; i < n; i++)
	{
		if (Px[i].x <= mid)
			Qx[i] = Px[i];
		else
			Rx[i - num] = Px[i];
	}
	delete[]Px;
	Node*Qy = new Node[num];
	Node*Ry = new Node[n - num];
	int idxQ = 0, idxR = 0;
	for (int i = 0; i < n; i++)
	{
		if (Py[i].x <= mid)
			Qy[idxQ++] = Py[i];
		else
			Ry[idxR++] = Py[i];
	}

	/*****�������������� �ֱ���õݹ麯��*****/
	int delta;
	int deltaL = ClosestRec(Qx, Qy, num);
	delete[]Qy;
	int deltaR = ClosestRec(Rx, Ry, n - num);
	delete[]Ry;
	delta = Min(deltaL, deltaR);
	/*************�м�խ������**************/
	Node*Sy = new Node[n];  //խ���еĵ㼯��������������
	int idxS = 0;
	for (int i = 0; i < n; i++)
	{
		if (Py[i].x >= (mid - delta) && Py[i].x <= (mid + delta))
			Sy[idxS++] = Py[i];
	}
	int d = NodesDis(Sy[0], Sy[1]);//�м���̾���
	for (int i = 0; i < idxS; i += 15)
	{
		for (int j = i + 1; j < i + 15 && j<idxS; j++)
		{
			int len = NodesDis(Sy[i], Sy[j]);
			if (len < d)
				d = len;
		}
	}
	delete[]Sy;

	/************���ؽ��***************/
	if (d < delta) return d;
	else return delta;
}

int ClosestDis(int n, Node* nodes)
{
	int min = NodesDis(nodes[0], nodes[1]);
	/********����Px��Py , ��ʱO(nlogn)****************/
	Node*Px = new Node[n];
	Node*Py = new Node[n];
	for (int i = 0; i < n; i++) { Px[i] = Py[i] = nodes[i]; }
	QuickSort(Px, 'x', 0, n - 1);   //������������
	QuickSort(Py, 'y', 0, n - 1); //������������
	delete[]nodes;
	/********���õݹ麯������̾���********************/
	min = ClosestRec(Px, Py, n);
	return min;
}

int main()
{
	int ClosestDistance = 0;
	ifstream fin("data.txt");  //���ļ�
	int n;
	fin >> n;
	Node*nodes = new Node[n];
	for (int i = 0; i < n; i++)
		fin >> nodes[i].x >> nodes[i].y;
	fin.close();

	//int n;
	//int ClosestDistance = 0;
	//cin >> n;
	//Node*nodes=new Node[n];
	//for (int i = 0; i < n; i++)
	//	cin >> nodes[i].x >> nodes[i].y;

	ClosestDistance = ClosestDis(n, nodes);
	cout << ClosestDistance;

	system("pause");
	return 1;
}