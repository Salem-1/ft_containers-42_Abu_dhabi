str = """
	rev_operators(void)
rev_mli_comp(void)
ret2(void)
test_insert_mli()
test_erase_mli(void)
test_copy_constructor_mli()
test_biderection_at(void)
test_at_mli(void)
test_at()
test_push_back()
test_pop()
test_clear()
test_equalibrium()
test_begin_end()
test_rbegin_rend()
test_crbegin_crend()
test_const_iter()
test_smaller()
test_larger()
test_larger_or_equal()
test_less_or_equal()
test_not_equal()
test_insert()
test_my_insert()
test_my_insert_iter()
test_allocator_const()
test_fill_vec_constr()
test_fill_vec_iter_constr()
test_assign()
test_assign2()
test_equal_operator()
test_copy_constructor()
test_erase()
test_erase_with_iter()
test_swap()
test_non_member_swap()"""
str.replace(";", "")
list_functions = str.split("\n")

for i in list_functions:
    print(f"	std::cout << \" -{i}- \" << std::endl;")
    print(f"	{i};")