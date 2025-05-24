
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 7

// pair of vector is used to pair the place name and weight value
vector<pair<string, int>> from;
// places - stores the place names
vector<string> places = {
    "ULAB Research Building",
    "Cooper's Bakery",
    "Bakers Confection",
    "Officer's Club",
    "Presley: The Bakers",
    "Yusuf Bakery & Confectionery",
    "Puro Pastry & Bakery"};


// FindMinWeight function finds the vertex that has the minimum weight value from the set of vertices that are not yet included in the MST yet
int FindMinWeight(int weight[], bool MST[])
{
    // Initializes min value with a greater value
    int min = INT_MAX, minIndex;

    for (int i = 0; i < V; i++)
        if (MST[i] == false && weight[i] < min)
        {
            min = weight[i];
            minIndex = i;
        }
    return minIndex;
}

// DisplayMST function prints the constructed MST
void DisplayMST(int ConstructedMST[V], int graph[V][V])
{
    for (int i = 1; i < V; i++)
    {
        if (ConstructedMST[i] == 0)
            from.push_back({"ULAB Research Building", ConstructedMST[i]});
        else if (ConstructedMST[i] == 1)
            from.push_back({"Cooper's Bakery", ConstructedMST[i]});
        else if (ConstructedMST[i] == 2)
            from.push_back({"Bakers Confection", ConstructedMST[i]});
        else if (ConstructedMST[i] == 3)
            from.push_back({"Officer's Club", ConstructedMST[i]});
        else if (ConstructedMST[i] == 4)
            from.push_back({"Presley: The Bakers", ConstructedMST[i]});
        else if (ConstructedMST[i] == 5)
            from.push_back({"Yusuf Bakery & Confectionery", ConstructedMST[i]});
        else if (ConstructedMST[i] == 6)
            from.push_back({"Puro Pastry & Bakery", ConstructedMST[i]});
    }
    int sumMST = 0;

    system("COLOR BC");
    cout << "\n\n\n\n\t\t\t\t***********************************************\n";
    cout << "\t\t\t\t* Minimum Spanning Tree Using Prim's Algorithm *\n";
    cout << "\t\t\t\t***********************************************\n\n\n\n";

    cout << "\t\t\t\t\tThe edges and weight values:\n";
    cout << "\t----------------------------------------------------------------------------------------------\n";
    for (int i = 1; i < V; i++)
    {
        cout <<fixed<<setw(35)<<from[i - 1].first << " -----> " << places[i]<<"\t"<<setw(25)<< "|\tWeight Value: " << graph[i][ConstructedMST[i]] << " \n";
        sumMST += graph[i][ConstructedMST[i]];
    }
    cout << "\t-----------------------------------------------------------------------------------------------\n";
    cout << "\n\n\n\tTotal cost to make this MST itinerary work: " << sumMST << endl<<endl<<endl<<endl;
}

// BuildMST function builds the MST for the graph that is given and print it
void BuildMST(int graph[V][V])
{
    // ConstructedMST - array that stores the constructed MST
    int ConstructedMST[V];

    // weight - used to pick minimum weighted edge
    int weight[V];

    // MST - represents the set of vertices included in MST
    bool MST[V];

    // Initializing all keys with INFINITE
    for (int i = 0; i < V; i++)
        weight[i] = INT_MAX, MST[i] = false;

    // Includes the first 1st vertex in MST making the weight 0 so that this vertex is picked as first vertex i.e. root node
    weight[0] = 0;
    ConstructedMST[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        // Picking the minimum weight vertex from the set of vertices not yet included in MST
        int u = FindMinWeight(weight, MST);

        // Adding the picked vertex to the MST Set
        MST[u] = true;

        // Updating the weight value and ConstructedMST index of the adjacent vertices of the picked vertex (that are not included i the MST yet)
        for (int v = 0; v < V; v++)
        {
             // graph[u][v] is non zero only for adjacent vertices of m
            // MST[v] is false for vertices not yet included in MST
            // Updating the weight only if graph[u][v] is smaller than weight[v]
            if (graph[u][v] && MST[v] == false && graph[u][v] < weight[v])
                ConstructedMST[v] = u, weight[v] = graph[u][v];
        }

    }

    // Printing the constructed MST
    DisplayMST(ConstructedMST, graph);
}

int main()
{
    int graph[V][V] = {{0, 4, 11, 0, 0, 9, 2},
                       {4, 0, 10, 0, 0, 0, 0},
                       {11, 10, 0, 6, 0, 8, 0},
                       {0, 0, 6, 0, 4, 0, 0},
                       {0, 0, 0, 4, 0, 12, 0},
                       {9, 0, 8, 0, 12, 0, 7},
                       {2, 0, 0, 0, 0, 7, 0}};

    BuildMST(graph);

    return 0;
}
