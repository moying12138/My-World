##  Linux 基础命令
> 2019.2.28开始整理之前用过或忘掉的linux基础命令, 每天整理三个， 加入新的有意思的命令

---
[TOC]

### 常用命令
**2019.2.28**
#### grep  文本检索
> 一种强大的文本搜索工具，它能使用正则表达式搜索文本，并把匹配的行打印出来。

-  grep -i "moying" a.txt      忽略大小写查找含有字符串"moying"
-  grep -w  "moying" a.txt    完全匹配
-  -v    反转匹配
-   -e  -E   多模式串检索  -e    要分开    -E 以管道符分割 grep -E "moying | yingmo" a.txt    
-  -c  输出匹配的行数
-  -o 只输出检索到的词， 而不是一行
-  可以加入正则来检索
	
#### tr 字符转换
> tr -[cdst] [第一字符集] [第二字符集]   
>  tr 指令从标准输入设备读取数据，经过字符串转译后，将结果输出到标准输出设备。

- -d 删除第一字符集的字符
- -c  反转替换， 取第一字符集的补集， 来被第二字符集提替换
- -s 连续压缩重复的字符为单个字符， cat a.txt  | tr -s "\n"  删除空行
- -t  默认用第一字符集的长度来替换， -t 消减第一字符集的长度，用第二字符集的长度。
- tr [a-z] [A-Z]   小写转换大写

#### find 文件查找
> 强大的文件搜索命令, 注意查找根目录时最好加上管理员权限， 不然就会  哇  哇  哇
> find path -option     最近知道一个-exec  command {} \;  和  -delete 可以直接删除   -perm  664 权限

- 查找本目录下所有的c程序
```
find . -name "*.c"
```
- 查找本目录下所有文件夹  
```
find . -type d 

-exec  command  {}  \;  对每个检索到的目标执行command 命令
find . -type d -exec ls {} \;   展开所有文件夹中的内容

-print  输出匹配到的目标
find . -type d -print  -exec ls {} \;   展开所有文件夹中文件

-ok   交互式匹配， 没检索到匹配项需要确认
find . -type d -ok ls {} \;   展开所有文件夹中文件
```

- 查找文件以时间来查找
```
find ./ -mtime -2  查找文件更新日时在距现在时刻二天以内的文件
find ./ -mtime +2  查找文件更新日时在距现在时刻二天以上的文件
find ./ -mtime 2   查找文件更新日时在距现在时刻一天以上二天以内的文件
find ./ -newer abc  查找文件更新时间比文件abc的内容更新时间新的文件


```
- 查找文件以大小来查找   
```
find ./ -size -10m 查找10M以内的文件或目录
find ./ -empty 查找空文件或空目录
find ./ -empty -type f -delete   查找空文件并删除
```
---
**2019.3.1**
> 今天测试命令时， 想快速建立一个指定大小的文件， 才发现不会适合的命令

#### dd 磁盘管理(备份) 
> 用于读取、转换并输出数据。dd可从标准输入或文件中读取数据，根据指定的格式来转换数据，再输出到文件、设备或标准输出。 命令很强大 
> 
> if=文件名：输入文件名，缺省为标准输入。即指定源文件。
> of=文件名：输出文件名，缺省为标准输出。即指定目的文件。 
> bs=块大小，  count=块数量，   //最终文件大小= bs * count
> 有意思的选项 conv=很多参数， 例如： ucase 转大写， lcase转小写 

- 创建指定大小的文件，用0填充
```
sudo dd if=/dev/zero of=./a.txt bs=500k count=6  //创建一个6×500K的文件， /dev/zero提供无数的0。 此处应该是二进制的0， 因为cat a.txt 是空， 可以用od 命令去查看 od a.txt，这里不介绍 
```
- 备份文件， 不能是文件夹
```
sudo dd if=/linux/1_happy.txt of=./1_happy_back.txt   //这里只复制文件内容，不复制文件权限
```

- 销毁磁盘数据
```
dd if=/dev/urandom of=/dev/hda1   // 利用随机的数据填充磁盘，必要的场合可以用来销毁数据。
```
- [更多秀秀的操作](https://www.cnblogs.com/jikexianfeng/p/6103500.html)

#### cat  tac 查看文件内容
> cat 为正向按行读取， tac 为反向按行读取

- 查看文件内容
```
cat a.txt //查看文件
cat -n a.txt //从1开始按行编号
cat -b a.txt  //对空白行不编号
cat -s a.txt  //对多个连续空行， 压缩成一个空行
tac 没有上述选项。。 有什么好的玩法没玩过
```
- 从标准输入写入指定文件
```
cat << END  >> a.txt     从标准输入追加到a.txt    输入END结束， 可替换成别的结束字符
cat << END > a.txt       从标准输入覆盖到a.txt
一个很好的解释
1、cat << EOF，以EOF输入字符为标准输入结束：
2、cat>filename，创建文件，并把标准输入输出到filename文件中，以ctrl+d作为输入结束：
注意：输入时是没有'>'的。
3、cat>filename<<EOF，以EOF作为输入结束，和ctrl+d的作用一样：
```
#### cut 文本切割
> 从文本中提取分割有效的信息， 很好用， 但是因为有时分割符不好确定，可以使用awk
- -d 指定分隔的字符， 默认是TAB        
- -f 指定显示范围
- -b 按照字节选取
- -c 按照字符选取    反正在我电脑上-b  和 -c是一样的， 我的是中文算3个字节编码
```
cat /etc/passwd | cut -b1-3　#取每行的第1-3字字节

cat /etc/passwd | cut -b1-3,5-7,8　#取每行的第1-3,5-7,8的字节(后面的数字会先进行从小到大的排列) 需要事先知道具体字节，很容易出错

cat song.txt |cut -nb 1,2,3  #当 -b 添加 -n 后则不会分割多字节 (我的系统是utf-8，所以需要用三个字节来表示一个汉字)
cat /etc/passwd | cut -c1,3 #适用于中文 

cat /etc/passwd | cut -d : -f 3 #以:分割，取第三段

```

[gdb](https://linuxtools-rst.readthedocs.io/zh_CN/latest/tool/gdb.html)


