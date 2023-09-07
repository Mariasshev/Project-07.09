#include<iostream>
using namespace std;

class Student
{
private:
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, const char* e, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);

		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);

		age = a;
	}
	void Input()
	{
		char buffName[20], buffEmail[40];
		cout << "Enter name: ";
		cin >> buffName;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[] name;
		}
		name = new char[strlen(buffName) + 1];
		strcpy_s(name, strlen(buffName) + 1, buffName);

		cout << "Enter email: ";
		cin >> buffEmail;
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[] email;
		}
		email = new char[strlen(buffEmail) + 1];
		strcpy_s(email, strlen(buffEmail) + 1, buffEmail);

		cout << "Enter age: ";
		cin >> age;
	}
	void Print()
	{
		cout << "Name: " << name << "\nEmail: " << email << "\nAge: " << age << endl << endl;
	}

	void SetCName(const char* n) {
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "... \n";
			delete[] name;
		}
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	char* GetCName() {
		return name;
	}
	void SetCEmail(const char* e) {
		if (email != nullptr)
		{
			cout << "Delete -> " << email << "... \n";
			delete[] email;
		}
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
	}
	char* GetCEmail() {
		return email;
	}
	void SetCAge(int a) {
		age = a;
	}
	int GetCAge() {
		return age;
	}
	~Student()
	{
		delete[] name;
		delete[] email;
	}


};

int main()
{
	Student a("Oleg", "oleg20@gmail.com", 20);
	cout << "First student (with 3 parameters)" << endl;
	a.Print();

	Student b;
	cout << "Second student (with default constructor)" << endl;
	b.Input();
	cout << endl;
	b.Print();

	Student c;
	cout << "Third student (default constructor with 0 parameters and with accessor methods)" << endl;
	c.SetCName("Maria");
	c.SetCEmail("shevchenkomaria@gmail.com");
	c.SetCAge(22);
	cout << "Name: " << c.GetCName() << "\nEmail: " << c.GetCEmail() << "\nAge: " << c.GetCAge() << endl;

}