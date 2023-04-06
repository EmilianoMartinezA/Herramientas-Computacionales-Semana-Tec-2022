#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


string Read(string nom){
  string linea;
  nom += ".txt";
  ifstream file; 
  
  file.open(nom, ios::in);
  if(file.fail()){
      cout << "\nNo se puede acceder al archivo.\n Verifique el nombre del archivo y su ubicacion." <<endl;
  }
  else{
      getline(file, linea);
      file.close();
  }
  return linea;
}

string lcs(string s1, string s2, int l1, int l2){
  int L[l1 + 1][l2 + 1];

  for (int i = 0; i <= l1; i++){
    for (int j = 0; j <= l2; j++){
      if (i == 0 || j == 0){
        L[i][j] = 0;
      }
      else if (s1[i - 1] == s2[j - 1]){
        L[i][j] = L[i - 1][j - 1] + 1;
      }
      else{
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
      }
    }
  }

  int size = L[l1][l2];
  string LCS_characters[size];
  int i = l1;
  int j = l2;
  while (i > 0 && j > 0){
    if (s1[i - 1] == s2[j - 1]){
      LCS_characters[size - 1] = s1[i - 1];
      i--;
      j--;
      size--;
    }
    else if (L[i - 1][j] > L[i][j - 1]){
      i--;
    }
    else{
      j--;
    }
  }

  string LCS = "";
  for(int i = 0; i < L[l1][l2]; i++){
    LCS += LCS_characters[i];
  }
  return LCS;
}

int main() {
  string DNA;
  string Namefiles[] = {
  "DNA_BlackPanther",
  "DNA_PatrickStar",
  "DNA_PerryThePlatypus",
  "DNA_Pikachu",
  "DNA_RickSapiens",
  "DNA_Spiderman",
  "DNA_SpongeBob"
  };
  vector<string> Dataset;
  
  DNA = Read("DNA_new");
  int size = sizeof(Namefiles)/sizeof(Namefiles[0]);
  for (int i = 0; i < size; i++){
    string temp = "DNA_DATASET/";
    Dataset.push_back(Read(temp += Namefiles[i]));
  }

  int max = 0,
      index = 0;
  string temp2,
         LCS = "";
  for (int i = 0; i < Dataset.size(); i++){  
    temp2 = lcs(DNA, Dataset[i], DNA.length(), Dataset[i].length());
    if (max < temp2.length()){
      max = temp2.length();
      index = i;
      LCS = temp2;
    }
  }

  if (max >= (Dataset[index].length())*0.35){
    cout << "Afiliación: " << Namefiles[index] <<endl;
    cout << "\nLCS:" << LCS <<endl;
    cout << "\nPorcentaje LCS: " << max*100/Dataset[index].length() << "%" <<endl;
    cout << "\nLongitud LCS: " << max <<endl;
    cout << "\nNueva Especie: " << Namefiles[index] << "_Shiny" <<endl;
  }
  else{
    cout << "No se puede afiliar a ninguna especie existente." <<endl;
  }
  
  return 0;
}