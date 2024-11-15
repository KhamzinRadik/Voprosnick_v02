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
    int size = ukaz->size() + 1;
    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == count)ukaz[i] = "=>";
            else ukaz[i] = "  ";
        }

        std::cout << "\n\n\n\n\t\t\t\t" << ukaz[0] << "Регистрация " << std::endl;
        std::cout << "\t\t\t\t" << ukaz[1] << "Тест " << std::endl;
        std::cout << "\t\t\t\t" << ukaz[2] << "Выход " << std::endl;
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
        
       reg.TEST();
       
    }
    if (count == 2 && x == '\r')
    {
        
        break;

    }
    system("cls");
    }

}

