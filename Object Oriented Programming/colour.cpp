#include <iostream>
using namespace std;

//    0 to restore default color
// 	  1	for brighter colors
// 	  4	for underlined text
// 	  5	for flashing text
// 	 30	for black foreground
// 	 31	for red foreground
// 	 32	for green foreground
// 	 33	for yellow (or brown) foreground
// 	 34	for blue foreground
// 	 35	for purple foreground
// 	 36	for cyan foreground
// 	 37	for white (or gray) foreground
// 	 40	for black background
// 	 41	for red background
// 	 42	for green background
// 	 43	for yellow (or brown) background
// 	 44	for blue background
// 	 45	for purple background
// 	 46	for cyan background
// 	 47	for white (or gray) background

// To reset attributes: \x1b[0m
//           NORMAL      BOLD       HIGHLIGHTED
// BLACK : \x1b[1;30m  \x1b[0;30m  \x1b[1;30;40m
// RED   : \x1b[1;31m  \x1b[0;31m  \x1b[1;31;41m
// GREEN : \x1b[1;32m  \x1b[0;32m  \x1b[1;32;42m
// YELLOW: \x1b[1;33m  \x1b[0;33m  \x1b[1;33;43m
// BLUE  : \x1b[1;34m  \x1b[0;34m  \x1b[1;34;44m
// PURPLE: \x1b[1;35m  \x1b[0;35m  \x1b[1;35;45m
// CYAN  : \x1b[1;36m  \x1b[0;36m  \x1b[1;36;46m
// WHITE : \x1b[1;37m  \x1b[0;37m  \x1b[1;37;47m

#define FT_RED "\x1B[4;31m"
#define FT_GRN "\x1B[0;32m"
#define FT_YEL "\x1B[0;33m"
#define FT_BLU "\x1B[0;34m"
#define FT_PIN "\x1B[0;35m"
#define FT_WHT "\x1B[0;37m"
#define FT_GR "\x1B[0;38m"
#define FT_NRM "\x1B[0m"

int main()
{
    cout << FT_RED << "RED" << FT_NRM << endl;
    cout << FT_GRN << "GREEN" << FT_NRM << endl;
    cout << FT_YEL << "ORANGE" << FT_NRM << endl;
    cout << FT_WHT << "WHITE" << FT_NRM << endl;
    cout << FT_PIN << "COLOUR" << FT_NRM << endl;

    return 0;
}