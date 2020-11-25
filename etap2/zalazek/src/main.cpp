#include <iostream>
#include <string>
#include <sstream>
#include "xmlinterp.hh"
#include "ReadInter.hh"
#include <filesystem>


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


bool ReadCommands(int argc, char **argv)
{
    std::istringstream IStrm4Cmds;

    if(!ExecPreprocesor(argv[1], IStrm4Cmds))
    {
        std::cerr << "Cannot process\n";
        return 2;
    }

    Set4LibInterfaces libInerfaces;
    Scene scene;
    std::string libName, objectName;

    IStrm4Cmds >> libName;
    IStrm4Cmds >> objectName;

    while(!IStrm4Cmds.eof())
    {
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
            std::cerr << "Couldnt execute action for: " << libName << "\n" ;
            return 2;
        }

        IStrm4Cmds >> libName;
        IStrm4Cmds >> objectName;
    }
    return true;
}

int main(int argc, char **argv)
{
  //  if(!ReadCommands(argc, argv)) return 1;

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    if(!ReadFile(argv[2], argv[3])) return 1;
    return 0;
}
