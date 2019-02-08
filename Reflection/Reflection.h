// Reflection.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#ifndef REFLECTION_H
#define RELFECTION_H

#include <string>
#include <map>
#include <vector>

template<typename Singleton>
class SingletonWrapper;

class Object;

class Class
{
public:
	using Contructor = Object *(*)();
	using ArrayContructor = Object *(*)(size_t size);
    using Map = std::map<std::string, Class*>;

	Class(int size, std::string name, std::string baseName, Contructor ctor, ArrayContructor arrCtor);
    Class(const Class&) = default;
	Class& operator=(const Class&) = default;
    Class(Class&&) = default;
    Class& operator=(Class&&) = default;

	std::string getName() const;
	std::string getBaseName() const;
	size_t getSize() const;
	Class& getBaseClass() const;
	Object* getInstance(size_t size = 1);
	static Class& forName(std::string name);
	static bool is(const Class& lhs, const Class& rhs);
private:
	std::string Name;
	std::string BaseName;
	size_t Size;
	Contructor Ctor;
	ArrayContructor ArrCtor;
	static Map *ClassMap;
    static SingletonWrapper<Map> Wrapper;
	static void regist(Class& classInfo);
	static void unregist(const Class& classInfo);

};

class Object
{
private: 
    static Class ClassInfo; 
public: 
    static Object *create(); 
    static Object *createArray(size_t size);	
    static Class& getClass();
};

#define SIZE(T) sizeof(T)
#define NAME(N) #N##s

#define RUNTIME_DEC(CLASS) \
private: \
	static Class ClassInfo; \
public: \
	static CLASS *create(); \
	static CLASS *createArray(size_t size);	\
	static Class& getClass(); \

#define RUNTIME_IMP(CLASS, BASE) \
Class CLASS::ClassInfo(SIZE(CLASS), NAME(CLASS), NAME(BASE), reinterpret_cast<Class::Contructor>(&CLASS::create), reinterpret_cast<Class::ArrayContructor>(&CLASS::createArray)); \
\
CLASS *CLASS::create(){ \
	return new CLASS; \
} \
\
CLASS *CLASS::createArray(size_t size){ \
	return new CLASS[size]; \
}\
\
Class& CLASS::getClass(){ \
	return ClassInfo;\
} \




#endif // !REFLECTION_H

// TODO: 在此处引用程序需要的其他标头。
