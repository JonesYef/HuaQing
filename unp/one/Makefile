C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))
# 目标文件也是多个
TARGETLIST = $(patsubst %.c, %, $(C_SRC))

.PHONY:all clean
# 这句不写规则的语句可以自动把相应的a.c b.c编译成a b，神奇~
all:${TARGETLIST}

clean:  
	rm -f ${TARGETLIST} *.o 
