// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
int main()
{
	int punkt = 0;
	static DCB dcb;
	static HANDLE hNumPort;
	static char lpBuffor_read[4], lpBuffor_write[4];
	static DWORD RS_ile;

	hNumPort = CreateFile(L"COM8", GENERIC_WRITE |
		GENERIC_READ, 0, NULL,
		OPEN_EXISTING, 0, NULL);
	dcb.DCBlength = sizeof(dcb);

	dcb.BaudRate = CBR_9600;
	dcb.fParity = FALSE;
	
	dcb.StopBits = ONESTOPBIT;
	dcb.ByteSize = 8;

	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;

	dcb.fOutxCtsFlow = FALSE;
	dcb.fOutxDsrFlow = FALSE;
	dcb.fDsrSensitivity = FALSE;
	dcb.fAbortOnError = FALSE;
	dcb.fOutX = FALSE;
	dcb.fInX = FALSE;
	dcb.fErrorChar = FALSE;
	dcb.fNull = FALSE;

	SetCommState(hNumPort, &dcb);
	while (1)
	{
		if (!ReadFile(hNumPort, lpBuffor_read, 4, &RS_ile, 0))
		{
			std::cout << "BLAD";
		}
		else
		{
			if (lpBuffor_read[0] == 'K')
			{
				punkt++;
				std::cout << "TRAFIONE, Liczba pkt: " << punkt << std::endl;
				
				
			}
			else
			{
				std::cout << "Nietrafione" << std::endl;

			}
		}

	}
	CloseHandle(hNumPort);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
