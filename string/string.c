// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i, l;
	i = 0;
	l = strlen(source);
	while(i < l) {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i = 0;
	while(i < len) {
		destination[i] = source[i];
		i++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	int i, l1, l2;
	l1 = strlen(destination);
	l2 = strlen(source);
	for(i = l1;i < l1 + l2; i++)
		destination[i] = source[i - l1];
	destination[l1 + l2] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t i, l1;
	l1 = strlen(destination);
	for(i = l1; i < l1 + len; i++)
		destination[i] = source[i - l1];
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	int i, l1, l2;
	i = 0;
	l1 = strlen(str1);
	l2 = strlen(str2);
	while(i < l1 && i < l2) {
		if(str1[i] > str2[i])
			return 1;
		if(str1[i] < str2[i])
			return -1;
		i++;
	}
	if(l1 < l2)
		return -1;
	else if (l1 > l2)
		return 1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while(i < len) {
		if(str1[i] > str2[i])
			return 1;
		if(str1[i] < str2[i])
			return -1;
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0, len = strlen(str);
	while(i < len && str[i] != c)
		i++;
	if(i == len)
		return NULL;
	return str + i;
}

char *strrchr(const char *str, int c)
{
	int i = strlen(str) - 1;
	while(i >= 0 && str[i] != c)
		i--;
	if(i == -1)
		return NULL;
	return str + i;
}

char *strstr(const char *haystack, const char *needle)
{
	int i, l1, l2;
	i = 0;
	l1 = strlen(haystack);
	l2 = strlen(needle);
	while(i + l2 <= l1) {
		if(strncmp(haystack + i, needle, l2) == 0)
			return haystack + i;
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int i, l1, l2;
	l1 = strlen(haystack);
	l2 = strlen(needle);
	i = l1 - l2;
	while(i >= 0) {
		if(strncmp(haystack + i, needle, l2) == 0)
			return haystack + i;
		i--;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	while(i < num) {
		((char*)destination)[i] = ((char*)source)[i];
		i++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	char aux;
	while(i < num) {
		aux = ((char*)source)[i];
		((char*)destination)[i] = aux;
		i++;
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i = 0;
	while(i < num) {
		if( ((char*)ptr1)[i] > ((char*)ptr2)[i] )
			return 1;
		if( ((char*)ptr1)[i] < ((char*)ptr2)[i] )
			return -1;
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	size_t i = 0;
	while(i < num) {
		((char*)source)[i] = value;
		i++;
	}
	return source;
}
