

MY_TARGETS = source

.PHONY: all $(MY_TARGETS)
	all: $(MY_TARGETS)

$(MY_TARGETS):
	    @$(MAKE) -C $@;
