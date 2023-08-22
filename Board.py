class Board:
    """
    Maintain positions of all pieces on board through a 96 bit number
    Track if any captures can be made on a turn (forced move)
    Update positions of pieces
    Have red start at 0 side, black at 7 side
    """
    def __init__(self):
        # initialize all squares to None
        black = 1
        red = 2
        self.board = [None] * 32
        # Initializes starting board with red on starting squares 0-11 and black on squares 20-31
        for i in range(12):
            self.board[i] = 1
            self.board[i + 20] = 2
        for i in range(12, 20):
            self.board[i] = 0

    # Returns piece at the index
    def get_square(self, index):
        return self.board[index]
    # def valid_moves(self):
    #     return


if __name__ == "__main__":
    checkers = Board()
    index_0 = checkers.get_square(0)
    index_25 = checkers.get_square(15)
    index_32 = checkers.get_square(31)
    print(f"0: {index_0}\n15: {index_25}\n31: {index_32}")