#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int surfaceArea(vector<vector<int>> A) {
     enum dir{NORTH = 0, EAST, SOUTH, WEST};
    int total_surface_area{}, rows = A.size(), cols = A[0].size();
    
    // iterate through each grid cell A[i][j]
    for(int r{}; r < rows; ++r){
        for(int c{}; c < cols; ++c){
            int height = A[r][c]; // height of current cell
            // calculate height differences between all neighbours (cardinal)
            int neighbours[4]; // n e s w
            // r - 1, r + 1, c - 1, c + 1
            if(r - 1 < 0) neighbours[dir::NORTH] = height;
            else neighbours[dir::NORTH] = height - A[r-1][c];
            if(r + 1 >= rows) neighbours[dir::SOUTH] = height;
            else neighbours[dir::SOUTH] = height - A[r+1][c];
            if(c - 1 < 0) neighbours[dir::WEST] = height;
            else neighbours[dir::WEST] = height - A[r][c-1];
            if(c + 1 >= cols) neighbours[dir::EAST] = height;
            else neighbours[dir::EAST] = height - A[r][c+1];
            
            int local_surface_area = 2; // top + bottom
            // go through all neighbours and check the height difference (only take +)
            for(int x{}; x < 4; ++x){
                if(neighbours[x] > 0)
                    local_surface_area += neighbours[x];
            }
            total_surface_area += local_surface_area;
        }
    }
    return total_surface_area;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
