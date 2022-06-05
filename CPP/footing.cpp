#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    cout<<"This program is to calculate footing"<<endl;
    cout<<endl;
    cout<<"Design of footing"<<endl;
    float dl,il,l,b,db,fck,fy,lo,sw,sb,a,d,d1,dd,pu,tc,x,y;
    float q,sh,s,ps,tp,mu,c,xu,z,as,n,asb,db1,db2,tpp,cd,cc;
    cout<<"Enter the dead load in KN = ";
    cin>>dl;
    cout<<"Enter the imposed load in KN = ";
    cin>>il;
    cout<<"Enter the dimensions of columns= ";
    cin>>l;
    cin>>b;
    cout<<"Enter the dia of bar= ";
    cin>>db;
    cout<<"Enter the concrete grade= ";
    cin>>fck;
    cout<<"Enter steel grade= ";
    cin>>fy;
    cout<<"Enter the soil bearing capacity in (KN/m2) = ";
    cin>>sb;
    cout<<"Enter the self weight of footing in KN = ";
    cin>>sw;
    lo= (1*dl)+(1*il)+sw;
    cout<<"Total load ="<<lo<<" KN"<<endl;
    a= (lo/sb);
    cout<<"Area of footing = "<<a<<" m2"<<endl;
    d= sqrtf(a);
    cout<<"Length of footing = "<<d<<" m"<<" x "<<d<<" m"<<endl;
    pu= (dl+il+sw)*1.5;
    cout<<"Pu = "<<pu<<" KN"<<endl;
    cout<<"Enter the round figure number for length of footing based on "<<d<<" "<<endl;
    cin>>d1;
    cout<<"Enter the tc value= ";
    cin>>tc;            
    dd= (pu *(d1-(l/1000))) / (2*(pu+(tc*d1*d1)));
    cout<<"d = "<<dd*1000<<" m"<<endl;
    q=pu/(d1*d1);
    cout<<"q= "<<q<<" KN/m2"<<endl;
    cout<<(l/1000)<<endl;
    cout<<dd;
    s=(l/1000)+dd;
    cout<<s<<endl;
    sh=q*((d1*d1)-(s*s));
    cout<<"Shear force= "<<sh<<" KN"<<endl;
    cout<<endl;
    cout<<"Check for permissible shear stress"<<endl;
    ps=0.25*sqrtf(fck);
    cout<<"Permissible Shear stress= "<<ps<<" N/mm2"<<endl;
    tp = (sh/(4*s*dd));
    tpp=tp/1000;
    cout<<"Tp= "<<tpp<<" N/m2"<<endl;
    if (tpp<ps)
    {
        cout<<"The taken depth can be considere for further calculations"<<endl;
    }
    else
    {
        cout<<"Increase the deapth "<<endl;
    }
    cout<<endl; 
    cout<<"Deapth required for bending"<<endl;
    c = (d1-(l/1000));
    cout<<c<<endl;
    mu= (q*(d1*c*c))/8;
    cout<<"Mu= "<<mu<<" KNm"<<endl;
    xu=1.2-(sqrtf(1.44-(6.6*mu*1000000/(fck*d1*1000*dd*dd*1000*1000))));
    cout<<"(x/d)= "<<xu<<endl;
    cout<<endl;
    cout<<"CALCUALTION OF LEVER ARM "<<endl;
    z=(dd*1000)*(1-(0.416*xu));
    cout<<"Lever Arm = "<<z<<" mm"<<endl;
    cout<<endl;
    cout<<"Area of Steel (reqiured) "<<endl;
    as= (mu*1000000)/(0.87*fy* z);
    cout<<"Area of steel = "<<as<<" mm2"<<endl;
    cout<<"Enter the dia of bars : ";
    cin>>db1;
    asb= 0.785*db1*db1;
    n= as/asb;
    cout<<"Enter the round figure of number of bars based on  "<<n<<" = "<<endl;
    cin>>db2;
    cout<<"Enter the clear cover of footing= ";
    cin>>cc;
    cd=(dd*1000)+cc+cc+db1+(db1/2);
    cout<<"Overall deapth of footing is "<<cd<<" mm"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Overall Design summary of footing"<<endl;
    cout<<"Dimensions of footing = "<<d1<<" m x m "<<d1<<endl;
    cout<<"Total deapth of footing= "<<cd<<" mm"<<endl;
    cout<<"Column size = "<<l<<" mm x "<<b<<" mm"<<endl;



    
    return 0;





     





}
