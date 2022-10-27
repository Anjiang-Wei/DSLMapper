# TODO : Error out if LEGION_DIR isn't defined.
INCLUDE_PATH=-I$(LEGION_DIR)/runtime -I$(LEGION_DIR)/bindings/regent -I$(CUDA)/include
CXXFLAGS=-std=c++11 -O2 -Wall -Werror -fPIC -shared

objects=libdsl_mapper.so

.PHONY: clean

all: libdsl_mapper.so

clean:
	-rm $(objects)

libdsl_mapper.so: beam_mapper.cc libautomap_base.so beam_mapper.h automap.h 
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -o $@ $^
