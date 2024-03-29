#pragma once

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "reg.h"
void meny(user reg)
{
    int count = 0;
    int getch();
    std::string ukaz[3] = { "=>"," "," " };
    char x;
    while (true)
    {
        for (int i = 0; i < ukaz->size()+1; i++)
        {
            if (i == count)ukaz[i] = "=>";
            else ukaz[i] = "  ";
        }

        std::cout << "\n\n\n\n\t\t\t\t" << ukaz[0] << "registreyschn " << std::endl;
        std::cout << "\t\t\t\t" << ukaz[1] << "test " << std::endl;
        std::cout << "\t\t\t\t" << ukaz[2] << "exit " << std::endl;
        x = 0;

        x = getch();

        if (x == 72)
        {
            if (count == 0 ) count = 2;
            else count -= 1;
        }


   
    if (x == 80)
    {
        if (count == 2) count = 0;
        else count += 1;
    }
    if (count == 0 && x == '\r')
    {
        system("cls");
        reg.uuser();//регистрация экзаменуемого и 
                    //создание фаило с его именем и фамилией
        
    }
    if (count == 1 && x == '\r')
    {
        system("cls");
        reg.test();
       
    }
    if (count == 2 && x == '\r')
    {
        
        break;

    }
    system("cls");
    }

}

