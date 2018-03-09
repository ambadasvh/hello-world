#ifndef _TEST_H_
#define _TEST_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

typedef enum {
    LOG_OK = 1,
    LOG_FAIL,
    LOG_INVALID,
} e_Log;


#define DebugLog(a) {\
    std::cout << "\n" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ":" << logStmt(a) << "\n";\
}

class TestClass {
    public:
        //Getters
        const char * GetMsg() { return msg.c_str(); };
        
        //Setters
        void SetMsg(const char * aMsg) {
            msg.erase();
            msg.assign(aMsg);
        };
    
    private:
        std::string msg;
};

std::string& logStmt(e_Log aLog);

#endif
