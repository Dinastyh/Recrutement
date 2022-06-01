Recruitment project, based on centos stream 8

# Usage

## Compile project

To build this project, go to the directory and make:

```sh
make all
```

This command will build WolfSSL, a library used, if you alredy have wolfssl you can compile bin with:

```sh
make extract
```

## Config

To config this software must must create a config.toml in the directory of it.

### Default config
```toml
[DataBase]
host = <your_host>
user = <your_user>
password = <your_password>
default_database = <your_default_database>
port = <your_port>
```
If you run this software without config file, it will generate one and kill itself

## Use

```sh
./extract <EML_FILE>
```

## Command Guide

Project Makefile provied some commands:

```sh
make all
make
```
Build wolfssl and binary
```sh
make extract
```
Build binary
```sh
make clean
```
Clean binary and obj file
```sh
make clean_lib
```
Clean wolfssl
```sh
make clean_all
```
Clean binary, obj file and wolfssl
