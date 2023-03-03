# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 09:47:26 by lcrimet           #+#    #+#              #
#    Updated: 2023/03/03 18:51:40 by lcrimet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= mini_rt

VERSION		= 0.0.1

SRCS		= srcs/main.c \
			  srcs/math/vec3.c \
			  srcs/init/init_mlx.c \
			  srcs/event_management/events.c \
			  srcs/ray/ray.c \
			  srcs/camera/camera.c \

HEADERS		= includes \
			  
CCDEFS		= VERSION=\"$(VERSION)\" \
			  NAME=\"$(NAME)\" \

LIB_NAMES	= libmlx \
			  libft \
			  
LIBS		= $(subst lib,-l,$(notdir $(LIB_NAMES)))
LIB_LD		= $(foreach lib,$(LIB_NAMES),-L$(lib))
LIB_PATHS	= $(foreach lib,$(LIB_NAMES),$(lib)/$(notdir $(lib)).a)
LIB_HEADERS	= $(foreach lib,$(LIB_NAMES),-I$(lib)/includes/)

CCDEFSFLGS	= $(foreach def,$(CCDEFS),-D $(def))

BUILDDIR	= .build
OBJS		= $(SRCS:%.c=$(BUILDDIR)/%.o) 
DEPS		= $(SRCS:%.c=$(BUILDDIR)/%.d) 
CC			= cc
CCWFLGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address
CCDBGFLGS	= -DDEBUG
CCDEPSFLAGS	= -MMD -MP
RM			= rm -Rf
MAKE		= make -C
MKDIR		= mkdir
ECHO		:= echo -e
MLX_FLAGS	= -Llibmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
MLX_CCFLAGS	= #-O3

all : banner libs $(NAME)

$(NAME) : $(LIB_PATHS) $(OBJS)
		$(CC) $(CCWFLGS) $(CCDBGFLGS) -o $(NAME) $(OBJS) $(LIB_LD) $(LIBS) $(MLX_FLAGS)

bonus : $(NAME)

libs :
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib); \
		)

clean : banner
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) clean; \
		)
		-$(RM) $(BUILDDIR)

fclean : clean
		$(foreach lib, $(LIB_NAMES), \
			$(MAKE) $(lib) fclean; \
		)
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS)

$(BUILDDIR)/%.o : %.c Makefile $(LIB_PATHS)
		@mkdir -p $(@D)
		$(CC) $(CCWFLGS) $(CCDEPSFLAGS) $(CCDBGFLGS) $(CCDEFSFLGS) $(MLX_CCFLAGS) -I$(HEADERS) $(LIB_HEADERS) -c $< -o $@

banner :
		
		@$(ECHO) '\x1b[1m\x1b[38;5;6m                          iiii                     iiii                   RRRRRRRRRRRRRRRRR   TTTTTTTTTTTTTTTTTTTTTTT'
		@$(ECHO) '\x1b[1m\x1b[38;5;6m                         i::::i                   i::::i                  R::::::::::::::::R  T:::::::::::::::::::::T'
		@$(ECHO) '\x1b[1m\x1b[38;5;6m                          iiii                     iiii                   R::::::RRRRRR:::::R T:::::::::::::::::::::T'
		@$(ECHO) '\x1b[1m\x1b[38;5;6m                                                                          RR:::::R     R:::::RT:::::TT:::::::TT:::::T'
		@$(ECHO) '\x1b[1m\x1b[38;5;6m   mmmmmmm    mmmmmmm   iiiiiiinnnn  nnnnnnnn    iiiiiii                    R::::R     R:::::RTTTTTT  T:::::T  TTTTTT'
		@$(ECHO) '\x1b[1m\x1b[38;5;6m mm:::::::m  m:::::::mm i:::::in:::nn::::::::nn  i:::::i                    R::::R     R:::::R        T:::::T '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::::::::mm::::::::::m i::::in::::::::::::::nn  i::::i                    R::::RRRRRR:::::R         T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::::::::::::::::::::m i::::inn:::::::::::::::n i::::i  ---------------   R:::::::::::::RR          T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm:::::mmm::::::mmm:::::m i::::i  n:::::nnnn:::::n i::::i  -:::::::::::::-   R::::RRRRRR:::::R         T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i  ---------------   R::::R     R:::::R        T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i                    R::::R     R:::::R        T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::m i::::i  n::::n    n::::n i::::i                    R::::R     R:::::R        T:::::T        '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::i                 RR:::::R     R:::::R      TT:::::::TT      '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::i                 R::::::R     R:::::R      T:::::::::T      '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mm::::m   m::::m   m::::mi::::::i n::::n    n::::ni::::::i                 R::::::R     R:::::R      T:::::::::T      '
		@$(ECHO) '\x1b[1m\x1b[38;5;6mmmmmmm   mmmmmm   mmmmmmiiiiiiii nnnnnn    nnnnnniiiiiiii                 RRRRRRRR     RRRRRRR      TTTTTTTTTTT      '
		@$(ECHO) '\x1b[1m\x1b[38;5;6m \x1b[0mversion \x1b[1m$(VERSION)                                                                                         \x1b[38;5;11m lcrimet\x1b[0m'

.PHONY: all clean fclean re bonus libs banner