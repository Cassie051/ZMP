#pragma once
#include <memory>
#include <string>
#include "Interp4Command.hh"
#include <dlfcn.h>

class LibInterface
{
private:
    std::string _CmdName;
    void *_pLibHnd;
    Interp4Command *(*pCreateCmd)(void);
public:
    LibInterface();
    bool execActions(std::istream &rIstrm, std::shared_ptr<MobileObj>& mobileObject);
    bool initInterface(const std::string& CmdName);
    ~LibInterface();
};
