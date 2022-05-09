#include <iostream>
#include <vector>
#include "thread_config.h"

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif

int main()
{
    std::cout << "hello world" << std::endl;
    std::cout << "Vsersion " << thread_test_VERSION_MAJOR << "." 
                << thread_test_VERSION_MINOR << std::endl; 

    std::vector<int> vec = {2,3,4,5};
    for (auto& item : vec)
    {
        std::cout << item << std::endl;
    }

    std::cout << std::stod("10") << std::endl;

#ifdef USE_MYMATH
    std::cout << mysqrt(99) << std::endl;
#else
    
#endif
    
    return 0;
}