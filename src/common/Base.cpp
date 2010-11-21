#include "Base.h"
#include <sstream>

std::string Base::ToString() const
{
	std::ostringstream os;
	PrintOn(os);
	return os.str();
}

std::ostream& operator << (std::ostream& os, const Base& object)
{
	return os << object.ToString();
}
