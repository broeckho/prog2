template <typename T>
T muladd(T a, T b, T c)
{
	// Template definition with incorrect semantics.
	return a + b + c;
}

// Explicitly instantiate 'muladd<T>' for 'int's.
template int muladd<int>(int, int, int);
