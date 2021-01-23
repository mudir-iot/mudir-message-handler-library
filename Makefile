BOLD := \e[1m
SGR0 := \e[0m
GREEN := \e[1;32m
RED := \e[1;31m
RESET := \e[0m
YELLOW := \e[1;33m
BLUE := \e[1;34m
CYAN := \e[1;36m
UNDRLN := \e[4m

PROJPFX := $(CYAN)$(UNDRLN)[libmudirmsghandlerdrv]$(SGR0)$(RESET):

CC := arm-linux-gnueabihf-gcc
TESTCC := gcc

DESTDIR := bin
SRCDIR := src
OBJDIR := obj

BUILDVERSION := $(shell git describe --tags --abbrev=0)
BUILDNUMBER := $(shell git describe --tags --long)
BUILDDATE := $(shell date +'%Y-%m-%d')

EXE := libmudirmsghandlerdrv.so.$(BUILDVERSION)
TESTEXE := mudirmsghandlerdrv.test

TESTSRCDIR := test
TESTOUTPUTDIR := testoutput
TESTOUTPUTOBJ1DIR := obj1
TESTOUTPUTOBJ2DIR := obj2

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

SRCFORTEST := $(SRC)
TESTSRC := $(wildcard $(TESTSRCDIR)/*.c)
TESTOBJ1 := $(SRCFORTEST:$(SRCDIR)/%.c=$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ1DIR)/%.o)
TESTOBJ2 := $(TESTSRC:$(TESTSRCDIR)/%.c=$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ2DIR)/%.o)

CPPFLAGS := -Iinclude -Iinclude_lib \
						-D__BUILDDATE__="\"$(BUILDDATE)\"" \
						-D__BUILDNUMBER__="\"$(BUILDNUMBER)\"" \
						-D__BUILDVERSION__="\"$(BUILDVERSION)\""
CFLAGS   := -fPIC -Wall
LDFLAGS  := -Llib/arm -shared -Wl,-soname,$(EXE) 
LDLIBS   := 

TESTCPPFLAGS := -Iinclude_test
TESTCFLAGS := --coverage -g
TESTLDFLAGS := -Llib/x86 -Ltestlib
TESTLDLIBS := -lcunit -lgcov

.PHONY: all clean test printbanner printtestbanner

all: | printbanner $(DESTDIR)/$(EXE)
	@printf '$(PROJPFX)$(YELLOW)$(BOLD)Script for building driver message library ended.$(SGR0)$(RESET)\n'

$(DESTDIR)/$(EXE): $(OBJ) | $(DESTDIR)
	@printf '$(PROJPFX)Linking $(BOLD)$(BLUE)$@$(RESET)$(SGR0) with $(CC)...\n'
	@$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@cp include/msghandlerdrv.h $(DESTDIR)/
	@cp include/common.h $(DESTDIR)/
	@printf '$(PROJPFX)$(GREEN)$(BOLD)Build Completed Successfully.$(SGR0)$(RESET)\n'
	@printf '$(PROJPFX)Output filename: $(YELLOW)$(EXE)$(RESET)\n'
	@printf '$(PROJPFX)$(GREEN)Build Version: $(BUILDNUMBER) Dated: $(BUILDDATE)$(RESET)\n'

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@printf '$(PROJPFX)Compiling $(BOLD)$(BLUE)$<$(RESET)$(SGR0) with $(CC)...\n'
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir $@

$(DESTDIR):
	@mkdir $@

test: | printtestbanner $(TESTOUTPUTDIR)/$(TESTEXE)
	@printf '$(PROJPFX)$(GREEN)$(BOLD)Build Completed Successfully.$(SGR0)$(RESET)\n'
	@printf '$(PROJPFX)Output filename: $(YELLOW)$(TESTEXE)$(RESET)\n'
	@printf '$(PROJPFX)$(GREEN)Build Version: $(BUILDNUMBER) Dated: $(BUILDDATE)$(RESET)\n'
	@printf '$(PROJPFX)$(YELLOW)$(BOLD)Starting test run...$(SGR0)$(RESET)\n'
	@./runTests.sh $(TESTOUTPUTDIR)/$(TESTEXE)
	@printf '$(PROJPFX)$(YELLOW)$(BOLD)Script for testing driver message library ended.$(SGR0)$(RESET)\n'

$(TESTOUTPUTDIR)/$(TESTEXE): $(TESTOBJ1) $(TESTOBJ2) | $(TESTOUTPUTDIR)
	@printf '$(PROJPFX)Linking $(BOLD)$(BLUE)$@$(RESET)$(SGR0) with $(TESTCC)...\n'
	@$(TESTCC) $(TESTLDFLAGS) $^ $(LDLIBS) $(TESTLDLIBS) -o $@

$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ1DIR)/%.o: $(SRCDIR)/%.c | $(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ1DIR)
	@printf '$(PROJPFX)Compiling $(BOLD)$(BLUE)$<$(RESET)$(SGR0) with $(TESTCC)...\n'
	@$(TESTCC) $(CPPFLAGS) $(TESTCPPFLAGS) $(CFLAGS) $(TESTCFLAGS) -c $< -o $@

$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ2DIR)/%.o: $(TESTSRCDIR)/%.c | $(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ2DIR)
	@printf '$(PROJPFX)Compiling $(BOLD)$(BLUE)$<$(RESET)$(SGR0) with $(TESTCC)...\n'
	@$(TESTCC) $(CPPFLAGS) $(TESTCPPFLAGS) $(CFLAGS) -c $< -o $@

$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ1DIR): $(TESTOUTPUTDIR)
	@mkdir -p $@

$(TESTOUTPUTDIR)/$(TESTOUTPUTOBJ2DIR): $(TESTOUTPUTDIR)
	@mkdir -p $@

$(TESTOUTPUTDIR):
	@mkdir -p $@

clean:
	@-rm -rf $(DESTDIR) 2> /dev/null || true
	@-rm -rf $(OBJDIR) 2> /dev/null || true
	@-rm -rf $(TESTOUTPUTDIR) 2> /dev/null || true
	@-rm *.xml 2> /dev/null || true
	@-rm *.html 2> /dev/null || true
	@-rm src/*.gcno 2> /dev/null || true
	@-rm src/*.gcda 2> /dev/null || true
	@-rm *.gcov 2> /dev/null || true
	@-rm -f unittestfail 2> /dev/null || true
	@printf '$(PROJPFX)Clean up complete.\n'

printbanner:
	@printf '$(PROJPFX)$(YELLOW)$(BOLD)Starting script for building driver message library...$(SGR0)$(RESET)\n'

printtestbanner:
	@printf '$(PROJPFX)$(YELLOW)$(BOLD)Starting script for testing driver message library...$(SGR0)$(RESET)\n'