while(<>) {
	s/(\([^\)]*\))/\(\)/g;
	print;
}