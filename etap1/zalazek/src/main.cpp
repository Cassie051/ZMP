#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include "MobileObj.hh"
#include "Set4LibInterfaces.hpp"
#include "Scene.hh"


#define LINE_SIZE 500

bool ExecPreprocesor( const char * NazwaPliku, std::istringstream &IStrm4Cmds )
{
    std::string Cmd4Preproc = "cpp -P ";
    char Line[LINE_SIZE];
    std::ostringstream OTmpStrm;
    Cmd4Preproc += NazwaPliku;
    FILE *pProc = popen(Cmd4Preproc.c_str(), "r");
    if (!pProc)
        return false;
    while (fgets(Line, LINE_SIZE, pProc))
    {
        OTmpStrm << Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());
    return pclose(pProc) == 0;
}



int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cerr << "Too few arguments\n";
    return 1;
  }

  std::istringstream IStrm4Cmds;

  if(!ExecPreprocesor(argv[1], IStrm4Cmds))
  {
      std::cerr << "Cannot process\n";
      return 2;
  }

  std::cout << IStrm4Cmds.str() << "\n";  

  Set4LibInterfaces libInerfaces;
  Scene scene;

  while(IStrm4Cmds.eof())
  {
    std::string libName, objectName;

    IStrm4Cmds >> libName;
    IStrm4Cmds >> objectName;
     
     std::shared_ptr<MobileObj> mobileObject = scene.findMobileObject(objectName);
     if(!mobileObject)
     {
       scene.addMobileObject(objectName);
     }
     mobileObject = scene.findMobileObject(objectName);
     
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
     if(!interface->execActions(IStrm4Cmds, mobileObject))
     {
       std::cerr << "Couldnt execute action for: " << IStrm4Cmds.str()<< "\n";
       return 2;
     }
  }
  return 0;
}
