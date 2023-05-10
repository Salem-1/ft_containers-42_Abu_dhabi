FROM debian:latest

RUN apt-get update && \
    apt-get install -y valgrind gcc g++ make clang

COPY . /app

VOLUME /app

CMD ["bash"]
