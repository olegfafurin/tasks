while(<>) {
	print if /\([^()]*\w+[^()]*\)/;
}