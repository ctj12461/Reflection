<<<<<<< HEAD
#include "stdafx.h"
#include <iostream>
#include"Reflection.h"
#include <exception>
=======
#include <iostream>
#include"Reflection.h"
>>>>>>> 47bbe149ff84f7f1e9a6432876fd4d2d6c5f5d37

using namespace std;

class TestA : public Object
{
	RUNTIME_DEC(TestA)
<<<<<<< HEAD
	void print() {
=======
		void print() {
>>>>>>> 47bbe149ff84f7f1e9a6432876fd4d2d6c5f5d37
		cout << "TestA's Object is here." << endl;
	}
};

RUNTIME_IMP(TestA, Object)


int main(){
<<<<<<< HEAD
    try {
        auto c = Class::forName("TestA");
        cout << "Get TestA Class." << endl;
        cout << "--Name : " << c.getName() << endl;
        cout << "--Base Name : " << c.getBaseName() << endl;
        cout << "--Size : " << c.getSize() << endl;
        cout << "Create Object..." << endl;
        TestA *p = static_cast<TestA*>(c.getInstance());
        p->print();
        return 0;
    } catch(exception& e) {
        cerr << e.what();
    }
	
=======
	//cout << "Hello CMake¡£" << endl;
	auto c = Class::forName("TestA");
	cout << "Get TestA Class." << endl;
	cout << "--Name : " << c.getName() << endl;
	cout << "--Base Name : " << c.getBaseName() << endl;
	cout << "--Size : " << c.getSize() << endl;
	cout << "Create Object..." << endl;
	TestA *p = dynamic_cast<TestA>(c.getInstance());
	p->print();
	return 0;
>>>>>>> 47bbe149ff84f7f1e9a6432876fd4d2d6c5f5d37
}
