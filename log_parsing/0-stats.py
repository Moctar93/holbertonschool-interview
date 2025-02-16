#!/usr/bin/python3
"""
Log Parsing Module

This script reads log data from stdin line by line, computes metrics, and prints statistics
every 10 lines or upon a keyboard interruption (CTRL + C). The input format is expected to be:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

If the format is not matched, the line is skipped. The script computes the total file size
and counts the occurrences of specific status codes (200, 301, 400, 401, 403, 404, 405, 500).
"""

import sys

def print_stats(total_size, status_counts):
    """
    Prints the computed statistics.

    Args:
        total_size (int): The total file size computed from the log lines.
        status_counts (dict): A dictionary containing counts of status codes.
    """
    print(f"File size: {total_size}")
    for status_code in sorted(status_counts.keys()):
        print(f"{status_code}: {status_counts[status_code]}")

def main():
    """
    Main function to read log data from stdin, compute metrics, and print statistics.

    The function reads input line by line, parses each line to extract the file size and
    status code, and updates the total file size and status code counts. Statistics are
    printed every 10 lines or upon a keyboard interruption.
    """
    total_size = 0
    status_counts = {}
    valid_status_codes = {200, 301, 400, 401, 403, 404, 405, 500}
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1

            # Debugging: Print the line being processed
            print(f"Processing line: {line.strip()}", file=sys.stderr)

            # Parse the line
            parts = line.split()
            if len(parts) < 7:
                print("Skipping line: Invalid format", file=sys.stderr)
                continue

            # Extract file size and status code
            try:
                file_size = int(parts[-1])
                status_code = int(parts[-2])
                print(f"Extracted file size: {file_size}, status code: {status_code}", file=sys.stderr)
            except (ValueError, IndexError):
                print("Skipping line: Invalid file size or status code", file=sys.stderr)
                continue

            # Update total file size
            total_size += file_size

            # Update status code counts
            if status_code in valid_status_codes:
                status_counts[status_code] = status_counts.get(status_code, 0) + 1
                print(f"Updated status counts: {status_counts}", file=sys.stderr)

            # Print stats every 10 lines
            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        # Print stats on keyboard interruption
        print_stats(total_size, status_counts)
        raise

if __name__ == "__main__":
    main()
