#include <iostream>
#include "Interp4Rotate.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;


extern "C" {
 Interp4Command* CreateCmd(void);
  const char* GetCmdName() { return "Rotate"; }
}




/*!
 * \brief
 *
 *
 */
Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}


/*!
 *
 */
Interp4Rotate::Interp4Rotate()
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  /*
   *  Tu trzeba napisać odpowiednio zmodyfikować kod poniżej.
   */
  cout << GetCmdName() << " " << _angularVelocity << " " << _angle << endl;
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd( MobileObj  *pMobObj, AccessControl * AccCtrlPtr) const
{

    int timeToSleep = (int)(1000000 / std::abs(_angularVelocity));
    double targetOrientation  =pMobObj->GetAng_Yaw_deg() + _angularVelocity <0 ? -1 *_angle : _angle;
    bool exist = true;
    while(exist)
    {
        AccCtrlPtr->LockAccess();
        Vector3D poss = pMobObj->GetPositoin_m();
        double angleAfterIter = pMobObj->GetAng_Yaw_deg()+ _angularVelocity <0 ? -1 : 1;
        std::string strposs =
                std::to_string(poss[0]).substr(0, std::to_string(poss[0]).find(".") + 2)+" "+
                std::to_string(poss[1]).substr(0, std::to_string(poss[1]).find(".") + 2)+" "+
                std::to_string(poss[2]).substr(0, std::to_string(poss[2]).find(".") + 2);
        std::string AngRoll = std::to_string(pMobObj->GetAng_Roll_deg()).substr(0, std::to_string(pMobObj->GetAng_Roll_deg()).find(".") + 2);
        std::string AngPitch = std::to_string(pMobObj->GetAng_Pitch_deg()).substr(0, std::to_string(pMobObj->GetAng_Pitch_deg()).find(".") + 2);
        std::string AngYaw = std::to_string(angleAfterIter).substr(0, std::to_string(angleAfterIter).find(".") + 2);


        pMobObj -> SetCmds("Cube  " + pMobObj->GetSize() + "  " + strposs+ "  "+AngRoll+" "+AngPitch+" "+ AngYaw+ " "+ pMobObj->GetColor()+"\n");
        pMobObj -> SetAng_Yaw_deg(angleAfterIter);
        if (std::abs(targetOrientation - angleAfterIter) < 1.0)  exist = false;

        AccCtrlPtr->MarkChange();
        AccCtrlPtr->UnlockAccess();
    }
    return true;
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{

    Strm_CmdsList >> _angularVelocity;
    Strm_CmdsList >> _angle;

  return true;
}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  predkoscKatowa[rad/s] katObrotu[rad]" << endl;
}
