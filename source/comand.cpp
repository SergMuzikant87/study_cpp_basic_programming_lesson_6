
#include "comand.h"
#include "counter.h"

#include <string>
#include <iostream>

Command::Command(void)
{
    std::string input_text;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите \'да\' или \'нет\': ";
    std::cin >> input_text;
    
    if(input_text == "да")
    {
        uint32_t cnt_default {};
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> cnt_default;
        __counter = new Counter(cnt_default);
    }
    else
    {   if(input_text != "нет")
        {
            std::cout << "Введён некорректный текст. Для счётчика оставляем значение по умолчанию: ";
        }
        __counter = new Counter();
    } 
}

Command::~Command(void)
{
    delete __counter;
}

Command::Command(const Command & command)
{
    __counter = new Counter(command.__counter->get());
}

Command & Command::operator= (const Command & command)
{
    if((&command) != this)
    {
        delete __counter;
        __counter = new Counter(command.__counter->get());
    }
    return *this;
}

void Command::run(void)
{
    char command {UNKNOWN};
    while(command != STOP)
    {
        std::cout << "Введите команду: ( \'" << INC << "\', \'" << DEC << "\', \'" << READ << "\', \'" << STOP << "\'): ";
        std::cin >> command;
        switch(command)
        {
            case INC: 
                if(__counter->inc() == COUNTER_OVERFLOW)
                {
                    std::cout << "Счётчик переполнился.\n";
                } 
                break;
            case DEC: 
                if(__counter->dec() == COUNTER_OVERFLOW)
                {
                    std::cout << "Счётчик переполнился.\n";
                } 
                break;
            case READ: 
                std::cout << __counter->get() << std::endl; 
                break;
            case STOP: 
                std::cout << "До свидания!" << std::endl; 
                break;

            default: 
                std::cout << "Введена некорректная команда." << std::endl;
                command = UNKNOWN;
        }
    }
}