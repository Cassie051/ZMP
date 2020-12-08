#pragma once
#include <map>
#include <string>
#include <memory>
#include "LibInterface.hh"

class Set4LibInterfaces 
{
private:
    std::map<std::string, std::shared_ptr<LibInterface>> set4LibInterfaces;
public:
    Set4LibInterfaces();
    std::shared_ptr<LibInterface> findInterface(const std::string& libName);
    bool addInterface(const std::string& libname);
    ~Set4LibInterfaces();
};
