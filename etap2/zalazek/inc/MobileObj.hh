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
       /*!
        * \brief Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OZ.
	*
	* Kąt \e yaw reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OZ. Wartość kąta wyrażona jest w stopniach.
        */
       double _Ang_Yaw_deg = 0;

       /*!
        * \brief Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OY.
	*
	* Kąt \e pitch reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OY. Wartość kąta wyrażona jest w stopniach.
        */
       double _Ang_Pitch_deg = 0;

       /*!
        * \brief Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
        *        wokół osi \e OX.
	*
	* Kąt \e roll reprezentuje rotację zgodnie z ruchem wskazówek zegara
        * wokół osi \e OX. Wartość kąta wyrażona jest w stopniach.
        */
       double _Ang_Roll_deg = 0;

       /*!
        * \brief Współrzędne aktualnej pozycji obiektu.
	*
	* Współrzędne aktualnej pozycji obiektu. Przyjmuje się,
	* że współrzędne wyrażone są w metrach.
        */
       Vector3D  _Position_m;

       /*!
        * \brief Nazwa obiektu, która go indentyfikuje.
        *
        * Nazwa obiektu, która go indentyfikuje. Z tego względu musi
        * musi to być nazwa unikalna wśród wszystkich obiektów na scenie.
        */
       std::string  _Name;
       int RGB[2];
       double SizeXYZ[2];
       std::string _Cmd4StatDesc;

     public:
        MobileObj() {SetCmds();}
      /*!
       * \brief Udostępia wartość kąta \e roll.
       *
       * Udostępia wartość kąta \e roll. Jest ona wyrażona w stopniach.
       */
       double GetAng_Roll_deg() const { return _Ang_Roll_deg; }
      /*!
       * \brief Udostępia wartość kąta \e pitch.
       *
       * Udostępia wartość kąta \e pitch. Jest ona wyrażona w stopniach.
       */
       double GetAng_Pitch_deg() const { return _Ang_Pitch_deg; }
       /*!
       * \brief Udostępia wartość kąta \e yaw.
       *
       * Udostępia wartość kąta \e yaw. Jest ona wyrażona w stopniach.
       */
       double GetAng_Yaw_deg() const { return _Ang_Yaw_deg; }

      /*!
       * \brief Zmienia wartość kąta \e roll.
       *
       * Zmienia wartość kąta \e roll.
       * \param[in] Ang_Roll_deg - nowa wartość kąta \e roll wyrażona w stopniach.
       */
       void SetAng_Roll_deg(double Ang_Roll_deg) { _Ang_Roll_deg = Ang_Roll_deg; }
      /*!
       * \brief Zmienia wartość kąta \e pitch.
       *
       * Zmienia wartość kąta \e pitch.
       * \param[in] Ang_Pitch_deg - nowa wartość kąta \e pitch wyrażona w stopniach.
       */
       void SetAng_Pitch_deg(double Ang_Pitch_deg) { _Ang_Pitch_deg = Ang_Pitch_deg; }
      /*!
       * \brief Zmienia wartość kąta \e yaw.
       *
       * Zmienia wartość kąta \e yaw.
       * \param[in] Ang_Yaw_deg - nowa wartość kąta \e yaw wyrażona w stopniach.
       */
       void SetAng_Yaw_deg(double Ang_Yaw_deg) { _Ang_Yaw_deg = Ang_Yaw_deg; }

      /*!
       * \brief Udostępnia współrzędne położenia obiektu w trybie tylko do odczytu.
       *
       * Udostępnia współrzędne punktu, który definiuje położenia obiektu
       * w trybie tylko do odczytu.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       */
       const Vector3D & GetPositoin_m() const { return _Position_m; }
      /*!
       * \brief Udostępnia współrzędne położenia obiektu w trybie modyfikacji.
       *
       * Udostępnia współrzędne punktu, który definiuje położenia obiektu
       * w trybie modyfikacji.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       */
       Vector3D & UsePosition_m() { return _Position_m; }
      /*!
       * \brief Zmienia współrzędne położenia obiektu.
       *
       * Zmienia współrzędne punktu, który definiuje położenia obiektu.
       * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
       * \param[in] rPos_m - współrzędne nowgo położenia. Przyjmuje się,
       *                     że są one wyrażone w metrach.
       */
       void SetPosition_m(const Vector3D &rPos_m) { _Position_m = rPos_m; }


      /*!
       * \brief Zmienia nazwę obiektu.
       *
       *  Zmienia nazwę obiektu.
       *  \param[in] sName - nowa nazwa obiektu.
       */
       void SetName(const std::string& sName) { _Name = sName; }
       /*!
        * \brief Udostępnia nazwę obiektu.
	*
	* Udostępnia nazwę obiektu w trybie tylko do odczytu.
        */
       const std::string & GetName() const { return _Name; }

       void SetColor(int r, int g, int b)
       {
           RGB[0] = 0;
           RGB[1] = 0;
           RGB[2] = 255;
       }

       void SetSize(double x, double y, double z)
       {
           SizeXYZ[0] = x;
           SizeXYZ[1] = y;
           SizeXYZ[2] = z;
       }

       std::string GetSize() {
           return
           std::to_string(SizeXYZ[0]).substr(0, std::to_string(SizeXYZ[0]).find(".") + 2)+" "+
           std::to_string(SizeXYZ[1]).substr(0, std::to_string(SizeXYZ[1]).find(".") + 2)+" "+
           std::to_string(SizeXYZ[2]).substr(0, std::to_string(SizeXYZ[2]).find(".") + 2);
       }


       std::string GetColor()
       {
           /*std::string toReturn = std::to_string(RGB[0]).substr(0, std::to_string(RGB[0]).find(".") + 2)+ " "
                   +std::to_string(RGB[1]).substr(0, std::to_string(RGB[1]).find(".") + 2)+" "
                   +std::to_string(RGB[2]).substr(0, std::to_string(RGB[2]).find(".") + 2);*/
           return std::to_string(RGB[0]) + " " +std::to_string(RGB[1]) + " " +std::to_string(RGB[2]);
       }

       bool IncStateIndex() {return true;}

       void SetCmds()
       {
           std::string AngRoll = std::to_string(_Ang_Roll_deg);
           std::string AngPitch = std::to_string(_Ang_Pitch_deg);
           std::string AngYaw = std::to_string(_Ang_Yaw_deg);
           std::string strposs = std::to_string(_Position_m[0])+" "+std::to_string(_Position_m[1])+" "+std::to_string(_Position_m[2]);
           _Cmd4StatDesc = "Cube  " +GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+"  "+GetColor()+"\n";
       }
        std::string GetCommand()
        {
            Vector3D poss = GetPositoin_m();
            std::string AngRoll = std::to_string(GetAng_Roll_deg()).substr(0, std::to_string(GetAng_Roll_deg()).find(".") + 2); //std::to_string(GetAng_Roll_deg());
            std::string AngPitch = std::to_string(GetAng_Pitch_deg()).substr(0, std::to_string(GetAng_Pitch_deg()).find(".") + 2); //std::to_string(GetAng_Pitch_deg());
            std::string AngYaw = std::to_string(GetAng_Yaw_deg()).substr(0, std::to_string(GetAng_Yaw_deg()).find(".") + 2);  //std::to_string(GetAng_Yaw_deg());
            std::string strposs =
                    std::to_string(poss[0]).substr(0, std::to_string(poss[0]).find(".") + 2)+" "+
                    std::to_string(poss[1]).substr(0, std::to_string(poss[1]).find(".") + 2)+" "+
                    std::to_string(poss[2]).substr(0, std::to_string(poss[2]).find(".") + 2);
            std::string sizes = GetSize();
            std::string colours = GetColor();
            std::string resuly = "Cube  " + GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+ GetColor()+"\n";
            return "Cube  " + GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+ " "+ GetColor()+"\n";
            //return "Cube  8.0 11.5 5.0  0.0 0.0 0.0  0.0 0.0 0.0 0 0 255\n";
        }
    };


#endif