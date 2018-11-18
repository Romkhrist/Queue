.PHONY: all install uninstall clean

CXX = g++
CFLAGS = -c -Wall
TARGET = Queue
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
INSTALL_PATH = ~/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(LDFLAGS) -o $@ $^
	
$(OBJS): $(SRCS) $(TARGET).h

install:
	-@install -D -m 744 $(TARGET) $(INSTALL_PATH)/$(TARGET)
	@$(MAKE) clean
		
uninstall:
	@rm -rf $(INSTALL_PATH)/$(TARGET)
	
clean:
	@rm -rf $(TARGET) *.o 
