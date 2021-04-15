#!/usr/bin/env perl

srand 94315435;

use strict;
use warnings;

my $n = 200000;
my $m = 10000;
print "$n $m\n";

sub stair {
  my $x = shift;
  if (int rand 20 == 0) {
    return '?';
  } else {
    my $dirn = ('n', 'e', 's', 'w')[$x % 4];
    my $value = 1 + (int($x / 4) % 7);
    return "$dirn $value";
  }
}

for my $i (1 ... $n) {
  print stair($i) . "\n";
}
for my $i (1 ... $m) {
  print stair(341 + $i) . "\n";
}
