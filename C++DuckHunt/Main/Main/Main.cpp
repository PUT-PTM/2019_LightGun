// Arkanoid.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Square.h"

#include<algorithm>
#include<iostream>
#include<conio.h>

#include<Windows.h>
using namespace sf;
using namespace std;

template <class T1, class T2> bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

int main()
{
	static DCB dcb;
	static HANDLE hNumPort;
	static char lpBuffor_read[1], lpBuffor_write[1];
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
	RenderWindow window{ VideoMode{800,600}, "Prototyp" };
	window.setFramerateLimit(60);
	Sprite sprite;
	Texture texture;
	texture.loadFromFile("black.jpg");
	sprite.setTexture(texture);

	while(true)
	{
		Square square(600, 600);
		while (window.isOpen())
		{
			window.draw(sprite);
			window.draw(square);
			square.update();
			window.display();

		}
		
		
	
	}
	return 0;
}