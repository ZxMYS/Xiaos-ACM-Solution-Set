
vector<int> roll(int i,int st){
vector<int> tmp;
tmp.clear();
if(i==0){
    tmp.push_back(stat[st][2]);
    tmp.push_back(stat[st][3]);
    tmp.push_back(stat[st][1]);
    tmp.push_back(stat[st][0]);
    tmp.push_back(stat[st][4]);
    tmp.push_back(stat[st][5]);
    return tmp;
}
if(i==1){
    tmp.push_back(stat[st][3]);
    tmp.push_back(stat[st][2]);
    tmp.push_back(stat[st][0]);
    tmp.push_back(stat[st][1]);
    tmp.push_back(stat[st][4]);
    tmp.push_back(stat[st][5]);
    return tmp;
}
if(i==2){
    tmp.push_back(stat[st][5]);
    tmp.push_back(stat[st][4]);
    tmp.push_back(stat[st][2]);
    tmp.push_back(stat[st][3]);
    tmp.push_back(stat[st][0]);
    tmp.push_back(stat[st][1]);
    return tmp;
}
if(i==3){
    tmp.push_back(stat[st][4]);
    tmp.push_back(stat[st][5]);
    tmp.push_back(stat[st][2]);
    tmp.push_back(stat[st][3]);
    tmp.push_back(stat[st][1]);
    tmp.push_back(stat[st][0]);
    return tmp;
}
}

int find(vector<int>st){
    int i;
    LOOPB(i,0,24){
        if(CHECK(0)&&CHECK(1)&&CHECK(2)&&CHECK(3)&&CHECK(4)&&CHECK(5))
            return i;
    }
    return -1;
}
