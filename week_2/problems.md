# Problems

## Setup

For these, use the image called `pementorship/w2_problems`. As a reminder, you just
need to run:
```
docker run -it pementorship/w2_problems
```
You might need to `docker pull` it first.

## Questions

1. **man ls**: Run `man ls`. Construct invocations of `ls` that will output:
  - The author/last editor of the file
  - File sizes in KB instead of bytes
  - inode (or index node) numbers of the files
2. **seq**: Linux has a command called `seq` that takes in two integers and generates
   every number between them. Read `seq --help` and the `man` page of `seq` to learn
   more about this program. Once you're done, generate a file called "`numbers.txt`"
   containing every even number between 10 and 200 (inclusive on both ends) using `seq`
   (hint: much like how we used `|` to pipe between programs, you can use `>` to pipe
   to a file, just supply the file name on the right side).
   1. How how would you do this for the odd numbers?

