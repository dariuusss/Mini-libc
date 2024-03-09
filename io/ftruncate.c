// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	long x = -syscall(77, fd, length);
	if(x < 1 || x > 121)
		return 0;
	errno = x;
	return -1;
}
