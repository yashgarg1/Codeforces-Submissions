#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include<map>


using namespace std;

vector<string> timestamps,stock_name;
vector<int> bid,ask,times;
map<string, list<pair<int,int>>> mp; //(this map stores stock name as key and value is time,bid)

void readCSV(){
    std::ifstream file("Candlestick.touch.csv");  
    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        return ;
    }

    std::vector<std::vector<std::string>> data;  // Store the CSV data as a 2D vector of strings

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;

        while (getline(ss, cell, ',')) {  // Assuming comma-separated values
            row.push_back(cell);
        }

        data.push_back(row);
    }

    // int k=1000;
    bool first_row = true;
    // Printing the CSV data
    for (const auto& row : data) {
        int col=0;
        if(first_row){
            first_row=false;
            continue;
        }
        for (const auto& cell : row) {
            if(col==0){
                timestamps.push_back(cell);
            }
            else if(col==1){
                stock_name.push_back(cell);
            }
            else if(col==2){
                bid.push_back(stoi(cell));
            }
            else if(col==3){
                ask.push_back(stoi(cell));
            }
            col++;
        }
        // k--;
        // if(k==0){
        //     break;
        // }
    }
}

void convert_timestamp(vector<string>& str_times){
    cout<<endl<<endl;
    for (int i=0;i<str_times.size();i++){
        const string& timeStr = str_times[i];
        int hours,minutes,seconds,ms;
        
        sscanf(timeStr.c_str(), "%2f%2f%2f", &hours, &minutes, &seconds, &ms);

        // Converting to seconds
        int totalSeconds = hours * 3600 + minutes * 60 + seconds;
        times.push_back(totalSeconds);
    }
}

void print_ohlc(){
    cout<<"Print OHLC"<<endl;
    int start_time=times[0];
    int i=0;
    for ( ;i<times.size();i++){
        if(times[i] > start_time+60){
            break;
        }
        mp[stock_name[i]].push_back({times[i], bid[i]});
    }
    for (auto it:mp){
        cout<<it.first<<endl;
    }
    // cout<<"O = "<<bid[0]<<" H = "<<high<<" L = "<<low<<" C = "<<bid[i-1]<<endl;
    cout<<"Print OHLC 1"<<endl;
    cout<<i<<endl;
    int front_p = i, back_p = 0;
    while(front_p < times.size()){
        mp[stock_name[front_p]].push_back({times[front_p], bid[front_p]});
        
        string s_name = stock_name[front_p];
        list<pair<int,int>>& q=mp[s_name];
        while(q.front().first < times[front_p]-60){
            q.pop_front();
        }
        int open,close;
        open = q.front().second;
        close = q.back().second;
        int high=open, low=open;
        for (auto it:q){
            high = max(high, it.second);
            low  = min(low,it.second);
        }
        cout<<"O = "<<open<<" H = "<<high<<" L = "<<low<<" C = "<<close<<endl;
        front_p++;
    }
    cout<<"Print OHLC end"<<endl;
}

int main() {

    readCSV();

    convert_timestamp(timestamps);

    print_ohlc();
    return 0;
}
