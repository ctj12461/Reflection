// Reflection.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#ifndef REFLECTION_H
#define RELFECTION_H

#include <string>
#include <map>

class Object;

class Class
{
public:
	using Contructor = Object *(*)();
	using ArrayContructor = Object *(*)(size_t size);

	Class();
	Class(int size, std::string name, std::string baseName, Contructor ctor, ArrayContructor arrCtor);
	Class& operator=(const Class& other) = default;

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
	static std::map<std::string, Class*> ClassMap;
	static void regist(Class& classInfo);
	static void unregist(const Class& classInfo);

};

#define SIZE(T) sizeof(T)
#define NAME(N) #N

#define RUNTIME_DEC(CLASS) \
private: \
	static Class ClassInfo; \
public: \
	static CLASS *create(); \
	static CLASS *createArray(size_t size);	\
	static Class& getClass(); \

#define RUNTIME_IMP(CLASS, BASE) \
Class ClassInfo = Class(SIZE(CLASS), NAME(CLASS), NAME(BASE), &CLASS::create, &CLASS::createArray); \
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

class Object
{
	RUNTIME_DEC(Object)
};


#endif // !REFLECTION_H

// TODO: 在此处引用程序需要的其他标头。
