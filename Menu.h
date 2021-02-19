#pragma once

enum Comands{ OPEN = 0, SHOW, EXIT, STOP };
enum Modes { START = 0, MENU, PAUSE };

void ShowMenu(int MenuPointer);

class Menu
{
public:
	Menu(bool &ProgWork, Modes d);
	void Action();
	void Input();
	~Menu();
private:
	bool &ProgramWork;
	bool File_selected = false;

	int MenuPointer;

	Comands dir = STOP;
	Modes mode;

	char *FileName;
};

