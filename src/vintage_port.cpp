#include "vintage_port.h"

VintagePort::VintagePort() : Port("", "", 0), m_nickname(""), m_year(0)
{
}

VintagePort::VintagePort(const char* brand, std::size_t bottles, const char* nickname, std::size_t year) : Port(brand, type, bottles),
                                                                                                           m_nickname(nickname),
                                                                                                           m_year(year)
{
}

VintagePort::VintagePort(const std::string& brand, std::size_t bottles, const std::string& nickname, std::size_t year) : Port(brand, type, bottles),
                                                                                                                        m_nickname(nickname),
                                                                                                                        m_year(year)
{
} 

VintagePort::VintagePort(const VintagePort& vp) : Port(vp),
                                                 m_nickname(vp.m_nickname),
                                                 m_year(vp.m_year)
{
}

VintagePort::~VintagePort()
{
}

VintagePort& VintagePort::operator = (const VintagePort& vp)
{
    if(this == &vp)
    {
        return *this;
    }

    Port::operator=(vp);
    m_nickname = vp.m_nickname;
    m_year = vp.m_year;

    return *this;
}

void VintagePort::Show() const
{
    Port::Show(); 
    std::cout << "Name: " << m_nickname << std::endl
              << "Year of bottling: " << m_year << std::endl;
}

std::ostream& VintagePort::print(std::ostream& os) const
{
    os << m_nickname << " ," << m_year;
}

std::ostream& operator << (std::ostream& os, const VintagePort& vp)
{
    return vp.print(os);
}