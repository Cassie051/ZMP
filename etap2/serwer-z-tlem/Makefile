NAZWA_APLIKACJI=serwer_graficzny
URUCHOMIENIE_APLIKACJI=./${NAZWA_APLIKACJI}
ZRODLA_PROJEKTU=`/bin/pwd`/src/*.cpp `/bin/pwd`/inc/*.hh
PODSTAWIENIA=OBJECTS_DIR=${KATALOG_OBJ} INCLUDEPATH=inc\
             MOC_DIR=${KATALOG_MOC}\
             QT+=widgets\
             QT+=opengl QT+=xml\
             LIBS+=-lQGLViewer-qt5 LIBS+=-lSOIL
KATALOG_OBJ=./out/obj
KATALOG_MOC=./out/moc
KATALOG_PRO=./out/pro


__start__: __lines__ __sprawdz_Qt__ ${NAZWA_APLIKACJI}
	rm -f core*; ${URUCHOMIENIE_APLIKACJI}

__lines__:
	@echo
	@echo
	@echo
	@echo
	@echo
	@echo



__sprawdz_Qt__: __sprawdz_qmake__
	@if qmake -v | grep 'ver.*5\.[0-9]*\.[0-9]*' > /dev/null;\
         then exit 0;\
         else echo; echo " Brak biblioteki Qt w wersji 5.x.x";\
              echo;  exit 1;\
        fi

__sprawdz_qmake__:
	@if which qmake > /dev/null; then exit 0;\
        else\
          echo; echo " Brak programu qmake."\
               " Prawdopodobnie biblioteka Qt nie zostala zainstalowana.";\
          echo; exit 1;\
        fi


${NAZWA_APLIKACJI}: Makefile.app __sprawdz__

__sprawdz__:
	make -f Makefile.app

Makefile.app: Makefile ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro
	qmake -o Makefile.app ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro: Makefile
	rm -f ${NAZWA_APLIKACJI}
	rm -rf out
	qmake -project -nopwd -o ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro\
               ${PODSTAWIENIA} ${ZRODLA_PROJEKTU} 

project: __usun_pro__ ${KATALOG_PRO}/${NAZWA_APLIKACJI}.pro

__usun_pro__:
	rm -fr ${KATALOG_PRO}/

clean:
	make -f Makefile.app clean

cleanall: clean
	rm -f ${NAZWA_APLIKACJI}

cleantotally: cleanall
	rm -f  Makefile.app
	rm -rf out
	find . -name \*~ -exec rm {} \;
	find . -name \*.tex -exec rm {} \;

help:
	@echo "Podcele:"
	@echo 
	@echo " project  - wymusza utworzenie nowego projektu"
	@echo " clean    - usuwa wszystkie produkty kompilacji i konsolidacji"
	@echo " cleanall - usuwa produkty kompilacji wraz z aplikacja"
	@echo " cleantotally - usuwa wszystko oprocz zrodel i pliku Makefile"
	@echo " help     - wyswietla niniejszy pomoc"
	@echo
