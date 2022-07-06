#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    cout<<"Design of column reinforcement"<<endl;
    cout<<endl;
    float p,le,d,l,b,e,em,s,fck,fy,ast,x,y,z,db;
    float astb,n,cg,cc,cb,ccg,ccd,ps,sb,dt,n1,pu;
    cout<<"STEP 1:"<<endl;
    cout<<"Enter the design load in KN = ";
    cin>>p;
    pu=p*1.5;
    cout<<"Pu= "<<pu<<" KN"<<endl;
    cout<<"Enter the effective length in m = ";
    cin>>le;
    d= (le*1000)/12;
    cout<<"D = "<<d<<" mm"<<endl;
    cout<<"Enter the column size in mm = "<<endl;
    cout<<"Note: first enter the length"<<endl;
    cin>>l;
    cin>>b;
    em= ((le*1000)/500)+(b/30);
    cout<<em<<" mm "<<endl;
    if (em<20)
    {
        cout<<"The dimension of columns can be taken for calculations"<<endl;

    }
    else
    {
        cout<<"Please decrease the dimension of columns"<<endl;
    }
    cout<<endl;
    cout<<"Check for slenderness"<<endl;
    s=(le/b);
    if (s<12)
    {
        cout<<"Effective length is correct"<<endl;
    }
    else
    {
        cout<<"Efective length should be increased"<<endl;
    }
    cout<<endl;
    cout<<"STEP 2:COMPUTE AREA OF STEEL"<<endl;
    cout<<"Enter the concrete grade= ";
    cin>>fck;
    cout<<"Enter the steel grade= ";
    cin>>fy;
    ast=(((pu*1000)-(0.4*fck*b*b))/((0.67*fy)-(0.4*fck)));
    cout<<ast<<" mm2"<<endl;
    cout<<"Enter the dia of bar in mm = ";
    cin>>db;
    astb= 0.785*db*db;
    cout<<"Area of steel bars = "<<astb<<" mm2"<<endl;
    n=ast/astb;
    cout<<"Number of bars = "<<n<<" mm"<<endl;
    cout<<"Enter the number of bars based on "<<n<<" ";
    cin>>n1;
    cout<<"Enter the clear cover in mm = ";
    cin>>cc;
    cb=b-cc-cc-(db/2)-(db/2);
    cout<<"Center - Center outer bar is  "<<cb<<" mm"<<endl;
    cout<<"Enter the number of gaps between bar = ";
    cin>>cg;
    ccg=cb/cg;
    ccd=ccg-(db/2)-(db/2);
    cout<<"Clear gap between two bars is "<<ccd<<" mm"<<endl;
    ps= (n1*astb*100)/(l*b);
    cout<<"Percentage of steel provided is "<<ps<<" %"<<endl;
    if (ps<6)
    {
        cout<<"The assumed dimensions of column is can be considerable"<<endl;
    }
    else
    {
        cout<<"Increase the dimensions of column"<<endl;
        cout<<ps<<" should be less than 6% "<<endl;
    }
    cout<<endl;
    cout<<"STEP 3 = SPACING OF TIE BARS"<<endl;
    cout<<"1) Dimension(breadth) of column = "<<b<<" mm"<<endl;
    sb= 16* db;
    cout<<"2) 16x"<<db<<" ="<<sb<<" mm"<<endl;
    cout<<"3) Lesser or equal to 300 mm"<<endl;
    cout<<"Enter the dia for tie bar = ";
    cin>>dt;
    if (b<sb && b<300)
    {
        cout<<"Provide "<<dt<<" mm bars @ "<<b<<" mm c/c"<<endl;
    }
    else if (sb<b && sb<300)
    {
         cout<<"Provide "<<dt<<" mm bars @ "<<sb<<" mm c/c"<<endl;
    }
    else
    {
         cout<<"Provide "<<dt<<" mm bars @ 300 mm c/c"<<endl;
    }
    













    
    
 
  

    




    


    return 0;


}
