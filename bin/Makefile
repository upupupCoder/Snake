TARGET:=Snake
Source:=$(wildcard ../src/*.c)
Object:=$(patsubst %.c,%.o,$(Source))
GCC:=arm-linux-gcc

Include:=-I ../inc

LIB:=-L ../libs
LIB_PARAMENT:=-lm -lpthread

$(TARGET):$(Object)
	$(GCC) $^ -o $@ $(Include) $(LIB) $(LIB_PARAMENT)
	

%.o:%.c
	$(GCC) -c $^ -o  $@ $(Include) $(LIB) 

.PHONY:clean all

all:
	$(TARGET)

clean:
	cp $(TARGET) ~/tftpboot
	rm $(Object)	
	







