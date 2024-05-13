#include <iostream>

using namespace std;
struct PhanSo
{
    int tu;
    int mau;
};
void nhapPhanSo(PhanSo &ps)
{
    do
    {
        cout<<"Nhap tu so: ";
        cin>>ps.tu;
        cout<<"Nhap mau so: ";
        cin>>ps.mau;
    }
    while(ps.tu<=0 || ps.mau<=0);
}
void xuatPhanSo(PhanSo ps)
{
    cout<<ps.tu<<"/"<<ps.mau<<endl;
}
int timUocChungLonNhat(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return timUocChungLonNhat(b,a%b);
}
void toiGianPhanSo(PhanSo &ps)
{
    int uocChungLonNhat=timUocChungLonNhat(ps.tu, ps.mau);
    ps.tu=ps.tu/uocChungLonNhat;
    ps.mau=ps.mau/uocChungLonNhat;
}
PhanSo congHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    /* a/b + c/d = (a*d+b*c)/(b*d) */
    PhanSo ps3;
    ps3.tu=ps1.tu*ps2.mau+ps1.mau*ps2.tu;
    ps3.mau=ps1.mau*ps2.mau;
    toiGianPhanSo(ps3);
    return ps3;
}
PhanSo truHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    /* a/b - c/d = (a*d-b*c)/(b*d) */
    PhanSo ps3;
    ps3.tu=ps1.tu*ps2.mau-ps1.mau*ps2.tu;
    ps3.mau=ps1.mau*ps2.mau;
    toiGianPhanSo(ps3);
    return ps3;
}
PhanSo nhanHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    /* a/b * c/d = (a*c)/(b*d) */
    PhanSo ps3;
    ps3.tu=ps1.tu*ps2.tu;
    ps3.mau=ps1.mau*ps2.mau;
    toiGianPhanSo(ps3);
    return ps3;
}
PhanSo chiaHaiPhanSo(PhanSo ps1, PhanSo ps2)
{
    /* a/b / c/d = (a*d)/(b*c) */
    PhanSo ps3;
    ps3.tu=ps1.tu*ps2.mau;
    ps3.mau=ps1.mau*ps2.tu;
    toiGianPhanSo(ps3);
    return ps3;
}
int main()
{
    PhanSo ps1;
    PhanSo ps2;

    cout<<"Nhap phan so thu nhat:\n";
    nhapPhanSo(ps1);

    cout<<"Nhap phan so thu hai:\n";
    nhapPhanSo(ps2);

    cout<<"Phan so thu nhat: ";
    xuatPhanSo(ps1);

    cout<<"Phan so thu hai: ";
    xuatPhanSo(ps2);

    /*
    toiGianPhanSo(ps1);
    toiGianPhanSo(ps2);

    cout<<"Phan so thu nhat sau khi toi gian(rut gon) la: ";
    xuatPhanSo(ps1);

    cout<<"Phan so thu hai sau khi toi gian(rut gon) la: ";
    xuatPhanSo(ps2);
    */

    PhanSo cong=congHaiPhanSo(ps1,ps2);
    cout<<"Cong hai phan so la: ";
    cout<<cong.tu<<"/"<<cong.mau<<endl;

    PhanSo tru=truHaiPhanSo(ps1,ps2);
    cout<<"Tru hai phan so la: ";
    cout<<tru.tu<<"/"<<tru.mau<<endl;

    PhanSo nhan=nhanHaiPhanSo(ps1,ps2);
    cout<<"Nhan hai phan so la: ";
    cout<<nhan.tu<<"/"<<nhan.mau<<endl;

    PhanSo chia=chiaHaiPhanSo(ps1,ps2);
    cout<<"Chia hai phan so la: ";
    cout<<chia.tu<<"/"<<chia.mau<<endl;
    return 0;
}
