typedef unsigned char bool;
#define false 0
#define true 1
#define NUMARGS(type,...)(sizeof((type[]){0,##__VA_ARGS__})/sizeof(type)-1)
