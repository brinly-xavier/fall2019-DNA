#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// read a line


int main(){
  ifstream textfile;
  string filename;
  //this takes the input of the dna file
  cout<<"Enter the file name\n";
  cin>>filename;
  textfile.open(filename);
  cout<<"Opened file";

  if(textfile.is_open()){
    //this reads through each line in the genome file
      double variance, stdev;
      int denom = 0;
      std::string line;
      ifstream &file(textfile);
      std::ofstream outfile ("brinly.txt");
      outfile << "Brinly Xavier\n"<<"ID: 2316142\n";
      int sum;
      //this calculates the sum of lines
      while (std::getline(file, line))
      {
      	if(line.size() > 0)
        //MAKE IT CAPITAL
      		denom++;
        //  for (int i = 0; i < line.length(); ++i) {
        	//	sum++;
            //outfile << "The sum of DNA is "<< + sum + "\n";
          }
          //cout<<endl;

      }



    //this creates a new file to write results in
    //outfile << "The sum of DNA is "<< + sum + "\n";
    //int mean = sum / denom;
    //outfile << "The mean of the file is "<< + mean + "\n";

    //this while loop cancels the program if there is no proper file
    string final;
    cout<<"All done! Do you want to go again?";
    cin>>final;
    if(final == "yes"){
      //DO THIS SHIT AGAIN
    }
    else if(final == "no"){
      cout<<"Goodbye!\n";
      return 0;
    }
    //close the file when the program is done
    textfile.close();
    outfile.close();
    return 0;
  }
  else cout <<"The file does not open";
  return 0;

}
