#include <cstring>
#include <fstream>

#include "ZBrush_lib_template.hpp"


#define EXPORT __attribute__((visibility("default")))

// a sample exported function
EXPORT
float Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
              char* pOptBuffer2, int optBuffer2Size, char** zData)
{
    return 1.0f;
}

EXPORT
float HelloLib(char* textFromZBrush, double valueFromZBrush, char* pOptBuffer1, int optBuffer1Size,
               char* pOptBuffer2, int optBuffer2Size, char** zData)
{
    strcpy(pOptBuffer1, "Hello from my Lib file.");

    return 0.0f;
}

EXPORT
float SaveMemStringToFile(char* textFromZBrush, double valueFromZBrush, char* pOptBuffer1,
                          int optBuffer1Size, char* pOptBuffer2, int optBuffer2Size, char** zData)
{

    const char* fileName = "/Users/Shared/Pixologic/temp.txt";
    std::ofstream ofs(fileName);

    if (!ofs) {
        return 1.0f;
    }

    int count = static_cast<int>(valueFromZBrush);

    for (int i=0; i<count; i++) {
        const char c = pOptBuffer1[i];
        if (c == ':') {
            ofs << std::endl;
        } else {
            ofs << c;
        }
    }

    ofs.close();

    return 0.0f;
}
