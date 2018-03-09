#include <test.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
	{
        std::cout << "\nUsage: ./test \"Enter Message\"\n";
        DebugLog(LOG_INVALID);
        return 0;
    }
    
	const char *no_str = "";

	if( (argv[1] == NULL) ||
		(!strncmp(no_str, argv[1], 1)) )
	{
		DebugLog(LOG_FAIL);
        return 0;
    }

    TestClass tObj;
    tObj.SetMsg(argv[1]);
    std::cout << tObj.GetMsg();
    
    DebugLog(LOG_OK);

    return 0;
}
