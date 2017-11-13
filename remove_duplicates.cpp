#include <iostream>

using namespace std;

int main() {

    int vec[] = {1,3,4,4,4,5,4,7,8,9,1,3,-1,33},  //-> remove duplicates 
        n = sizeof(vec)/sizeof(vec[0]), 
        j;


        cout<<"Initial Array"<<endl; 
        for(int i = 0; i < n; ++i) cout<<vec[i]<<" ";
        cout<<endl<<"Remove duplicates from array"<<endl;

        for(int i = 0; i < n - 1; ++i) {

            j = i + 1; 

            while(j < n) {
                  
                  if(vec[i] == vec[j]) {

                    cout<<"Removes: "<<vec[i]<<endl;

                    for(int k = j; k < n; ++k) {
 
                            vec[ k ] = vec[k + 1]; 
                    }

                    n--;

                  } else { 

                    j++; 
                  }
            }
        } 

        for(int i = 0; i < n; ++i) cout<<vec[i]<<" ";

 return(0);
};