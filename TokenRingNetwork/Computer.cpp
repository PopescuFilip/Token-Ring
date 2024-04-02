#include "Computer.h"
#include "Random.h"
#include <sstream>

int Computer::sCounter = 0;

std::string GenerateIPAddress() 
{
    std::ostringstream oss;
    oss << GetRandom(0, 255) << '.' << GetRandom(0, 255) << '.' << GetRandom(0, 255) << '.' << GetRandom(0, 255);
    return oss.str();
}

Computer::Computer():
    kNumber{ sCounter },
    kIPAdress{ GenerateIPAddress() }
{
    sCounter++;
}

const std::string Computer::GetAdress() const
{
    return kIPAdress;;
}

std::string Computer::GetBuffer() const
{
    if (m_buffer == "")
        return "null";
    return m_buffer;
}

std::string Computer::GetName() const
{
    return "C" + std::to_string(kNumber);
}

void Computer::AddToBuffer(const std::string& message)
{
    m_buffer += message + ';';
}

std::ostream& operator<<(std::ostream& os, const Computer& c)
{
    os << c.GetName() << "(" << c.GetAdress() << ") -> " << c.GetBuffer();
    return os;
}
