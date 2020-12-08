#include "Init.hh"

InitInter::InitInter() {}

InitInter::~InitInter() {}

int InitInter::AddMobileObject( std::string objectName) 
{
    std::shared_ptr<MobileObj> mobileObject = scene.findMobileObject(objectName);
    if(!mobileObject)
    {
        scene.addMobileObject(objectName);
    }

    mobileObject = scene.findMobileObject(objectName);
    return 0;
}

int InitInter::AddLibrary(std::string libName)
{
    std::shared_ptr<LibInterface> interface = libInerfaces.findInterface(libName);
    if(!interface)
    {
        bool addedLibSuccesfully = libInerfaces.addInterface(libName);
        if(!addedLibSuccesfully)
        {
            std::cerr << "Couldnt init lib: "  << libName << "\n";
            return 2;
        }
        interface = libInerfaces.findInterface(libName);
    }
    return 0;
}

