#!/usr/bin/env python3

import sys

def main():
    nums = [int(line.strip()) for line in sys.stdin if line.strip()]

    print(sum(nums) / len(nums))

if __name__ == "__main__":
    main()
