#include <iostream>
#include "Calculator.hpp"

int main()
{
    Calculator cal;
    std::cout << "cal.add(4,2) = " << cal.add(4,2) <<std::endl;
    std::cout << "cal.subtract(4,2) = " << cal.subtract(4,2) <<std::endl;
    std::cout << "cal.multiply(4,2) = " << cal.multiply(4,2)<<std::endl;
    std::cout << "cal.divide(4,2) = " << cal.divide(4,2)<<std::endl;
    return 0;
}