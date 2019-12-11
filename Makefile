NAME = Interpretor

CC= clang++

FLAGS= -Wall -Wextra -Werror

SRCS= srcs/Instruction.cpp\
	  srcs/main.cpp

all: ${NAME}

${NAME}:
	${CC} -o ${NAME} ${FLAGS} ${SRCS}

clean:
	rm -r ${NAME}
