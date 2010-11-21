#ifndef BASE_H_
#define BASE_H_

#include <string>
#include <iostream>
#include "Class.h"

class Base : public Class {
protected:
	virtual std::ostream& PrintOn(std::ostream&) const = 0;
public:
	virtual std::string ToString() const;

	friend std::ostream& operator << (std::ostream&, const Base&);
};

#endif /* BASE_H_ */
