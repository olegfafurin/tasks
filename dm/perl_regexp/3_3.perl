my %set;
while(<>) {
    while (m'<a.+?href="(((https?)|(ftp))://)?(\w.*?)(/|:|").*?>'g) {
        $set{$5}++;
    }
}
my @res = sort keys %set;
for my $a (@res) {
    print "$a\n"
}
