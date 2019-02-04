// Reflection.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件。

#ifndef REFLECTION_H
#define RELFECTION_H

#include <string>
#include <map>

class Class;

struct Object
{
	static Class ClassInfo;
	virtual Object *create() = 0;
	Class& getClass() const;
};

class Class
{
public:
	using Contructor = Object * (Object::*)();
	Class();
	Class(int size, std::string name, std::string baseName);
	Class& operator=(const Class& other) = default;

	std::string getName() const;
	std::string getBaseName() const;
	size_t getSize() const;
	Class& getBaseClass() const;
	Object* getInstance();
	static Class forName(std::string name);
	static bool is(const Class& lhs, const Class& rhs);
private:
	std::string Name;
	std::string BaseName;
	size_t Size;
	Contructor Ctor;
	static std::map<std::string, Class> ClassMap;
	static void registerClass(const Class& classInfo);
	static void unregisterClass(const Class& classInfo);

};

#define SIZE(T) sizeof(T)
#define NAME(N) #N
#define runtime_dec(CLASS, BASE) static Class ClassInfo; = Class(CLASS, NAME(CLASS), NAME(BASE));
#define runtime_dec(CLASS, BASE) Class ClassInfo = Class(CLASS, NAME(CLASS), NAME(BASE));

#endif // !REFLECTION_H

// TODO: 在此处引用程序需要的其他标头。
