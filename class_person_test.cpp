#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};*/


void TestEmpty ()
{
  Person person;

  AssertEqual(person.GetFullName(1900), "Incognito", "Empty test");
}

void TestEmptyFirstName ()
{
  Person person;

  person.ChangeLastName(1900, "Yaylyan");
  AssertEqual(person.GetFullName(1900), "Yaylyan with unknown first name", "Empty first name");

}

void TestEmptyLastName ()
{
  Person person;

  person.ChangeFirstName(1900, "Karen");
  AssertEqual(person.GetFullName(1900), "Karen with unknown last name", "Empty first name");
}

void TestIncognito ()
{
  Person person;

  person.ChangeFirstName(1900, "Karen");
  person.ChangeLastName(1930, "Yaylyan");

  AssertEqual(person.GetFullName(1899), "Incognito", "Incognito person");
}

void TestUnknownFirstName ()
{
  Person person;

  person.ChangeLastName(1900, "Yaylyan");
  person.ChangeLastName(1930, "Petrov");
  person.ChangeLastName(1888, "Sidorov");

  person.ChangeFirstName(1920, "Jack");
  person.ChangeFirstName(1919, "Jon");

  AssertEqual(person.GetFullName(1910), "Yaylyan with unknown first name", "Unknown first name");
}

void TestUnknownLastName ()
{
  Person person;

  person.ChangeLastName(1900, "Yaylyan");
  person.ChangeLastName(1930, "Petrov");
  person.ChangeLastName(1888, "Sidorov");

  person.ChangeFirstName(1780, "Jack");
  person.ChangeFirstName(1799, "Jon");

  AssertEqual(person.GetFullName(1799), "Jon with unknown last name", "Unknown last name");
}

void TestFullName ()
{
  Person person;

  person.ChangeLastName(1900, "Yaylyan");
  person.ChangeLastName(1988, "Sidorov");
  person.ChangeLastName(1930, "Petrov");


  person.ChangeFirstName(1980, "Jack");
  person.ChangeFirstName(1919, "Jon");

  AssertEqual(person.GetFullName(1999), "Jack Sidorov", "Total name");
  AssertEqual(person.GetFullName(1988), "Jack Sidorov", "Total name");
  AssertEqual(person.GetFullName(1980), "Jack Petrov", "Total name");
  AssertEqual(person.GetFullName(1919), "Jon Yaylyan", "");
  AssertEqual(person.GetFullName(1930), "Jon Petrov", "");
  AssertEqual(person.GetFullName(1935), "Jon Petrov", "");
}


void TestAll ()
{
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestEmptyFirstName, "TestEmptyFirstName");
  runner.RunTest(TestEmptyLastName, "TestEmptyLastName");
  runner.RunTest(TestIncognito, "TestIncognito");
  runner.RunTest(TestUnknownFirstName, "TestUnknownFirstName");
  runner.RunTest(TestUnknownLastName, "TestUnknownLastName");
  runner.RunTest(TestFullName, "TestFullName");
}

int main() {
  TestAll();
  
  return 0;
}