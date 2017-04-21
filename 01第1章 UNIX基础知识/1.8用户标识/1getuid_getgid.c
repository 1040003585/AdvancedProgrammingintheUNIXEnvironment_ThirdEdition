#include <stdio.h>
#include <unistd.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 10:51:1492743091
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	printf("[+] uid = %d, gid = %d \n", getuid(), getgid() );
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.8用户标识$ gcc 1getuid_getgid.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.8用户标识$ ./a.out 
[+] uid = 1000, gid = 1000 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.8用户标识$ 
*/