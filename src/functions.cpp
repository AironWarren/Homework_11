#include "functions.h"


ArrayContainer intersecData(const ArrayContainer& dataOne, const ArrayContainer&datatSecond)
{
	ArrayContainer* cont = new ArrayContainer;

	int size1 = dataOne.getSize();
	int size2 = datatSecond.getSize();

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; i < size2; j++)
		{
			if (dataOne.getElemPosition(i) == datatSecond.getElemPosition(j))
			{
				cont->pushBack(dataOne.getElemPosition(i));	
				break;
			}
		}
	}

	return *cont;
}