#ifndef libTemplate_hpp
#define libTemplate_hpp

// how to make a dylib
// https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/DynamicLibraries/100-Articles/CreatingDynamicLibraries.html#//apple_ref/doc/uid/TP40002073-SW1
//

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C"
{
#endif

//ZBrush expects these arguments for a dll function, though it's best to only use the first three
float Version(char* pDontCare, double optValue, char* pOptBuffer1, int optBuffer1Size,
              char* pOptBuffer2, int optBuffer2Size, char** zData);
                            
float HelloLib(char* textFromZBrush, double valueFromZBrush, char* pOptBuffer1, int optBuffer1Size,
	           char* pOptBuffer2, int optBuffer2Size, char** zData);

float SaveMemStringToFile(char* textFromZBrush, double valueFromZBrush, char* pOptBuffer1, int optBuffer1Size,
	           char* pOptBuffer2, int optBuffer2Size, char** zData);

#ifdef __cplusplus
}
#endif


#endif /* libTemplate_hpp */
