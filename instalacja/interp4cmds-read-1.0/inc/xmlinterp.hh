#pragma once
#ifndef XMLINTERP4ACTIONS_HH
#define XMLINTERP4ACTIONS_HH

#include <string>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/Locator.hpp>
#include <xercesc/sax2/Attributes.hpp>
#include "Set4LibInterfaces.hh"
#include "Scene.hh"

//XERCES_CPP_NAMESPACE_USE


/*!
 * \brief Implementuje reakcje na napotkane elementu opisu akcji
 *
 * Klasa zawiera zestaw metod, które wywoływane są w trakcie czytania i analizy
 * pliku XML.
 */
class XMLInterp4Config : xercesc::DefaultHandler {
  public:
   /*!
    * \brief Inicjalizuje obiekt i kojarzy go z listą poleceń robota
    */
  XMLInterp4Config();


   /*!
    * \brief Wywoływana jest na początku dokumentu
    */
    virtual void startDocument() override;
   /*!
    * \brief Wywoływana jest na końcu dokumentu
    */
    virtual void endDocument() override;

   /*!
    * \brief Wywoływana jest po napotkaniu nowego elementu XML
    */
    virtual void startElement(
                    const XMLCh *const pURI, 
                    const XMLCh *const pLocalName, 
                    const XMLCh *const pQNname,
                    const   xercesc::Attributes&     attrs
                  ) override;

   /*! 
    * \brief Wywoływana jest po dojściu do końca elementu XML
    */
    virtual  void endElement(
                    const XMLCh *const pURI, 
                    const XMLCh *const pLocalName, 
                    const XMLCh *const pQNname
                   ) override;
   /*!
    * \brief Wywoływana jest gdy napotkany zostanie błąd fatalny
    */
    void fatalError(const xercesc::SAXParseException&);
   /*!
    * \brief Wywoływana jest gdy napotkany zostanie błąd
    */
    void error(const xercesc::SAXParseException &exc);
   /*!
    * \brief Wywoływana jest gdy parser sygnalizuje ostrzeżenie
    */
    void warning(const xercesc::SAXParseException &exc);


    /*!
     * \brief Wykonuje operacje związane z danym elementem XML
     */
    void WhenStartElement( const std::string&             ElemName,
		           const xercesc::Attributes&     Attrs
                         );
    /*!
     * \brief Analizuje atrybuty i  odpwiednio je interpretuje
     */
    int ProcessLibAttrs(const xercesc::Attributes&   Attrs);
    /*!
     * \brief Analizuje atrybuty i odpwiednio je interpretuje
     */
    void ProcessCubeAttrs(const xercesc::Attributes&   Attrs);
    Scene* GetScene();
  protected:
    Set4LibInterfaces libInerfaces;
    Scene scene;
};

#endif