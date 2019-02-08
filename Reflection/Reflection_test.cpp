#include "stdafx.h"
#include <iostream>
#include"Reflection.h"
#include <exception>

using namespace std;

class TestA : public Object
{
	RUNTIME_DEC(TestA)
	void print() {
		cout << "TestA's Object is here." << endl;
	}
};

RUNTIME_IMP(TestA, Object)


int main(){
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
}
