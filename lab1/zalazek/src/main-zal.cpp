#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Interp4Command.hh"

using std::cout;
using std::cerr;
using std::endl;




int main()
{
  void *pLibHnd_Fly = dlopen("Interp4Fly.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Fly)(void);
  void *pFun;

  if (!pLibHnd_Fly) {
    cerr << "!!! Brak biblioteki: Interp4Fly.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Fly,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Fly = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd_Fly();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  dlclose(pLibHnd_Fly);
}
