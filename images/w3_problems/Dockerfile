FROM pementorship/centos_base
RUN pip3 install flask
USER me
WORKDIR /home/me
ADD --chown=me home $HOME
EXPOSE 8080
CMD ["/bin/bash"]
