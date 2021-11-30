#include <string>
#include <iostream>

//using namespace std;
using hello = double;

int main() {
    hello hello2(4), hello3(5), hello4(0);
    std::string hello;

    hello4 = hello2+hello3;

    hello = "why?";

    std::cout << hello << " " << hello4 << std::endl;
}