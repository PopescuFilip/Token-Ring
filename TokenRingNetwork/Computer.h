#pragma once

#include<string>

namespace tokenRingNetwork
{
    class Computer
    {
    public:
        Computer();

        std::string GetAdress() const { return kIPAdress; }
        std::string GetName() const { return kName; }
        std::string GetBuffer() const;

        void AddToBuffer(const std::string& message);

    private:
        const std::string kIPAdress;
        const std::string kName;

        static int sCounter;

    private:
        std::string m_buffer;

    };
    std::ostream& operator<<(std::ostream& os, const Computer& c);
}