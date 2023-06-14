.PHONY: all
all: a.out

.PHONY: clean
clean:
	rm -f a.out Config.pcm iostream.pcm term_colors.pcm


CPP_BASE := clang++ \
	-std=c++2b \

CPP := $(CPP_BASE) \
	-Weverything \
	-Wno-c++98-compat-pedantic \
	-fexperimental-library \
	-fprebuilt-module-path=.


a.out: main.cpp Config.pcm term_colors.pcm
	$(CPP) \
		Config.pcm \
		term_colors.pcm \
		main.cpp


CPP_MODULE := $(CPP) \
	--precompile

Config.pcm: Config.cppm
	$(CPP_MODULE) \
		Config.cppm \
		-o Config.pcm

term_colors.pcm: term_colors.cppm
	$(CPP_MODULE) \
		term_colors.cppm \
		-o term_colors.pcm


CPP_SYSTEM_HEADER := $(CPP_BASE) \
	-Wno-everything \
	-I/usr/local/opt/llvm/include \
	-I/usr/local/opt/llvm/include/c++/v1/ \
	-xc++-system-header

iostream.pcm:
	$(CPP_SYSTEM_HEADER) \
		--precompile iostream \
		-o iostream.pcm
