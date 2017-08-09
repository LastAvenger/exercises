/**
 * @file tun.c
 * @brief Linux tun device
 * @author Shengyu Zhang <i@srain.im>
 * @version
 * @date 2017-07
 *
 * Ref: https://www.kernel.org/doc/Documentation/networking/tuntap.txt
 *
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>

int main(int argc, char *argv[]){
    int fd;
    int err;
    struct ifreq ifr;
    char buf[1025];
    char dev[] = "la-tun";

    if ((fd = open("/dev/net/tun", O_RDWR)) < 0){
        perror("open tun failed");
        return -1;
    }
    printf("fd: %d\n", fd);

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = IFF_TUN;
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);

    if((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0 ){
        close(fd);
        perror("ioclt(TUNSETIFF) failed");
        return err;
    }

    strncpy(dev, ifr.ifr_name, sizeof(dev) - 1);
    printf("dev: %s\n", dev);

    for (;;){
        size_t n;
        if ((n = read(fd, buf, sizeof(buf) - 1)) > 0){
            printf("read: %ld\n", n);
         }
    }
}
