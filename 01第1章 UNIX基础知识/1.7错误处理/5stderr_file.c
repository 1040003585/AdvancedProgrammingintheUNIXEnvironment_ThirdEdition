#include <stdio.h>

/**
 * Copyright ? 2016 Authors. All rights reserved.
 *
 * FileName: .cpp
 * Author: Wu_Being <1040003585@qq.com>
 * Date Time: 2017-04-21 15:40:1492760446
 * Description: 
 *
 */


int main(int argc, char const *argv[])
{
	printf("stdout: printf\n");
	fprintf(stderr, "stderr: fprintf\n");
	return 0;
}

/*
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ gcc 5fprintf_file.c 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ tee 5out.txt 
hello tee
hello tee
tee
tee
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
hello tee
tee
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out &> 5out.txt 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stderr: fprintf
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out > 5out.txt 
stderr: fprintf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out &>> 5out.txt 
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stdout: printf
stderr: fprintf
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 




wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 2>> 5out.txt 
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 2>> 5out.txt 
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stdout: printf
stderr: fprintf
stdout: printf
stderr: fprintf
stderr: fprintf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 1>> 5out.txt 
stderr: fprintf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 1>> 5out.txt 
stderr: fprintf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stdout: printf
stderr: fprintf
stdout: printf
stderr: fprintf
stderr: fprintf
stdout: printf
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ ./a.out 0>> 5out.txt 
stdout: printf
stderr: fprintf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ more 5out.txt 
stdout: printf
stderr: fprintf
stdout: printf
stderr: fprintf
stderr: fprintf
stdout: printf
stdout: printf
wu_being@ubuntukylin64:~/GitHub/AdvancedProgrammingintheUNIXEnvironment_ThirdEdition/01第1章 UNIX基础知识/1.7错误处理$ 

*/