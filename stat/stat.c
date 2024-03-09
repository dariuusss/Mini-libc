// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int x = -syscall(4, path, buf);
	if(x < 1 || x > 121)
		return 0;
	errno = x;
	return -1;
}
