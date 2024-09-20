#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Runner {
    int index;
    int number;
    string name;
    int preferred_distance;
    int assigned_distance;
    char start_mark;
    char end_mark;
};

int main() {
    vector<Runner> runners =  {

        {1, 35, "中島", 150, 0, 'a', 'a'},

        {2, 7, "上西", 100, 0, 'a', 'a'},

        {3, 14, "小南", 100, 0, 'a', 'a'},

        {4, 16, "関原", 100, 0, 'a', 'a'},

        {5, 6, "金尾", 100, 0, 'a', 'a'},

        {6, 2, "石川", 100, 0, 'a', 'a'},

        {7, 4, "井上", 100, 0, 'a', 'a'},

        {8, 17, "谷山", 100, 0, 'a', 'a'},

        {9, 1, "あい田", 100, 0, 'a', 'a'},

        {10, 19, "出口", 100, 0, 'a', 'a'},

        {11, 9, "神戸", 100, 0, 'a', 'a'},

        {12, 18, "土田", 100, 0, 'a', 'a'},

        {13, 5, "牛島", 100, 0, 'a', 'a'},

        {14, 28, "松尾", 100, 0, 'a', 'a'},

        {15, 23, "橋本", 100, 0, 'a', 'a'},

        {16, 27, "牧田", 100, 0, 'a', 'a'},

        {17, 11, "栗原", 100, 0, 'a', 'a'},

        {18, 29, "松岡", 100, 0, 'a', 'a'},

        {19, 10, "熊木", 100, 0, 'a', 'a'},

        {20, 21, "外山", 50, 0, 'a', 'a'},

        {21, 13, "小林", 150, 0, 'a', 'a'},

        {22, 31, "松本", 50, 0, 'a', 'a'},

        {23, 12, "小林", 150, 0, 'a', 'a'},

        {24, 30, "松本", 150, 0, 'a', 'a'},

        {25, 8, "上村", 150, 0, 'a', 'a'},

        {26, 34, "淀川", 150, 0, 'a', 'a'},

        {27, 30, "南出", 150, 0, 'a', 'a'},

        {28, 29, "原", 150, 0, 'a', 'a'},

        {29, 33, "吉満", 150, 0, 'a', 'a'},

        {30, 15, "芝", 150, 0, 'a', 'a'},

        {31, 20, "時田", 150, 0, 'a', 'a'},

        {32, 22, "西塚", 150, 0, 'a', 'a'},

        {33, 26, "堀口", 150, 0, 'a', 'a'},

        {34, 25, "福田", 150, 0, 'a', 'a'}

    };

    set<int> absentees;
    int absentee_number;
    
    cout << "欠席者の出席番号を入力してください（複数ある場合は空白で区切る）。終了するには-1を入力: " << endl;
    while (cin >> absentee_number && absentee_number != -1) {
        absentees.insert(absentee_number);
    }

    const int total_distance = 5000;
    vector<Runner> present_runners;
    int remaining_distance = total_distance; 

    for (auto& runner : runners) {
        if (absentees.count(runner.number) == 0) {
            runner.assigned_distance = runner.preferred_distance;
            present_runners.push_back(runner);
            remaining_distance -= runner.assigned_distance;
        }
    }

    // 調整が必要
    // もし5000にならない場合、距離の短い人に50ずつ増やす例。
    size_t i = 0;
    while (remaining_distance != 0) {
        present_runners[i].assigned_distance += 50;
        remaining_distance -= 50;
        i = (i + 1) % present_runners.size();
    }
    
    // スタート地点とゴール地点の決定
    char marks[] = {'a', 'b', 'c', 'd'};
    int start_index = 0;

    for (auto& runner : present_runners) {
        runner.start_mark = marks[start_index % 4];
        start_index += runner.assigned_distance / 50; // 50ごとに次のマークへ
        runner.end_mark = marks[start_index % 4];
    }

    // 出力
    for (const auto& runner : present_runners) {
        cout << runner.number << " " << runner.name << " " << runner.assigned_distance 
             << " " << runner.start_mark << " " << runner.end_mark << endl;
    }

    return 0;
}