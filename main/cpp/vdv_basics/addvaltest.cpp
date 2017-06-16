/**
 * @file.
 *
 * @author J. Broeckhove - see copyright.txt
 */

#include "addval.hpp"

void call_addValue() { addValue<int, 5>(42); }

template <typename IT, typename OP>
void transform(IT beg, IT end, IT to, OP op)
{
	while (beg != end) {
		*to++ = op(*beg++);
	}
}

int main()
{
	call_addValue();
	int m[] = {1, 2, 3, 4, 5, 6};
	transform(m, m + 6, m, addValue<int, 5>);
	return 0;
}
