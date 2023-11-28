#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class Person {
	private:
		string name;
		int yearOfBirth;

	public:
		Person() = default;
		Person(const string &name, int yearOfBirth) : name{name}, yearOfBirth{yearOfBirth} {}
		virtual ~Person() = default;

		virtual void describe() { cout << "Name: " << this->name << " - yearOfBirth: " << this->yearOfBirth; }

		virtual int getYearOfBirth() { return this->yearOfBirth; }

};

class Student : public Person {
	private:
		Person person;
		string grade;

	public:
		Student() = default;
		Student(const string &name, int yearOfBirth, string grade) : person(name, yearOfBirth), grade{grade} {}
		~Student() = default; 

		void describe() {
			person.describe();
			cout << " - Grade: " << this->grade << endl;
		}

		int getYearOfBirth() { return person.getYearOfBirth(); }
};


class Teacher : public Person {
	private:
		Person person;
		string subject;

	public:
		Teacher() = default;
		Teacher(const string &name, int yearOfBirth, string subject) : person(name, yearOfBirth), subject{subject} {}
		~Teacher() = default;

		void describe() {
			person.describe();
			cout << " - Subject: " << this->subject << endl;
		}

		int getYearOfBirth() { return person.getYearOfBirth(); }

};

class Doctor : public Person {
	private:
		Person person;
		string specialist;

	public:
		Doctor() = default;
		Doctor(const string &name, int yearOfBirth, string specialist) : person(name, yearOfBirth), specialist{specialist} {}
		~Doctor() = default;

		void describe() {
			person.describe();
			cout << " - Specialist: " << this->specialist << endl;
		}

		int getYearOfBirth() { return person.getYearOfBirth(); }

};

bool compare(Person *p1, Person *p2) { return p1->getYearOfBirth() > p2->getYearOfBirth(); }

class Ward {
	private:
		string name;
		vector<Person*> listOfPeople;

	public:
		Ward() = default;
		Ward(const string &name) : name{name} {}

		void addPerson(Person *person) { listOfPeople.push_back(person); }

		void describe() {
        	cout << "Ward Name: " << this->name << endl;
        	for (int i = 0; i < (int)listOfPeople.size(); ++i) {
        		listOfPeople[i]->describe();
        	}

		}

        int countDoctor() {
        	int total = 0;
			vector<Person*>::iterator iter = listOfPeople.begin();
            while (iter != listOfPeople.end()) {
                Person *person = *iter;

				if (dynamic_cast<Doctor*>(person) != nullptr) {
    				total++;
    			}
                iter++;
            }
            return total;
        }


		void sortAge() { sort(listOfPeople.begin(), listOfPeople.end(), compare); }

		int aveTeacherYearOfBirth() {
            int numberOfTeacher = 0;
            int average = 0;
            
            for (int i = 0; i < (int)listOfPeople.size(); i++) {
                if (Teacher *t1 = dynamic_cast<Teacher*>(listOfPeople[i])) {
                    numberOfTeacher++;
                    average += listOfPeople[i]->getYearOfBirth();
                }
            }
            return average / numberOfTeacher;
		}

};

int main() {
	Student student("studentA", 2010, "7");
	student.describe();

	Teacher teacher1("teacherA", 1969, "Math");
	teacher1.describe();

	Doctor doctor1("doctorA", 1945, "Endocrinologists");
	doctor1.describe();

	Teacher teacher2("teacherB", 1995, "History");
	Doctor doctor2("doctorB", 1975, "Cardiologists");

	Ward ward("Ward1");
	ward.addPerson(&student);
	ward.addPerson(&teacher1);
	ward.addPerson(&teacher2);
	ward.addPerson(&doctor1);
	ward.addPerson(&doctor2);

	ward.describe();

	int numberOfDoctors = ward.countDoctor();
	cout << "number of doctors: " <<  numberOfDoctors << endl;

	ward.sortAge();
	ward.describe();

	int aveTeacherYearOfBirth = ward.aveTeacherYearOfBirth();
	cout << "average year of birth (teachers): " << aveTeacherYearOfBirth << endl;
	
	return 0;	
}