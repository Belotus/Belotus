#include "Class.h"

unsigned int Class::ref = 0;

Class::Class()
{
	ref++;
}

Class::Class(const Class& c)
{
	ref++;
}

Class::~Class()
{
	ref--;
}

unsigned int Class::GetRef()
{
	return ref;
}
