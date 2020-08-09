# What to do here?
This is a simple hello world. To build just run `make`.

Run the program first:
```
./hello
```

Before anything else, ask yourself, based on the code, what syscalls do you expect to
see? Write those guesses down.

Now, run:
```
strace ./hello > /dev/null
```

A few notes about what we're running here

Why do we put `> /dev/null` ? This will send standard output (aka the output of the
./hello program) to a magical file called `/dev/null`, also known as the void.
Basically, this will only leave us with the output of `strace`, which goes to standard
error. What is standard output and error? We'll talk about those further down.

Now compare your guesses with what actually came out. Did it match up what you expected?

Here's the output that came out for me:

```
$ strace ./hello
execve("./hello", ["./hello"], 0x7fffd3a042e0 /* 81 vars */) = 0
brk(NULL)                               = 0x55750b220000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118683, ...}) = 0
mmap(NULL, 118683, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f5fdc63c000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\260\34\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=2030544, ...}) = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f5fdc63a000
mmap(NULL, 4131552, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f5fdc041000
mprotect(0x7f5fdc228000, 2097152, PROT_NONE) = 0
mmap(0x7f5fdc428000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1e7000) = 0x7f5fdc428000
mmap(0x7f5fdc42e000, 15072, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f5fdc42e000
close(3)                                = 0
arch_prctl(ARCH_SET_FS, 0x7f5fdc63b4c0) = 0
mprotect(0x7f5fdc428000, 16384, PROT_READ) = 0
mprotect(0x557509ac6000, 4096, PROT_READ) = 0
mprotect(0x7f5fdc659000, 4096, PROT_READ) = 0
munmap(0x7f5fdc63c000, 118683)          = 0
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 4), ...}) = 0
brk(NULL)                               = 0x55750b220000
brk(0x55750b241000)                     = 0x55750b241000
write(1, "Hello, world!\n", 14)         = 14
exit_group(0)                           = ?
+++ exited with 0 +++
```

This is a lot of text, so let me explain what's going on. Each line represents a
syscall being made. You can see they look like functions, with inputs inside the
parenthesis and the outputs on the right hand side of the equals.

There's a lot going on here. It can all be important and interesting, but there's just
two lines that we're gonna focus on for now:

```
write(1, "Hello, world!\n", 14Hello, world!
)         = 14
exit_group(0)                           = ?
```

The `write()` syscall enables us to write out to a file-descriptor (aka an open file).
There's three special file descriptors: 0 for standard input, 1 for standard output and
2 for standard error. These three are basically fake "files" that you can either read
or write to to generate output or fetch text input for the program. If your program is
running in the foreground on your terminal, the output will go straight to your
terminal, and the input will be fetched when you type something and press enter on that
same terminal.

The `exit_group()` system call is also important. Whenever your program terminates it
calls some form of `exit()`. `exit_group()` just makes sure that the entire program,
not just the current thread, exits. The compiler makes sure that this system call is
made for you, which is why you don't have to make it yourself (and why you can't see
such a call made anywhere in the code).


## Questions
1. A few lines before the write, there's a `close(3)`. This means a file with file
   descriptor 3 that got closed
