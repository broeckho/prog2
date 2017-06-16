std::function<int(int)> makeCountingAdder(int& counter)
{
	return [&counter](int x) -> int {
		int val = counter + x;
		counter++;
		return val;
	};
}
