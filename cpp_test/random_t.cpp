#include <cstddef>
#include <iostream>
#include <random>


int main()
{
    std::default_random_engine e;
    //std::uniform_int_distribution<int> u(1,9); 
    std::uniform_real_distribution<float>u(1,50);
    for(size_t i=0;i<10;i++) std::cout<<u(e)<<std::endl;

    return 0;
}