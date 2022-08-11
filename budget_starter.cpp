#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class personal_budget {
public:
  personal_budget () : income(37000, 0)
  {

  }
  void Earn (int date_from, int date_to, double earn)
  {
    double money = earn/(date_to - date_from + 1);

    for (int i = date_from; i <= date_to; ++i)
    {
      income[i] += money;
    }
  }

  void ComputeIncome (int date_from, int date_to)
  {
    double result = accumulate(income.begin() + date_from, income.begin() + date_to + 1, 0.0);
    cout << result << endl;
  }

private:
  vector<double> income;
};

int convert_date (string date)
{
  stringstream ss;
  ss << date;

  int year;
  int month;
  int day;
  char c;

  vector<int> Months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  ss >> year >> c >> month >> c >> day;
  int result = 0;
  result += (year-2000)*365;
  result += ((year-2000) / 4);
  if (year % 4 != 0)
  {
    ++result;
  }
  else if (month > 2) //в высокосном году после февраля
  {
    ++result;
  }
  

  for (int i = 0; i < month-1; ++i)
  {
    result += Months[i];
  }

  result += day;

  return result;
}

int main() {
  cout.precision(25);

  int n;
  cin >> n;
  personal_budget person;
  for (int i = 0; i < n; ++i)
  {
    string q;
    cin >> q;
    if (q == "Earn")
    {
      string date_from, date_to;
      cin >> date_from >> date_to;
      double sum;
      cin >> sum;
      person.Earn(convert_date(date_from), convert_date(date_to), sum);
    }
    else
    {
      string date_from, date_to;
      cin >> date_from >> date_to;
      person.ComputeIncome(convert_date(date_from), convert_date(date_to));
    }
  }
  
  return 0;
}

