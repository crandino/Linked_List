#include <stdio.h>
#include <stdarg.h>
#include <wtypes.h>

#include "string.h"

#define TMP_STRING_SIZE 4096

void String::alloc(int required_memory) {
	allocated_memory = required_memory;
	string = new char[allocated_memory];
}

String::String()
{
	alloc(1);
	string[0] = '\0';
}

String::String(const char* format, ...)
{
	allocated_memory = 0;
	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;
		// Construct the string from variable arguments
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);
		if (res > 0)
		{
			alloc(res + 1);
			strcpy_s(string, allocated_memory, tmp);
		}
	}
	if (allocated_memory == 0)
	{
		alloc(1);
		clear();
	}
}

//String::String(const char *_str)
//{
//	allocated_memory = strlen(_str) + 1;
//	str = new char[allocated_memory];
//	strcpy_s(str, allocated_memory, _str);
//}

String::String(const String &new_string)
{
	allocated_memory = new_string.allocated_memory;
	string = new char[allocated_memory];
	strcpy_s(string, allocated_memory, new_string.string);
}

String::~String() {
	delete[] string;
}

bool String::operator== (const String &str_to_compare) const
{
	return strcmp(string, str_to_compare.string) == 0;
}

bool String::operator== (const char *str_to_compare) const
{
	if (str_to_compare != NULL)
		return strcmp(string, str_to_compare) == 0;
	return false;	
}

bool String::operator!= (const String &str_to_compare) const
{
	return strcmp(string, str_to_compare.string) != 0;
}

bool String::operator!= (const char *str_to_compare) const
{
	if (str_to_compare != NULL)
		return strcmp(string, str_to_compare) != 0;
	return true;
}

const String& String::operator= (const String &str_to_assign)
{
	if (str_to_assign.allocated_memory > allocated_memory)
	{
		delete[] string;
		alloc(allocated_memory);
	}

	strcpy_s(string, allocated_memory, str_to_assign.string);
	return (*this);
}

const String& String::operator= (const char *str_to_assign)
{
	if (str_to_assign != NULL)
	{
		if (strlen(str_to_assign) + 1 > allocated_memory)
		{
			delete[] string;
			alloc(strlen(str_to_assign) + 1);
		}

		strcpy_s(string, allocated_memory, str_to_assign);
	}
	else
		clear();
	return (*this);
}

const String& String::operator+= (const String &str_to_concatenate)
{
	
	char *str_tmp = string;
	unsigned int allocated_memory_tmp = allocated_memory;
	allocated_memory = strlen(str_to_concatenate.string) + allocated_memory_tmp + 1;
	
	/* The pointer str_tmp points to the same address that 
	str, so we can not eliminate it until we have concatenated
	the two strings because the corresponding value disappears.*/
	char *tmp;
	tmp = new char[allocated_memory];
	strcpy_s(tmp, allocated_memory, str_tmp);
	strcat_s(tmp, allocated_memory, str_to_concatenate.string);
	
	delete[] string;
	string = tmp;

	/*delete[] string;
	string = new char[allocated_memory];
	strcpy_s(string, allocated_memory, tmp);*/
	//delete[] tmp;

	return (*this);
}

const String& String::operator+= (const char *str_to_concatenate)
{
	if (str_to_concatenate != NULL)
	{
		char *str_tmp = string;
		unsigned int allocated_memory_tmp = allocated_memory;
		allocated_memory = strlen(str_to_concatenate) + allocated_memory_tmp + 1;

		char *tmp;
		tmp = new char[allocated_memory];
		strcpy_s(tmp, allocated_memory, str_tmp);
		strcat_s(tmp, allocated_memory, str_to_concatenate);

		delete[] string;
		string = tmp;

		/*delete[] string;
		string = new char[allocated_memory];
		strcpy_s(string, allocated_memory, tmp);
		delete[] tmp;*/
	}
	else
		clear();

	return (*this);	
}

unsigned int String::getLength() const
{
	return strlen(string);
}

const char* String::getString() const
{
	return string;
}

unsigned int String::capacity() const
{
	return allocated_memory;
}

void String::clear()
{
	string[0] = '\0';
}



