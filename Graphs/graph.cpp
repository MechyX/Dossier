#include "graph.hpp"

Graph :: Graph(int vertexCount){
        for(int i=0; i < vertexCount ; i++){
            list<pair<int,int> > temp;
            pair<int ,int> edge;
            int vertex;
            int weight;
            cout << "Enter adjacent vertices for vertex and the weight together, enter -1 to proceed to next vertex " << endl;
            while(1){
                cin >> vertex;
                cin >> weight;
                if(vertex == -1)
                    break;

                edge.first = vertex;
                edge.second = weight;
                temp.push_back(edge);
            }
            vertices.push_back(temp);
        }
    }

void Graph :: addEdge(int vertex1,int vertex2,int weight){
    pair<int, int> edge;
    edge.first = vertex2;
    edge.second = weight; 
    vertices.at(vertex1).push_back(edge);
    edge.first = vertex1;
    vertices.at(vertex2).push_back(edge); 
}

void Graph :: addVertex(){
    list<pair<int,int> > temp;
    vertices.push_back(temp);
}

void Graph :: displayGraph(){
    cout << "Graph currently" << endl;
    vector< list<pair<int,int> > > :: iterator it; 
    list<pair<int,int> >::iterator jt;
    for(it = vertices.begin() ; it != vertices.end() ; it++){
        for(jt = (*it).begin(); jt !=  (*it).end(); jt++){
            cout << (*jt).first << " ";
        }       
        cout << endl;
    }
}

list<pair<int,int> > Graph :: adjacentVertices(int vertex){
    return vertices.at(vertex);
}

void Graph :: particularDegree(int degree){
    for(int i = 0 ; i < vertices.size() ;i++){
            if(vertices.at(i).size() == degree)
                cout << i << " th vertex has degree " << degree << endl;
                break;
    } 
}

void Graph :: sumOfDegrees(){
    int sum = 0;
    vector< list <pair<int, int> > > :: iterator it;
    for(it = vertices.begin() ; it != vertices.end() ; it++)
        sum += (*it).size();
    cout << "Sum of degrees is " << sum << endl;
}



void Graph :: dfs(int vertex){
    list<int> adjacent; //stack
    vector<bool> visited(vertices.size(),false);
    vector<bool> inStack(vertices.size(),false);

int i = 1;
list<pair<int,int> >::iterator jt;
adjacent.push_front(i);
    while(!adjacent.empty()){
        //push neighbours into stack
        i = adjacent.front();
            adjacent.pop_front();
        cout << i  << " ";
        for(jt = vertices.at(i).begin() ; jt != vertices.at(i).end() ; jt++){
            if(visited.at((*jt).first) != 1 && inStack.at((*jt).first) != 1){
                inStack.at((*jt).first) = 1;
                adjacent.push_front((*jt).first);
            }               
        } 
        visited.at(i) = true;   
    }
}

std::pair<int,int> Graph :: minEdge(int vertex, vector<bool> visited){
    list<pair<int,int> >::iterator it;
    std::pair<int,int> minPair;
    int minWeight = INT_MAX;

    for(it = vertices.at(vertex).begin() ; it != vertices.at(vertex).end() ; it++){
        if(minWeight > (*it).second & !visited.at((*it).first)){
            minPair = *it;
            minWeight = (*it).second;
        } 
    }

    return minPair;
}

void Graph :: shortestPath(){
    vector<int> dist(vertices.size(), INT_MAX);
    set<pair<int, int> > st;
    st.insert(make_pair(0, 0));
    dist[0] = 0;

    while (!st.empty()) {
        pair<int, int> now = *st.begin();
        st.erase(st.begin());

        int v = now.second;
        int w = now.first;

        list<pair<int,int> >::iterator it;

        //for all adjacent vertices 
        for (it = vertices.at(v).begin() ; it != vertices.at(v).end() ; it++) {
            if (w + (*it).second < dist[(*it).first]) {
                st.erase(make_pair(dist[(*it).first], (*it).first));
                dist[(*it).first] = w + (*it).second;
                st.insert(make_pair(dist[(*it).first], (*it).first));
            }
        }
    }

    for (int i = 0; i < vertices.size(); i++) {
        cout << i << ' ' << dist[i] << endl;
    }
}


void Graph :: minSpanningTree(){
    //prim's algorithm 
    priority_queue< pair<int,int> , vector <pair<int,int> > , greater<pair<int,int> > > pq; 
  
    vector<int> key(vertices.size(), INT_MAX); 
    vector<int> parent(vertices.size(), -1); 
    vector<bool> inMST(vertices.size(), false); 
  
    pq.push(make_pair(0, 0)); 
    key[0] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;  // Include vertex in MST 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = vertices.at(u).begin(); i != vertices.at(u).end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && key[v] > weight) 
            { 
                // Updating key of v 
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u;
            } 
        } 
    } 
  
    // Print edges of MST using parent array 
    for (int i = 1; i < vertices.size(); ++i) 
        cout << parent[i] << " - " << i << endl; 
}


bool Graph :: path(int vertex1,int vertex2){
list<int> adjacent;
vector<bool> visited(vertices.size(),false);
vector<bool> inQueue(vertices.size(),false);


int i = vertex1;
list<pair<int,int> >::iterator jt;
adjacent.push_back(i);
    while(!adjacent.empty()){
        //push neighbours into queue
        i = adjacent.front();
        for(jt = vertices.at(i).begin() ; jt != vertices.at(i).end() ; jt++){
            if((*jt).first == vertex2)
                return true;

            if(visited.at((*jt).first) != 1 && inQueue.at((*jt).first) != 1){
                inQueue.at((*jt).first) = 1;
                adjacent.push_back((*jt).first);
            }               
        }
        visited.at(i) = true;
        adjacent.pop_front();
    }
    return false;
}


void Graph :: bfs(int vertex){
list<int> adjacent;
vector<bool> visited(vertices.size(),false);
vector<bool> inQueue(vertices.size(),false);


int i = vertex;
list<pair<int,int> >::iterator jt;
adjacent.push_back(i);
    while(!adjacent.empty()){
        //push neighbours into queue
        i = adjacent.front();
        cout << i  << " ";
        for(jt = vertices.at(i).begin() ; jt != vertices.at(i).end() ; jt++){
            if(visited.at((*jt).first) != 1 && inQueue.at((*jt).first) != 1){
                inQueue.at((*jt).first) = 1;
                adjacent.push_back((*jt).first);
            }               
        }
        visited.at(i) = true;
        adjacent.pop_front();
    }
}

int main(){
    Graph g(0);
    
    //input example
    //added 9 vertices
    for(int i = 0; i < 9 ;i++)
        g.addVertex();
    
   
    //add connections
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);    
}
