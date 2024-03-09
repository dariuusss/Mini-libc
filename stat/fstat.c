// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int x = -syscall(5, fd, st);
	if(x < 1 || x > 121)
		return 0;
	errno = x;
	return -1;
}
