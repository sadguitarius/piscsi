//---------------------------------------------------------------------------
//
// SCSI Target Emulator RaSCSI (*^..^*)
// for Raspberry Pi
//
// Copyright (C) 2022 Uwe Seimet
//
// Host Services with realtime clock and shutdown support
//
//---------------------------------------------------------------------------
#pragma once

#include "mode_page_device.h"

using namespace std;

class HostServices: public ModePageDevice
{

public:

	HostServices();
	~HostServices() {}

	virtual bool Dispatch(SCSIDEV *) override;

	int Inquiry(const DWORD *, BYTE *) override;
	void TestUnitReady(SCSIDEV *);
	void StartStopUnit(SCSIDEV *);

	int ModeSense6(const DWORD *, BYTE *);
	int ModeSense10(const DWORD *, BYTE *);

private:

	typedef ModePageDevice super;

	Dispatcher<HostServices, SCSIDEV> dispatcher;

	int AddRealtimeClockPage(int, BYTE *);
};