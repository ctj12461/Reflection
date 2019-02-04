// Reflection.cpp: 定义应用程序的入口点。
//

#include "Reflection.h"

using namespace std;

Class ClassInfo = Class(sizeof(Object), "Object", "");

Class& Object::getClass() const
{
	// TODO: 在此处插入 return 语句
}

Class::Class()
	:
	Size(0),
	Ctor(nullptr)
{
}

Class::Class(int size, std::string name, std::string baseName)
	:
	Size(size),
	Name(name),
	BaseName(baseName),
	Ctor(nullptr)
{
	registerClass(*this);
}

std::string Class::getName() const{
	return Name;
}

std::string Class::getBaseName() const{
	return BaseName;
}

size_t Class::getSize() const{
	return Size;
}

Class& Class::getBaseClass() const {
	return forName(BaseName);
}

Object * Class::getInstance(){
	return (*Ctor)();
}

Class Class::forName(std::string name){
	return ClassMap[name];
}

bool Class::is(const Class& lhs, const Class& rhs){
	if (lhs.Name == rhs.Name) {
		return true;
	} else if (lhs.Name == "") {
		return false;
	} else {
		return is(lhs, forName(rhs.BaseName));
	}
}

void Class::registerClass(const Class& classInfo){
	ClassMap[classInfo.Name] = classInfo;
}

void Class::unregisterClass(const Class& classInfo){
	ClassMap.erase(classInfo.Name);
}

