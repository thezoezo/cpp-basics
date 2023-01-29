#include <iostream>
#include <fstream>
#include <string>
#include "random_value.h"

int getRandomValue (); // объявляем функцию до использования
int main() {    

    const std::string high_scores_filename = "high_scores.txt"; // файл, в который будем записывать результат
	std::cout << "Hello! Enter your name, please:" << std::endl; 
	std::string user_name;
	std::cin >> user_name; // пользователь вводит свое имя, оно сохраняется в переменную    

	int target_value = getRandomValue (); //сохраняем в переменную результат работы функции рандомного числа

	int current_value = 0; // переменная, в которую запишем число пользователя
    int attempts = 0; // переменная для счетчика попыток   

    std::cout << "Enter your guess, please:" << std::endl;

    do { // цикл попыток
 
    std::cin >> current_value; // число пользователя
    attempts++; // увеличить счетчик попыток

    if (current_value < target_value) {
        std::cout << "more than " << current_value << std::endl; // подсказка, что загаданное число больше введенного 
    }
    else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl; // подсказка, что загаданное число меньше введенного 
		}
    else { // числа равны, выигрыш

       std::cout << "Finally you won!" << std::endl; 
       std::cout << "Your attempts: " << attempts << std::endl; // счетчик попыток = числу попыток
      
       break;
    }    
   
    } while (true);
    
    {   
		std::ofstream out_file{high_scores_filename, std::ios_base::app}; // запись в файл результата
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
			return -1;
		}

		out_file << user_name << ' ';
		out_file << attempts;
		out_file << std::endl;
    }

    {   
		std::string line;
		std::ifstream in_file{high_scores_filename}; // чтение из файла всех результатов 
		if (in_file.is_open()) {
			std::cout << "High scores table:" << std::endl;
			while (getline(in_file, line)) {
			std::cout << line << std::endl;
			}
	    }
	    
		in_file.close();
			
	}	 

return 0;

}