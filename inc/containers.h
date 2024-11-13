class ArrayContainer
{
public:
	ArrayContainer() : arr(nullptr), size(0) 
	{
	
	}

	~ArrayContainer()
	{
		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}
	}

	void inputData(int* arr, int size);
	void showData() const;

	int getSize() const;
	
	bool isElemInArray(int elem) const;
	
	int getElemPosition(int elem) const;
	
	void pushBack(int value);
	void pushBack(ArrayContainer array);

	void pushFront(int value);
	void pushFront(ArrayContainer array);

	void pushOnSelectedPos(int value, int pos);
	void pushOnSelectedPos(ArrayContainer array, int pos);

private:
	int* arr;
	int size;
};