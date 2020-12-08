#include "MobileObj.hh"
#include "Set4LibInterfaces.hh"
#include "Scene.hh"


class InitInter
{
        Set4LibInterfaces libInerfaces;
        Scene scene;
        InitInter();
        ~InitInter();
        int AddMobileObject(std::string objectName);
        int AddLibrary(std::string libName);
        
};