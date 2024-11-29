<!-------gnl_Image-------->
<a name="readme-top"></a>
<p align="center">
	<img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=0ABAB5&text=get_next_line&fontColor=fcf3f2" />
</p>

<!-------About-------->

## About

The `get_next_line` project is one of the pivotal challenges in the **42 School Common Core curriculum**. It combines system-level programming concepts with memory management to read a file line-by-line, a fundamental operation in many real-world applications. Understanding this project requires an in-depth look at Unix's file descriptor model, system calls like `open()` and `read()`, and the role of **static variables** in stateful programming. This document provides a detailed exploration of these concepts and their relationship to Unix's philosophy.

----
<!-------Index-------->
# Index
<ul>

</ul>

---
## **1. File Descriptors: The Foundation of I/O in Unix**

At the heart of Unix’s input/output operations lies the concept of the **file descriptor (FD)**. A file descriptor is a small, non-negative integer that represents an open file, pipe, or device within a process. File descriptors serve as the bridge between user-level applications and the underlying kernel, abstracting file access as streams of bytes.

### **1.1. How File Descriptors Work**

1. When a process opens a file or creates a communication channel (like a pipe), the kernel allocates an entry in the **file descriptor table**, a per-process data structure.
2. This table maps the file descriptor to an open file description, which contains metadata like file offsets, access modes, and pointers to the actual file in the kernel's global file table.

### **1.2. Standard File Descriptors**
- **`0` (stdin)**: Standard input, typically tied to the keyboard.
- **`1` (stdout)**: Standard output, typically tied to the terminal display.
- **`2` (stderr)**: Standard error, used for error messages.

>[!IMPORTANT]
> File descriptors are integral to Unix's design, embodying the philosophy that "everything is a file." Whether it’s a regular file, a socket, or a hardware device, Unix treats all I/O uniformly, enabling programs to read, write, and manipulate these resources seamlessly. This abstraction simplifies the development of tools like `get_next_line`, which processes file descriptors as byte streams.

---

## **2. System Calls: The Role of `open()` and `read()`**

In the `get_next_line` project, **`open()`** and **`read()`** are the primary system calls used to interact with file descriptors. These functions interface directly with the kernel, allowing user-space programs to access data.

### **`open()`**

The `open()` system call is responsible for opening a file and returning its associated file descriptor.

#### Prototype:
```c
int open(const char *pathname, int flags, mode_t mode);
```

#### Parameters:
- ** `pathname`: Path to the file.
- ** `flags`: File access mode (see it more below)
- ** `mode`: Permissions for the file (used only when creating a file)

#### Flags:

- ** `O_RDONLY`: In read only mode, opens the file
- ** `O_WRONLY`: In write only mode, opens the file
- ** `O_RDWR`: Opens the file in read and write mode
- ** `O_CREAT`: This flag is applied to create a file if it doesnt exist
- ** `O_EXCL`: Prevent the file creation if it already exist in directory or location

#### Example
