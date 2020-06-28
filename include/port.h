#ifndef _PORT_H
#define _PORT_H

#include <iostream>
#include <cstddef>
#include <string>
#include <cstring>

class Port {

private:
    std::string m_brand;
    std::string m_style; // e.g. tawny, ruby, vintage
    std::size_t m_bottles;

    virtual std::ostream& print(std::ostream& os) const; //Need this method to call correct ostream overloading by Base pointer

public:
    Port(const char* brand = "none", const char* style = "none", std::size_t bottles = 0);
    Port(const std::string& brand = "none", const std::string& style = "none", std::size_t bottles = 0);
    Port(const Port& p);
    virtual ~Port();

    Port& operator= (const Port & p);
    Port& operator+= (std::size_t b) ; // adds b to bottles
    Port& operator-= (std::size_t b); // subtracts b from bottles, if possible

    std::size_t BottleCount() const;
    virtual void Show() const;
    friend std::ostream& operator << (std::ostream& os, const Port& p);

    static const std::size_t maxStyleLength = 20;
};

#endif