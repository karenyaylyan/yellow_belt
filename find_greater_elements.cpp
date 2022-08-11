#include <vector>
#include <set>
#include <string>
#include <iostream>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
	std::vector<T> greater_elements;
	for (typename std::set<T>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if (*it > border)
		{
			greater_elements.push_back(*it);
		}
	}
	return greater_elements;
}

int main() { 
  for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  
  std::string to_find = "Python";
  std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
  return 0;
}
