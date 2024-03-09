// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int x = -syscall(8, fd, offset, whence);
	if(x < 1 || x > 121)
		return -x;
	errno = x;
	return -1;
}
