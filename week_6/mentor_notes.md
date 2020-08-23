# Mentor notes

## Problems

- In question 1, the solution is to simply handle `SIGHUP` by ignoring it. This will
  turn the process into a daemon process once bash dies, as it will get re-parented to
  init. You can show the mentee this by showing them `top` or `/proc`

- In question 2, my machine lost ~20 signals, and I'm hoping this won't vary much from
  computer to computer.

- Again, in question 2, your mentee might ask why not all signals are received. This
  is, frankly, a hard thing to find. You can find it in `man 7 signals`, where, under
  real-time signals, you'll find this almost sidenote:
  ```
  1.  Multiple instances of real-time signals can be queued.  By contrast, if multiple
      instances of a standard signal are delivered while that signal is currently
      blocked, then only one instance is queued.
  ```
  Basically, the lost signals are likely ones that are being dropped because of the
  lack of a queue.

- On the second part of question 2, you should see issues when you re-open the same
  file. This is a great chance to talk about the requirements signal handlers have, and
  why you don't ever want to do things like call printf (non-reentrant) or open and
  write to files from within signal handlers. ex1 has some code that shows how you can
  avoid puting printf's inside signal handlers.
