#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person
{
public:
	Person(const string& name, unsigned int age):
	  _name(name),
	  _age(age)
	  {cout << "Constructing a person " << name << endl;}

	// The copy constructor and assignment operator and destructor are not needed
	//  -- the compiler-generated versions work fine
    Person(const Person& rhs)
    {
        cout << "Copying a person" << rhs.name() << endl;
	    this->_name = rhs.name();
	    this->_age = rhs.age();
    }

	void operator= (const Person& rhs)
	{
	    cout << "Copying a person" << rhs.name() << endl;
	    this->_name = rhs.name();
	    this->_age = rhs.age();
	}

	string name() const { return _name; }
	void name(const string& newname) { _name = newname; }
	unsigned int age() const { return _age; }
	void age(unsigned int new_age) { _age = new_age; }
	~Person(){cout<<"Destroying a person called: "<<_name<<endl;}

private:
	string _name;
	unsigned int _age;
};

#endif
