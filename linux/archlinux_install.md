## 1. 安装准备
1. 官网下载ISO镜像
1. 准备安装介质：USB flash
    > 如果是虚拟机安装，直接将ISO镜像放入CD-ROM盘即可


## 2. 开始安装
1. 从U盘启动，进入系统安装程序的终端
2. 使用默认的键盘布局（US）和字体
2. 检查主机系统引导模式 boot mode
    > `cat /sys/firmware/efi/fw_platform_size`
    > 
    > 假如返回值64或32，则对应位数的UEFI模式，无返回值，则对应BIOS模式
4. 联网

     1. 使用`ip/ip link`命令检查网卡
    2. 如果是网线，直接插上即可
    3. 如果是wifi，使用`iwctl`命令
5. 更新系统时钟：`timedatectl`
6. 磁盘分区：`fdisk`
    > 根目录与efi目录是必须的，此外还可以有home,opt等
7. 格式化分区与挂载分区
    ```
    格式化分区：
    mkfs.ext4 /dev/root_partition
    mkswap /dev/swap_partition
    mkfs.fat -F 32 /dev/efi_system_partition
    挂载分区：
    mount /dev/root_partition /mnt
    mount --mkdir /dev/efi_system_partition /mnt/boot
    swapon /dev/swap_partition
8. 选择镜像服务器
    > 镜像服务器列表文件`/etc/pacman.d/mirrorlist`,可以通过更改此文件中的顺序来更改优先使用的服务器。
9. 安装系统包

    1. 安装基础包
    ```
    pacstrap -K /mnt base linux linux-firmware
    ```
    > 如果是虚拟机安装，可以不安装firmware包
    2. 可选包安装
    ```
    fsck,固件驱动，软件包如网络管理、dhcp服务等，文本编辑器vim，man/man-db/man-pages等

## 3. 安装完成后的配置
1. 生成fstab文件
    ```
    genfstab -U /mnt >> /mnt/etc/fstab
    ```
    查看是否生成，/mnt/etc/fstab.
2. 切换进入新安装系统root
    ```
    arch-chroot /mnt 
    ```
3. 设置时区
    ```
    ln -sf /usr/share/zoneinfo/Region/City /etc/localtime
    使用hwclock生成/etc/adjtime:
    hwclock --systohc
4. Localization
    ```
    注释/etc/locale.gen中的需要的UTF-8的选项行，使用下列命令重生成：
    locale-gen
    编辑locale.conf设置LANG全局变量：
    /etc/locale.conf
    LANG=en_US.UTF-8
    假如还要设置键盘布局，可以更改该设置文件：
    /etc/vconsole.conf
    例：KEYMAP=de-latinl
5. 设置主机名
    ```
    hostname > /etc/hostname
6. 联网
    
    如果在上面已经安装了dhcpcd服务，即可开启此服务，并加入系统启动项即可。
    ``` 
    systemctl start dhcpcd
    systemctl enable dhcpcd
    ```
    使用ip命令设置静态ip等
    ```
    ip addr add 要设置的ip地址/24 broadcast + dev 网卡名
    ip route add default via 默认网关地址 dev 网卡名
7. 设置root密码
    ```
    passwd

8. 安装bootloader并设置
    
    boot和efi模式都使用grub即可。
    > 首先安装grub和efibootmgr
    >
    >使用 `grub-mkconfig -o /boot/grub/grub.cfg`生成grub设置文件

9. 解挂/mnt
    ```
    使用exit退出chroot。
    使用umount -R /mnt解挂所有文件系统。
    
10. reboot重启
    
    完成安装！