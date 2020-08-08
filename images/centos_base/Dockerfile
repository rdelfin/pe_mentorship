FROM centos:8
ENV container docker
RUN yum -y install man man-pages vim emacs nano;
RUN yum -y install strace sudo;
RUN useradd -ms /bin/bash  me;
RUN usermod -aG wheel me;
VOLUME [ "/sys/fs/cgroup" ]
CMD ["/usr/sbin/init"]
