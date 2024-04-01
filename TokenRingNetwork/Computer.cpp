#include "Computer.h"
#include <random>
#include <sstream>

int Computer::sCounter = 0;

std::string generateIPAddress() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 255);

    std::ostringstream oss;
    oss << dis(gen) << '.' << dis(gen) << '.' << dis(gen) << '.' << dis(gen);
    return oss.str();
}

Computer::Computer():
    kNumber{ sCounter },
    kIPAdress{ generateIPAddress() }
{
    sCounter++;
}

std::string Computer::GetBuffer() const
{
    if (m_buffer == "")
        return "null";
    return m_buffer;
}

void Computer::SetBuffer(const std::string& message)
{
    m_buffer = message;
}

std::ostream& operator<<(std::ostream& os, const Computer& c)
{
    os << "C" << c.kNumber << "(" << c.kIPAdress << ") -> " << c.GetBuffer();
    return os;
}
