str = """
	original_insert_test();
	test_insert();
	test_iterators();
	test_iterators_operators();
	test_access_operator();
	test_copy_constructor();
	test_begin();
	test_rbegin();
	test_end();
	test_rend();
	test_copy_constructor();"""
str.replace(";", "")
list_functions = str.split("\n")

for i in list_functions:
    print(f"    std::cout << \" -{i}- \" << std::endl;")
    print(f"{i};")