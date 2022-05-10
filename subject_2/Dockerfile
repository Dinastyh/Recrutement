FROM quay.io/centos/centos:stream

RUN dnf upgrade --setopt=install_weak_deps=False -y

RUN dnf install -y make gcc binutils autoconf automake zip

ADD wolfssl/wolfssl-5.2.0.zip /build/wolfssl/wolfssl-5.2.0.zip

RUN cd /build/wolfssl/ && \
    unzip wolfssl-5.2.0.zip && \
    cd wolfssl-5.2.0 && \
    ./configure && \
    make install

RUN dnf clean all && \
    rm -rf /tmp/* && \
    rm -rf /var/cache/yum && \
    rm -rf /var/cache/dnf && \
    find /var/log -type f -name '*.log' -delete

RUN useradd -m cen

WORKDIR /home/cen/project
USER cen