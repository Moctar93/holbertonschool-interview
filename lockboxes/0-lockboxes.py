#!/usr/bin/python3

def canUnlockAll(boxes):
    unlocked = set()  # Set of unlocked box indices
    unlocked.add(0)   # Start with box 0 being unlocked
    
    # Iterate over the boxes that are currently unlocked
    for box_index in unlocked:
        # Go through the keys in the current box
        for key in boxes[box_index]:
            # If the key corresponds to a box that isn't unlocked yet, unlock it
            if key < len(boxes) and key not in unlocked:
                unlocked.add(key)
    
    # If the number of unlocked boxes is equal to the total number of boxes, return True
    return len(unlocked) == len(boxes)

