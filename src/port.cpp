#include "port.h"

Port::Port(const char* brand, const char* style, std::size_t bottles) : m_brand(brand),
                                                                        m_bottles(bottles)
{
    strlen(style) > maxStyleLength ? m_style = "size overflow" : m_style = style;
}
Port::Port(const std::string& brand, const std::string& style, std::size_t bottles) : m_brand(brand),
                                                                                      m_bottles(bottles)
{
    style.size() > maxStyleLength ? m_style = "size overflow" : m_style = style;
}

Port::Port(const Port& p)
{
    m_brand = p.m_brand;
    m_style = p.m_style;
    m_bottles = p.m_bottles;
}

Port::~Port(){}

Port& Port::operator = (const Port& p)
{
    if(this == &p)
    {
        return *this;
    }
    
    m_brand = p.m_brand;
    m_style = p.m_style;
    m_bottles = p.m_bottles;

    return *this;
}

Port& Port::operator += (std::size_t b)
{
    m_bottles += b;
    return *this;
}

Port& Port::operator -= (std::size_t b)
{
    m_bottles -= b;
    return *this;
}

std::size_t Port::BottleCount() const
{
    return m_bottles;
} 

void Port::Show() const
{
    std::cout << "=================\n";
    std::cout << "Brand: " << m_brand << std::endl
              << "Kind: " << m_style << std::endl
              << "Bottles: " << m_bottles << std::endl
              << "=================\n"; 
}

std::ostream& Port::print(std::ostream& os) const
{
    os << m_brand << ", " << m_style << ", " << m_bottles;
}

std::ostream& operator << (std::ostream& os, const Port& p)
{
    return p.print(os);
}