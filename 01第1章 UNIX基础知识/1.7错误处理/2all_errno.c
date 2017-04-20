#include <stdio.h>
#include <string.h>
#include <errno.h>
// #include <asm/errno.h>


/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-20 19:37:1492688259
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	for (int i = -1; i <140; ++i)
	{
		fprintf(stderr, "EACCES: %s\n", strerror(i));
	}

	errno=ENOENT;//2
	perror(argv[0]);
	errno=0;
	perror(argv[0]);

	return 0;
}


/*wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 2all_errno.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 
EACCES: Unknown error -1
EACCES: Success
EACCES: Operation not permitted
EACCES: No such file or directory
EACCES: No such process
EACCES: Interrupted system call
EACCES: Input/output error
EACCES: No such device or address
EACCES: Argument list too long
EACCES: Exec format error
EACCES: Bad file descriptor
EACCES: No child processes
EACCES: Resource temporarily unavailable
EACCES: Cannot allocate memory
EACCES: Permission denied
EACCES: Bad address
EACCES: Block device required
EACCES: Device or resource busy
EACCES: File exists
EACCES: Invalid cross-device link
EACCES: No such device
EACCES: Not a directory
EACCES: Is a directory
EACCES: Invalid argument
EACCES: Too many open files in system
EACCES: Too many open files
EACCES: Inappropriate ioctl for device
EACCES: Text file busy
EACCES: File too large
EACCES: No space left on device
EACCES: Illegal seek
EACCES: Read-only file system
EACCES: Too many links
EACCES: Broken pipe
EACCES: Numerical argument out of domain
EACCES: Numerical result out of range
EACCES: Resource deadlock avoided
EACCES: File name too long
EACCES: No locks available
EACCES: Function not implemented
EACCES: Directory not empty
EACCES: Too many levels of symbolic links
EACCES: Unknown error 41
EACCES: No message of desired type
EACCES: Identifier removed
EACCES: Channel number out of range
EACCES: Level 2 not synchronized
EACCES: Level 3 halted
EACCES: Level 3 reset
EACCES: Link number out of range
EACCES: Protocol driver not attached
EACCES: No CSI structure available
EACCES: Level 2 halted
EACCES: Invalid exchange
EACCES: Invalid request descriptor
EACCES: Exchange full
EACCES: No anode
EACCES: Invalid request code
EACCES: Invalid slot
EACCES: Unknown error 58
EACCES: Bad font file format
EACCES: Device not a stream
EACCES: No data available
EACCES: Timer expired
EACCES: Out of streams resources
EACCES: Machine is not on the network
EACCES: Package not installed
EACCES: Object is remote
EACCES: Link has been severed
EACCES: Advertise error
EACCES: Srmount error
EACCES: Communication error on send
EACCES: Protocol error
EACCES: Multihop attempted
EACCES: RFS specific error
EACCES: Bad message
EACCES: Value too large for defined data type
EACCES: Name not unique on network
EACCES: File descriptor in bad state
EACCES: Remote address changed
EACCES: Can not access a needed shared library
EACCES: Accessing a corrupted shared library
EACCES: .lib section in a.out corrupted
EACCES: Attempting to link in too many shared libraries
EACCES: Cannot exec a shared library directly
EACCES: Invalid or incomplete multibyte or wide character
EACCES: Interrupted system call should be restarted
EACCES: Streams pipe error
EACCES: Too many users
EACCES: Socket operation on non-socket
EACCES: Destination address required
EACCES: Message too long
EACCES: Protocol wrong type for socket
EACCES: Protocol not available
EACCES: Protocol not supported
EACCES: Socket type not supported
EACCES: Operation not supported
EACCES: Protocol family not supported
EACCES: Address family not supported by protocol
EACCES: Address already in use
EACCES: Cannot assign requested address
EACCES: Network is down
EACCES: Network is unreachable
EACCES: Network dropped connection on reset
EACCES: Software caused connection abort
EACCES: Connection reset by peer
EACCES: No buffer space available
EACCES: Transport endpoint is already connected
EACCES: Transport endpoint is not connected
EACCES: Cannot send after transport endpoint shutdown
EACCES: Too many references: cannot splice
EACCES: Connection timed out
EACCES: Connection refused
EACCES: Host is down
EACCES: No route to host
EACCES: Operation already in progress
EACCES: Operation now in progress
EACCES: Stale file handle
EACCES: Structure needs cleaning
EACCES: Not a XENIX named type file
EACCES: No XENIX semaphores available
EACCES: Is a named type file
EACCES: Remote I/O error
EACCES: Disk quota exceeded
EACCES: No medium found
EACCES: Wrong medium type
EACCES: Operation canceled
EACCES: Required key not available
EACCES: Key has expired
EACCES: Key has been revoked
EACCES: Key was rejected by service
EACCES: Owner died
EACCES: State not recoverable
EACCES: Operation not possible due to RF-kill
EACCES: Memory page has hardware error
EACCES: Unknown error 134
EACCES: Unknown error 135
EACCES: Unknown error 136
EACCES: Unknown error 137
EACCES: Unknown error 138
EACCES: Unknown error 139
./a.out: No such file or directory
./a.out: Success
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 
*/