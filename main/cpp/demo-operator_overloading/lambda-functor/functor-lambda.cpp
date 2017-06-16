class Lambda1
{
public:
	Lambda1(int& counter) : counter(counter) {}
	int operator()(int x)
	{
		int val = counter + x;
		counter++;
		return val;
	}

private:
	int& counter;
};

Lambda1 makeCountingAdder(int& counter) { return Lambda1(counter); }
