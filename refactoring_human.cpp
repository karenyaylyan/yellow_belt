#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human {
public:
    Human(const string& name, const string& job) : Name(name), Job(job) {}

    virtual void Walk(const string& destination) const = 0;

    string GetName() const {
        return Name;
    }

    string GetJob() const {
        return Job;
    }

private:
    const string Name;
    const string Job;
};

class Student : public Human {
public:
    Student(const string& name, const string& favouriteSong)
        : Human(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << GetName() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << GetName() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << GetName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(const string& name, const string& subject) 
        : Human(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << GetName() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << GetName() << " walks to: " << destination << endl;
    }

public:
    string Subject;
};


class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& human) const {
        cout << "Policeman: " << GetName() << " checks "<< human.GetJob() << ". " << 
            human.GetJob() << "'s name is: " << human.GetName() << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << GetName() << " walks to: " << destination << endl;
    }
};


void VisitPlaces(const Human& human, const vector<string>& places) {
    for (const auto& p : places) {
        human.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
