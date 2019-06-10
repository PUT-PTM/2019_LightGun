# 2019_LightGun
Overwiew - this is a project of a video game accessory called Lightgun. It gives abbility to shoot virtual enemies with real gun. 

Description - this project uses STM32 microcontroller with proper software and two PC applications. On PC one application is used to receive data from Bluetooth port and the other one is a simple C++ game which works on the same basis as well known Duck Hunt game. In this project we used a microcontroller STM32 f4-discovery, a Bluetooth transmitter HC-05 v2, a PC with Windows operating system, a photoresistor and 6.2k Ohm resistor. We uses these resistors to make a voltage divider. When there is enough light on photoresistor it allows voltage to pass.  When we click the user button on microcontroller it checks whether we aimed the white square (our goal). other way black screen of monitor doesn't give enough light to pass voltage through voltage divider. Microcontroler anylsis output voltage and when it's bigger than 800 it sends via bluetooth KILL. Otherway it sends MISS. Then, this message is received on PC and the result is changed. 

Tools - Visual Studio 2017 - game and receiver app, both in C++,
	STM32Cube
	eclipse

How to run - it is a 1.0 release version, we need a power supply to STM32 microcontroller, then we have to connect with our Bluetooth transmitter and run exe files. 

How to compile - if there is included SFML Library in Visual Studio, copying only is required.  

Future improvements - multithreading, make game and reciver as one app, no bugs.																																											
Attributions - https://www.xanthium.in/Serial-Port-Programming-using-Win32-API

License - MIT

Credits - Michał Czub/Marcin Kubiak/Jakub Pogodziński

The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology.
Supervisor: Marek Kraft/Michał Fularz/Tomasz Mańkowski/Adam Bondyra
