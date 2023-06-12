.PHONY: all
all: a.out

.PHONY: clean
clean:
	rm -f a.out iostream.pcm


CPP_BASE := clang++ \
	-std=c++2b \

CPP := $(CPP_BASE) \
	-Weverything \
	-Wno-c++98-compat-pedantic

a.out: main.cpp
	$(CPP) \
		main.cpp


CPP_SYSTEM_HEADER := $(CPP_BASE) \
	-Wno-everything \
	-I/usr/local/opt/llvm/include \
	-I/usr/local/opt/llvm/include/c++/v1/ \
	-xc++-system-header

iostream.pcm:
	$(CPP_SYSTEM_HEADER) \
		--precompile iostream \
		-o iostream.pcm
