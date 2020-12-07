//
// Created by kasia on 24.11.2020.
//
#include "LibInterface.hh"

LibInterface::LibInterface()
{}

bool LibInterface::initInterface(const std::string& CmdName)
{
//    std::string libName("libInterp4");
//    libName.append(CmdName);
//    libName.append(".o");
//    std::string t = libName.c_str();
//    std::string path = "../lib/" + CmdName;
    _pLibHnd = dlopen(("./plugin/"+CmdName).c_str(), RTLD_LAZY);
    if(!_pLibHnd)
    {
        return false;
    }
    void *pFun;
    pFun = dlsym(_pLibHnd,"CreateCmd");

    if(!pFun)
    {
        return false;
    }
    pCreateCmd = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);

    return true;
}

bool LibInterface::execActions(std::istream &rIstrm, std::shared_ptr<MobileObj>& mobileObject)
{
    Interp4Command *pCmd = pCreateCmd();


    if(!pCmd->ReadParams(rIstrm))
    {
        return false;
    }

    std::cout << mobileObject->GetName() << " ";
    pCmd->PrintCmd();
    delete pCmd;
    return true;
}


LibInterface::~LibInterface() {
    if (_pLibHnd) {
        dlclose(_pLibHnd);
    }
}