#ifndef ARRAY_H
#define ARRAY_H


class Array {
protected: //private member but want to be used by sub member function. 
	int *pArr_;
	int size_;
	
private:
	static const int ARRAYSIZE; //instead of Macro 	
	void set_arr(const int *pArr, int size); //help function - tool function
	
public:
	//Array * operator&();
	//const Array* operator&() const;
	
	explicit Array(int size = Array::ARRAYSIZE); //to keep the shape. arr2=10 won't work 
	Array(const int *pArr, int size);
	Array(const Array& rhs);
	//when there is virtual, always the destructor should be virtual
	virtual ~Array();
	
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	int size() const;
	//no set function since size and pArr are connected
	
	//to use dynamic binding
	virtual int &operator[](int index);
	virtual const int &operator[](int index) const; //if array is const
	
};

#endif
