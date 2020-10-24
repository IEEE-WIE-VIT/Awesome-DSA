#include <iostream>
using namespace std;
#include<vector>
class vec
{
private:

    vector<float>v;//declaration of vector
public:
    void creator()
    {
        cout<<"enter the size of the vector"<<endl;
        int n;
        cin>>n;
        float x;
        for(int i=0;i<n;i++)
        {
            cout<<"enter the "<<i+1<<" value:";
            cin>>x;
            v.push_back(x);//pushing into the vector
        }
    }
    void changer(float key,float rep);//function to change elements
    void multiplicate(float m);//function to perform scalar multiplication
    void show();//function to display vector
};
void vec::changer(float key,float rep)//function to change elements
    {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==key)
            {
                v[i]=rep;
            }
        }
    }
void vec::multiplicate(float m)
    {
        for(int i=0;i<v.size();i++)
        {
            v[i]=v[i]*m;
        }
    }
void vec::show()
    {

        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<"  ";
        }
        cout<<endl;
    }
int main()
{
    vec v1;
    v1.creator();
    start:
    cout<<"your vector is created"<<endl<<"what do you want to do with it?"<<endl;
    cout<<"enter 1 to display"<<endl<<"enter 2 to perform scalar multiplication"<<endl;
    cout<<"enter 3 to perform search and replace elements"<<endl<<"enter 0 to exit"<<endl;
    int choice;
    cin>>choice;
    if(choice==0)
    {
        goto end;
    }
    if(choice==1)
    {
        v1.show();

    }
    if(choice==2)
    {
        cout<<"enter the scalar for which you want to perform multipication"<<endl;
        int mul;
        cin>>mul;
        v1.multiplicate(mul);
        goto start;
    }
    if(choice==3)
    {
        cout<<"enter the no you want to replace"<<endl;
        float k;
        cin>>k;
        cout<<"enter the no you want it to replace with"<<endl;
        float r;
        cin>>r;
        v1.changer(k,r);
        goto start;
    }
    end:
    return 0;
}
