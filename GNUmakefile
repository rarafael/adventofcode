CC	:= cc
CFLAGS	:= -ggdb -Wall -Wextra -std=c99 -O2 -Wno-unused-result -Wno-unused-parameter
BINARY	:= program.bin

all:
define make-year
$1/$2/$(BINARY): $1/$2/source.c $1/$2/input
	$(CC) $(CFLAGS) $1/$2/source.c -o $1/$2/$(BINARY)
	$1/$2/$(BINARY) 1 ./$1/$2/input > ./$1/$2/output_one
	$1/$2/$(BINARY) 2 ./$1/$2/input > ./$1/$2/output_two
all += $1/$2/$(BINARY)
endef

define make-days
$(foreach day,$(notdir $(wildcard $1/*)),$(eval $(call make-year,$1,$(day))))
endef

$(foreach year,$(notdir $(wildcard 20*)),$(eval $(call make-days,$(year))))
all: $(all)
clean: $(all)
	rm $^
