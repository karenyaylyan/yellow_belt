#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	string start_number;
	cin >> start_number;
	deque<string> expression;
	expression.push_back(start_number);

	int n = 0;
	cin >> n;

	char operat_last = 0;
	char operat_current = 0;
	int number;

	for (int i = 0; i < n; ++i)
	{
		cin >> operat_current >> number;
		if ((operat_last == '+' || operat_last == '-') && (operat_current == '*' || operat_current == '/'))
		{
			expression.push_front("(");
			expression.push_back(")");
		}

		expression.push_back(" ");
		expression.push_back(string(1,operat_current));
		expression.push_back(" ");
		expression.push_back(to_string(number));
		
		operat_last = operat_current;
	}

	for (const auto& s : expression)
	{
		cout << s;
	}
	cout << endl;
	return 0;
}