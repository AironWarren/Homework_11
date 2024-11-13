#include <memory>
#include <string>

class Testing 
{
public:
	Testing(std::string name);
	Testing();
	
	~Testing();

	std::string getData() const;

	void inputData(int* arr, int size);
	
	void showData() const;

	int getSize() const;

	bool isElemInArray(int elem) const;

	int getElemPosition(int elem) const;

	void pushBack(int value);
	void pushBack(Testing array);

	void pushFront(int value);
	void pushFront(Testing array);

	void pushOnSelectedPos(int value, int pos);
	void pushOnSelectedPos(Testing array, int pos);

private:
	class Impl;
	std::unique_ptr<Impl> m_pData;
};