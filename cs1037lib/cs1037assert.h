#ifndef Assert
#include <stdio.h>
#ifndef _DEBUG
#define Assert(expr,msg) 
#else
#define Assert(expr,msg) { if (expr) { } else { printf("ASSERT(%s) FAILED:\n    %s\n", #expr, msg); __asm { int 0x3 } } }
#endif
#endif
