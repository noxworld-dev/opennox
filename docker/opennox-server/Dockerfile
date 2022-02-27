FROM ubuntu:21.04

RUN dpkg --add-architecture i386 && \
    apt update && \
    apt upgrade -y && \
    apt install -y libc6:i386 ca-certificates

ADD opennox-server /usr/bin/opennox-server

VOLUME /nox/

EXPOSE 22/tcp
EXPOSE 18590/udp
EXPOSE 18580/tcp
EXPOSE 6060/tcp

WORKDIR /nox/
ENTRYPOINT ["opennox-server", "--rcon=:22"]
