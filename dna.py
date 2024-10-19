import csv
import sys


def main():
    if len(sys.argv) != 3:
        sys.exit("your input should be 3")

    # Read database file into a dictionary called database after reading
    database = []
    with open(sys.argv[1], "r") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            database.append(row)

    # Read DNA sequence file into a variable.
    with open(sys.argv[2], "r") as dna:
        sequence = dna.read()

    # databsde[0] means 1st line in dic. and [1:] saying start from the 2end home in the first line.shouldnt consider when line ends and is no key anymoore?
    # guess '.keys' is like a second beacket index in c++. like database[][].
    strs = list(database[0].keys())[1:]

    # gotta save the longest mach result in a list here called result
    results = {}
    for subsequence in strs:
        results[subsequence] = longest_match(sequence, subsequence)

        # Check database for matching profiles. person is a key of the database velues as a dictionary file
    for person in database:
        match = 0
        for subsequence in strs:
            if int(person[subsequence]) == results[subsequence]:
                match += 1

            # check is all subsequences match
        if match == len(strs):
            print(person["name"])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
