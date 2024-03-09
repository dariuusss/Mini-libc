// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE , -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	void *p = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	size_t i = 0;
	while(i < nmemb * size * sizeof(char)) {
		((char*)p)[i] = 0;
		i++;
	}
	return p;
}

void free(void *ptr)
{

}

void *realloc(void *ptr, size_t size)
{
	void *p = mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE , -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	void *p = mmap(ptr, size * nmemb, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if(p == MAP_FAILED)
		return NULL;
	return p;
}
