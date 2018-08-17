# 文件管理器说明文档

## 目录

### 1.文件管理器介绍


### 2.Demo测试

### 3.使用说明

#### 3.1 查看文件（夹）大

#### 3.2 复制文件

#### 3.3 删除文件（夹）

#### 3.4 查看文件目录

### 4.项目贡献者及作者

### 附录 代码

---
## 1.文件管理器介绍
       这是我在学完Java后使用学过的语法制作的一个简单的文件管理相关的demo，该demo多涉及到iostream和file的知识，对类的继承和引用运用不多。
       该文件管理器在命令行里运行，成功实现了查看指定文件（夹）大小、复制文件、删除文件和查看文件目录的功能。

---

## 2.Demo测试

       打开cmd,在文件路径下执行命令。
```
java governmor      

```
       会出现以下文字，若 3 中的使用说明可以正常使用，则测试成功。
![](read.png '')

---

## 3.使用说明

        接下来分别对文件管理器的四个功能：查看指定文件（夹）大小、复制（文件）、删除文件和查看文件目录进行介绍。

### 3.1 查看文件（夹）大小

       打开demo后按照说明输入 1 并按下回车，进行下一步；
       按照提示输入文件路径，如果输入错误，会提示输入路径不存在或输入为文件名并重新输入；
       最后会输出文件的字节大小数。
![](1.png '')

### 3.2 复制文件
    
       输入 2 按下回车，输入原文件的文件路径，接着输入文件复制的目标位置进行复制，
![](2.png '')     
       
       最后目标文件路径下会出现copy-文件名的文件夹
![](22.png '')

**！！注意该功能由于使用了递归，不可以复制到文件本身的路径**

### 3.3 删除文件（夹）

       输入 3 并按回车，输入指定文件路径，会对文件进行删除
![](3.png '')

### 3.4 查看文件目录

       输入 4 并按回车，输入指定文件路径，会按照文件夹的级层列出文件内容，如下目录中有一个文本文档和一个MP3文档，输入后会得到
![](4.png '')

## 4.项目贡献值及作者

       作 者  ：黄博 
       GitHub ：Ssssplendid

## 附录 demo代码

```
package Demo_asd;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class Demo_Governer {
	public static void main(String[] args) throws IOException {
		System.out.println("欢迎使用文件管理器，您可以进行一下操作 ：");
		
		while(true) {

			System.out.println("---------------------------------");
			System.out.println("1.查看文件大小");
			System.out.println("2.复制文件");
			System.out.println("3.删除文件");
			System.out.println("4.查看文件目录");
			System.out.println("---------------------------------");
			System.out.println("请输入数字1-4进行上述操作");
			Scanner sc = new Scanner(System.in);
			int i = sc.nextInt();
		
			switch (i) {
				case 1:
					
					System.out.println("请输入文件夹路径");
					File dir = getDir();
					System.out.println("文件大小为 " + getDirLength(dir) + "字节");
					break;
					
				case 2:
					
					System.out.println("请输入原文件路径");
					File dir1 = getDir();
					System.out.println("请输入目标文件路径");
					File dir2 = getDir();
					copyFiles(dir1,dir2);
					break;
					
				case 3:
					
					System.out.println("请输入文件夹路径");
					File dir3 = getDir();
					deleteFiles(dir3);
					break;
					
				case 4:

					System.out.println("请输入文件夹路径");
					File dir4 = getDir();
					printLev(dir4 , 0);
					
					break;
					
				default:
					System.out.println("您输入有误，请重新输入数字1-4");
					break;
			}
		}
	}
	
	public static File getDir() {
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		
		while(true) {
			File dir = new File(line);
			if(!dir.exists()) {
				System.out.println("该路径不存在，请重新输入：");
				getDir();
			}else if(!dir.isDirectory()) {
				System.out.println("该路径是一个文件，请重新输入：");
				getDir();
			}else {
				return dir;
			}
		}
	}
	
	public static long getDirLength(File dir) {
		long length = 0;
		File [] subfiles = dir.listFiles();
		
		for (File file : subfiles) {
			if(file.isDirectory()) {
				length = length + getDirLength(file);
			}else {
				length = length + file.length();
			}
		}
		
		return length;
	}
	
	public static void copyFiles(File dir1, File dir2) throws IOException {
		File dir = new File(dir2 , "Copy-" + dir1.getName());
		dir.mkdir();
		
		File [] subfile = dir1.listFiles();
		for (File file : subfile) {
			if(file.isFile()) {
				BufferedInputStream bis = new BufferedInputStream(new FileInputStream(file));
				BufferedOutputStream bos = 
						new BufferedOutputStream(new FileOutputStream(new File(dir , file.getName())));
				int b ;
				while((b = bis.read()) != -1) {
					bos.write(b);
				}
				bis.close();
				bos.close();
			}else {
				copyFiles(file, dir);
			}
		}
		System.out.println("复制完成");
	}
	
	public static void deleteFiles(File dir) {
		File [] SubFiles = dir.listFiles();
		for (File file : SubFiles) {
			if(file.isDirectory()) {
				deleteFiles(file);
			}else {
				file.delete();
			}
		}
		dir.delete();
		System.out.println("已删除");
	}

	public static void printLev(File dir , int level) {
		File [] subfile = dir.listFiles();
		for (File file : subfile) {
			for(int i = 0 ; i <= level ; i++) {
				System.out.print("\t");
			}
			System.out.println(file);
			if(file.isDirectory()) {
				printLev(file ,level + 1);
			}
		}
	}
	
}

```