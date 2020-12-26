#pragma once

#include <stdbool.h>

// Принимает два указателя на строки line и comments (владение остаётся у вызывающего),
// в строку comments записываются все комментарии из строки line вида /* комментарий */
// (в comments комменатрии разделены друг от друга символами "\n\n")
bool searchComments(char* line, char* comments);