#include "levelzero.h"

#define toUpper(c) (char)(('a' <= c && c <= 'z') ? (c - 'a' + 'A') : c)

LevelZero::LevelZero(int seed, std::vector<char> sequence) : Level{seed, 0}, sequence{sequence}, i{0} {}

char LevelZero::generateBlock()
{
    if (i == sequence.size()) i = 0;
    char out = sequence[i];
    i++;
    return toUpper(out);
}
