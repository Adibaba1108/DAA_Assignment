 #include <iostream>
using namespace std;
#define NUMBER_OF_DECIMAL_PLACES 3

int divisor_multiplied_by_quotient(int divisor, int quotient)
{
    int res = 0;
    for (int i = 1; i <= min(divisor, quotient); i++)
        res += max(divisor, quotient);
    return res;
}

int get_dividend(string number)
{
    string num = "1";
    for (int i = 0; i < number.length(); i++)
        num += "0";
    return stoi(num);
}

int generate_dividend(int divisor, int remainderr, int *count)
{
    *count = -1;
    int generated_remainder;
    while (remainderr < divisor)
    {
        generated_remainder = 0;
        for (int i = 0; i < 10; i++)
            generated_remainder += remainderr;
        remainderr = generated_remainder;
        *count++; 
    }
    return generated_remainder;
}

int get_quotient(int dividend, int divisor)
{
    int quotient = 0;
    while (dividend >= divisor)
    {
        dividend -= divisor;
        quotient++;
    }
    return quotient;
}

int main()
{
    string ans = "";
    float number;
    cout << "Enter the sine value : \n";
    cin >> number;
    if (number < -1 || number > 1)
    {
        cout << number << " is not a valid sine value\n";
        exit(0);
    }
    if(number==0){
      printf("undefined\n");
      return 0;
    }

    if (number < 0){
        ans += "-";
      number *=-1;
      
    }
   
    string string_number = to_string(number);
    string_number = string_number.substr(2, string_number.length()-2);
    int dividend = get_dividend(string_number);
    int divisor = stoi(string_number);

    int quotient = get_quotient(dividend, divisor);
    int remainderr = dividend - divisor_multiplied_by_quotient(divisor, quotient);
    ans += to_string(quotient);
    if (remainderr == 0)
    {
        cout << ans << endl;
        exit(0);
    }
    ans += ".";
    for (int i = 0; i < NUMBER_OF_DECIMAL_PLACES; i++)
    {
        int count;
        count=-1;
        dividend = generate_dividend(divisor, remainderr, &count);
        for (int j = 0; j < count; j++)
            ans += "0";
        quotient = get_quotient(dividend, divisor);
        remainderr = dividend - divisor_multiplied_by_quotient(divisor, quotient);
        ans += to_string(quotient);
        if (remainderr == 0)
            break;
    }
    cout << ans;
}