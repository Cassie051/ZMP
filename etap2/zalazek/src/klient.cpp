//
// Created by kasia on 26.11.2020.
//

#include "klient.h"


void Fun_CommunicationThread(Sender  *pSender)
{
    pSender->Watching_and_Sending();
}


/*!
 * Otwiera połączenie sieciowe
 * \param[out]  rSocket - deskryptor gniazda, poprzez które może być
 *                        realizowana komunikacja sieciowa.
 */
bool OpenConnection(int &rSocket)
{
    struct sockaddr_in  DaneAdSerw;

    bzero((char *)&DaneAdSerw,sizeof(DaneAdSerw));

    DaneAdSerw.sin_family = AF_INET;
    DaneAdSerw.sin_addr.s_addr = inet_addr("127.0.0.1");
    DaneAdSerw.sin_port = htons(PORT);


    rSocket = socket(AF_INET,SOCK_STREAM,0);

    if (rSocket < 0) {
        std::cerr << "*** Blad otwarcia gniazda." << std::endl;
        return false;
    }

    if (connect(rSocket,(struct sockaddr*)&DaneAdSerw,sizeof(DaneAdSerw)) < 0)
    {
        std::cerr << "*** Brak mozliwosci polaczenia do portu: " << PORT << std::endl;
        return false;
    }
    return true;
}


bool ExecCmd(MobileObj *pObj, AccessControl  *pAccCtrl)
{
    bool Changed;

    while (true) {
        pAccCtrl->LockAccess(); // Zamykamy dostęp do sceny, gdy wykonujemy
        // modyfikacje na obiekcie.
        if (!(Changed = pObj->IncStateIndex())) { pAccCtrl->UnlockAccess();  break; }
        pAccCtrl->MarkChange();
        pAccCtrl->UnlockAccess();
        usleep(300000);
    }
    return true;
}


int Exec(Scene &Scn)
{
    std::cout << "Port: " << PORT << std::endl;
    int                 Socket4Sending;

    if (!OpenConnection(Socket4Sending)) return 1;

    Sender   ClientSender(Socket4Sending,&Scn);
    //  thread   Thread4Sending(Fun_Sender, Socket4Sending, &ClientSender);

    std::thread   Thread4Sending(Fun_CommunicationThread,&ClientSender);

    for (std::shared_ptr<MobileObj> rObj : Scn.GetObjs()) {
        usleep(20000);
        ExecCmd(rObj.get(),&Scn);
        Scn.MarkChange();
        usleep(100000);
    }
    usleep(100000);

    //-------------------------------------
    // Należy pamiętać o zamknięciu połączenia.
    // Bez tego serwer nie będzie reagował na
    // nowe połączenia.
    //
    std::cout << "Close\n" << std::endl; // To tylko, aby pokazac wysylana instrukcje
    ClientSender.Send(Socket4Sending,"Close\n");
    ClientSender.CancelCountinueLooping();
    Thread4Sending.join();
    close(Socket4Sending);
    return 0;
}
