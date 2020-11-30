#pragma once
#ifndef MOBILEOBJ_HH
#define MOBILEOBJ_HH


#include <string>
#include "Vector3D.hh"


/*!
 * \file
 * \brief Zawiera definicję klasy MobileObj
 *
 * Plik zawiera definicję klasy MobileObj.
 * Definicja to może być rozszerzona i zmienione mogą
 * być nazwy pól. Obowiązkowe są jedynie nazwy metod.
 */




   /*!
    * Nazwy pól klasy są jedynie propozycją i mogą być zmienione
    * Nazwy metod są obowiązujące.
    */
    class MobileObj {

       double _Ang_Yaw_deg = 0;

       double _Ang_Pitch_deg = 0;

       double _Ang_Roll_deg = 0;

       Vector3D  _Position_m;

       std::string  _Name;
       int RGB[2];
       double SizeXYZ[2];
       std::string _Cmd4StatDesc;

     public:
        MobileObj();

       double GetAng_Roll_deg() const;

       double GetAng_Pitch_deg() const;

       double GetAng_Yaw_deg() const;

       void SetAng_Roll_deg(double Ang_Roll_deg);

       void SetAng_Pitch_deg(double Ang_Pitch_deg);

       void SetAng_Yaw_deg(double Ang_Yaw_deg);


       const Vector3D & GetPositoin_m() const ;

       Vector3D & UsePosition_m();

       void SetPosition_m(const Vector3D &rPos_m);


       void SetName(const std::string& sName);

       const std::string & GetName() const;

       void SetColor(int r, int g, int b);

       void SetSize(double x, double y, double z);

       std::string GetSize();


       std::string GetColor();

       bool IncStateIndex();

       void SetCmds();

        std::string GetCommand();
    };


#endif