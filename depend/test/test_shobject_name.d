objects/test/test_shobject_name.o: test/test_shobject_name.c test/test_shobject_name.h \
  test/munit.h test/../shobject_name.h | objects/test
	$(CC) -c $(CFLAGS) $< -o $@
