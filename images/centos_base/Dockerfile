FROM centos:8
ENV container docker
RUN yum -y install man man-pages vim emacs nano;
RUN yum -y install strace sudo;
RUN yum -y install words;
RUN useradd -ms /bin/bash  me;
RUN usermod -aG wheel me;
run echo "me ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers
VOLUME [ "/sys/fs/cgroup" ]
CMD ["/usr/sbin/init"]
