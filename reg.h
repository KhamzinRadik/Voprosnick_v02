#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <fstream>

class user
{
public:
	
	std::string f_name;
	std::string l_name;
	



	void uuser()
	{
		std::cout << "\n\n\n\n\t\t\t\t input first name :";
		std::cin >> f_name;
		std::cout << std::endl << "\t\t\t\t input last name :";
		std::cin >> l_name;

		std::string namefile = f_name + "_" + l_name + ".doc";
		std::ofstream ofs(namefile, std::ios::app);

		if (ofs.is_open())
		{
			ofs << f_name << " " << l_name << std::endl << "test result :";
		}


	}

	void test()
	{

		std::string line_v , line_o;
		std::vector <std::string> voprosy, otvet;

		std::ifstream in_v("C:\\Users\\Admin\\KhamzinRadik\\KhamzinRadik\\Voprosnick_v02\\qvestion.txt"); // окрываем файл для чтения
		if (in_v.is_open())
		{
			std::cout << " file qvestion.txt open ! " << std::endl;
			while (std::getline(in_v, line_v))
			{
				std::cout << line_v << std::endl;
				voprosy.push_back(line_v);
			}
			
		}
		else {
			std::cout << " file qvestion.txt NOT open !!!" << std::endl;
		}
		in_v.close();

		std::ifstream in_o("C:\\Users\\Admin\\KhamzinRadik\\KhamzinRadik\\Voprosnick_v02\\otvety.txt"); // окрываем файл для чтения
		if (in_o.is_open())
		{
			std::cout << " file otvety.txt open ! " << std::endl;
			while (std::getline(in_o, line_o))
			{
				std::cout << line_o << std::endl;
				otvet.push_back(line_o);
			}
			
		}
		else {
			std::cout << " file otvety.txt NOT open !!!" << std::endl;
		}
		in_o.close();
		
		
		system("pause");
	}
};
