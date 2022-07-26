//بسم الله الرحمن الرحیم
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void sort_to_nth_step(vector<int>&start_array, int n, int& counter)
{
	if (counter >= n)
		return ;
	int array_size = start_array.size();

	for (int i = 0; i < start_array.size(); i += 2)
	{
		if (start_array[i] == 0)
		{
			start_array.insert(start_array.begin() + i + 1, 1);
		}
		else if (start_array[i] == 1)
		{
			start_array.insert(start_array.begin() + i + 1, 0);
		}
	}
	counter++;
	sort_to_nth_step(start_array, n, counter);
}

int main()
{
	int n, k;
	int counter = 0;
	vector<int>start_array = { 0 };
	cin >> n >> k;
	sort_to_nth_step(start_array, n, counter);
	cout << start_array[k - 1] << endl;
	return 0;
}
