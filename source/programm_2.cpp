#include "comand.h"
#include <iostream>
#include <clocale>

int main(int argc, char * argv[])
{
    setlocale(LC_ALL, "Russian");

    Command command;
    command.run();

    return 0;
}
