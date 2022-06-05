#include<iostream>
#include<conio.h>
#include<math.h>
#include<cmath>
using namespace std;

int main()

{
    float df,t1,t2,w,n,n1,n2,n3,bw,r1,m,m1,ll,wf,le,mu; 
    float vu,bf,deff,cc,d,od,fck,x,ast,area,a,tv,tc,x1,x2,x3;
    float fy,vc,vs,d2,l,asv,y,sv,lb,cd;
    cout<<"Calcualtion for beam reinforcements"<<endl; 
    cout<<"Enter the live load as IS code 875 : ";
    cin>>ll;
    cout<<"Enter the thickness of slab in mm : ";
    cin>>df;
    cout<<"Deapth of web in mm : ";
    cin>>w;
    cout<<"Size of rib(width)in mm : ";
    cin>>bw;
    cout<<"Size of rid(deapth)in mm :";
    cin>>r1;
    cout<<"Enter the thickness of ceiling plaster in mm : ";
    cin>>t1;
    cout<<"Enter the thickness of floor finish in mm : ";
    cin>>t2;
    cout<<endl;
    cout<<"Step 1 : Dead Loads"<<endl;
    n=(df*25)/1000;
    cout<<" n = "<<n<<endl;
    n1=float((t1*24)/1000);
    cout<<" n1 = "<<n1<<endl;
    n2=float((t2*24)/1000);
    cout<<" n2 = "<<n2<<endl;
    cout<<"Dead loads are "<<n+n1+n2<<"KN/m"<<endl;
    cout<<endl;
    cout<<"Step 2: Loads on beam : "<<endl;
    cout<<"Enter the distance of beams center to center : "<<endl;
    cin>>lb;
    m=((n+n1+n2)*lb);
    m1=(1.05*w*bw*25)/1000000;
    cout<<"Dead loads for slabs: "<<m<<"KN/m"<<endl;
    cout<<"5 percent extra: "<<m1<<"KN/m"<<endl;
    cout<<"Total dead load= "<<m+m1<<"KN/m"<<endl;
    cout<<"Total live load= "<<ll*3<<"KN/m"<<endl;
    cout<<endl;
    cout<< "STEP 3: CALCUALTION OF FACTOR LOAD:"<<endl;
    wf =1.5*((m+m1)+(ll*3));
    cout<<"Wf="<<wf<<"KN/m"<<endl;
    cout<<"Enter the length of the beams in m :";
    cin>>le;
    mu=((wf*le*le)/8);
    cout<<"Mu="<<mu<<"KNm"<<endl;
    vu=((wf*le)/2);
    cout<<"Vu="<<vu<<"KNm"<<endl;
    cout<<endl;
    cout<<"STEP 4: EFFECTIVE WIDTH AND DEAPTH "<<endl;
    bf=((le/6)+(bw/1000)+((6*df)/1000));
    cout<<"Bf= "<<bf<<"m"<<endl;
    od=r1+df;
    cout<<"Overall deapth= "<<od<<"m"<<endl;
    cout<<"Enter the dia of tensile reinforcement in mm = ";
    cin>>d;
    cout<<"Enter the clear cover in mm =";
    cin>>cc;
    deff= ((od-cc)-(d/2));
    cout<<"Effective deapth is "<<deff<<" mm"<<endl;
    cout<<endl;
    cout<<" STEP5: CALCULATION OF X "<<endl;
    cout<<"Enter the concrete grade: ";
    cin>>fck;
    x = (1.2 - (sqrtf(1.44-(6.68*mu*1000000)/(fck*bf*1000*deff*deff))))*deff;
    cout<<"The value of x is:"<<x<<" m"<<endl;

    if (x < df){
        cout<<"The chosen thickness of slab  "<< df<<"mm  calculatons can be continued"<<endl;

    }
    else{
        cout<<"The thickness of the slab should be increased"<<endl;
    }

    cout<<endl;
   cout<<"STEP6: STEEL TO BE PROVIDED:"<<endl;
   cout<<"Enter the steel grade: ";
   cin>>fy;
   ast= ((mu*1000000) / ((0.87*fy)*(deff-(0.42*x ))));
   cout<<"The ast provided : "<<ast<<" mm2"<<endl;
   cout<<endl;
   cout<<"STEP7: CHECKING OF STEEL PERCENTAGE"<<endl;
   cout<<"Enter the number of bars: ";
   cin>>n3;
   area= n3*0.785*d*d;
    a=(area*100)/(w*deff);
    cout<<"Ast provided (steel %): "<<a<<" %"<<endl;
    cout<<endl;
    cout<<"STEP 8:SHEAR REINFORCEMENT"<<endl;
    tv = (vu*1000) /(bw*deff);
    cout<<"Value of Tv: "<<tv<<" N/m"<<endl;
    cout<<"Check the value of Tv in table 19 from IS456:2000"<<endl;
    cout<<"Enter the Tc values two :  "<<endl;
    cout<<"Hint: first least number"<<endl;
    cin>>x1;
    cin>>x2;
    cout<<"Enter the (100Ast/bd) value (hint: least number): ";
    cin>>x3;
    tc = x1+(((x2-x1)*(a-x3)/0.25));
    cout<<"The value of Tc is :"<<tc<<" N/mm2"<<endl;
    cout<<endl;
    cout<<"STEP 9: DUE TO CONCERETE"<<endl;
    vc=(tc*bw*deff)/1000;
    cout<<"Vc = "<<vc<<" KN"<<endl;
    cout<<"Shear to be taken by steel:"<<endl;
    vs=vu-vc;
    cout<<"Vs = "<<vs<<endl;
    cout<<"Enter the stirup diameter in mm : ";
    cin>>d2;
    cout<<"Enter the legged of stirup in mm : ";
    cin>>l;
    asv=(l*0.785*d2*d2);
    cout<<"Asv = "<<asv<<endl;
    y=(vs*1000/(0.87*fy*deff));
    sv=asv/y;
    cout<<"Spacing of bars is : "<<sv<<"mm"<<endl;
    cout<<endl;
    cd=0.75*(deff/1000);
    cout<<"Checking for maximum spacing :"<<endl;
    if (sv<cd && sv<300)
    {
       cout<<sv<<" mm can be taken for spacing of bars";
    }
    else if (cd<sv && cd<300)
    {
        cout<<cd<<" mm can be taken for spacing of bars";   
    }
    else
    {
         cout<<"  300 mm can be taken for spacing of bars";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Design summary"<<endl;
    cout<<"Concrete grade = "<<fck<<endl;
    cout<<"Steel grade = "<<fy<<endl;
    cout<<"Clear cover = "<<cc<<endl;
    cout<<"Main longitudinal tensile bars = " <<n3<<" - "<<d<<" mm"<<endl;
    cout<<"Stirrup rods = "<<d2<<" mm @ "<<sv<<" mm c/c";
    
   
    


    


    



   
    
    
    
    return 0;
}