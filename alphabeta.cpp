class alphabeta:public makemove{
    const int MAX = 1000;
    const int MIN = -1000;
    int mg_value[7] = { 0, 82, 337, 365, 477, 1025,  0};
    int eg_value[7] = { 0, 94, 281, 297, 512,  936,  0};
    int mg_pawn_table[78] = {
      0,   0,   0,   0,   0,   0,  0,   0, 0, 0,
     98, 134,  61,  95,  68, 126, 34, -11, 0, 0,
     -6,   7,  26,  31,  65,  56, 25, -20, 0, 0,
    -14,  13,   6,  21,  23,  12, 17, -23, 0, 0,
    -27,  -2,  -5,  12,  17,   6, 10, -25, 0, 0,
    -26,  -4,  -4, -10,   3,   3, 33, -12, 0, 0,
    -35,  -1, -20, -23, -15,  24, 38, -22, 0, 0,
      0,   0,   0,   0,   0,   0,  0,   0,
};

int eg_pawn_table[78] = {
      0,   0,   0,   0,   0,   0,   0,   0, 0, 0,
    178, 173, 158, 134, 147, 132, 165, 187, 0, 0,
     94, 100,  85,  67,  56,  53,  82,  84, 0, 0,
     32,  24,  13,   5,  -2,   4,  17,  17, 0, 0,
     13,   9,  -3,  -7,  -7,  -8,   3,  -1, 0, 0,
      4,   7,  -6,   1,   0,  -5,  -1,  -8, 0, 0,
     13,   8,   8,  10,  13,   0,   2,  -7, 0, 0,
      0,   0,   0,   0,   0,   0,   0,   0,
};

int mg_knight_table[78] = {
    -167, -89, -34, -49,  61, -97, -15, -107, 0, 0,
     -73, -41,  72,  36,  23,  62,   7,  -17, 0, 0,
     -47,  60,  37,  65,  84, 129,  73,   44, 0, 0,
      -9,  17,  19,  53,  37,  69,  18,   22, 0, 0,
     -13,   4,  16,  13,  28,  19,  21,   -8, 0, 0,
     -23,  -9,  12,  10,  19,  17,  25,  -16, 0, 0,
     -29, -53, -12,  -3,  -1,  18, -14,  -19, 0, 0,
    -105, -21, -58, -33, -17, -28, -19,  -23,
};

int eg_knight_table[78] = {
    -58, -38, -13, -28, -31, -27, -63, -99, 0, 0,
    -25,  -8, -25,  -2,  -9, -25, -24, -52, 0, 0,
    -24, -20,  10,   9,  -1,  -9, -19, -41, 0, 0,
    -17,   3,  22,  22,  22,  11,   8, -18, 0, 0,
    -18,  -6,  16,  25,  16,  17,   4, -18, 0, 0,
    -23,  -3,  -1,  15,  10,  -3, -20, -22, 0, 0,
    -42, -20, -10,  -5,  -2, -20, -23, -44, 0, 0,
    -29, -51, -23, -15, -22, -18, -50, -64,
};

int mg_bishop_table[78] = {
    -29,   4, -82, -37, -25, -42,   7,  -8, 0, 0,
    -26,  16, -18, -13,  30,  59,  18, -47, 0, 0,
    -16,  37,  43,  40,  35,  50,  37,  -2, 0, 0,
     -4,   5,  19,  50,  37,  37,   7,  -2, 0, 0,
     -6,  13,  13,  26,  34,  12,  10,   4, 0, 0,
      0,  15,  15,  15,  14,  27,  18,  10, 0, 0,
      4,  15,  16,   0,   7,  21,  33,   1, 0, 0,
    -33,  -3, -14, -21, -13, -12, -39, -21,
};

int eg_bishop_table[78] = {
    -14, -21, -11,  -8, -7,  -9, -17, -24, 0, 0,
     -8,  -4,   7, -12, -3, -13,  -4, -14, 0, 0,
      2,  -8,   0,  -1, -2,   6,   0,   4, 0, 0,
     -3,   9,  12,   9, 14,  10,   3,   2, 0, 0,
     -6,   3,  13,  19,  7,  10,  -3,  -9, 0, 0,
    -12,  -3,   8,  10, 13,   3,  -7, -15, 0, 0,
    -14, -18,  -7,  -1,  4,  -9, -15, -27, 0, 0,
    -23,  -9, -23,  -5, -9, -16,  -5, -17,
};

int mg_rook_table[78] = {
     32,  42,  32,  51, 63,  9,  31,  43, 0, 0,
     27,  32,  58,  62, 80, 67,  26,  44, 0, 0,
     -5,  19,  26,  36, 17, 45,  61,  16, 0, 0,
    -24, -11,   7,  26, 24, 35,  -8, -20, 0, 0,
    -36, -26, -12,  -1,  9, -7,   6, -23, 0, 0,
    -45, -25, -16, -17,  3,  0,  -5, -33, 0, 0,
    -44, -16, -20,  -9, -1, 11,  -6, -71, 0, 0,
    -19, -13,   1,  17, 16,  7, -37, -26,
};

int eg_rook_table[78] = {
    13, 10, 18, 15, 12,  12,   8,   5, 0, 0,
    11, 13, 13, 11, -3,   3,   8,   3, 0, 0,
     7,  7,  7,  5,  4,  -3,  -5,  -3, 0, 0,
     4,  3, 13,  1,  2,   1,  -1,   2, 0, 0,
     3,  5,  8,  4, -5,  -6,  -8, -11, 0, 0,
    -4,  0, -5, -1, -7, -12,  -8, -16, 0, 0,
    -6, -6,  0,  2, -9,  -9, -11,  -3, 0, 0,
    -9,  2,  3, -1, -5, -13,   4, -20,
};

int mg_queen_table[78] = {
    -28,   0,  29,  12,  59,  44,  43,  45, 0, 0,
    -24, -39,  -5,   1, -16,  57,  28,  54, 0, 0,
    -13, -17,   7,   8,  29,  56,  47,  57, 0, 0,
    -27, -27, -16, -16,  -1,  17,  -2,   1, 0, 0,
     -9, -26,  -9, -10,  -2,  -4,   3,  -3, 0, 0,
    -14,   2, -11,  -2,  -5,   2,  14,   5, 0, 0,
    -35,  -8,  11,   2,   8,  15,  -3,   1, 0, 0,
     -1, -18,  -9,  10, -15, -25, -31, -50,
};

int eg_queen_table[78] = {
     -9,  22,  22,  27,  27,  19,  10,  20, 0, 0,
    -17,  20,  32,  41,  58,  25,  30,   0, 0, 0,
    -20,   6,   9,  49,  47,  35,  19,   9, 0, 0,
      3,  22,  24,  45,  57,  40,  57,  36, 0, 0,
    -18,  28,  19,  47,  31,  34,  39,  23, 0, 0,
    -16, -27,  15,   6,   9,  17,  10,   5, 0, 0,
    -22, -23, -30, -16, -16, -23, -36, -32, 0, 0,
    -33, -28, -22, -43,  -5, -32, -20, -41,
};

int mg_king_table[78] = {
    -65,  23,  16, -15, -56, -34,   2,  13, 0, 0,
     29,  -1, -20,  -7,  -8,  -4, -38, -29, 0, 0,
     -9,  24,   2, -16, -20,   6,  22, -22, 0, 0,
    -17, -20, -12, -27, -30, -25, -14, -36, 0, 0,
    -49,  -1, -27, -39, -46, -44, -33, -51, 0, 0,
    -14, -14, -22, -46, -44, -30, -15, -27, 0, 0,
      1,   7,  -8, -64, -43, -16,   9,   8, 0, 0,
    -15,  36,  12, -54,   8, -28,  24,  14,
};

int eg_king_table[78] = {
    -74, -35, -18, -18, -11,  15,   4, -17, 0, 0,
    -12,  17,  14,  17,  17,  38,  23,  11, 0, 0,
     10,  17,  23,  15,  20,  45,  44,  13, 0, 0,
     -8,  22,  24,  27,  26,  33,  26,   3, 0, 0,
    -18,  -4,  21,  24,  27,  23,   9, -11, 0, 0,
    -19,  -3,  11,  21,  23,  16,   7,  -9, 0, 0,
    -27, -11,   4,  13,  14,   4,  -5, -17, 0, 0,
    -53, -34, -21, -11, -28, -14, -24, -43
};
    public:
    alphabeta(){
        vector<int> moves;
        movedata.push_back(moves);
        movedata.push_back(moves);
    }
    vector<vector<int>> movedata;
    int DEPTH=0;
    int minimax(int depth,
            bool maximizingPlayer, int alpha,
            int beta);
    int Evaluate();
    int bestmove(int n);
};
int alphabeta::bestmove(int n){
    int fn=0;
    DEPTH=n;
    movedata[0].clear();
    movedata[1].clear();
    if(side==0){
        fn=minimax(n,true,-1000,1000);
    }else{
        fn=minimax(n,false,-1000,1000);
    }
    int i;
    for(i= 0;i<movedata[0].size();i++){
        if(fn==movedata[1][i]){
            break;
        }
    }
    return movedata[0][i];
}

int alphabeta::Evaluate(){
    int sq,ptype,score=0;
    if(!(Material[0]<51000 || Material[1]>-51000)){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                ptype=Brd[i][j];
                sq=(i*10)+j;
                switch(ptype){
                    
                    case 1:score+=(mg_pawn_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 2:score+=(mg_knight_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 3:score+=(mg_bishop_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 4:score+=(mg_rook_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 5: score+=(mg_queen_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 6:score+=(mg_king_table[78-sq]+ mg_value[ptype]) ;
                            break;
                    case 7:score-=(mg_pawn_table[sq] + mg_value[ptype-6]);
                            break;
                    case 8:score-=(mg_knight_table[sq]+ mg_value[ptype-6]) ;
                            break;
                    case 9:score-=(mg_bishop_table[sq]+ mg_value[ptype-6]) ;
                            break;
                    case 10:score-=(mg_rook_table[sq]+ mg_value[ptype-6]) ;
                            break;
                    case 11:score-=(mg_queen_table[sq]+ mg_value[ptype-6]) ;
                            break;
                    case 12:score-=(mg_king_table[sq]+ mg_value[ptype-6]) ;
                            break;
                }
            }
        }
    }
    else{
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                ptype=Brd[i][j];
                sq=(i*10)+j;
                switch(ptype){
                   case 1: score+=(eg_pawn_table[78-sq] + eg_value[ptype]) ;
                        break;
                   case 2: score+=(eg_knight_table[78-sq]+ eg_value[ptype]);
                        break;
                   case 3: score+=(eg_bishop_table[78-sq]+ eg_value[ptype]);
                        break;
                   case 4: score+=(eg_rook_table[78-sq]+ eg_value[ptype]);
                        break;
                    case 5:score+=(eg_queen_table[78-sq]+ eg_value[ptype]);
                        break;
                    case 6:score+=(eg_king_table[78-sq]+ eg_value[ptype]);
                        break;
                    case 7:score-=(eg_pawn_table[sq]+ eg_value[ptype-6]);
                        break;
                    case 8:score-=(eg_knight_table[sq]+ eg_value[ptype-6]);
                        break;
                    case 9:score-=(eg_bishop_table[sq]+ eg_value[ptype-6]);
                        break;
                    case 10:score-=(eg_rook_table[sq]+ eg_value[ptype-6]);
                        break;
                    case 11:score-=(eg_queen_table[sq]+ eg_value[ptype-6]);
                        break;
                    case 12:score-=(eg_king_table[sq]+ eg_value[ptype-6]);
                }
            }
        }
    }
    return score;
}

int alphabeta::minimax(int depth, bool maximizingPlayer, int alpha, int beta){
    vector<int> movelist1;

    if (depth == 0){
        return Evaluate();
    }
    if (maximizingPlayer)
    {   

        int best = MIN;
        movelist.clear();
        GenerateAllMoves();
        movelist1 = movelist;
        movelist.clear();
        string PrevFen;
        PrevFen = generateFen();
        for (int i = 0; i < movelist1.size(); i++)
        { 
            execmove(movelist1[i]);
            int val = minimax(depth - 1, false, alpha, beta);
            if(depth == DEPTH){
                movedata[0].push_back(movelist1[i]);
                movedata[1].push_back(val); 
            }
            ParseFEN(PrevFen);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha){
                break;}
        }
        
        return best;
    }
    else
    {
        int best = MAX;
        movelist.clear();
        GenerateAllMoves();
        movelist1 = movelist;
        movelist.clear();
        string PrevFen;
        PrevFen = generateFen();
        for (int i = 0; i < movelist1.size(); i++)
        {
            execmove(movelist1[i]);
            int val = minimax(depth - 1,true, alpha, beta);
            if(depth == DEPTH){
                movedata[0].push_back(movelist1[i]);
                movedata[1].push_back(val); 
            }
            ParseFEN(PrevFen);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha){
                 break;
            }   
        }
        return best;
    }
}