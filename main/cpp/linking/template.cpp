template <typename T>
T muladd(T a, T b, T c)
{
        return a * b + c;
}

// Explicitly instantiate 'muladd<T>' for 'int's.
template int muladd<int>(int, int, int);
