#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    int n;

     const char *inFile = "submultimi.in";
    const char *outFile = "submultimi.out";

    ifstream fin(inFile);

    ofstream fout(outFile);


    if(!fin || !fout) {

          cerr<<"Error opening one of \"" << inFile << "\" or \"" << outFile<<"\""<<endl;
          return -1;
    }

    fin>>n;

    vector<int> stack;

    stack.push_back( 1 );

    while(!stack.empty()) {

          for(vector<int>::size_type i = 0; i < stack.size(); ++i) fout<<stack[i]<<" ";

          fout<<"\n";

          if(stack.back() < n) {

             stack.push_back(stack.back() + 1);

          } else {

             stack.pop_back();

             if(!stack.empty()) stack.back()++;
          }
    }  

    return(0);
};