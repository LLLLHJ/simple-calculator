# 简单计算器

使用c语言完成一个简单的计算器，支持文件和标准输入，支持（），+，-，*，/，-（负号），sqrt，pow运算

## 文件说明

arithmetic（.c .h）：四则运算实现；

sqrt_pow（.c .h）：pow和sqrt功能实现；

calc（.c .h）:实现表达式的转换和计算功能，该过程首先将中缀表达式转换为后缀表达式，然后对后缀表达式进行计算；

input_test（.c .h）:实现输入功能，可以从标准输入也可以从文件输入；

my_stack（.c .h）:简单的栈实现，由于中缀表达式向后缀表达式转换时，使用栈类型数据结构会比较方便；

output（.c .h）：输出功能实现，对应输入功能，若为标准输入，则标准输出，若为文件输入，则输出到文件中；

test.c：测试函数，程序的入口

a.out:生成的可执行文件

Input:输入文件

Input.out:计算后的结果输出

## 程序测试

测试代码如下，首先声明str_input，mode，path，默认为从标准输入中输入，在运行可执行文件时可以额外输入参数 “1”，选择文件输入；前提是概路径下有名为Input的文件，输出文件名为output.out；

~~~c 
#include <stdio.h>
#include "calc.h"
#include "input_test.h"
#include "output.h"
char str_input[1000] = {'\0'};
char* path = "./Input";
int mode = 0;
int main(int argc, char *argv[] ) {
    if(argc > 1){
        if(argv[1][0] == '1') mode = 1;
    }
    output(str_input, mode, path);
    return 0;
}

~~~

### 编译过程

~~~c
gcc arithmetic.c sqrt_pow.c calc.c my_stack.c output.c input_test.c test.c 
~~~

### 执行结果

~~~
//标准输入
./a.out
~~~



![image-20210529151425712](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20210529151425712.png)

~~~
//文件输入
./a.out 1
~~~

![image-20210529154552176](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20210529154552176.png)

