#include "vintage_port.h"

void clear(Port** p, std::size_t SIZE)
{
    for(auto i = 0; i < SIZE; ++i)
    {
        delete p[i];
    }
}

int main(int argc, char** argv)
{
    const std::size_t SIZE = 10;
    
    Port* pPorts[SIZE];

    for(auto i = 0; i < SIZE; ++i)
    {
        if(i % 2)
        {
            pPorts[i] = new Port("PortBrand", "ruby", i);
        }
        else
        {
            pPorts[i] = new VintagePort("VintagePortBrand", i*SIZE, "VPName", 1000 + i);
        }
        (*pPorts[i]).Show();        
    }

    std::cout << "Base: " << *(pPorts[3]) << std::endl
              << "Derived: " << *(pPorts[4]) << std::endl;

    *(pPorts[3]) += 10;
    *(pPorts[3]) -= 5;

    std::cout << "Base: " << *(pPorts[3]) << std::endl;


    /* Stil cannot understand why it's impossible to convert it like that:
     * vp = *(pPorts[4])
     * typeid(*(pPorts[4])).name() tells that it's VintagePort class value
     * but conversion is not applicable because of missing VintagePort = Port operator */

    VintagePort vp;
    vp = *(dynamic_cast<VintagePort*>(pPorts[4]));
    std::cout << "Derived: " << vp << std::endl;

    Port p = *(pPorts[3]);
    std::cout << p << std::endl;

    clear(pPorts, SIZE);

    return 0;
}