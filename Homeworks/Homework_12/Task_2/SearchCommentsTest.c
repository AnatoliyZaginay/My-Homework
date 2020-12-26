#include "SearchCommentsTest.h"

#include "SearchComments.h"
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

bool searchCommentsTest(void)
{
	char firstLine[] = "/*abc*/";
	char secondLine[] = "///**abc**///";
	char thirdLine[] = "abc///a/*abc/*a*/abc/*/*/**/";
	char firstLineComments[LENGTH] = "";
	char secondLineComments[LENGTH] = "";
	char thirdLineComments[LENGTH] = "";
	searchComments(firstLine, firstLineComments);
	searchComments(secondLine, secondLineComments);
	searchComments(thirdLine, thirdLineComments);
	return strcmp(firstLineComments, "/*abc*/\n\n") == 0 && strcmp(secondLineComments, "/**abc**/\n\n") == 0 &&
		strcmp(thirdLineComments, "/*abc/*a*/\n\n/*/*/\n\n") == 0 && strcmp(thirdLineComments, "abc///a/*abc/*a*/abc/*/*/**/") != 0;
}