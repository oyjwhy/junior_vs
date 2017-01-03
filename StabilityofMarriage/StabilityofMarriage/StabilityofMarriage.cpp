#include<iostream>
#include<stack>

using namespace std;

class man
{
public:
	int * PriorityofWoman;
	int OrderofWoman;
	int w;
};

class woman
{
public:
	int * PriorityofMan; 
	int m;
	bool compare(int x)
	{
		return PriorityofMan[m]> PriorityofMan[x]; 
	}
};


int main()
{
	int size = 0;
	cin >> size;
	size++;
	man *ListofMan = new man[size]();
	stack<int> SingleMan;
	for (int i = 1; i < size; i++)
	{
		ListofMan[i].OrderofWoman = 1;
		ListofMan[i].w = 0;
		ListofMan[i].PriorityofWoman = new int[size];
		for (int j = 1; j < size; j++)
		{
			cin>>ListofMan[i].PriorityofWoman[j];
		}
		SingleMan.push(i);
	}

	int temp;
	woman * ListofWoman = new woman[size]();
	for (int i = 1; i < size; i++)
	{
		ListofWoman[i].m = 0;
		ListofWoman[i].PriorityofMan = new int[size];
		for (int j = 1; j < size; j++)
		{
			cin >> temp;
			ListofWoman[i].PriorityofMan[temp]=j;
		}
	}
	 
	int man_now;
	int woman_now;
	while (!SingleMan.empty())
	{
		man_now = SingleMan.top();
		SingleMan.pop();
		woman_now = ListofMan[man_now].PriorityofWoman[ListofMan[man_now].OrderofWoman];
		ListofMan[man_now].OrderofWoman++;
		if (ListofWoman[woman_now].m == 0)
		{
			ListofMan[man_now].w = woman_now;
			ListofWoman[woman_now].m = man_now;
		}
		else
		{
			if (ListofWoman[woman_now].compare(man_now))
			{
				ListofMan[man_now].w = woman_now;
				swap(man_now, ListofWoman[woman_now].m);			
			}
			SingleMan.push(man_now);
		}
	}
	for (int i = 1; i < size; i++)
	{
		cout << ListofMan[i].w <<" ";
	}
	cout << endl;
}