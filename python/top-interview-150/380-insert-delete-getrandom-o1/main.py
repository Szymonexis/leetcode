import random


class RandomizedSet:
    def __init__(self):
        self.storage: dict[int, int] = {}

    def insert(self, val: int) -> bool:
        was_not_present = False
        try:
            self.storage[val]
        except KeyError:
            was_not_present = True

        self.storage[val] = val
        return was_not_present

    def remove(self, val: int) -> bool:
        was_present = True
        try:
            del self.storage[val]
        except KeyError:
            was_present = False

        return was_present

    def getRandom(self) -> int:
        return random.choice(list(self.storage.keys()))
