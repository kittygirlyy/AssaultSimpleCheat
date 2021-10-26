#include <iostream>
#include <Windows.h>
#include <assert.h>


int main() 
{

	HWND fenetre{ FindWindow(0, "AssaultCube") };
	if (!fenetre)
	{
		std::cout << u8"ça ne marche pas" << std::endl;
	} else {
		std::cout << u8"ça marche (1)";
		DWORD pId;
		GetWindowThreadProcessId(fenetre, &pId);
		HANDLE pH{ OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId) };
		if (!pH)
		{
			std::cout << u8"ça ne marche pas (2)" << std::endl;
		} else {
			std::cout << u8"ça marche (2)";
			DWORD data{ 999100 };
			DWORD data2{ sizeof(data) };
			if (WriteProcessMemory(pH, (LPVOID)0x00DEA420, &data, data2, NULL)) {
				std::cout << u8"Memoire modifié avec succés" << std::endl;
			} else {
				std::cout << u8"Erreur lors de la modification";
			}
			CloseHandle(pH);
		}
	}

	std::cin.ignore();
	return 0;

}