#include "Computer.h"
#include <random>
#include <sstream>

std::string generateIPAddress() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 255);

    std::ostringstream oss;
    oss << dis(gen) << '.' << dis(gen) << '.' << dis(gen) << '.' << dis(gen);
    return oss.str();
}

Computer::Computer():
    m_IPAdress{ generateIPAddress() }
{

}

const std::string Computer::GetIP() const
{
    return m_IPAdress;
}

std::string Computer::GetBuffer() const
{
    return m_buffer;
}

void Computer::SetBuffer(const std::string& message)
{
    m_buffer = message;
}
