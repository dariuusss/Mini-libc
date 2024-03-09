// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int x = -syscall(3, fd);
	if(x <= 0)
		return -x;
	errno = x;
	return -1;
}
