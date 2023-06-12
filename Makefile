.PHONY: all
all: a.out

.PHONY: clean
clean:
	rm -f a.out iostream.pcm

CPP := clang++ \
	-std=c++2b \
	-Weverything \
	-Wno-c++98-compat

CPP_SYSTEM_HEADER := $(CPP) \
	-Wno-reserved-macro-identifier \
	-Wno-pragma-system-header-outside-header \
	-I/usr/local/opt/llvm/include \
	-I/usr/local/opt/llvm/include/c++/v1/ \
	-xc++-system-header \

a.out: main.cpp iostream.pcm
	$(CPP) \
		-fmodule-file=iostream.pcm \
		main.cpp

iostream.pcm:
	$(CPP_SYSTEM_HEADER) \
		--precompile iostream \
		-o iostream.pcm
