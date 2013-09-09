#include "graph.h"

// classe principal
// graph::graph(string s) {
  
// }

void graph::generate_info() {
    ofstream myfile;
    myfile.open("output.txt");
    // myfile << "Writing this to a file.\n";

    myfile << "Número de nós: " << n << endl;
    
    myfile.close();
}
