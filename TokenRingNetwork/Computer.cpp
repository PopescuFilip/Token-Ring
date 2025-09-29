#include "Computer.h"
#include "Random.h"
#include <sstream>

namespace tokenRingNetwork
{
    int Computer::sCounter = 0;

    std::string static GenerateIPAddress()
    {
        std::ostringstream oss;
        oss << GetRandom(0, 255) << '.'
            << GetRandom(0, 255) << '.'
            << GetRandom(0, 255) << '.'
            << GetRandom(0, 255);
        return oss.str();
    }

    Computer::Computer() :
        kIPAdress{ GenerateIPAddress() },
        kName{ 'C' + std::to_string(sCounter++) }
    {
        sCounter++;
    }

    std::string Computer::GetBuffer() const
    {
        return m_buffer == "" ? "null" : m_buffer;
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
}