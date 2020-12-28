#include "RealNumberLexer.h"

#include <string.h>
#include <ctype.h>

enum State
{
	start,
	firstDigit,
	point,
	secondDigit,
	symbolE,
	sign,
	thirdDigit
};

bool isRealNumber(char* line)
{
	enum State currentState = start;
	for (int i = 0; i < strlen(line); ++i)
	{
		switch (currentState)
		{
		case start:
			if (isdigit(line[i]))
			{
				currentState = firstDigit;
				break;
			}
			return false;
		case firstDigit:
			if (isdigit(line[i]))
			{
				break;
			}
			if (line[i] == '.')
			{
				currentState = point;
				break;
			}
			if (line[i] == 'E')
			{
				currentState = symbolE;
				break;
			}
			return false;
		case point:
			if (isdigit(line[i]))
			{
				currentState = secondDigit;
				break;
			}
			return false;
		case secondDigit:
			if (isdigit(line[i]))
			{
				break;
			}
			if (line[i] == 'E')
			{
				currentState = symbolE;
				break;
			}
			return false;
		case symbolE:
			if (isdigit(line[i]))
			{
				currentState = thirdDigit;
				break;
			}
			if (line[i] == '-' || line[i] == '+')
			{
				currentState = sign;
				break;
			}
			return false;
		case sign:
			if (isdigit(line[i]))
			{
				currentState = thirdDigit;
				break;
			}
			return false;
		case thirdDigit:
			if (isdigit(line[i]))
			{
				break;
			}
			return false;
		}
	}
	return currentState == firstDigit || currentState == secondDigit || currentState == thirdDigit;
}