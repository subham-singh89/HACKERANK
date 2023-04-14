int R=G.size();
    int C=G[0].size();
    int r=P.size();
    int c=P[0].size();
     bool patternExists = false;
        // Main algorithm
        for(int i = 0; i < R; i++) {
            bool foundMatch = false;
            for(int j = 0; j < C; j++) {
                if(G[i][j] == P[0][0] && (i+r <= R) && (j+c <= C)) {
                    // Potential match
                    bool match = true;
                    for(int x = 0; x < r; x++) {
                        bool rowMatch = true;
                        for(int y = 0; y < c; y++) {
                            if(P[x][y] != G[x+i][y+j]) {
                                rowMatch = false;
                                match = false;
                                break;
                            }
                        }
                        if(!rowMatch) {
                            break;
                        }
                    }
                    if(match) {
                        foundMatch = true;
                        break;
                    }
                }
            }
            if(foundMatch) {
                patternExists = true;
                break;
            }
        }
        if(patternExists) {
            return "YES";
        } else {
            return "NO";
        }
