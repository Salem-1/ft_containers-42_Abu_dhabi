str = """
		test_mypair();
	test_make_pair();
	test_insert();
	test_iterators();
	test_iterators_operators();
	original_insert_test();
	test_access_operator();
	test_copy_constructor();
	test_begin();
	test_end();
	test_rbegin();
	test_rend();
	test_empty();
	test_size();
	test_max_size();
	test_original_delete();
	test_delete();
	original_test_erase();
	test_accessor();
	test_at();
	test_swap();
	test_equal();
	test_clear();
	test_comp();
	test_value_comp();
	test_count();
	test_allocator();
	test_square();
	test_range_rev_iter_const();
	test_find();
	tet_lower_upper_bound();
	test_equal_range();"""
str.replace(";", "")
list_functions = str.split("\n")

for i in list_functions:
    print(f"	std::cout << \" -{i}- \" << std::endl;")
    print(f"{i};")