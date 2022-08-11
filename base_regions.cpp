#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <tuple>

// tuple<const string&, const string&, const <Lang, string>&, const int_64t&> t =  tie(regions[i].std_name, regions[i].parent_std_name,...)
// tuple<int, string, bool> t(7, "C++", true)
// auto t = make_tuple(7, "C++", true)
//get<1>(t) - получит 1 элемент кортежа t

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};


bool operator<(const Region& lhs, const Region& rhs)
{
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
  int max = 0;
  map<Region, int> regs;
  
  for (const auto& x : regions)
  {
    ++regs[x];
    if (regs[x] > max)
    {
      max = regs[x];
    }
  }
  return max;
}

int main()
{

 cout << FindMaxRepetitionCount({
    {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    },
  }) << endl;

 cout << FindMaxRepetitionCount({
    {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Toulouse",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89
    }, {
        "Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        31
    },
  }) << endl;

 vector<Region> var;
 cout << FindMaxRepetitionCount (var);


  return 0;
}