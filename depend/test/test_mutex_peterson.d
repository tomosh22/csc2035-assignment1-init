objects/test/test_mutex_peterson.o: test/test_mutex_peterson.c \
  test/../mutex_peterson.h test/../mutex.h test/../ipc.h test/../proc.h \
  test/../shobject_name.h test/test_mutex_peterson.h test/munit.h \
  test/procs4tests.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
