#pragma once
#include <string>

class ClassInfo
{
public:
    ClassInfo(std::string c) : className(c) {}
    const std::string&  GetName() const { return className; }

private:
    std::string className;
};

#define LUCENT_CLASS_INFO(reg_class)       \
public:                                    \
    static const ClassInfo* GetClassInfo() \
    {                                      \
        static const ClassInfo info(#reg_class); \
        return &info;                      \
    }