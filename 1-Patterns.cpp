#include <bits/stdc++.h>
using namespace std;

class Patterns
{
private:
    int n;

public:
    Patterns(int n)
    {
        this->n = n;
        pattern1();
        cout << "\n";
        pattern2();
        cout << "\n";
        pattern3();
        cout << "\n";
        pattern4();
        cout << "\n";
        pattern5();
        cout << "\n";
        pattern6();
        cout << "\n";
        pattern7();
        cout << "\n";
        pattern8();
        cout << "\n";
        pattern9();
        cout << "\n";
        pattern10();
        cout << "\n";
        pattern11();
        cout << "\n";
        pattern12();
        cout << "\n";
        pattern13();
        cout << "\n";
        pattern14();
        cout << "\n";
        pattern15();
        cout << "\n";
        pattern16();
        cout << "\n";
        pattern17();
        cout << "\n";
        pattern18();
        cout << "\n";
        pattern19();
        cout << "\n";
        pattern20();
        cout << "\n";
        pattern21();
    }

    /*
     ****
     ****
     ****
     ****
     */
    void pattern1()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << "*";
            cout << "\n";
        }
    }

    /*
     *
     * *
     * * *
     * * * *
     */
    void pattern2()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << "* ";
            cout << "\n";
        }
    }

    /*
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
    */
    void pattern3()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << j + 1 << " ";
            cout << "\n";
        }
    }

    /*
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5
    */
    void pattern4()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << i + 1 << " ";
            cout << "\n";
        }
    }

    /*
     * * * * *
     * * * *
     * * *
     * *
     *
     */
    void pattern5()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n - i; j > 0; j--)
                cout << "* ";
            cout << "\n";
        }
    }

    /*
        1 2 3 4 5
        1 2 3 4
        1 2 3
        1 2
        1
    */
    void pattern6()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
                cout << j + 1 << " ";
            cout << "\n";
        }
    }

    /*
        *
       ***
      *****
     *******
    *********
    */
    void pattern7(){
        for(int i = 0; i < n; i++){
            
            // For spaces
            for(int j = 0; j < n-i; j++)
                cout << " ";
            // For stars
            for(int j = 0; j < 2*i + 1; j++)
                cout << "*";
            
            cout << "\n";
        }
    }

/*
 *********
  *******
   *****
    ***
     *
*/
    void pattern8(){
        for(int i = 0; i < n; i++){
                
                // For spaces
                for(int j = 0; j <= i; j++)
                    cout << " ";
                // For stars
                for(int j = 0; j < 2*n - 2*i - 1; j++)
                    cout << "*";
                
                cout << "\n";
            }
        }


    /*
             *
            ***
           *****
          *******
         *********
         *********
          *******
           *****
            ***
             *
    */
    void pattern9(){
        pattern7();
        pattern8();
    }


    /*
        * 
        * * 
        * * * 
        * * * * 
        * * * * * 
        * * * * 
        * * * 
        * * 
        * 
    */
    void pattern10(){
        for(int i = 0; i < 2*n - 1; i++){
            int stars = (i<n) ? i : 2*n - i - 2;
            for(int j = 0; j <= stars; j++)
                cout << "* ";
            cout << "\n";
        }
    }


    /*
        1 
        0 1 
        1 0 1 
        0 1 0 1 
        1 0 1 0 1 
    */
    void pattern11(){
        for(int i = 0; i < n; i++){
            int start = (i%2) ? 1 : 0;
            for(int j = 0; j <= i; j++){
                start = (start) ? 0 : 1;
                cout << start << " ";
            }
            cout << "\n";
        }
    }

    /*
        1        1
        12      21
        123    321
        1234  4321
        1234554321
    */
    void pattern12(){
        int space = 2*(n-1);
        for(int i = 0; i < n; i++){
            // numbers
            for(int j = 0; j <= i; j++)
                cout << j+1;

            // space
            for(int j = 0; j < space; j++)
                cout << " ";

            // numbers
            for(int j = i + 1; j >= 1; j--)
                cout << j;
            space -= 2;
            cout << "\n";
        }
    }

    /*
        1 
        2 3 
        4 5 6 
        7 8 9 10 
        11 12 13 14 15 
    */
    void pattern13(){
        int num = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++)
                cout << num++ << " ";
            cout << endl;
        }
    }

    /*
        A 
        A B 
        A B C 
        A B C D 
        A B C D E 
    */
    void pattern14(){
        for(int i = 0; i < n; i++){
            for (char ch = 'A'; ch <= 'A' + i; ch++)
                cout << ch << " ";
            cout << endl;
        }
    }


    /*
        ABCDE
        ABCD
        ABC
        AB
        A
    */
    void pattern15(){
        for(int i = 0; i < n; i++){
            for (char ch = 'A'; ch < 'A' + (n-i); ch++)
                cout << ch << " ";
            cout << "\n";
        }
    }

    /*
        A 
        B B 
        C C C 
        D D D D 
        E E E E E 
    */
    void pattern16(){
        for(int i = 0; i < n; i++){
            char a = 'A' + i;
            for(int j = 0; j <= i; j++){
                cout << a << " ";
            }
            cout << "\n";
        }
    }

    /*
            A 
          A B A 
        A B C B A 
      A B C D C B A 
    A B C D E D C B A 
    */
    void pattern17(){
        for(int i = 0; i < n; i++){
            // Spaces 
            for(int j = 0; j < n - i - 1; j++)
                cout << "  ";

            // Characters
            char a = 'A';
            int breakpoint = (2*i + 1)/ 2;
            for(int j = 0; j < 2*i + 1; j++){
                if (j<breakpoint)
                    cout << a++;
                else
                    cout << a--;
                cout << " ";
            }
            cout << "\n";
        }
    }

    /*
        E 
        D E 
        C D E 
        B C D E 
        A B C D E 
    */
    void pattern18(){
        for(int i = 0; i < n; i++){
            for (char ch = 'E' - i; ch <= 'E'; ch++)
                cout << ch << " ";
            cout << "\n";
        }
    }


    /*
        **********
        ****  ****
        ***    ***
        **      **
        *        *
        *        *
        **      **
        ***    ***
        ****  ****
        ********** 
    */
    void pattern19(){
        for(int i = 0; i < n; i++){
            // Stars
                for(int j = 0; j < n-i; j++)
                    cout << "*";
    
            // Spaces
            for(int j = 0; j < 2*i; j++)
                cout << " ";
            
            // Stars
            for(int j = 0; j < n-i; j++)
                cout << "*";
            
            cout << "\n";
        }

        int initialSpace = 8;
        for(int i = 0; i < n; i++){
            // Stars
                for(int j = 0; j <= i; j++)
                    cout << "*";
    
            // Spaces
            for(int j = 0; j < initialSpace; j++)
                cout << " ";
            
            // Stars
            for(int j = 0; j <=i ; j++)
                cout << "*";
            
            cout << "\n";
            initialSpace -=2;
        }
    }


    /*
        *        *
        **      **
        ***    ***
        ****  ****
        **********
        ****  ****
        ***    ***
        **      **
        *        *
    */
    void pattern20(){
        int initalSpace = 2*n,stars = 0;
        for(int i = 0; i < 2*n  - 1; i++){
            if(i >= n){
                stars = 2*n - i - 2;
                initalSpace += 2;
            }
            else{
                stars = i;
                initalSpace -= 2;
            }
            // Stars
            for(int j = 0; j <= stars; j++){
                cout << "*";
            }
            // Spaces
            for(int j = 0; j < initalSpace; j++){
                cout <<" ";
            }
            // Stars
            for(int j = 0; j <= stars; j++){
                cout << "*";
            }

            cout << "\n";
        }
    }


    /*
        *****
        *   *
        *   *
        *   *
        *****
    */
    void pattern21(){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == 1 || j == 1 || i == n || j == n)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << "\n";
        }
    }


    void pattern22(){
        // TO BE COMPLETED : https://www.youtube.com/watch?v=tNm_NNSB3_w&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=7
        for(int i = 0; i < 2*n - i; i++){
        }
    }
};



int main()
{
    int n;
    cin >> n;
    Patterns pattern(n);
    return 0;
}