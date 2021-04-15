#!/usr/bin/env perl

use strict;
use warnings;

my $i = 0;
while (<>) {
  if ($i++ > 0 && (int rand 3) != 0) {
    print "?\n";
  } else {
    print "$_";
  }
}
