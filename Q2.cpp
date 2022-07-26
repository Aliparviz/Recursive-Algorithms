//بسم الله الرحمن الرحیم
#include<iostream>
#include<string>
using namespace std;
int substring(string refrence, string different, string disordered, int& check_true, int& step_counter)
{
	if (step_counter == 0 && (refrence.length() + different.length() != disordered.length()))
	{
		return 1;
	}
	if (refrence == "")
	{
		if (different == disordered)
		{
			check_true = 1;
		}
		return 1;
	}
	if (different == "")
	{
		if (refrence == disordered)
		{
			check_true = 1;
		}
		return 1;
	}
	if (disordered == "")
	{
		return 1;
	}
	if (refrence[0] == different[0] && different[0] == disordered[0])
	{
		step_counter++;
		substring(refrence.substr(1), different, disordered.substr(1), check_true, step_counter) ||
			substring(refrence, different.substr(1), disordered.substr(1), check_true, step_counter);
	}
	else if (refrence[0] == disordered[0])
	{
		step_counter++;
		substring(refrence.substr(1), different, disordered.substr(1), check_true, step_counter);
	}
	else if (different[0] == disordered[0])
	{
		step_counter++;
		substring(refrence, different.substr(1), disordered.substr(1), check_true, step_counter);
	}
	else
	{

		substring(refrence, different, disordered.substr(1), check_true, step_counter);
	}
}
void print_result(int result) 
{
	if (result == true)
	{
		cout << "Interleaving" << endl;
	}
	else
	{
		cout << "Not Interleaving" << endl;
	}
}

int main()
{
	string refrence, different, disordered;
	int check_true = 0;
	int step_counter = 0;
	cin >> refrence >> different >> disordered;

	substring(refrence, different, disordered, check_true, step_counter);

	print_result(check_true);

	return 0;
}