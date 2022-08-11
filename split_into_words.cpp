#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> split_words;
	auto str_begin = s.begin();
	const auto str_end = s.end();

	while (1)
	{
		auto it = find(str_begin, str_end, ' ');
		split_words.push_back(string(str_begin, it));

		if (it != str_end)
		{
			str_begin = it + 1;
		}
		else
		{
			return split_words;
		}
	}
}

int main() 
{
  string s = "C Cpp Java Python";
  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}