###  git 环境配置
git下windows配置   参考 https://blog.csdn.net/qq_39412702/article/details/104843324
1. git 下载
> 下载git bash    https://git-scm.com/ 
> 在windows下：\r\n代表换行，拆分两个代码是：回到行首+换到下一行（CRLF）；但是在linux下的区别是：只用\n即可以代表换行（LF）。

2. 配置git 环境变量
把git的bin文件夹放到个人路径的 path中

3 配置git
> git bash 下 配置git 
> git config                  #查看本机是否配置了个人信息
> git config --global user.name “name”     #定义全局的用户名
> git config --global user.email “qwer@qq.com”  #定义全局的邮件地址
> git config --list               #查看配置信息

4 生成ssh 公私key
生成公钥和私钥，实现本地和服务器的认证 
> $ ssh-keygen -t rsa -C “qwer@qq.com”

 添加sshkey_pub到github上
