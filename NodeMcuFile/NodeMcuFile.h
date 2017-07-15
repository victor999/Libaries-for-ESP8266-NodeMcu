#include <FS.h>

class NodeMcuFile
{
public:
	void start();
	bool readFile(String fName_A, String& buf_A);
	bool saveFile(String fName_A, String buf_A);

};