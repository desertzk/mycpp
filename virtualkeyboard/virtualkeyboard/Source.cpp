#include <windows.h>

void SetNumLock(BOOL bState)
{
	BYTE keyState[256];

	GetKeyboardState((LPBYTE)&keyState);
	if ((bState && !(keyState[VK_NUMLOCK] & 1)) ||
		(!bState && (keyState[VK_NUMLOCK] & 1)))
	{
		// Simulate a key press
		keybd_event(VK_NUMLOCK,
			0x45,
			KEYEVENTF_EXTENDEDKEY | 0,
			0);

		// Simulate a key release
		keybd_event(VK_NUMLOCK,
			0x45,
			KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
			0);
	}
}


void SetF5(BOOL bState)
{
	/*BYTE keyState[256];

	GetKeyboardState((LPBYTE)&keyState);*/
	
	// Simulate a key press
	keybd_event(VK_F5,
		0x45,
		KEYEVENTF_EXTENDEDKEY | 0,
		0);

	// Simulate a key release
	keybd_event(VK_F5,
		0x45,
		KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
		0);
	
}


void main()
{
	//SetNumLock(TRUE);
	while (true)
	{
		SetF5(TRUE);
		Sleep(5*60*1000);
	}
	
}