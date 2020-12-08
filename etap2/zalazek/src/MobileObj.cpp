//
// Created by kasia on 30.11.2020.
//
#include "MobileObj.hh"

MobileObj::MobileObj()
{
    MobileObj::SetCmds();
}

std::string _cmd;

double MobileObj::GetAng_Roll_deg() const { return _Ang_Roll_deg; }

double MobileObj::GetAng_Pitch_deg() const { return _Ang_Pitch_deg; }

double MobileObj::GetAng_Yaw_deg() const { return _Ang_Yaw_deg; }

void MobileObj::SetAng_Roll_deg(double Ang_Roll_deg) { _Ang_Roll_deg = Ang_Roll_deg; }

void MobileObj::SetAng_Pitch_deg(double Ang_Pitch_deg) { _Ang_Pitch_deg = Ang_Pitch_deg; }

void MobileObj::SetAng_Yaw_deg(double Ang_Yaw_deg) { _Ang_Yaw_deg = Ang_Yaw_deg; }


const Vector3D & MobileObj::GetPositoin_m() const { return _Position_m; }

Vector3D & MobileObj::UsePosition_m() { return _Position_m; }

void MobileObj::SetPosition_m(const Vector3D &rPos_m) { _Position_m = rPos_m; }


void MobileObj::SetName(const std::string& sName) { _Name = sName; }

const std::string & MobileObj::GetName() const { return _Name; }

void MobileObj::SetColor(int r, int g, int b)
{
    RGB[0] = r;
    RGB[1] = g;
    RGB[2] = b;
}

void MobileObj::SetSize(double x, double y, double z)
{
    SizeXYZ[0] = x;
    SizeXYZ[1] = y;
    SizeXYZ[2] = z;
}

std::string MobileObj::GetSize() {
    return
            std::to_string(SizeXYZ[0]).substr(0, std::to_string(SizeXYZ[0]).find(".") + 2)+" "+
            std::to_string(SizeXYZ[1]).substr(0, std::to_string(SizeXYZ[1]).find(".") + 2)+" "+
            std::to_string(SizeXYZ[2]).substr(0, std::to_string(SizeXYZ[2]).find(".") + 2);
}


std::string MobileObj::GetColor()
{
    /*std::string toReturn = std::to_string(RGB[0]).substr(0, std::to_string(RGB[0]).find(".") + 2)+ " "
            +std::to_string(RGB[1]).substr(0, std::to_string(RGB[1]).find(".") + 2)+" "
            +std::to_string(RGB[2]).substr(0, std::to_string(RGB[2]).find(".") + 2);*/
    return std::to_string(RGB[0]) + " " +std::to_string(RGB[1]) + " " +std::to_string(RGB[2]);
}

bool MobileObj::IncStateIndex() {return true;}

void MobileObj::SetCmds()
{
    std::string AngRoll = std::to_string(_Ang_Roll_deg);
    std::string AngPitch = std::to_string(_Ang_Pitch_deg);
    std::string AngYaw = std::to_string(_Ang_Yaw_deg);
    std::string strposs = std::to_string(_Position_m[0])+" "+std::to_string(_Position_m[1])+" "+std::to_string(_Position_m[2]);
    _Cmd4StatDesc = "Cube  " +GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+"  "+GetColor()+"\n";

}

void MobileObj::SetCmds(std::string newCmd)
{
    _cmd = newCmd;
}

std::string MobileObj::GetCommand()
{
//    Vector3D poss = GetPositoin_m();
//    std::string AngRoll = std::to_string(GetAng_Roll_deg()).substr(0, std::to_string(GetAng_Roll_deg()).find(".") + 2); //std::to_string(GetAng_Roll_deg());
//    std::string AngPitch = std::to_string(GetAng_Pitch_deg()).substr(0, std::to_string(GetAng_Pitch_deg()).find(".") + 2); //std::to_string(GetAng_Pitch_deg());
//    std::string AngYaw = std::to_string(GetAng_Yaw_deg()).substr(0, std::to_string(GetAng_Yaw_deg()).find(".") + 2);  //std::to_string(GetAng_Yaw_deg());
//    std::string strposs =
//            std::to_string(poss[0]).substr(0, std::to_string(poss[0]).find(".") + 2)+" "+
//            std::to_string(poss[1]).substr(0, std::to_string(poss[1]).find(".") + 2)+" "+
//            std::to_string(poss[2]).substr(0, std::to_string(poss[2]).find(".") + 2);
//    std::string sizes = GetSize();
//    std::string colours = GetColor();
//    std::string resuly = "Cube  " + GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+ GetColor()+"\n";
//    return "Cube  " + GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+ " "+ GetColor()+"\n";
    //return "Cube  8.0 11.5 5.0  0.0 0.0 0.0  0.0 0.0 0.0 0 0 255\n";

//    std::string backcmd = _cmd;
    return _cmd;

}