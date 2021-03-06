// license:BSD-3-Clause
// copyright-holders:Wilbert Pol
#ifndef __MSX_SLOT_RAM_H
#define __MSX_SLOT_RAM_H

#include "slot.h"

#define MCFG_MSX_SLOT_RAM_ADD(_tag, _startpage, _numpages) \
	MCFG_MSX_INTERNAL_SLOT_ADD(_tag, MSX_SLOT_RAM, _startpage, _numpages)

#define MCFG_MSX_SLOT_RAM_8KB \
	msx_slot_ram_device::force_start_address(*device, 0xe000);


class msx_slot_ram_device : public device_t,
							public msx_internal_slot_interface
{
public:
	msx_slot_ram_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	static void force_start_address(device_t &device, uint16_t start) { downcast<msx_slot_ram_device &>(device).m_start_address = start; }

	virtual void device_start() override;

	virtual DECLARE_READ8_MEMBER(read) override;
	virtual DECLARE_WRITE8_MEMBER(write) override;

private:
	std::vector<uint8_t> m_ram;
};


extern const device_type MSX_SLOT_RAM;


#endif
