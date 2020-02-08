my $blank_counter = 0;
my $beginning = 1;
LINE: while (<>) {
	if (/^\ *$/) {
	    #print "blank";
		$blank_counter++;
		next LINE;
	}
    if ($blank_counter > 0 && $beginning == 0) {
        print "\n";
    }
    $beginning = 0;
	$blank_counter = 0;
	s/[\ ]{2,}/\ /g;
    s/^\ (.+?)/$1/;
    s/(.+?)\ $/$1/;
	print;
    }
