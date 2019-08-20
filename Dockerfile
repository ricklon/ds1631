#https://hub.docker.com/r/zoobab/arduino-cli/dockerfile

FROM arm64v8/alpine-glibc
RUN apk add ca-certificates python curl
WORKDIR /root

RUN curl -O -J -L https://github.com/arduino/arduino-cli/releases/download/0.4.0/arduino-cli_0.4.0_Linux_64bit.tar.gz
RUN tar xvzf arduino-cli_0.4.0_Linux_64bit.tar.gz
      
ENV USER root
# COPY dot-cli-config.yml /usr/bin/.cli-config.yml
RUN arduino-cli core update-index --debug
RUN arduino-cli core install arduino:avr
RUN arduino-cli board listall
RUN arduino-cli sketch new blink --debug

# COPY blink.ino /root/Arduino/blink/blink.ino
# RUN arduino-cli compile --fqbn earduino:avr:uno Arduino/blink

