CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mfloat-abi=soft -mthumb -std=gnu11 -Wall -O0
#LDFLAGS= -mcpu=$(MACH) -mfloat-abi=soft --specs=nano.specs -T stm32_ls.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mfloat-abi=soft --specs=rdimon.specs -T stm32_ls.ld -Wl,-Map=final.map

all:main.o led.o stm32_startup.o syscalls.o final.elf 
semi:main.o led.o stm32_startup.o syscalls.o final_sh.elf 

main.o:main.c
	$(CC) $(CFLAGS) -o $@ $^
led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^

stm32_startup.o:stm32_startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^

final.elf:main.o led.o stm32_startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^
final_sh.elf:main.o led.o stm32_startup.o 
	$(CC) $(LDFLAGS_SH) -o $@ $^

load: 
	openocd -f "board/stm32f4discovery.cfg"

clean:
	rm -rf *.o *.elf
