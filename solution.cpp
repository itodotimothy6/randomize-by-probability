#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

// Server struct which stores the name & size of a server
struct Server {
    string name;
    double size;
    Server(string n, double s) {
        name = n;
        size = s;
    }
};

// Function Declaration
void generateRandomServer(vector<Server> servers);

int main() {
    vector<Server> servers;

    // Fill list of servers with input from the file "input.txt"
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        string serverName = line.substr(0, line.find(":"));
        string serverSize = line.substr(line.find(":")+1, line.size());
        servers.push_back(Server(serverName, atof(serverSize.c_str())));
    }

    generateRandomServer(servers);

    return 0;   
}

/*
 * This function prints out a random server name based on a probability
 * The Probability of a server name to be printed is the (size of server)/(total size of servers)
 */
void generateRandomServer(vector<Server> servers) {
    mt19937 generator(time(NULL));

    /* In this function, weight is the ratio of a given size to the total size of all the servers
     * For the example: X:3 Y:1, The weight of X is 3/4(0.75) while the weight of Y is 1/4(0.25)
     */ 

    double weights[servers.size()]; 
    double totalSize = 0;

    // Total size of all servers
    for (int i = 0; i < servers.size(); i++) {
        totalSize += servers[i].size;
    }

    // For every server, the weight is the server's size divided by the total server size
    for (int i = 0; i < servers.size(); i++) {
        weights[i] = servers[i].size/totalSize;
    }
    
    discrete_distribution<> weightedDistribution(weights, weights + sizeof weights/sizeof weights[0]);
    cout << servers[weightedDistribution(generator)].name << endl;
}