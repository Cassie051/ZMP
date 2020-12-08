#include <iostream>
#include <string>
#include <filesystem>
#include "Sender.hh"
#include "klient.hh"
#include "xmlinterp.hh"

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


bool ReadCommands(Scene &scene)
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
    else if (libName == "Set")
    {
        libName = "libInterp4Set.so";
    }

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
        else if (libName == "Set")
        {
            libName = "libInterp4Set.so";
        }
    }
    return true;
}

bool ReadFile(const char* sFileName, const char* sGrammaryFileName,xercesc::DefaultHandler* &Handler)
{
   try {
            xercesc::XMLPlatformUtils::Initialize();
   }
   catch (const xercesc::XMLException& toCatch) {
            char* message = xercesc::XMLString::transcode(toCatch.getMessage());
            std::cerr << "Error during initialization! :\n";
            std::cerr << "Exception message is: \n"
                 << message << "\n";
            xercesc::XMLString::release(&message);
            return 1;
   }

   xercesc::SAX2XMLReader* pParser = xercesc::XMLReaderFactory::createXMLReader();

   pParser->setFeature(xercesc::XMLUni::fgSAX2CoreNameSpaces, true);
   pParser->setFeature(xercesc::XMLUni::fgSAX2CoreValidation, true);
   pParser->setFeature(xercesc::XMLUni::fgXercesDynamic, false);
   pParser->setFeature(xercesc::XMLUni::fgXercesSchema, true);
   pParser->setFeature(xercesc::XMLUni::fgXercesSchemaFullChecking, true);

   pParser->setFeature(xercesc::XMLUni::fgXercesValidationErrorAsFatal, true);

    pParser->setContentHandler(Handler);
    pParser->setErrorHandler(Handler);

   try {
     
     if (!pParser->loadGrammar(sGrammaryFileName,
                              xercesc::Grammar::SchemaGrammarType,true)) {
       std::cerr << "!!! Plik grammar/actions.xsd, '" << std::endl
            << "!!! ktory zawiera opis gramatyki, nie moze zostac wczytany."
            << std::endl;
       return false;
     }
     pParser->setFeature(xercesc::XMLUni::fgXercesUseCachedGrammarInParse,true);
     pParser->parse(sFileName);
   }
   catch (const xercesc::XMLException& Exception) {
            char* sMessage = xercesc::XMLString::transcode(Exception.getMessage());
            std::cerr << "Informacja o wyjatku: \n"
                 << "   " << sMessage << "\n";
            xercesc::XMLString::release(&sMessage);
            return false;
   }
   catch (const xercesc::SAXParseException& Exception)
   {
            char* sMessage = xercesc::XMLString::transcode(Exception.getMessage());
            char* sSystemId = xercesc::XMLString::transcode(Exception.getSystemId());

            std::cerr << "Blad! " << std::endl
                 << "    Plik:  " << sSystemId << std::endl
                 << "   Linia: " << Exception.getLineNumber() << std::endl
                 << " Kolumna: " << Exception.getColumnNumber() << std::endl
                 << " Informacja: " << sMessage 
                 << std::endl;

            xercesc::XMLString::release(&sMessage);
            xercesc::XMLString::release(&sSystemId);
            return false;
   }
   catch (...) {
            std::cout << "Zgloszony zostal nieoczekiwany wyjatek!\n" ;
            return false;
   }

   return true;
}



int main(int argc, char **argv)
{
    std::string FileName = "../config/config.xml";
    std::string GramarFileName = "../config/config.xsd";

    std::cout << "Current path is " << std::filesystem::current_path() << '\n';
    xercesc::DefaultHandler* pHandler = (xercesc::DefaultHandler*)(new XMLInterp4Config());
    if(!ReadFile(FileName.c_str(), GramarFileName.c_str(), pHandler)) return 1;
    XMLInterp4Config* SceneHendler = (XMLInterp4Config*)(pHandler);

    Exec(*(SceneHendler->GetScene()));

    if(!ReadCommands(*(SceneHendler->GetScene()))) return 1;
}
