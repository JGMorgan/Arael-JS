#include <vector>
#include <thread>

std::vector<std::vector<double>> dot(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b) {
    std::vector<std::thread> threads;
    std::vector<std::vector<double>> out;
    for (int i = 0; i < a.size(); i++) {
        std::vector<double> row(b[0].size(), 0);
        out.append(row);
        for (int j = 0; j < b[0].size(); j++) {
            threads.push_back(std::thread (a, b, i, j));
        }
    }
}

double calc_cell_val(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b, int i, int j) {
    int sum = 0;
    for (int k = 0; k < b.size(); k++) {
        sum += a[i][k] * b[k][j];
    }
    return sum;
}
