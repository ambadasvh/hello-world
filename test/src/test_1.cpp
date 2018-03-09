#include <test.h>

std::string& logStmt(e_Log aLog) {
    static std::string ret;

    switch(aLog) {
        case LOG_OK: {
            ret.assign("Execution OK");
            break;
        }
        case LOG_FAIL: {
            ret.assign("Execution Fail");
            break;
        }
        case LOG_INVALID:
        default: {
            ret.assign("Execution Invalid");
            break;
        }
    }

    return ret;
}
