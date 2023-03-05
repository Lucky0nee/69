#include <iostream>
#include <vector>
using namespace std;

class Person {
public:
	explicit Person() {
		this->name = Names[rand() % 4] + " / " + LastNames[rand() % 4];
		this->type = typeid(Person).name();

		this->address = AddressCountry[rand() % 4] + "/" + AddressCity[rand() % 4] + "/" + AddressHouse[rand() % 4];
	}

	void printInfo() {
		cout << "Name: " << this->name << "\n";
		cout << "Type: " << this->type << "\n";
		cout << "Address: " << this->address << "\n\n";
	}

	decltype(auto) GetType() {
		return this->type;
	}

protected:
	string name;
	string type;
	string address;

	vector<string> AddressHouse{ "House #1", "House #2", "House #3", "House #4" };
	vector<string> AddressCity{ "City #1", "City #2", "City #3", "City #4" };
	vector<string> AddressCountry{ "Botswana", "Brazil", "Brunei", "Burkina Faso" };

	vector<string> Names{ "Sasha", "Ivan", "Anya", "Danya" };
	vector<string> LastNames{ "Barash", "Tarkhanov", "Kobelev", "Saburov" };
};

class Student : public Person {
public:
	explicit Student() {
		this->name = Names[rand() % 4] + " / " + LastNames[rand() % 4];
		this->type = typeid(Student).name();

		this->address = AddressCountry[rand() % 4] + "/" + AddressCity[rand() % 4] + "/" + AddressHouse[rand() % 4];
	}

	template<typename T>
	decltype(auto) Dosomething(T&& something) {
		return something;
	}

	template<typename T>
	decltype(auto) DoSomething(T&& something) {
		return Dosomething(forward<T>(something));
	}
};

template <typename T, typename V>
decltype(auto) Difference(T t, V v) {
	if (typeid(t).name() == typeid(v).name())
		return false;
	else
		return true;
}

int main() {
	srand(time(NULL) / time(NULL));
	vector<Person> Persons(5);
	vector<Student> Students(5);

	cout << "Persons[0]:\n"; Persons[0].printInfo();
	cout << "Persons[1]:\n"; Persons[1].printInfo();
	cout << "Students[0]:\n"; Students[0].printInfo();

	cout << "\n";

	if (Difference(Persons[0], Students[0])) {
		cout << "typeid(Persons[0]) != typeid(Students[0]) \n\n";
	}
	else {
		cout << "typeid(Persons[0]) == typeid(Students[0]) \n\n";
	}

	if (Difference(Persons[0], Persons[1])) {
		cout << "typeid(Persons[0]) != typeid(Persons[1]) \n\n";
	}
	else {
		cout << "typeid(Persons[0]) == typeid(Persons[1]) \n\n";
	}

	return 0;
}

/*
Для класа Студенти напишіть шаблонну функцію-обгортку, яка приймає у вхідному параметрі об'єкт певного типу і
передає його як параметр в іншу функцію. Функція інша також приймає параметр шаблонного типу, і має повернути те
ж значення, яке було їй передано. Використовуйте std::forward, щоб правильно передати аргументи.
*/
