//
// Created by kasia on 26.11.2020.
//

#include "Sender.h"

Sender::Sender(int Socket, Scene *pScn): _Socket(Socket), _pScn(pScn) {}

    bool Sender::ShouldCountinueLooping() { return _ContinueLooping; }
    /*!
     * \brief Powoduje przerwanie działania pętli wątku.
     *
     * Powoduje przerwanie działania pętli wątku.
     * \warning Reakcja na tę operację nie będize natychmiastowa.
     */
    void Sender::CancelCountinueLooping() { _ContinueLooping = false; }

    /*!
     * \brief Ta metoda jest de facto treścią wątku komunikacyjnego
     *
     * Przegląda scenę i tworzy odpowiednie polecenia, a następnie
     * wysyła je do serwera.
     * \param[in] Socket - deskryptor gniazda sieciowego, poprzez które
     *                     wysyłane są polecenia.
     */
    void Sender::Watching_and_Sending() {
        while (ShouldCountinueLooping()) {
            if (!_pScn->IsChanged())  { usleep(10000); continue; }
            _pScn->LockAccess();

            //------- Przeglądanie tej kolekcji to uproszczony przykład

            Send(_Socket,"Clear\n"); // To jest konieczne, aby usunąć wcześniejsze obiekty.
            std::cout << "Clear\n";
//            for (const MobileObj &rObj : _pScn->_Container4Objects) {
//                // Ta instrukcja to tylko uproszczony przykład
//                std::cout << rObj.GetStateDesc();
//                Send(_Socket,rObj.GetStateDesc()); // Tu musi zostać wywołanie odpowiedniej
//                // metody/funkcji gerującej polecenia dla serwera.
//            }
            Send(_Socket,"Display\n"); // To jest konieczne, aby zobaczyć zmiany
            std::cout << "Display\n";

            _pScn->CancelChange();
            _pScn->UnlockAccess();
        }
    }
    int Sender::Send(int Sk2Server, const char *sMesg)
    {
        ssize_t  IlWyslanych;
        ssize_t  IlDoWyslania = (ssize_t) strlen(sMesg);

        while ((IlWyslanych = write(Sk2Server,sMesg,IlDoWyslania)) > 0) {
            IlDoWyslania -= IlWyslanych;
            sMesg += IlWyslanych;
        }
        if (IlWyslanych < 0) {
            std::cerr << "*** Blad przeslania napisu." << std::endl;
        }
        return 0;
    }
