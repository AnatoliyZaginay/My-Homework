#include "Huffman.h"
#include <stdio.h>
#include <locale.h>

void main(void)
{
	setlocale(LC_ALL, "Rus");
	struct TreeElement* tree = buildTree("анатолийдокажитечтоэнтропиямонеткипринимаетнаибольшеезначениедляправильноймонеткизагинай");
	char code[100] = "";
	printCodes(tree, code, 0);
	deleteTree(tree);
}