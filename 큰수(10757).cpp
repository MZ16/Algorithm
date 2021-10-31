#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N, sum;
int num1[10001], num2[10001];
string str1, str2, tmp;
vector<int> ans;

int main()
{
	cin >> str1 >> str2;
	if (str1.size() < str2.size())
	{
		tmp = str1;
		str1 = str2;
		str2 = tmp;
	}

	for (int i = 0; i < str1.size(); i++)
		num1[i + 1] = str1[i] - '0';

	for (int i = 0; i < str2.size(); i++)
		num2[i + 1 + (str1.size() - str2.size())] = str2[i] - '0';

	for (int i = str1.size(); i > 0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;
			sum -= 10;
		}
		ans.push_back(sum);
	}
	if (num1[0] != 0) cout << 1;

	for (int i = ans.size() - 1; i >= 0; i--)	cout << ans[i];
	return 0;
}
