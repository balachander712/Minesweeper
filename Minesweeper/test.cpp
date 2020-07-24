#include <iostream>
#include <ctime>
#include <string>

int main()
{

    time_t now = time(0);
    char* str = ctime(&now);
    std::cout << str;

    return 0;
}
