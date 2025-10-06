#include <sstream>

#include "Computer.h"
#include "Constants.h"
#include "Random.h"

namespace tokenRingNetwork
{
    int Computer::sCounter = 0;

    std::string static GenerateIPAddress()
    {
        std::ostringstream oss;
        oss << GetRandom(0, 255) << constants::Point
            << GetRandom(0, 255) << constants::Point
            << GetRandom(0, 255) << constants::Point
            << GetRandom(0, 255);
        return oss.str();
    }

    Computer::Computer() :
        kIPAdress{ GenerateIPAddress() },
        kName{ constants::C + std::to_string(sCounter++) }
    {}

    std::string Computer::GetBuffer() const
    {
        return m_buffer == std::string{} ? kEmptyBufferMessage : m_buffer;
    }

    void Computer::AddToBuffer(const std::string& message)
    {
        m_buffer += message + constants::Semicolon;
    }

    std::ostream& operator<<(std::ostream& os, const Computer& c)
    {
        os << c.GetName() << constants::OpenParenthesis
           << c.GetAdress() << constants::ClosedParenthesis << constants::Arrow
           << c.GetBuffer();
        return os;
    }
}