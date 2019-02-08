// Reflection.cpp: 定义应用程序的入口点。
//
#include "stdafx.h"
#include "Reflection.h"
#include "Exception.h"

using namespace std;

std::map<std::string, Class*> Class::ClassMap;

Class Object::ClassInfo(sizeof(Object), "Object", "", reinterpret_cast<Class::Contructor>(&Object::create), reinterpret_cast<Class::ArrayContructor>(&Object::createArray));

Object *Object::create() {
    return new Object;
} 

Object *Object::createArray(size_t size) {      
    return new Object[size];
}
        
Class& Object::getClass() {
    return ClassInfo; 
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
	auto iter = Class::ClassMap.find(name);
	if (iter != Class::ClassMap.end()) {
		throw NoNameException("No match found name.");
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
    Class::ClassMap[classInfo.Name] = &classInfo;
}

void Class::unregist(const Class& classInfo){
    Class::ClassMap.erase(classInfo.Name);
}

