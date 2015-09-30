C++ = g++

CCFLAGS = -Wall -I/usr/include/mysql -finline-functions -O3
LDFLAGS = -L/usr/libmysql -lmysqlclient
DIR = $(shell pwd)

APP = create_table retrieva_data last_row_id headers multiple_statements

all: $(APP)

%.o: %.cpp
	$(C++) $(CCFLAGS) $< -c

create_table: create_table.o
	$(C++) $^ -o $@ $(LDFLAGS)
retrieva_data: retrieva_data.o
	$(C++) $^ -o $@ $(LDFLAGS)
last_row_id: last_row_id.o
	$(C++) $^ -o $@ $(LDFLAGS)
headers: headers.o
	$(C++) $^ -o $@ $(LDFLAGS)
multiple_statements:  multiple_statements.o
	$(C++) $^ -o $@ $(LDFLAGS)

clean:
	rm -f *.o $(APP)

install:
	export PATH=$(DIR):$$PATH
