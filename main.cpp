#include <iostream>
#include <Windows.h>


int main() 
{

	HWND fenetre{ FindWindow(0, "AssaultCube") };
	if (!fenetre)
	{
		std::cout << u8"ça ne marche pas\n" << std::endl;
	} else {
		std::cout << u8"Veuillez ouvrir AssaultCube\n";
		DWORD pId;
		GetWindowThreadProcessId(fenetre, &pId);
		HANDLE pHandle{ OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId) };
		if (!pHandle)
		{
			std::cout << u8"Erreur lors de l'attachement du process\n" << std::endl;
		} else {
			std::cout << u8"Succés\n";
			DWORD data{};
			std::cout << "Veuillez choisir combien de munitions vous voulez\n";
			std::cin >> data;
			DWORD data2{ sizeof(data) };
			if (WriteProcessMemory(pHandle, (LPVOID)0x00E1A420, &data, data2, NULL)) {
				std::cout << u8"Memoire modifié avec succés\n" << std::endl;
			} else {
				std::cout << u8"Erreur lors de la modification\n";
			}
			CloseHandle(pHandle);
		}
	}


	std::cin.ignore();
	return 0;

}