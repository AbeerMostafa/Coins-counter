//Coins
#include<iostream>
#include<stdio.h>
#include <map>
#include<string>
using namespace std;
map <int, int> Coins;
double money;
void Print()
{
	for (auto it = --Coins.cend(); it != --Coins.cbegin(); --it)
	{
		if (it->second > 0)
		{
			cout << it->second << " " << it->first << " Pound Coin" << endl;
		}
	}
}

void Operations()
{
	while (money > 0)
	{
		for (auto it = --Coins.cend(); it != --Coins.cbegin(); --it)
		{
			if (money >= it->first)
			{
				money -= it->first;
				int cur = it->second + 1;
				map<int, int>::iterator itt = Coins.find(it->first);
				if (itt != Coins.end())
					itt->second = cur;
				break;
			}
		}
	}
}
void Fill()
{
	cout << "Enter The Amount Of Money" << endl;
	cin >> money;
	cout << "Enter Number Of Allowed Coins" << endl;
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cout << "Enter The Coins Number: " << (i + 1) << endl;
		int val;
		cin >> val;
		Coins.insert(pair<int, int>(val, 0));
	}
}
void main()
{
	Fill();
	Operations();
	system("cls");
	Print();
	system("PAUSE");
}