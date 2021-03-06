
#pragma once

#include <cstdint>

class DebugCore;

class Breakpoint
{
public:
    Breakpoint(DebugCore* debugCore);
	~Breakpoint();
    Breakpoint(const Breakpoint&) = delete;
    Breakpoint(Breakpoint&&) = delete;

    uint64_t address() const
    {
        return m_address;
    }

	void setAddress(uint64_t address)
	{
		m_address = address;
	}

    uint8_t orgByte() const
    {
        return m_orgByte;
    }

	void setOrgByte(uint8_t orgByte)
	{
		m_orgByte = orgByte;
	}

    bool enabled() const
    {
        return m_enabled;
    }

    bool setEnabled(bool enabled);

    bool isHardware() const
    {
        return m_isHardware;
    }

	bool isOneTime()
	{
		return m_oneTime;
	}

	void setOneTime(bool oneTime)
	{
		m_oneTime = oneTime;
	}

	static const uint8_t bpData;
private:
    uint64_t m_address = 0;
    uint8_t m_orgByte = 0;
    bool m_enabled = false;
    bool m_isHardware = false;
    bool m_oneTime = false;

    DebugCore* m_debugCore;
};

