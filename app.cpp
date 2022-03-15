#include <iostream>

#include "app.hpp"
#include "mat.hpp"

/**
 * @brief A function for cleaning the screen for any major OS shwon here ttps://stackoverflow.com/questions/6486289/how-can-i-clear-console
 */
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void App::showAddScreen(){
    Clear(); // claers the consle

    Carpet carpet;

    std::cout << "Enter the number of columns: ";
    std::cin >> carpet.columns;
    std::cout << "Enter the number of rows: ";
    std::cin >> carpet.rows;
    std::cout << "Enter first symbol: ";
    std::cin >> carpet.sym1;
    std::cout << "Enter second symbol: " << std::endl;
    std::cin >> carpet.sym2;

    try{                                         //try to print the mat, if throws an error discard.
        std::cout << ariel::mat(carpet.columns,
                                carpet.rows,
                                carpet.sym1,
                                carpet.sym2);
    }catch(std::invalid_argument e){
        std::cout << "You can't add this mat becuse: " << e.what() << "\n";
        return;
    }

    carpets.push_back(carpet);
}
void App::showViewScreen(){
    Clear();
    for(Carpet carpet : carpets){
        std::cout << ariel::mat(carpet.columns,
                                carpet.rows,
                                carpet.sym1,
                                carpet.sym2);
        std::cout<< "------------------------------------------------";
    }
}

void App::showScreen(){
    int selectedOption = 0;
    while(selectedOption != STATE::EXIT){
        std::cout << "Enter your option:\n"
                  << "1. Add Mat\n"
                  << "2. View Mats\n"
                  << "3. Exit\n>";

        std::cin >> selectedOption;

        switch (selectedOption)
        {
        case STATE::ADD:
            showAddScreen();
            break;
        case STATE::VIEW:
            showViewScreen();
            break;
        default:
            selectedOption = STATE::EXIT;
            break;
        }
    }
}
