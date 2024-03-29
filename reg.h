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
		std::cout <<std::endl<< "\t\t\t\t input last name :";
		std::cin >> l_name;
		
		std::string namefile = f_name +"_"+ l_name + ".doc";
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

		std::ifstream in_v("qvestion.txt"); // окрываем файл для чтения
		if (in_v.is_open())
		{
			while (std::getline(in_v, line_v))
			{
				std::cout << line_v << std::endl;
				voprosy.push_back(line_v);
			}
		}
		in_v.close();

		std::ifstream in_o("otvety.txt"); // окрываем файл для чтения
		if (in_o.is_open())
		{
			while (std::getline(in_o, line_o))
			{
				std::cout << line_o << std::endl;
				otvet.push_back(line_o);
			}

		}
		in_o.close();
		system("pause");
	}
};
