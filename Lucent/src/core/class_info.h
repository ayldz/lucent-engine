#pragma once
#include <string>

class ClassInfo
{
public:
	ClassInfo(std::string className) : className(className) {}
	std::string GetName() { return className; }

private:
	std::string className;
};

#define LUCENT_CLASS_INFO(reg_class)			\
public:											\
	static const ClassInfo* GetClassInfo()      \
	{											\
		static ClassInfo info(#reg_class);		\
		return info;							\
	}