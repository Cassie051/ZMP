#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

#define LINE_SIZE 500

bool ExecPreprocesor( const char * NazwaPliku, std::istringstream &IStrm4Cmds )
{
    std::string Cmd4Preproc = "cpp -P ";
    char Line[LINE_SIZE];
    std::ostringstream OTmpStrm;
    Cmd4Preproc += NazwaPliku;
    FILE* pProc = popen(Cmd4Preproc.c_str(),"r");
    if (!pProc) return false;
    while (fgets(Line,LINE_SIZE,pProc)) {
        OTmpStrm << Line;
    }
    IStrm4Cmds.str(OTmpStrm.str());
    return pclose(pProc) == 0;
}

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "Too few arguments\n";
        return 1;
    }

    std::istringstream IStrm4Cmds;

    if(!ExecPreprocesor(argv[1], IStrm4Cmds))
    {
        std::cerr<< "Cannot process\n";
        return 2;
    }

    std::cout << IStrm4Cmds.str() << "\n";
    return 0;
}
