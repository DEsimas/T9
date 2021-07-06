#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class T9
{
private:
	string wrongstr;
	string truestr;
	int a[25][25];
	int n;	// ?? ???????????
	int m;	// ?? ?????????
	int min(int a, int b, int c)
	{
		if (a <= b && a <= c)
			return a;
		if (b <= a && b <= c)
			return b;
		return c;
	}
public:
	T9(string str1, string str2)
	{
		wrongstr = str1;
		truestr = str2;
		n = wrongstr.length() + 1;
		m = truestr.length() + 1;
		// ?? ???????????
		for (int i = 0; i < n; i++)
			a[0][i] = i;
		// ?? ?????????
		for (int i = 0; i < m; i++)
			a[i][0] = i;
		for (int j = 1; j < m; j++)
			for (int i = 1; i < n; i++)
				if (wrongstr[i] == truestr[j])
					a[j][i] = min(a[j][i - 1] + 1, a[j - 1][i] + 1, a[j - 1][i - 1]);
				else
					a[j][i] = min(a[j][i - 1] + 1, a[j - 1][i] + 1, a[j - 1][i - 1]+1);
	}
	int getNum()
	{
		return a[m-1][n-1];
	}
};

int main()
{
	fstream file("engWords.txt");
	string* voc = new string[20000];
	if (file.is_open() == false)
	{
		cout << "ERROR" << endl;
		return 1;
	}
	int count = 0;
	while (file.eof() == false)
	{
		file >> voc[count];
		count++;
	}
	file.close();

	string myword;
	cout << "Input the word: ";
	cin >> myword;
	string newword;
	int min = 50;
	for (int i = 0; i < count; i++)
	{
		T9 test(myword, voc[i]);
		if (test.getNum() < min)
		{
			min = test.getNum();
			newword = voc[i];
		}
	}
	cout << "Maybe you mean: " << newword << endl;
	delete[] voc;
	system("pause");
	return 0;
}
