#ifndef _VINTAGE_PORT_H
#define _VINTAGE_PORT_H

#include "port.h"

class VintagePort : public Port { // style always == "vintage"
private:
    std::string m_nickname; // like "The Noble", "Old Velvet", etc.
    std::size_t m_year; // year of bottling

    std::ostream& print(std::ostream& os) const; //Need this method to call correct ostream overloading by Base pointer
    
public:
    VintagePort();
    VintagePort(const char* brand, std::size_t bottles, const char* nickname, std::size_t year);
    VintagePort(const std::string& brand, std::size_t bottles, const std::string& nickname, std::size_t year);
    VintagePort(const VintagePort& vp);
    virtual ~VintagePort() override;

    VintagePort& operator = (const VintagePort& vp);
    virtual void Show() const override;
    friend std::ostream& operator << (std::ostream& os, const VintagePort& vp);
    
    static constexpr char const* type = "vintage";
};

#endif