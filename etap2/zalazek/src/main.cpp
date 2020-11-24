#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/XMLString.hpp>
#include "MobileObj.hh"
#include "Set4LibInterfaces.hpp"
#include "Scene.hh"
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


/*!
 * Czyta z pliku opis poleceń i dodaje je do listy komend,
 * które robot musi wykonać.
 * \param sFileName - (\b we.) nazwa pliku z opisem poleceń.
 * \param CmdList - (\b we.) zarządca listy poleceń dla robota.
 * \retval true - jeśli wczytanie zostało zrealizowane poprawnie,
 * \retval false - w przeciwnym przypadku.
 */
bool ReadFile(const char* sFileName, const char* sGrammaryFileName)
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

//    xercesc::DefaultHandler* pHandler = new XMLInterp4Config(rConfig);
//    pParser->setContentHandler(pHandler);
//    pParser->setErrorHandler(pHandler);

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

   delete pParser;
//    delete pHandler;
   return true;
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
    // Configuration Config;
    if(!ReadCommands(argc, argv)) return 1;


    if(!ReadFile(argv[2], argv[3])) return 1;
    return 0;
}
