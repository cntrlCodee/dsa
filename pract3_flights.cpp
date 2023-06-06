#include <iostream>
#include <string>
#define MAX 30
using namespace std;

class Node {
public:
    string city;
    int timeCost;
    Node* next;

    Node(string city = "", int timeCost = -1)
        : city(city), timeCost(timeCost), next(nullptr) {}
};

class Graph {
private:
    Node* head[MAX];
    int n;
    string vis[MAX];
    int cnt;

public:
    Graph(int num) : n(num), cnt(0) {
        for (int i = 0; i < n; i++)
            head[i] = nullptr;
    }

    void insert(string city1, string city2, int time);
    void readData();
    int getIndex(string s1);
    void bfs(string src);
    int visited(string city);
    void display();
};

void Graph::insert(string city1, string city2, int time) {
    int ind = getIndex(city1);
    Node* source = head[ind];

    if (source == nullptr) {
        head[ind] = new Node(city1);
        source = head[ind];
    }

    Node* dest = new Node(city2, time);
    while (source->next != nullptr)
        source = source->next;

    source->next = dest;
}

int Graph::getIndex(string s1) {
    for (int i = 0; i < n; i++) {
        if (head[i] != nullptr && head[i]->city == s1)
            return i;
    }
    return -1;
}

void Graph::bfs(string src) {
    int ind = getIndex(src);
    if (ind == -1) {
        cout << "Source city not found." << endl;
        return;
    }

    Node* start = head[ind];
    if (start == nullptr) {
        cout << "No flights available from the source city." << endl;
        return;
    }

    vis[cnt] = start->city;
    cnt++;
    cout << "\t" << start->city;

    while (start->next != nullptr) {
        start = start->next;
        if (!visited(start->city)) {
            vis[cnt] = start->city;
            cnt++;
            cout << "\t" << start->city;
        }
    }
}

int Graph::visited(string city) {
    for (int i = 0; i < cnt; i++) {
        if (vis[i] == city)
            return 1;
    }
    return 0;
}

void Graph::display() {
    for (int i = 0; i < n; i++) {
        Node* source = head[i];
        if (source == nullptr)
            continue;

        while (source != nullptr) {
            cout << source->city << "(" << source->timeCost << ")" << "->";
            source = source->next;
        }
        cout << "NULL" << endl;
    }
}

void Graph::readData() {
    string city1, city2;
    int time, flight;

    cout << "\nEnter City Details:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of city " << i + 1 << ": ";
        cin >> city1;
        head[i] = new Node(city1);
    }

    cout << "\nEnter Number of Flights to insert: ";
    cin >> flight;

    for (int i = 0; i < flight; i++) {
        cout << "\nEnter Source: ";
        cin >> city1;
        cout << "Enter Destination: ";
        cin >> city2;
        cout << "Enter Time: ";
        cin >> time;
        insert(city1, city2, time);
    }
}

int main() {
    int number, choice;
    string city1;

    cout << "Enter Number of Airport Stations: ";
    cin >> number;
    Graph g1(number);

    do {
        cout << "\n------Menu------"
             << "\n1. Insert Flight detail"
             << "\n2. Display"
             << "\n3. BFS"
             << "\n4. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g1.readData();
                break;
            case 2:
                cout << "**Adjacency List**" << endl;
                g1.display();
                break;
            case 3:
                cout << "Enter Starting City: ";
                cin >> city1;
                cout << "\nBFS Traversal of the given graph is: " << endl;
                g1.bfs(city1);
                break;
            default:
                cout << "\nWrong Choice";
        }
    } while (choice != 4);

    return 0;
}
