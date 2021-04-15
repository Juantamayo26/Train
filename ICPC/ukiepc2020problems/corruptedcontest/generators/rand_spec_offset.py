#!/usr/bin/env python3
import random
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--n", type=int, required=True)
parser.add_argument("--offset", type=int, required=True)
parser.add_argument("--max_zeroes", type=int, required=True)
parser.add_argument("--min_zeroes", type=int, default=0)
parser.add_argument("--max_time", type=int, required=True)
parser.add_argument("--seed")
args = parser.parse_args()

if args.seed is not None:
    secret = 'oSRxYfWgy8n0ckcu47rE'
    random.seed(secret + args.seed)

amount_zeroes = random.randint(args.min_zeroes, args.max_zeroes)

n_left = args.n - amount_zeroes

scores = [random.randint(1, args.max_time) for _ in range(n_left)]
scores += [0]*amount_zeroes

scores.reverse()

# Find correct answer
cur_solved = 0
cur_score = 0
for s in scores:
    if s == 0:
        continue

    if s > cur_score:
        cur_solved += 1
    cur_score = s

scores.reverse()
answer = cur_solved

p = max(1,min(answer + args.offset, 10000))

print("{} {}".format(args.n, p))
for s in scores:
    print(s)

