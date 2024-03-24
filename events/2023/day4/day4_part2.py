import functools
from day4 import parse

class Card:
    def __init__(self, id_:int, win_nums:set, nums:set):
        self._id = id_
        self.win_nums = win_nums
        self.nums = nums
        self._matching_nums_count = len(self.win_nums & self.nums)

    @property
    def id(self):
        return self._id

    def count_matching_nums(self):
        return self._matching_nums_count

    def copy(self):
        return Card(self._id, self.win_nums, self.nums)



if __name__ == "__main__":
    with open("input.txt") as f:
        # card id = id in text  - 1 to match with 0 index based arrays
        cards_deck = [ [Card(card_id, *parse(line.strip()))] for card_id, line in enumerate(f.readlines(), start=0) ]

    for cards in cards_deck:
        for card in cards:
            if card.count_matching_nums() > 0:
                for i in range(card.count_matching_nums()):
                    copy_index = card.id + i + 1 # zero based array
                    card_to_copy = cards_deck[copy_index][0]
                    cards_deck[copy_index].append(card_to_copy.copy())


    cards_count = functools.reduce(lambda count, cards: count + len(cards), cards_deck, 0)
    print(f"Total cards = {cards_count}")