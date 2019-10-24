#include<bits/stdc++.h>

using namespace std;

int lookUpArray[] = {1,2,3,4,5,6,7,8,9,
                2,4,6,8,10,12,14,16,18,
                3,6,9,12,15,18,21,24,27,
                4,8,12,16,20,24,28,32,36,
                5,10,15,20,25,30,35,40,45,
                6,12,18,24,30,36,42,48,54,
                7,14,21,28,35,42,49,56,63,
                8,16,24,32,40,48,56,64,72,
                9,18,27,36,45,54,63,72,81};

int mul(int a, int b){
    int c = 0;
    while(b--)
    c += a;
    return c;
}
int AtoI(char a){
    return a - 48;
}

string add(string str1, string str2) 
{
    int c = 0;
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = "";
    
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int carry = 0; 
    for (int i=0; i<n1; i++) {  
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0');  
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    }   
    if (carry) 
        str.push_back(carry+'0');  
    reverse(str.begin(), str.end()); 
    return str; 
} 

int lookUp(int i, int j) {
    if(i == 0 || j == 0) return 0;
    return lookUpArray[mul(9,i-1)+(j-1)];
}
string zeroStr(int i) {
    string s = "";
    while(i--){
        s = s + '0';
    }
    return s;
}
int decimalPos(string s) {
    int l = s.length();
    int pos = l;
    for(int i = 0; i < l; i++) {
        if(s[i] == '.') pos = i;
    }
    if(pos == l) return 0;
    return l-pos-1;
}
string absolute(string s) {
    if(s[0] == '-') return s.substr(1,s.length()-1);
    return s;
}
float multiply(string aStr, string bStr) {
    long long int  aLen, bLen, adecPos, bdecPos, i, j, k = 0,c = 0,
    carry, product, productLen, result, resultant;
    float finalAnswer;
    string productStr, resultantStr,finalStr = "0";
    if(aStr[0] == '-') c++;
    if(bStr[0] == '-') c++;
    // taking abs value of a & b
    aStr = absolute(aStr);
    bStr = absolute(bStr);
    
    aLen = aStr.length();
    bLen = bStr.length();
    adecPos = decimalPos(aStr);
    bdecPos = decimalPos(bStr);
    reverse(aStr.begin(), aStr.end());
    reverse(bStr.begin(), bStr.end());
    for(i = 0; i < bLen; i++) {
        carry = 0;
        if(bStr[i] == '.') continue;
        resultantStr = zeroStr(k++);
        for(j = 0; j < aLen; j++) {
            stringstream productParser;
            if(aStr[j] == '.') continue;
            product = lookUp( AtoI(aStr[j]), AtoI(bStr[i]));
            product += carry;
            productParser << product;
            productParser >> productStr;
            productLen = productStr.length();
            if(productLen == 2) {
                result = AtoI(productStr[1]);
                carry = AtoI(productStr[0]);
            }
            else if(productLen == 1) {
                result = AtoI(productStr[0]);
                carry = 0;
            }
            resultantStr.push_back(result+'0');
        }
        if(carry != 0) // if final carry is non zero
            resultantStr.push_back(carry+'0');
        reverse(resultantStr.begin(),resultantStr.end());
        finalStr = add(finalStr,resultantStr);
    }
    int finalLen = finalStr.length();
    int finalDecPos = finalLen-adecPos-bdecPos;
    if(finalDecPos >= 0 && finalDecPos <= finalLen)//checks if atleast one of the no is float
        finalStr.insert(finalLen-(adecPos+bdecPos),".");
    //converting back to actual value with sign
    if(c%2 != 0) finalStr.insert(0,"-");
    stringstream finalParser;
    finalParser << finalStr;
    finalParser >> finalAnswer;
    return finalAnswer;
}
 

int main() {
    float A,C, ac, bd, ad, bc, x, y, ac1, error;
    string a, b, c, d;
    int t;
    //ofstream file;
    cin >> t;
    //file.open("accuracy.dat");
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c >> d;
        ac = multiply(a,c);
        bd = multiply(b,d);
        ad = multiply(a,d);
        bc = multiply(b,c);
        x = ac - bd;
        y = ad + bc;
        stringstream numParser;
        numParser << a << " " << c;
        numParser >> A >> C; 
       // cout << "A " << A << " C " << C << endl;
        ac1 = A*C;
        error = abs(ac1-ac);
        if(y < 0)
            cout << x << "-" << abs(y) << "i";
        else
            cout << x << "+" << y << "i";
        cout << ac << '\t' << ac1 << '\t' << error << endl;
       // file << ac1 << '\t' << error << endl;
    }
}