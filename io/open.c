// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	long x = -syscall(2, filename, flags);
	if(x < 1 || x > 121)
		return -x;
	errno = x;
	return -1;
}
