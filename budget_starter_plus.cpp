#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class personal_budget {
public:
  personal_budget () : income(147000, 0), partial_sum_income(147000, 0)
  {

  }
  void Earn (int date, unsigned long long sum)
  {
    income[date] += sum;
  }

  void ComputeIncome (int date_from, int date_to)
  {
    if (date_from == 0)
    {
      cout << partial_sum_income[date_to] << endl;
    }
    else
    {
      cout << partial_sum_income[date_to] - partial_sum_income[date_from-1] << endl;
    }
    
  }

  void Partial_sum_generate ()
  {
    partial_sum(income.begin(), income.end(), partial_sum_income.begin());
  }

private:
  vector<unsigned long long> income;
  vector<unsigned long long> partial_sum_income;
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
  result += (year-1700)*365;
  result += ((year-1700) / 4);
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
  personal_budget person;

  int earn_count_days;
  cin >> earn_count_days;
  for (int i = 0; i < earn_count_days; ++i)
  {
    string date;
    unsigned long long sum;

    cin >> date >> sum;
    person.Earn(convert_date(date), sum);
  }

  person.Partial_sum_generate();

  int query_count;
  cin >> query_count;

  for (int i = 0; i < query_count; ++i)
  {   
    string date_from, date_to;
    cin >> date_from >> date_to;
    person.ComputeIncome(convert_date(date_from), convert_date(date_to));
  }
  
  return 0;
}

