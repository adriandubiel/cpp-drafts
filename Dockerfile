# Build stage

FROM ubuntu:latest AS build

# Install Ubuntu packages, as each RUN commits the layer to image, need to
# chain commands and clean up in the end to keep the image small
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        git \
        build-essential \
        pkg-config \
        cmake \
        libgtest-dev \
        valgrind \
        libpcsclite-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists

# Build GTest library
RUN cd /usr/src/googletest && \
    cmake . && \
    cmake --build . --target install

WORKDIR /cpp

COPY . .

RUN cd /cpp/src/database_example/ \
    cmake -S . -B /cpp/src/database_example/build/ \
    cmake --build /cpp/src/database_example/build/ \
    /cpp/src/database_example/build/app

#USER user
