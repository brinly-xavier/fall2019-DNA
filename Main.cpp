#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]){
  if (argc = 2){
    //this makes sure that everytime you loop you wont get the same random number
    //it reduces the probability
    srand(time(NULL));
    ifstream textfile;
    string filename;
    //setting all the variables I need here
    double variance = 0;
    int gaus_sum = 0;
    double num = 0;
    double num_var = 0;
    double mean = 0;
    float denom = 0;
    float sum = 0;
    int a_gaus = 0;
    int c_gaus = 0;
    int t_gaus = 0;
    int g_gaus = 0;
    int aa = 0;
    int ac = 0;
    int at = 0;
    int ag = 0;
    int ca = 0;
    int cc = 0;
    int ct = 0;
    int cg = 0;
    int ta = 0;
    int tc = 0;
    int tt = 0;
    int tg = 0;
    int ga = 0;
    int gc = 0;
    int gt = 0;
    int gg = 0;
    double a_total = 0;
    double c_total = 0;
    double t_total = 0;
    double g_total = 0;
    std::string line;
    //this creates a variable for the file being read
    ifstream &file(textfile);
    //this is a new file being created that will print out the results
    std::ofstream outfile ("brinly.txt");
    outfile << "Brinly Xavier\n"<<"ID: 2316142\n";
    outfile << "Assignment 1 C++ Review\n";
    outfile << "CPSC 350 - 01\n";
    string final;
    cout<<"Do you want to compute a file? 'yes' or 'no'\n";
    cin>>final;
    //this sends the program into a loop if they want to do this or not
    while(final == "yes"){
      cout<<"Enter the file name\n";
      cin>>filename;
      textfile.open(filename);
      cout<<"Opened file: "<<filename<<"\n";
    //this calculates the sum of lines
      while (std::getline(file, line))
      {
      	if(line.size() > 0)
         sum+=line.size();
        //this gets the number of lines in the file
      	 denom++;
         for(char i = 0; i < line.size(); i++){
           //this for loop adds only the needed characters to calculate the sum
           if(line[i] == 'A' || line [i] == 'a'){
             sum++;
             a_total++;
             if(line[i + 1] == 'A' || line[i+1] == 'a'){
               aa++;
             }
             if(line[i+1] == 'C' || line[i+1] == 'c'){
               ac++;
             }
             if(line[i+1] == 'T' || line[i+1] == 't'){
               at++;
             }
             if(line[i+1] == 'G' || line[i+1] == 'g'){
               ag++;
             }
           }
           else if(line[i] == 'C' || line [i] == 'c'){
             sum++;
             c_total++;
             if(line[i + 1] == 'A' || line[i+1] == 'a'){
               ca++;
             }
             if(line[i+1] == 'C' || line[i+1] == 'c'){
               cc++;
             }
             if(line[i+1] == 'T' || line[i+1] == 't'){
               ct++;
             }
             if(line[i+1] == 'G' || line[i+1] == 'g'){
               cg++;
             }
           }
           else if(line[i] == 'T' || line [i] == 't'){
             sum++;
             t_total++;
             if(line[i + 1] == 'A' || line[i+1] == 'a'){
               ta++;
             }
             if(line[i+1] == 'C' || line[i+1] == 'c'){
               tc++;
             }
             if(line[i+1] == 'T' || line[i+1] == 't'){
               tt++;
             }
             if(line[i+1] == 'G' || line[i+1] == 'g'){
               tg++;
             }
           }
           else if(line[i] == 'G' || line [i] == 'g'){
             sum++;
             g_total++;
             if(line[i + 1] == 'A' || line[i+1] == 'a'){
               ga++;
             }
             if(line[i+1] == 'C' || line[i+1] == 'c'){
               gc++;
             }
             if(line[i+1] == 'T' || line[i+1] == 't'){
               gt++;
             }
             if(line[i+1] == 'G' || line[i+1] == 'g'){
               gg++;
             }
           }
           else{
             sum--;
           }
         }
         //end of the characters loop
         //this next segment, helps to calculate the variance of the input file
         mean = sum / denom / 2;
         int dif = mean - line.size();
         num_var = pow(dif, 2);
         num+=num_var;
      }
      //the rest does basic math and also prints the result to the new file
      outfile << "\nThe sum of DNA is "<< sum / 2<<"\n";
      variance = num / denom;
      double stdev = sqrt(variance);
      outfile << "The mean of the file is "<<mean<<"\n";
      outfile << "The variance of the file is "<<variance<<"\n";
      outfile << "The standard deviation of the file is "<<stdev<<"\n";
      double a= a_total/sum * 2;
      double c= c_total/sum * 2;
      double t= t_total/sum * 2;
      double g= g_total/sum * 2;

      //this prints ouut the probability of all to the output file
      outfile << "The Probability of Nucleotide is A: "<<a*100<<"%"<<"\n";
      outfile << "The Probability of Nucleotide is C: "<<c*100<<"%"<<"\n";
      outfile << "The Probability of Nucleotide is T: "<<t*100<<"%"<<"\n";
      outfile << "The Probability of Nucleotide is G: "<<g*100<<"%"<<"\n";
      outfile << "The Probability of the BiGram AA is: "<<aa / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram AC is: "<<ac / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram AT is: "<<at / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram AG is: "<<ag / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram CA is: "<<ca / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram CC is: "<<cc / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram CT is: "<<ct / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram CG is: "<<cg / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram TA is: "<<ta / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram TC is: "<<tc / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram TT is: "<<tt / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram TG is: "<<tg / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram GA is: "<<ga / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram GC is: "<<gc / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram GT is: "<<gt / sum* 100<<"%"<<"\n";
      outfile << "The Probability of the BiGram GG is: "<<gg / sum* 100<<"%"<<"\n";

      //this for loop creates a new distribution for every line
      for (int i = 0; i < 1000; ++i){
        float a_rand = (float) rand()/ (float)RAND_MAX;
        float b_rand = (float) rand()/(float)RAND_MAX;
        double c_form = sqrt(-2*log(a_rand)) * cos( 2 * M_PI * b_rand);
        double d_form = ((float)stdev * c_form)+ (float)mean;
        //these variables calculate the distribution for each line based on their
        //probability that was previously calculated
        a_gaus = a_total * d_form / 100;
        c_gaus = c_total * d_form / 100;
        t_gaus = t_total * d_form / 100;
        g_gaus = g_total * d_form / 100;
        //this for loop prints the nucleotides into the output file
        for(int i = 0; i < a_gaus; ++i){
          outfile <<"a";
        }
        for(int i = 0; i < c_gaus; ++i){
          outfile<<"c";
        }
        for(int i = 0; i < t_gaus; ++i){
          outfile<<"t";
        }
        for(int i = 0; i < g_gaus; ++i){
          outfile <<"g";
        }
        outfile <<"\n";
      }
      textfile.close();
      cout<<"Do you want to go again?\n";
      cin>>final;
      //once they request to go again, all the variables are reset
      variance = 0;
      gaus_sum = 0;
      num = 0;
      num_var = 0;
      mean = 0;
      denom = 0;
      sum = 0;
      a_gaus = 0;
      c_gaus = 0;
      t_gaus = 0;
      g_gaus = 0;
      aa = 0;
      ac = 0;
      at = 0;
      ag = 0;
      ca = 0;
      cc = 0;
      ct = 0;
      cg = 0;
      ta = 0;
      tc = 0;
      tt = 0;
      tg = 0;
      ga = 0;
      gc = 0;
      gt = 0;
      gg = 0;
      a_total = 0;
      c_total = 0;
      t_total = 0;
      g_total = 0;
  }
  //this is what happens when the user chooses not to go through the loop
    outfile.close();
    cout<<"Goodbye!\n";
    return 0;
  }
  else{
    cout<<"That didnt work";
    cout<<"\nGoodbye";
    return 0;
  }
  }
