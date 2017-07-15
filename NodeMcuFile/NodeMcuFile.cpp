#include "NodeMcuFile.h"

void NodeMcuFile::start()
{
	SPIFFS.begin();
}

bool NodeMcuFile::readFile(String fName_A, String& buf_A)
{
	bool res = false;

	File f = SPIFFS.open(fName_A, "r");

	if (f) 
	{
		buf_A = f.readStringUntil('\n');

		Serial.print("file read: ");
		Serial.println(buf_A);
		f.close();
		res = true;
	}
	else
	{
		Serial.println(fName_A);
		Serial.println("file open failed");  
	}

	return res;
}

bool NodeMcuFile::saveFile(String fName_A, String buf_A)
{
	bool res = false;
	File f = SPIFFS.open(fName_A, "w+");
	if (f) 
	{
		f.print(buf_A);
		f.close();
		res = true;
	}
	else
	{
		Serial.println(fName_A);
		Serial.println("file open failed");
	}

	return res;
}

