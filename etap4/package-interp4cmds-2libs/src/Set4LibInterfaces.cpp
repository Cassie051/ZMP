//
// Created by kasia on 24.11.2020.
//

#include "Set4LibInterfaces.hh"

Set4LibInterfaces::Set4LibInterfaces()
{}

std::shared_ptr<LibInterface> Set4LibInterfaces::findInterface(const std::string& libName)
{
    std::map<std::string, std::shared_ptr<LibInterface>>::iterator iter = set4LibInterfaces.find(libName);
    if (iter != set4LibInterfaces.end())
    {
        return iter->second;
    }

    return nullptr;
}

bool Set4LibInterfaces::addInterface(const std::string& libname)
{
    std::shared_ptr<LibInterface> libInterface  = std::make_shared<LibInterface>();
    if(!libInterface->initInterface(libname))
    {
        return false;
    }
    set4LibInterfaces.insert({libname, libInterface});
    return true;
}

Set4LibInterfaces::~Set4LibInterfaces()
{}
