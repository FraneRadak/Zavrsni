#include "board.hpp"
#include "PositionStack.hpp"

Long Position::perft(int depth,ofstream&file,Move lastMove,int pos_num) {
    openNode(file);
    int move_counter = 0;
    Move moves[255];
    move_generator(move_counter,moves);
    int i;
    Long nodes = 0;
    writeContent(file, move_counter, moves,lastMove,pos_num);
    if (depth == 0) {
        closeNode(file);
        return 1;
    }
    for (i = 0; i < move_counter; i++) {
        this->make_move(moves[i]);
        nodes += perft(depth - 1,file,moves[i],pos_num+1);
        //cout << "num: " << nodes << endl;
        this->undo_move();
    }
    closeNode(file);
    return nodes;
}
