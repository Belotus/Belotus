#ifndef CLASS_H_
#define CLASS_H_

class Class
{
public:
	Class();
	Class(const Class&);
	virtual ~Class();

	static unsigned int GetRef();

private:
	static unsigned int ref;
};

#endif /* CLASS_H_ */
