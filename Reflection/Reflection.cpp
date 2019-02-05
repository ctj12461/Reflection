// Reflection.cpp: 定义应用程序的入口点。
//

#include "Reflection.h"

using namespace std;

//Class ClassInfo = Class(sizeof(Object), "Object", "", &Object::create);

RUNTIME_IMP(Object, Object)

Class::Class()
	:
	Size(0),
	Ctor(nullptr)
{
}

Class::Class(int size, std::string name, std::string baseName, Contructor ctor, ArrayContructor arrCtor)
	:
	Size(size),
	Name(name),
	BaseName(baseName),
	Ctor(ctor),
	ArrCtor(arrCtor)
{
	regist(*this);
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

Object * Class::getInstance(size_t size){
	if (size == 1) {
		return (*Ctor)();
	} else {
		return (*ArrCtor)(size);
	}
}

Class& Class::forName(std::string name){
	auto iter = ClassMap.find(name);
	if (iter != ClassMap.end()) {
		throw exception("No match found name.");
	} else {
		return *(iter->second);
	}
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

void Class::regist(Class& classInfo){
	ClassMap[classInfo.Name] = &classInfo;
}

void Class::unregist(const Class& classInfo){
	ClassMap.erase(classInfo.Name);
}

