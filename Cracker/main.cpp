#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
int k=0;
int kk;


void printLoad(){
			k++;
	if(k>=1&&k<15){
	cerr << "\rSearching.   "<<kk;
	}
	if(k>=15&&k<30){
	cerr << "\rSearching..  "<<kk;
	}
	if(k>=30&&k<45){
	cerr << "\rSearching... "<<kk;
	}
	if(k==45){
	cerr << "\rSearching... "<<kk;
		k=0;
	}

}


void handle_line(string title,string search) {
	bool b=true;
	int i=0;
	char s,t;
	while(b&&i<search.length()){
	 s=search[i];
	 t=title[i];
	 if(s>=65 && s<=90){//Capital letter
		 if(!(t>=65 && t<=90)){
		 b=false;
		 }
	 }

	 if(s>=97&&s<=122){//Small Letter
		if(!(t>=97&&t<=122)){
		b=false;
		}
	 }

	 if(s==32){ //SPACE
		 if(!(t==32)){
			 b=false;
		 }
	 }

	 if(s==33){ // Exclamation mark
		 if(!(t==33)){
			 b=false;
		 }
	 }

	 if(s==63){ // Question mark
		 if(!(t==63)){
			 b=false;
		 }
	 }

	 if(s==46){ // period
		 if(!(t==46)){
			 b=false;
		 }
	 }
	 i++;
	}
	if(b){
		cerr << "\r"+title+"                         \n";
		printLoad();
		
	}else{
		printLoad();
	}
	
}

int main(int argc, char *argv[]) {
	fstream file ("dvd_csv.txt");
	string line;
	string search;
	cerr << "Input what to search for:\n";
	getline(cin,search);
	cerr << "-------------------------------------------\n";
	int i;
	int x;
	char c;
	string title;
	while (getline(file, line)){
		i=0;
		x=0;
		title="";
		while(i<2){
			c=0;
			c=line[x];
			if(c==34){
				i++;
			}else{
				title=title+line[x];
			}
			x++;
		}
		if(title.length()==search.length()){
		handle_line(title,search);
		//cout << title+"\n";
		};
		kk++;
	}
	cerr <<"\nThat's all! Done!\n";
}