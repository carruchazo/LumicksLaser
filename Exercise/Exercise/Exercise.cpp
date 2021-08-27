// Exercise.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "CLaserController.h"
#include "CCommandInterpreter.h"

using namespace std;
using namespace NS_Laser_Controller;

int main()
{
    CLaserController controller;
    CCommandInterpreter interpreter;
    interpreter.SetPointerToLaserController(&controller);

    // runs indefinitely
    while (true)
    {
        string next;
        cin >> next;
        cout << interpreter.ParseCommand(next);
    }
}

