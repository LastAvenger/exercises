DEV = la-tun
IP = 192.168.9.0
CIDR = 24
TARGET = tun.out
CC = gcc

default: tun.c
	$(CC) $^ -o $(TARGET)

run:
	sudo ./$(TARGET)

if:
	# sudo ip tuntap add mode tun dev $(DEV)
	sudo ip addr add $(IP)/$(CIDR) dev $(DEV)
	sudo ip link set dev $(DEV) up
	ip route get $(IP) # test

unif:
	sudo ip tuntap del mode tun dev $(DEV)
