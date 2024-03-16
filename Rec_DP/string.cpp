#include<iostream>
using namespace std;
void pald(string& a, int i, int j){
    
    if(i>j){
        return;
    }
    swap(a[i],a[j]);
    i++;
    j--;
    pald(a,i,j);

}
int main(){
    string c = ("Arzu");
    int l = c.length() - 1;
    pald(c,0,l);
    cout << c << endl; 
}