#include "AlgorithmKMPTest.h"

#include "AlgorithmKMP.h"

bool searchSubstringTest(void)
{
	return searchSubstring("abb", "c") == -1 && searchSubstring("abcabc", "abc") == 0 && searchSubstring("bababc", "abc") == 3 &&
		searchSubstring("abcabcabc", "abcabcabc") == 0;
}