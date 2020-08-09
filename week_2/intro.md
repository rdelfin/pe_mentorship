# Week 2 - Linux Basics

Welcome! In this week, we'll go over some of the basics of Linux, what the purpose of
an OS is, and just how to move yourself around. Feel free to play around with the
terminal and look up things online as you discover them!

Each exercise in this section will introduce you to different concepts that should get
you moving around comfortably in Linux, and understanding what an OS does on your
computer, at a surface level.

## Setup

For this course you'll need a Linux instalation. If you use Linux already, all you'll
need is to open a Linux terminal and we can get started. If you don't, we'll use a
docker image we've prepared for this course. Follow the appropriate
[installation tutorial](https://docs.docker.com/engine/install/), and then just run:

```
$ docker run -it pementorship/centos_interactive
```

You can also build the images yourself, using the docker images in the `images/`
folder of this repo.

We recommend you use the docker images for this whole course, as that will ensure you
have a consistent experience.

## Introduction: What's an OS?

Let's think about what your standard computer looks like. When computers were designed,
there was a simple model, often called the von Neuman architecture:

![von Neumann architecture](arch_basics.png)

Basically, think of a computer as a machine that takes in input from the outside world
(e.g. from the mouse, keyboard, camera, incoming network packets, etc.) stores that
data, processes it, and turns it into output (e.g. via the screen, speakers, outgoing
network packages, etc.). However, this model can be a bit complicated if you're doing
things like writing and running your own code on the machine. How do you run more than
one program at a time? Does this mean you have to re-implement the hardware
instructions for working with a hard drive any time you need to access data there? Say
you manage to get multiple programs running. How do you get access to these resources
to work neatly across programs? Finally, how do you make sure programs don't modify
or affect each other? It would be really easy to write malicious code that just writes
to the files and memory that another program is using.

These are all questions that an operating system tries to answer. Basically, it
provides an abstraction layer for your programs to run on top of, as well as a lot of
libraries, utilities, and common interfaces to do things like access hardware, box off
running programs, 
