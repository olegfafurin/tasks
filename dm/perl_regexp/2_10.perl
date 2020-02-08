while(<>) {
	s/a.*?aa.*?aa[^a]*a/bad/g;
	print;
}