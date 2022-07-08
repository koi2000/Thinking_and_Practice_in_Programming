#include <bits/stdc++.h>
using namespace std;
struct ChatWindow{
    long long int u = 0;//喜爱度
    long long int w = 0;//交流w句话
    bool top1 = false;
    string MSG;//日志信息
};
deque<ChatWindow> chat;//双端队列存储所有窗口
set<long long int> allfavorite;//集合存储已知的喜爱度
long long int chatnumber;//操作后面的数字
int j;//便于打印序号
bool have;long long int topu;
ChatWindow s;
stack<ChatWindow> storage;
void show(){
    while (!storage.empty()) storage.pop();
    while (!chat.empty()){
        if (chat.front().top1)
            cout << "!" << chat.front().u << "(" << chat.front().w<<")"<< " ";
        else
            cout << chat.front().u<< "(" << chat.front().w<<")"<< " ";
        storage.push(chat.front());chat.pop_front();
    }
    cout << endl;
    while (!storage.empty()){
        chat.push_front(storage.top());
        storage.pop();
    }
}
void add(){
    if (allfavorite.count(chatnumber)==0){
        allfavorite.insert(chatnumber);
        s.u = chatnumber;s.w = 0;s.MSG = "success";s.top1 = false;
        chat.push_back(s);
        cout << "OpId #" << j << ":" << " " << s.MSG << "." << endl;
    }else{
        cout << "OpId #" << j << ":" << " " << "same likeness" << "." << endl;
    }
}
void close(){
    if (allfavorite.count(chatnumber) == 0){
        cout << "OpId #" << j << ":" << " " << "invalid likeness" << "." << endl;
    }else{
        while (!storage.empty()) storage.pop();
        //从队列头开始取直到找到了对应喜爱度的窗口
        while (chat.front().u != chatnumber){
            storage.push(chat.front());
            chat.pop_front();//用栈临时存储
        }
        if (!chat.empty()) {
            s = chat.front();
            allfavorite.erase(s.u);
            chat.pop_front();//删除这个窗口
        }
        if (s.top1 == have){have = false;}
        //将之前取出的再从栈中放回队列
        while (!storage.empty()){
            chat.push_front(storage.top());
            storage.pop();
        }
        cout << "OpId #" << j << ":" << " " << "close " << s.u << " with " << s.w << "." << endl;
    }
}
//置顶
void chatemmm(){
    while (!storage.empty()) {storage.pop();}
    if (chat.empty()){
        cout << "OpId #" << j << ":" << " " << "empty" << "." << endl;
    }else {
        if (have) {
            while (!chat.empty()){
                if (chat.front().top1){ chat.front().w += chatnumber;break;}
                storage.push(chat.front());
                chat.pop_front();
            }
            while (!storage.empty()){
                chat.push_front(storage.top());
                storage.pop();
            }
        } else {
            chat.front().w += chatnumber;
        }
        cout << "OpId #" << j << ":" << " " << "success" <<"." <<  endl;
    }
}
void rotate(){
    if (chatnumber<1||chatnumber>chat.size()){
        cout << "OpId #" << j << ":" << " " << "out of range" << "." << endl;
    }else{
        while (!storage.empty()) storage.pop();
        //从队列头开始取直到找到了对应喜爱度的窗口
        for (long long int i = 0; i < chatnumber-1; ++i) {
            storage.push(chat.front());
            chat.pop_front();//用栈临时存储
        }
        if (!chat.empty()) {
            s = chat.front();
            chat.pop_front();//删除这个窗口
        }
        //将之前取出的再从栈中放回队列
        while (!storage.empty()){
            chat.push_front(storage.top());
            storage.pop();
        }
        chat.push_front(s);
        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
    }
}
void prior(){
    if (chat.empty()){
        cout << "OpId #" << j << ":" << " " << "empty" <<"." <<  endl;
    }else{
        long long int lll = chat.size();
        while (!storage.empty()) storage.pop();
        for (long long int i = 0; i < lll; ++i) {
            if (s.u<chat.front().u){
                s = chat.front();
            }
            storage.push(chat.front());
            chat.pop_front();//用栈临时存储
        }
        while (!storage.empty()){
            if (storage.top().u == s.u){
                storage.pop();
            }else {
                chat.push_front(storage.top());
                storage.pop();
            }
        }
        chat.push_front(s);
        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
    }
}
void choose(){
    int lll = chat.size();bool is =false;
    while (!storage.empty()) storage.pop();
    while(!chat.empty()) {
        if(chat.front().u == chatnumber){
            s = chat.front();chat.pop_front();
            is = true;break;
        }
        storage.push(chat.front());
        chat.pop_front();
    }
//    if (!chat.empty()){s = chat.front();chat.pop_front();}
    while (!storage.empty()){
        chat.push_front(storage.top());
        storage.pop();
    }
    if (is){
        chat.push_front(s);
        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
    }else{
        cout << "OpId #" << j << ":" << " " << "invalid likeness" << "." << endl;
    }
};
//如果此次设定无效，是否会取消之前的top呢
void top(){
    int lll = chat.size();bool is =false;
    while (!storage.empty()) storage.pop();;
    while (!chat.empty()) {
        if(chat.front().u == chatnumber){
            chat.front().top1 = true;is = true;have = true;topu = chatnumber;
        }
//        else{
//            if (chat.front().top)
//                chat.front().top = false;
//        }
        storage.push(chat.front());
        chat.pop_front();
    }
    if (is){
        while (!storage.empty()){
            if (storage.top().top1&&storage.top().u!=chatnumber)
                storage.top().top1 = false;
            chat.push_front(storage.top());
            storage.pop();
        }
        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
    }else{
        while (!storage.empty()){
            chat.push_front(storage.top());
            storage.pop();
        }
        cout << "OpId #" << j << ":" << " " << "invalid likeness" <<"." <<  endl;
    }
}
//void top(){
//    int lll = chat.size();bool is =false;
//    while (!storage.empty()) storage.pop();;
//    while (!chat.empty()){
//        if (chat.front().top1) {
//            !chat.front().top1;
//            have = false;
//        }
//        storage.push(chat.front());chat.pop_front();
//    }
//    while (!storage.empty()){
//        chat.push_front(storage.top());storage.pop();
//    }
//    while (!chat.empty()) {
//        if(chat.front().u == chatnumber){
//            chat.front().top1 = true;is = true;have = true;topu = chatnumber;
//        }
//        storage.push(chat.front());
//        chat.pop_front();
//    }
//    while (!storage.empty()){
//        chat.push_front(storage.top());storage.pop();
//    }
//    if (is){
//        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
//    }else{
//        cout << "OpId #" << j << ":" << " " << "invalid likeness" <<"." <<  endl;
//    }
//}
void untop(){
    while (!storage.empty()) storage.pop();
    if (have){
        while (!chat.empty()){
            if (chat.front().top1){ chat.front().top1 = false;topu = -1;have = false;break;}
            storage.push(chat.front());
            chat.pop_front();
        }
        while (!storage.empty()){
            chat.push_front(storage.top());
            storage.pop();
        }
        cout << "OpId #" << j << ":" << " " << "success" << "." << endl;
    }else{
        cout << "OpId #" << j << ":" << " " << "no such person" << "." << endl;
    }
}
int main(){
    int T;
    cin >> T;
    for (long long int i = 0; i < T; ++i) {
        chat.clear();allfavorite.clear();topu = -1;have = false; chatnumber=0;
        long long int n;string select;
        scanf("%lld",&n);
        for (j = 1; j <= n; ++j) {
            cin >> select;
            if (select == "Add"){
                cin >> chatnumber;
                add();
            }else if (select == "Close"){
                cin >> chatnumber;
                close();
            }else if (select == "Chat"){
                cin >> chatnumber;
                chatemmm();
            }else if (select == "Rotate"){
                cin >> chatnumber;
                rotate();
            }else if (select == "Prior"){
                prior();
            }else if (select == "Choose"){
                cin >> chatnumber;
                choose();
            }else if (select == "Top"){
                cin >> chatnumber;
                top();
            }else if (select == "Untop"){
                untop();
            }
            show();
        }
        if (have) {
            chatnumber = topu;
            int lll = chat.size();bool is =false;
            while (!storage.empty()) storage.pop();
            while (!chat.empty()) {
                if(chat.front().u == chatnumber){
                    s = chat.front();chat.pop_front();
                    break;
                }
                storage.push(chat.front());
                chat.pop_front();
            }
            while (!storage.empty()){
                chat.push_front(storage.top());
                storage.pop();
            }
            chat.push_front(s);
        }
        while (!chat.empty()){
            if (chat.front().w!=0){
                cout <<"OpId #" << j++ << ":" << " " "Bye " << chat.front().u << ": " << chat.front().w << "." << endl;
            }
            chat.pop_front();
        }
    }
}

