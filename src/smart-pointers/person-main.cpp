// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
}

shared_ptr<Person> printName2()
{
	auto maryanne_ptr = make_shared<Person>("Maryanne",12);
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
}

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}


int main()
{
    auto sandile_ptr = make_unique<Person>("Sandile",15);

    auto thabo_in_main = printName();
    cout << thabo_in_main.name() << endl;

    auto person_ptr_in_main = printName2();
    printName3(person_ptr_in_main);

    sandile_ptr = make_unique<Person>("Sandile2",11);
    cout << sandile_ptr->age() << endl;
/*
1.  (a) Thabo goes out of scope in line 24
    (b) maryanne_ptr goes out of scope in line 31
    (c) person_ptr goes out of scope in line 37
    (d) sandile_ptr goes out of scope in line 54
    (e) thabo_in_main goes out of scope in line 54
    (f) person_ptr_in_main goes out of scope in line 54

2.  (a) first sandile_ptr pointee memory is released on line 50
    (b) person_ptr_in_main,maryanne_ptr and person_ptr pointee memory is released on line 54
    (c) second sandile_ptr pointee memory is released on line 54

3.  (a) sandile_ptr and person_ptr are not copied
    (b) maryanne_ptr is copied two times
    (c) person_ptr_in_main is copied once

4.  (a) sandile_ptr will go out of scope first since the destructor of a pointer
        will be called first as the object was created before thabo_in_main
*/

    return 0;
}


