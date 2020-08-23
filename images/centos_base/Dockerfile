FROM centos:8
ENV container docker
RUN useradd -ms /bin/bash  me;
RUN usermod -aG wheel me;
ADD --chown=me home /home/me
run echo "me ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
RUN yum -y install strace sudo;
RUN yum -y install zsh;
RUN yum -y install python3;
RUN yum -y install words;
RUN yum -y install gcc gcc-c++ make;
RUN yum -y install man man-pages vim emacs nano tmux;
RUN pip3 install click
VOLUME [ "/sys/fs/cgroup" ]
CMD ["/usr/sbin/init"]
