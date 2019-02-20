#include <iostream>

#include "Generator/accomodation.h"

int main()
{
    Generator::Accomodation generator(4, 2);
    for(size_t i = 0 ; i < generator.count(); ++i)
    {
        std::vector<uint> current = generator.next();
        for(auto item : current)
            std::cout << item << ' ';
        std::cout << std::endl;
    }

    return 0;
}
