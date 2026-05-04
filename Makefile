CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR  = src
SRCS     = $(SRC_DIR)/justeprix.cpp \
           $(SRC_DIR)/controller.cpp \
           $(SRC_DIR)/model.cpp \
           $(SRC_DIR)/view.cpp
TARGET   = justeprix

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
