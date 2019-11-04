CXX  := g++

MAJSRC = .

PROG := majority

MODULES := $(wildcard src/ext*) \
	src \
	src/brc

all: $(PROG)
default: $(PROG)

INCLUDES += -I$(MAJSRC)/src

CXXLAGS    += -Wall

SRC  :=

.PHONY: all default tags clean docs cmake_info

include $(patsubst %, $(MAJSRC)/%/module.make, $(MODULES))

OBJ := $(patsubst %.cpp, %.o, $(filter %.cpp, $(SRC)))

LIBOBJ := $(filter-out src/main.o,$(OBJ))

# implicit rules
%.o: %.cpp
	@echo "// Compiling:" $(LOCAL_PATH)/$<
	$(CXX) -std=c++11 -c $(INCLUDES) $(CXXFLAGS) $< -o $@

# Actual targets

$(PROG): $(OBJ)
	@echo "// Building binary:" $(notdir $@)
	$(CXX)  -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	@echo "// Cleaning up..."
	rm -rvf $(PROG) lib$(PROG).a $(OBJ) $(OBJ:.o=.d)