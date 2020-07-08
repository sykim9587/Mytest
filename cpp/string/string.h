#ifndef STRING_H
#define STRING_H
#include <cstddef>

class String{
private:
	char *str;
	int len;
	
	void set_str(const char *str); //helper function(tool function) -> only used by member function
public:
	//String(); -> because of default argument
	String(const char *str = NULL);
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs); //return String&	
	String& operator=(const char *str); //return String&	
	
	bool operator==(const String& rhs);
		
	const char *c_str(); //return the string pointer
	int length();
	
	

};

#endif
