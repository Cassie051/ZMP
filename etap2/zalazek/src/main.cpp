#include <iostream>
#include <string>
#include "ReadInter.cpp"
#include <filesystem>
#include "Sender.h"
#include "klient.h"

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


bool ReadCommands(Scene &Scn)
{
    std::istringstream IStrm4Cmds;
    std::string FileName = "../config/test.cmd";

    if(!ExecPreprocesor(FileName.c_str(), IStrm4Cmds))
    {
        std::cerr << "Cannot process\n";
        return 2;
    }

    Set4LibInterfaces libInerfaces;
    std::string libName, objectName;

    IStrm4Cmds >> libName;
    IStrm4Cmds >> objectName;

    if(libName == "Rotate")
    {
        libName = "libInterp4Rotate.so";
    }
    else if (libName == "Move")
    {
        libName = "libInterp4Move.so";
    }
    else if (libName == "Pause")
    {
        libName = "libInterp4Pause.so";
    }

    while(!IStrm4Cmds.eof())
    {
        std::shared_ptr<MobileObj> mobileObject = Scn.findMobileObject(objectName);
        if(!mobileObject)
        {
            Scn.addMobileObject(objectName);
        }
        mobileObject = Scn.findMobileObject(objectName);

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
        if(!interface->execActions(IStrm4Cmds, mobileObject, &Scn))
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
    std::string FileName = "../config/config.xml";
    std::string GramarFileName = "../config/config.xsd";
    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    xercesc::DefaultHandler* pHandler = (xercesc::DefaultHandler*)(new XMLInterp4Config());
    XMLInterp4Config* SceneHendler = (XMLInterp4Config*)(pHandler);
    if(!ReadFile(FileName.c_str(), GramarFileName.c_str(), pHandler)) return 1;

    Exec(*(SceneHendler->GetScene()));
    if(!ReadCommands(*(SceneHendler->GetScene()))) return 1;
}
