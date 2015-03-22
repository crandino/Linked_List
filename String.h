#ifndef __String_H__
#define __String_H__

class String {

private:
	char *string;
    unsigned int allocated_memory;

	void alloc(int required_memory);

public:

	String();
	String(const char* format, ...);
	//String(const char* _str);
	String(const String &new_string);
	~String();

	bool operator== (const String &str_to_compare) const;
	bool operator== (const char *str_to_compare) const;
	bool operator!= (const String &str_to_compare) const;
	bool operator!= (const char *str_to_compare) const;
	const String& operator= (const String &str_to_assign);
	const String& operator= (const char *str_to_assign);
	const String& operator+= (const String &str_to_concatenate);
	const String& operator+= (const char *str_to_concatenate);

	unsigned int getLength() const;
	const char* getString() const;
	unsigned int capacity() const;
	void clear();
	
};


#endif // !__String_H__
